// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Releases the allocated MSALRUNTIME_AUTH_RESULT_HANDLE in the MSALRuntime.
 *
 * @in-param MSALRUNTIME_AUTH_RESULT_HANDLE authResult - MSALRUNTIME_AUTH_RESULT_HANDLE to be released.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_ReleaseAuthResult(MSALRUNTIME_AUTH_RESULT_HANDLE authResult);

/*
 * Gets the msalruntimeaccount retrieved from RequestTokenSilently\Interactively() call on the authResult.
 *
 * @in-param MSALRUNTIME_AUTH_RESULT_HANDLE authResult - the authResult handle.
 * @in-out-param MSALRUNTIME_ACCOUNT_HANDLE* account - pointer to the MSALRUNTIME_ACCOUNT_HANDLE to be created.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetAccount(MSALRUNTIME_AUTH_RESULT_HANDLE authResult, MSALRUNTIME_ACCOUNT_HANDLE* account);

/*
 * Gets the idToken retrieved from RequestTokenSilently\Interactively() call on the authResult.
 * The idToken is the payload from the decoded raw idToken.
 *
 * @in-param MSALRUNTIME_AUTH_RESULT_HANDLE authResult - the authResult handle.
 * @out-param os_char* idToken - the buffer that is used to copy the id token into.
 * @in-out-param int32_t* bufferSize - this parameter contains the size of the buffer (number of characters +
 * null terminator) and is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetIdToken(MSALRUNTIME_AUTH_RESULT_HANDLE authResult, os_char* idToken, int32_t* bufferSize);

/*
 * Gets the raw idToken retrieved from RequestTokenSilently\Interactively() call on the authResult.
 * The raw idToken is returned from server without additional processing.
 *
 * @in-param MSALRUNTIME_AUTH_RESULT_HANDLE authResult - the authResult handle.
 * @out-param os_char* rawIdToken - the buffer that is used to copy the id token into.
 * @in-out-param int32_t* bufferSize - this parameter contains the size of the buffer (number of characters +
 * null terminator) and is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetRawIdToken(MSALRUNTIME_AUTH_RESULT_HANDLE authResult, os_char* rawIdToken, int32_t* bufferSize);

/*
 * Gets the AccessToken retrieved from RequestTokenSilently\Interactively() call on the authResult.
 *
 * @in-param MSALRUNTIME_AUTH_RESULT_HANDLE authResult - the authResult handle.
 * @out-param os_char* accessToken - the buffer that is used to copy the access token into.
 * @in-out-param int32_t* bufferSize - this parameter contains the size of the buffer (number of characters +
 * null terminator) and is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetAccessToken(MSALRUNTIME_AUTH_RESULT_HANDLE authResult, os_char* accessToken, int32_t* bufferSize);

/*
 * Gets the granted scopes retrieved from RequestTokenSilently\Interactively() call on the authResult.
 * the granted Scopes are returned as space separated string, e.g. "scope1 scope2 scope3"
 *
 * @in-param MSALRUNTIME_AUTH_RESULT_HANDLE authResult - the authResult handle.
 * @out-param os_char* grantedScopes - the buffer that is used to copy the grantedScopes into.
 * @in-out-param int32_t* bufferSize - this parameter contains the size of the buffer (number of characters +
 * null terminator) and is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetGrantedScopes(MSALRUNTIME_AUTH_RESULT_HANDLE authResult, os_char* grantedScopes, int32_t* bufferSize);

/*
 * Gets the authorization header that contains the SHR (Signed HTTP Request) for an POP param request.
 * Format of header value returned will look as follows:
 * pop <SHR>
 *
 * This authorization header should be included in the authorization header of the request like such:
 * Authorization: <value from MSALRUNTIME_GetAuthorizationHeader>
 *
 * @in-param MSALRUNTIME_AUTH_RESULT_HANDLE authResult - the authResult handle.
 * @out-param os_char* authHeader - the buffer that is used to copy the authHeader into.
 * @in-out-param int32_t* bufferSize - this parameter contains the size of the buffer (number of characters +
 * null terminator) and is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetAuthorizationHeader(MSALRUNTIME_AUTH_RESULT_HANDLE authResult, os_char* authHeader, int32_t* bufferSize);

/*
 * Gets whether the given request is a POP authorization request.
 *
 * @in-param MSALRUNTIME_AUTH_RESULT_HANDLE authResult - the authResult handle.
 * @in-out-param bool_t* isPopAuthorization - bool that contains true/false value of whether request is a POP auth
 * request.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_IsPopAuthorization(MSALRUNTIME_AUTH_RESULT_HANDLE authResult, bool_t* isPopAuthorization);

/*
 * Gets the tokenExpirationTime retrieved from RequestTokenSilently\Interactively() call on the authResult.
 *
 * @in-param MSALRUNTIME_AUTH_RESULT_HANDLE authResult - the authResult handle.
 * @out-param int32_t tokenExpirationTime - the tokenExpirationTime.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetExpiresOn(MSALRUNTIME_AUTH_RESULT_HANDLE authResult, int64_t* accessTokenExpirationTime);

/*
 * Gets the MSALRUNTIME_ERROR_HANDLE retrieved from RequestTokenSilently\Interactively() call on the authResult.
 *
 * @in-param MSALRUNTIME_AUTH_RESULT_HANDLE authResult - the authResult handle.
 * @in-out-param MSALRUNTIME_ERROR_HANDLE* responseError - this parameter will contain the MSALRUNTIME_ERROR_HANDLE.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetError(MSALRUNTIME_AUTH_RESULT_HANDLE authResult, MSALRUNTIME_ERROR_HANDLE* responseError);

/*
 * Gets the telemetry data from RequestTokenSilently\Interactively() call on the authResult.
 * the telemetry is returned as a JSON Array format. ex: ["data1", "data2"]
 *
 * @in-param MSALRUNTIME_AUTH_RESULT_HANDLE authResult - the authResult handle.
 * @out-param os_char* telemetryData - the buffer that is used to copy the telemetryData into.
 * @in-out-param int32_t* bufferSize - this parameter contains the size of the buffer (number of characters +
 * null terminator) and is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetTelemetryData(MSALRUNTIME_AUTH_RESULT_HANDLE authResult, os_char* telemetryData, int32_t* bufferSize);

#ifdef __cplusplus
}
#endif
