// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Releases the allocated MSALRUNTIME_SIGNOUT_RESULT_HANDLE in the MSALRuntime.
 *
 * @in-param MSALRUNTIME_SIGNOUT_RESULT_HANDLE signoutResult - MSALRUNTIME_SIGNOUT_RESULT_HANDLE to be released.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_ReleaseSignOutResult(MSALRUNTIME_SIGNOUT_RESULT_HANDLE signoutResult);

/*
 * Gets the MSALRUNTIME_ERROR_HANDLE retrieved from SignOutSilently() call on the signoutResult.
 *
 * @in-param MSALRUNTIME_SIGNOUT_RESULT_HANDLE signoutResult - the signoutResult handle.
 * @in-out-param MSALRUNTIME_ERROR_HANDLE* responseError - this parameter will contain the MSALRUNTIME_ERROR_HANDLE.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetSignOutError(MSALRUNTIME_SIGNOUT_RESULT_HANDLE signoutResult, MSALRUNTIME_ERROR_HANDLE* responseError);

/*
 * Gets the telemetry data from SignOutSilently() call on the signoutResult.
 * the telemetry is returned as a JSON Object format. ex: {"data1" : "value1", "data2" : "value2"}
 *
 * @in-param MSALRUNTIME_SIGNOUT_RESULT_HANDLE signoutResult - the signoutResult handle.
 * @out-param os_char* telemetryData - the buffer that is used to copy the telemetryData into.
 * @in-out-param int32_t* bufferSize - this parameter contains the size of the buffer (number of characters +
 * null terminator) and is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_GetSignOutTelemetryData(
    MSALRUNTIME_SIGNOUT_RESULT_HANDLE signoutResult,
    os_char* telemetryData,
    int32_t* bufferSize);

#ifdef __cplusplus
}
#endif
