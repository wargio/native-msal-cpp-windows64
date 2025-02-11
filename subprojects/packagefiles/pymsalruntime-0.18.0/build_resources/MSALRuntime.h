// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

// Consumers of MSALRuntime must only include this header file (MSALRuntime.h) and not the children header files
// MSALRuntime*.h

#pragma once
#include "MSALRuntimeAccount.h"
#include "MSALRuntimeAuthParameters.h"
#include "MSALRuntimeAuthResult.h"
#include "MSALRuntimeCancel.h"
#include "MSALRuntimeDiscoverAccountsResult.h"
#include "MSALRuntimeError.h"
#include "MSALRuntimeLogging.h"
#include "MSALRuntimeReadAccountResult.h"
#include "MSALRuntimeSignoutResult.h"
#include "MSALRuntimeTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Initializes the MSALRuntime for use. This must be called before calling any MSALRuntime functions.
 * (Internally this pins the .dll so that a crash does not happen if the .dll is unloaded early by the client)
 *
 * @return - null handle, success, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_Startup(void);

/*
 * Shuts the MSALRuntime down.
 * This must be called to ensure proper cleanup of the MSALRuntime before unloading the .dll.
 * If MSALRUNTIME_Shutdown() is not called prior to the .dll unload, then there will be a leak.
 */
void MSALRUNTIME_API MSALRUNTIME_Shutdown(void);

/*
 * Obtain the account by supplying the account id.
 *
 * @in-param const os_char* accountId - The id for the targeted account.
 * @in-param const os_char* correlationId - correlationId used to track telemetry.
 * @in-param MSALRUNTIME_READ_ACCOUNT_COMPLETION_ROUTINE callback - callback function to be called after the
 * ReadAccountById operation is completed.
 * @in-param void* callbackData - data to be passed to the callback() function by MSALRuntime.
 * @in-out-param MSALRUNTIME_ASYNC_HANDLE* asyncHandle - the handle for canceling this operation.
 *
 * @return - null handle, success, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_ReadAccountByIdAsync(
    const os_char* accountId,
    const os_char* correlationId,
    MSALRUNTIME_READ_ACCOUNT_COMPLETION_ROUTINE callback,
    void* callbackData,
    MSALRUNTIME_ASYNC_HANDLE* asyncHandle);

/*
 * SignIn the user, which may or may not show UI.
 * This operation will always sign in silently first and if fail, it will show UI.
 *
 * @in-param WINDOW_HANDLE  - parentHwnd to be set.
 * @in-param MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters - The handle for the request parameters.
 * @in-param const os_char* correlationId - correlationId used to track telemetry.
 * @in-param const os_char* accountHint - the account username.
 * @in-param MSALRUNTIME_COMPLETION_ROUTINE callback - callback function to be called after the SignInAsync operation is
 * completed.
 * @in-param void* callbackData - data to be passed to the callback() function by MSALRuntime.
 * @in-out-param MSALRUNTIME_ASYNC_HANDLE* asyncHandle - the handle for canceling this operation.
 *
 * @return - null handle, success, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_SignInAsync(
    WINDOW_HANDLE parentHwnd,
    MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters,
    const os_char* correlationId,
    const os_char* accountHint,
    MSALRUNTIME_COMPLETION_ROUTINE callback,
    void* callbackData,
    MSALRUNTIME_ASYNC_HANDLE* asyncHandle);

/*
 * Sign in the user, this is a silent operation, which will never show UI.
 *
 * @in-param MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters - The handle for the request parameters.
 * @in-param const os_char* correlationId - correlationId used to track telemetry.
 * @in-param MSALRUNTIME_COMPLETION_ROUTINE callback - callback function to be called after the silent operation is
 * completed.
 * @in-param void* callbackData - data to be passed to the callback() function by MSALRuntime.
 * @in-out-param MSALRUNTIME_ASYNC_HANDLE* asyncHandle - the handle for canceling this operation.
 *
 * @return - null handle, success, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_SignInSilentlyAsync(
    MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters,
    const os_char* correlationId,
    MSALRUNTIME_COMPLETION_ROUTINE callback,
    void* callbackData,
    MSALRUNTIME_ASYNC_HANDLE* asyncHandle);

/*
 * Sign in the user, which may or may not show UI.
 *
 * @in-param WINDOW_HANDLE  - parentHwnd to be set.
 * @in-param MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters - The handle for the request parameters.
 * @in-param const os_char* correlationId - correlationId used to track telemetry.
 * @in-param const os_char* accountHint - the account username.
 * @in-param MSALRUNTIME_COMPLETION_ROUTINE callback - callback function to be called after the interactive operation is
 * completed.
 * @in-param void* callbackData - data to be passed to the callback() function by MSALRuntime.
 * @in-out-param MSALRUNTIME_ASYNC_HANDLE* asyncHandle - the handle for canceling this operation.
 *
 * @return - null handle, success, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_SignInInteractivelyAsync(
    WINDOW_HANDLE parentHwnd,
    MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters,
    const os_char* correlationId,
    const os_char* accountHint,
    MSALRUNTIME_COMPLETION_ROUTINE callback,
    void* callbackData,
    MSALRUNTIME_ASYNC_HANDLE* asyncHandle);

/*
 * Acquire tokens for the given user, this is a silent operation, which will never show UI.
 *
 * @in-param MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters - The handle for the request parameters.
 * @in-param const os_char* correlationId - correlationId used to track telemetry.
 * @in-param MSALRUNTIME_ACCOUNT_HANDLE account - account to acquire tokens on.
 * @in-param MSALRUNTIME_COMPLETION_ROUTINE callback - callback function to be called after the silent operation is
 * completed.
 * @in-param void* callbackData - data to be passed to the callback() function by MSALRuntime.
 * @in-out-param MSALRUNTIME_ASYNC_HANDLE* asyncHandle - the handle for canceling this operation.
 *
 * @return - null handle, success, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_AcquireTokenSilentlyAsync(
    MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters,
    const os_char* correlationId,
    MSALRUNTIME_ACCOUNT_HANDLE account,
    MSALRUNTIME_COMPLETION_ROUTINE callback,
    void* callbackData,
    MSALRUNTIME_ASYNC_HANDLE* asyncHandle);

/*
 * Acquire tokens for the given user, which may or may not show UI.
 *
 * @in-param WINDOW_HANDLE  - parentHwnd to be set.
 * @in-param MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters - The handle for the request parameters.
 * @in-param const os_char* correlationId - correlationId used to track telemetry.
 * @in-param MSALRUNTIME_ACCOUNT_HANDLE account - account to acquire tokens on.
 * @in-param MSALRUNTIME_COMPLETION_ROUTINE callback - callback function to be called after the interactive operation is
 * completed.
 * @in-param void* callbackData - data to be passed to the callback() function by MSALRuntime.
 * @in-out-param MSALRUNTIME_ASYNC_HANDLE* asyncHandle - the handle for canceling this operation.
 *
 * @return - null handle, success, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_AcquireTokenInteractivelyAsync(
    WINDOW_HANDLE parentHwnd,
    MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters,
    const os_char* correlationId,
    MSALRUNTIME_ACCOUNT_HANDLE account,
    MSALRUNTIME_COMPLETION_ROUTINE callback,
    void* callbackData,
    MSALRUNTIME_ASYNC_HANDLE* asyncHandle);

/*
 * Signs the user out for the given account. After this method is called, attempting to silently use this account
 * will fail with an InvalidAccount error. To clear the signed out flag, either prompt the user (use an Interactive
 * method) OR [runtime only] make a silent call with ROPC (User/Pass) creds in the AuthParams. If either method
 * succeeds, the signed out flag will be cleared on the account.
 *
 * @in-optional-param const os_char* clientId - the id for the application.
 * @in-param const os_char* correlationId - correlationId used to track telemetry.
 * @in-param MSALRUNTIME_ACCOUNT_HANDLE account - account to be signed out.
 * @in-param MSALRUNTIME_COMPLETION_ROUTINE callback - callback function to be called after the SignOut operation is
 * completed.
 * @in-param void* callbackData - data to be passed to the callback() function by MSALRuntime.
 * @in-out-param MSALRUNTIME_ASYNC_HANDLE* asyncHandle - the handle for canceling this operation.
 *
 * @return - null handle, success, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_SignOutSilentlyAsync(
    const os_char* clientId,
    const os_char* correlationId,
    MSALRUNTIME_ACCOUNT_HANDLE account,
    MSALRUNTIME_SIGNOUT_COMPLETION_ROUTINE callback,
    void* callbackData,
    MSALRUNTIME_ASYNC_HANDLE* asyncHandle);

/*
 * Enumerate and return all accounts for a client.
 *
 * @in-param const os_char* clientId - the id for the application.
 * @in-param const os_char* correlationId - correlationId used to track telemetry.
 * @in-param MSALRUNTIME_DISCOVER_ACCOUNTS_COMPLETION_ROUTINE callback - callback function to be called after the
 * DiscoverAccounts operation is completed.
 * @in-param void* callbackData - data to be passed to the callback() function by MSALRuntime.
 * @in-out-param MSALRUNTIME_ASYNC_HANDLE* asyncHandle - the handle for canceling this operation.
 *
 * @return - null handle, success, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_DiscoverAccountsAsync(
    const os_char* clientId,
    const os_char* correlationId,
    MSALRUNTIME_DISCOVER_ACCOUNTS_COMPLETION_ROUTINE callback,
    void* callbackData,
    MSALRUNTIME_ASYNC_HANDLE* asyncHandle);

#ifdef __cplusplus
}
#endif
