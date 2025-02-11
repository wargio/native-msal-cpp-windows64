// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Releases the allocated MSALRUNTIME_ASYNC_HANDLE in the MSALRuntime.
 *
 * @in-param MSALRUNTIME_ASYNC_HANDLE asyncHandle - the handle for the async operation.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_ReleaseAsyncHandle(MSALRUNTIME_ASYNC_HANDLE asyncHandle);

/*
 * Cancel existing interactive flow.
 * The callback of the existing interactive flow will be returned with Cancel status.
 * @in-param MSALRUNTIME_ASYNC_HANDLE asyncHandle - the handle for the async operation.
 *
 * @return - null handle, success, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE
MSALRUNTIME_API MSALRUNTIME_CancelAsyncOperation(MSALRUNTIME_ASYNC_HANDLE asyncHandle);

#ifdef __cplusplus
}
#endif
