// SPDX-FileCopyrightText: 2023 deroad <wargio@libero.it>
// SPDX-License-Identifier: MIT

#include <MSALRuntime.h>
#include <MSALRuntimeLogging.h>

#include <iostream>
#include "utils.hpp"

#define APP_CLIENT_ID L"" APP_ID
#define APP_AUTHORITY L"https://login.microsoftonline.com/" AUTH_ID

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

static void auth_callback(
		MSALRUNTIME_AUTH_RESULT_HANDLE authResult, void *callbackData) {
	bool *shouldWait = (bool *)callbackData;
	MSALRUNTIME_ACCOUNT_HANDLE account = 0;

	// print account info
	MSALRUNTIME_GetAccount(authResult, &account);
	printAccount(account);

	// print auth result
	printAuthResult(authResult);

	// free memory
	MSALRUNTIME_ReleaseAccount(account);
	MSALRUNTIME_ReleaseAuthResult(authResult);

	// let's stop waiting for this async callback
	*shouldWait = false;
}

int main(int argc, char const *argv[]) {
	// Some vars to wait for reply
	bool shouldWait = true;

	// MSAL required variables
	MSALRUNTIME_LOG_CALLBACK_HANDLE logHandle = 0;
	MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters = 0;
	MSALRUNTIME_ASYNC_HANDLE asyncHandle = 0;

	// create a random correlation uuid (can be empty)
	auto correlationId = uuidGen();

	// initialize msalruntime
	MSALRUNTIME_Startup();

	// setup msal logger
	MSALRUNTIME_RegisterLogCallback(logger_callback, nullptr, &logHandle);

	// set pii
	MSALRUNTIME_SetIsPiiEnabled(0);

	// create auth parameters and configure the app.
	MSALRUNTIME_CreateAuthParameters(
			APP_CLIENT_ID, APP_AUTHORITY, &authParameters);

	// sets the requested scopes (mandatory and cannot be an empty string).
	MSALRUNTIME_SetRequestedScopes(
			authParameters, L"https://graph.microsoft.com/.default");

	// configure the redirect uri to use the secure broker popup
	// msal for python sets this as 'placeholder'.
	MSALRUNTIME_SetRedirectUri(authParameters, L"placeholder");

	// set the secure broker popup to not block this thread.
	MSALRUNTIME_SetAdditionalParameter(
			authParameters, L"msal_gui_thread", L"true");

	// finally try to sign in.
	// You can get the accountHint (i.e. username via MSALRUNTIME_DiscoverAccountsAsync)
	MSALRUNTIME_SignInSilentlyAsync(authParameters, correlationId.c_str(),
			auth_callback, &shouldWait, &asyncHandle);

	// this is a terrible way to wait for async, but this is
	// an example, so please use locks & signals.
	while (shouldWait) {
		Sleep(300);
	}

	// free the async handle
	MSALRUNTIME_ReleaseAsyncHandle(asyncHandle);

	// free auth parameters
	MSALRUNTIME_ReleaseAuthParameters(authParameters);

	// free logger handle
	MSALRUNTIME_ReleaseLogCallbackHandle(logHandle);

	// deinitialize msalruntime
	MSALRUNTIME_Shutdown();
	return 0;
}