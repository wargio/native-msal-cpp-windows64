// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Registers a logging callback for the application.
 *
 * @in-param MSALRUNTIME_LOG_CALLBACK_ROUTINE callback - logging callback function. Must be a valid function.
 * @in-param void* callbackData - data to be passed to the callback() function by MSALRuntime.
 * @in-out-param MSALRUNTIME_LOG_CALLBACK_HANDLE* callbackId - the callbackHandle to be used to unregister this logging
 * callback.
 *
 * @return - null handle, success, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_RegisterLogCallback(
    MSALRUNTIME_LOG_CALLBACK_ROUTINE callback,
    void* callbackData,
    MSALRUNTIME_LOG_CALLBACK_HANDLE* callbackHandle);

/*
 * Releases a logging callback, unregistering it.
 *
 * @in-param MSALRUNTIME_LOG_CALLBACK_HANDLE callbackHandle - the callbackHandle to unregister this logging callback.
 *
 * @return - null handle, success, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_ReleaseLogCallbackHandle(MSALRUNTIME_LOG_CALLBACK_HANDLE callbackHandle);

/*
 * Enable / disable the PII in the log.
 *
 * @in-param int32_t enabled - 1 is enabled, otherwise, it's disabled.
 */
void MSALRUNTIME_API MSALRUNTIME_SetIsPiiEnabled(int32_t enabled);

#ifdef __cplusplus
}
#endif
