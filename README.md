# Native MSAL C++ Example using msalruntime

This is a C++ example which uses the Microsoft MSAL Runtime library available for the python MSAL module.

## Usage

In this repository you will find 2 source folders

- `sources` contains the examples using the library `msalruntime.dll`
- `subproject` contains the meson `wrap` file that allows to download, unpack and include the library when building the examples.

## How to build it

Install python and then, using `pip`, install `ninja` and `meson`, alternatively you can use `muon`.

Then, open a developer command prompt and run the following commands

```
meson setup --reconfigure --prefix=%CD%\release -Dappid="xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx" -Dauthority="yyyyyyyy-yyyy-yyyy-yyyy-yyyyyyyyyyyy" build
ninja -C build install
```

You can then run any of the built examples from the `release/bin` folder.

## FAQ

- This code is pure native; there is no translation or calls to python and its modules.
- You can embed this code to build C++ client applications which requires an AzureAD (Entra ID) token for the REST APIs.
- All the calls made by the MSAL library are asyncronous.
- You are required to initialize `msalruntime.dll` using the startup/shutdown functions.
- You will need to ship your built executable with `msalruntime.dll`.

## Example of interactive signin.

For more examples, please look at the folder `sources`.

```cpp
#include <iostream>
#include <MSALRuntime.h>
#include <windows.h>

// Your Microsoft Azure AD/Entra ID "Application (client) ID"
#define APP_CLIENT_ID "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx"

// Your Microsoft Azure AD/Entra ID "Directory (tenant) ID"
#define APP_AUTHORITY \
	"https://login.microsoftonline.com/yyyyyyyy-yyyy-yyyy-yyyy-yyyyyyyyyyyy"

static void auth_callback(
		MSALRUNTIME_AUTH_RESULT_HANDLE authResult, void *callbackData) {
	bool *shouldWait = (bool *)callbackData;

	int32_t token_length = 0;
	// get token length.
	MSALRUNTIME_GetAccessToken(handle, nullptr, &token_length);
	if (token_length > 0) {
		os_char *token = new os_char[token_length];
		if (MSALRUNTIME_GetAccessToken(handle, token, &token_length) ==
				MSALRUNTIME_SUCCEED) {
			// print the token
			std::wcout << token << std::endl;
		}
		delete[] token;
	}

	// free memory
	MSALRUNTIME_ReleaseAuthResult(authResult);

	// let's stop waiting for this async callback
	*shouldWait = false;
}

static HWND consoleWindow() {
	return GetAncestor(GetConsoleWindow(), 3);
}

int main(int argc, char const *argv[]) {
	// Some vars to wait for reply
	bool shouldWait = true;

	// MSAL required variables
	MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters = 0;
	MSALRUNTIME_ASYNC_HANDLE asyncHandle = 0;

	// get parent window handler
	auto parentHwnd = consoleWindow();

	// create a random correlation uuid (can be empty)
	std::wstring correlationId = L"";

	// initialize msalruntime
	MSALRUNTIME_Startup();

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
	MSALRUNTIME_SignInAsync(parentHwnd, authParameters, correlationId.c_str(),
			L"", auth_callback, &shouldWait, &asyncHandle);

	// this is a terrible way to wait for async, but this is
	// an example, so please use locks & signals.
	while (shouldWait) {
		Sleep(300);
	}

	// free the async handle
	MSALRUNTIME_ReleaseAsyncHandle(asyncHandle);

	// free auth parameters
	MSALRUNTIME_ReleaseAuthParameters(authParameters);

	// deinitialize msalruntime
	MSALRUNTIME_Shutdown();
	return 0;
}
```
