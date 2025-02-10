// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Releases the allocated MSALRUNTIME_READ_ACCOUNT_RESULT_HANDLE in the MSALRuntime.
 *
 * @in-param MSALRUNTIME_READ_ACCOUNT_RESULT_HANDLE readAccountResult - MSALRUNTIME_READ_ACCOUNT_RESULT_HANDLE to be
 * released.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_ReleaseReadAccountResult(MSALRUNTIME_READ_ACCOUNT_RESULT_HANDLE readAccountResult);

/*
 * Gets the msalruntimeaccount retrieved from ReadAccountById() call on the readAccountResult.
 *
 * @in-param MSALRUNTIME_READ_ACCOUNT_RESULT_HANDLE readAccountResult - the readAccountResult handle.
 * @in-out-param MSALRUNTIME_ACCOUNT_HANDLE* account - pointer to the MSALRUNTIME_ACCOUNT_HANDLE to be created.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetReadAccount(MSALRUNTIME_READ_ACCOUNT_RESULT_HANDLE readAccountResult, MSALRUNTIME_ACCOUNT_HANDLE* account);

/*
 * Gets the MSALRUNTIME_ERROR_HANDLE retrieved from ReadAccountById() call on the readAccountResult.
 *
 * @in-param MSALRUNTIME_READ_ACCOUNT_RESULT_HANDLE readAccountResult - the readAccountResult handle.
 * @in-out-param MSALRUNTIME_ERROR_HANDLE* responseError - this parameter will contain the MSALRUNTIME_ERROR_HANDLE.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_GetReadAccountError(
    MSALRUNTIME_READ_ACCOUNT_RESULT_HANDLE readAccountResult,
    MSALRUNTIME_ERROR_HANDLE* responseError);

/*
 * Gets the telemetry data from ReadAccountById() call on the readAccountResult.
 * the telemetry is returned as a JSON Object format. ex: {"data1" : "value1", "data2" : "value2"}
 *
 * @in-param MSALRUNTIME_READ_ACCOUNT_RESULT_HANDLE readAccountResult - the readAccountResult handle.
 * @out-param os_char* telemetryData - the buffer that is used to copy the telemetryData into.
 * @in-out-param int32_t* bufferSize - this parameter contains the size of the buffer (number of characters +
 * null terminator) and is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_GetReadAccountTelemetryData(
    MSALRUNTIME_READ_ACCOUNT_RESULT_HANDLE readAccountResult,
    os_char* telemetryData,
    int32_t* bufferSize);

#ifdef __cplusplus
}
#endif
