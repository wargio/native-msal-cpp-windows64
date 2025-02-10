// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Releases the allocated MSALRUNTIME_ERROR_HANDLE in the MSALRuntime.
 *
 * @in-param MSALRUNTIME_ERROR_HANDLE error - the error handle.
 *
 * @return - false if the error handle is invalid, otherwise true.
 */
bool_t MSALRUNTIME_API MSALRUNTIME_ReleaseError(MSALRUNTIME_ERROR_HANDLE error);

/*
 * Gets the response status of the MSALRUNTIME_ERROR_HANDLE.
 *
 * @in-param MSALRUNTIME_ERROR_HANDLE error - the error handle.
 * @in-out-param MSALRUNTIME_RESPONSE_STATUS* responseStatus - pointer to the enum parameter that will contain the
 * status.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetStatus(MSALRUNTIME_ERROR_HANDLE error, MSALRUNTIME_RESPONSE_STATUS* responseStatus);

/*
 * Gets the error code of the MSALRUNTIME_ERROR_HANDLE.
 *
 * @in-param MSALRUNTIME_ERROR_HANDLE error - the error handle.
 * @in-out-param int64_t* responseErrorCode - pointer to the int64_t that will contain the ErrorCode.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetErrorCode(MSALRUNTIME_ERROR_HANDLE error, int64_t* responseErrorCode);

/*
 * Gets the error tag of the MSALRUNTIME_ERROR_HANDLE.
 *
 * @in-param MSALRUNTIME_ERROR_HANDLE error - the error handle.
 * @in-out-param int32_t* responseErrorTag - pointer to the int32_t that will contain the ErrorTag.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_GetTag(MSALRUNTIME_ERROR_HANDLE error, int32_t* responseErrorTag);

/*
 * Gets the error context of the MSALRUNTIME_ERROR_HANDLE.
 *
 * @in-param MSALRUNTIME_ERROR_HANDLE error - the error handle.
 * @out-param os_char* context - the buffer that is used to copy the error context into.
 * @in-out-param int32_t* bufferSize - this parameter contains the size of the buffer (number of characters +
 * null terminator) and is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetContext(MSALRUNTIME_ERROR_HANDLE error, os_char* context, int32_t* bufferSize);

#ifdef __cplusplus
}
#endif
