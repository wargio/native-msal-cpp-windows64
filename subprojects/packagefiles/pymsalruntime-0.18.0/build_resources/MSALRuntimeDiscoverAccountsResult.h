// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Releases the allocated MSALRUNTIME_DISCOVER_ACCOUNTS_RESULT_HANDLE in the MSALRuntime.
 *
 * @in-param MSALRUNTIME_DISCOVER_ACCOUNTS_RESULT_HANDLE discoverAccountsResult -
 * MSALRUNTIME_DISCOVER_ACCOUNTS_RESULT_HANDLE to be released.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_ReleaseDiscoverAccountsResult(MSALRUNTIME_DISCOVER_ACCOUNTS_RESULT_HANDLE discoverAccountsResult);

/*
 * Gets the msalruntimeaccount at index retrieved from DiscoverAccounts() call on the discoverAccountsResult.
 * This function is used to build up a vector of accounts in whatever final language is consuming this API.
 * A nullptr is returned if the index is out of bounds.
 *
 * @in-param MSALRUNTIME_DISCOVER_ACCOUNTS_RESULT_HANDLE discoverAccountsResult - the discoverAccountsResult handle.
 * @in-param int32_t index - the index in the list of the accounts to get
 * @in-out-param MSALRUNTIME_ACCOUNT_HANDLE* account - pointer to the MSALRUNTIME_ACCOUNT_HANDLE to be created.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_GetDiscoverAccountsAt(
    MSALRUNTIME_DISCOVER_ACCOUNTS_RESULT_HANDLE discoverAccountsResult,
    int32_t index,
    MSALRUNTIME_ACCOUNT_HANDLE* account);

/*
 * Gets the MSALRUNTIME_ERROR_HANDLE retrieved from DiscoverAccounts() call on the discoverAccountsResult.
 *
 * @in-param MSALRUNTIME_DISCOVER_ACCOUNTS_RESULT_HANDLE discoverAccountsResult - the discoverAccountsResult handle.
 * @in-out-param MSALRUNTIME_ERROR_HANDLE* responseError - this parameter will contain the MSALRUNTIME_ERROR_HANDLE.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_GetDiscoverAccountsError(
    MSALRUNTIME_DISCOVER_ACCOUNTS_RESULT_HANDLE discoverAccountsResult,
    MSALRUNTIME_ERROR_HANDLE* responseError);

/*
 * Gets the telemetry data from DiscoverAccounts() call on the discoverAccountsResult.
 * the telemetry is returned as a JSON Object format. ex: {"data1" : "value1", "data2" : "value2"}
 *
 * @in-param MSALRUNTIME_DISCOVER_ACCOUNTS_RESULT_HANDLE discoverAccountsResult - the discoverAccountsResult handle.
 * @out-param os_char* telemetryData - the buffer that is used to copy the telemetryData into.
 * @in-out-param int32_t* bufferSize - this parameter contains the size of the buffer (number of characters +
 * null terminator) and is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_GetDiscoverAccountsTelemetryData(
    MSALRUNTIME_DISCOVER_ACCOUNTS_RESULT_HANDLE discoverAccountsResult,
    os_char* telemetryData,
    int32_t* bufferSize);

#ifdef __cplusplus
}
#endif
