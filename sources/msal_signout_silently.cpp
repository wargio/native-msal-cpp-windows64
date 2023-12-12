// SPDX-FileCopyrightText: 2023 deroad <wargio@libero.it>
// SPDX-License-Identifier: MIT

#include <MSALRuntime.h>
#include <MSALRuntimeLogging.h>

#include <iostream>
#include "utils.hpp"

#define APP_CLIENT_ID L"" APP_ID

typedef struct discover_s {
		bool called;
		MSALRUNTIME_ACCOUNT_HANDLE account;
} discover_t;

static void logger_callback(const os_char *logMessage,
		const MSALRUNTIME_LOG_LEVEL logLevel, void *callbackData) {
	switch (logLevel) {
	default:
		/* fall-thru */
	case Msalruntime_Log_Level_Trace:
		std::wcout << "[Trace  ]" << logMessage << std::endl;
		break;
	case Msalruntime_Log_Level_Debug:
		std::wcout << "[Debug  ]" << logMessage << std::endl;
		break;
	case Msalruntime_Log_Level_Info:
		std::wcout << "[Info   ]" << logMessage << std::endl;
		break;
	case Msalruntime_Log_Level_Warning:
		std::wcout << "[Warning]" << logMessage << std::endl;
		break;
	case Msalruntime_Log_Level_Error:
		std::wcout << "[Error  ]" << logMessage << std::endl;
		break;
	case Msalruntime_Log_Level_Fatal:
		std::wcout << "[Fatal  ]" << logMessage << std::endl;
		break;
	}
}

static void signout_callback(
		MSALRUNTIME_SIGNOUT_RESULT_HANDLE signoutResult, void *callbackData) {
	bool *shouldWait = (bool *)callbackData;

	MSALRUNTIME_ReleaseSignOutResult(signoutResult);

	// let's stop waiting for this async callback
	*shouldWait = false;
}

static void discover_callback(
		MSALRUNTIME_DISCOVER_ACCOUNTS_RESULT_HANDLE discoverAccountsResult,
		void *callbackData) {
	discover_t *ctx = (discover_t *)callbackData;

	// fetch the first account available
	MSALRUNTIME_GetDiscoverAccountsAt(discoverAccountsResult, 0, &ctx->account);

	// free up memory
	MSALRUNTIME_ReleaseDiscoverAccountsResult(discoverAccountsResult);

	// stop waiting for this async call
	ctx->called = true;
}

static MSALRUNTIME_ACCOUNT_HANDLE discoverFirstAccount(
		std::wstring &correlationId) {
	discover_t ctx = { 0 };
	MSALRUNTIME_ASYNC_HANDLE asyncHandle = 0;

	MSALRUNTIME_DiscoverAccountsAsync(APP_CLIENT_ID, correlationId.c_str(),
			discover_callback, &ctx, &asyncHandle);

	// this is a terrible way to wait for async, but this is
	// an example, so please use locks & signals.
	while (!ctx.called) {
		Sleep(300);
	}

	// free the async handle
	MSALRUNTIME_ReleaseAsyncHandle(asyncHandle);

	// return the first account.
	return ctx.account;
}

int main(int argc, char const *argv[]) {
	// Some vars to wait for reply
	bool shouldWait = true;

	// MSAL required variables
	MSALRUNTIME_LOG_CALLBACK_HANDLE logHandle = 0;
	MSALRUNTIME_ASYNC_HANDLE asyncHandle = 0;
	MSALRUNTIME_ACCOUNT_HANDLE account = 0;

	// get parent window handler
	auto parentHwnd = consoleWindow();

	// create a random correlation uuid (can be empty)
	auto correlationId = uuidGen();

	// initialize msalruntime
	MSALRUNTIME_Startup();

	// setup msal logger
	MSALRUNTIME_RegisterLogCallback(logger_callback, nullptr, &logHandle);

	// set pii
	MSALRUNTIME_SetIsPiiEnabled(0);

	// get first account available
	account = discoverFirstAccount(correlationId);
	printAccount(account);

	// finally try to logout.
	MSALRUNTIME_SignOutSilentlyAsync(correlationId.c_str(), APP_CLIENT_ID,
			account, signout_callback, &shouldWait, &asyncHandle);

	// this is a terrible way to wait for async, but this is
	// an example, so please use locks & signals.
	while (shouldWait) {
		Sleep(300);
	}

	// free the async handle
	MSALRUNTIME_ReleaseAsyncHandle(asyncHandle);

	// free logger handle
	MSALRUNTIME_ReleaseLogCallbackHandle(logHandle);

	// deinitialize msalruntime
	MSALRUNTIME_Shutdown();
	return 0;
}