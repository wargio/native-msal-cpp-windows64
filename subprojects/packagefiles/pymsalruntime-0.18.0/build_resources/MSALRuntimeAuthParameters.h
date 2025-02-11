// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Creates the MSALRUNTIME_AUTH_PARAMETERS_HANDLE that is used for all signIn and authentication operations.
 *
 * @in-param const os_char* clientId - the id for the application.
 * @in-param const os_char* authority - authority the application is requesting for.
 * @in-out-param MSALRUNTIME_AUTH_PARAMETERS_HANDLE* - pointer to the MSALRUNTIME_AUTH_PARAMETERS_HANDLE to be created.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_CreateAuthParameters(
    const os_char* clientId,
    const os_char* authority,
    MSALRUNTIME_AUTH_PARAMETERS_HANDLE* authParameters);

/*
 * Releases the allocated MSALRUNTIME_AUTH_PARAMETERS_HANDLE in the MSALRuntime.
 *
 * @in-param MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters - handle for the authentication parameter.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_ReleaseAuthParameters(MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters);

/*
 * Sets the scopes on the given MSALRUNTIME_AUTH_PARAMETERS_HANDLE.
 * The scopes should be space separated, e.g. "scope1 scope2 scope3"
 *
 * @in-param MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters - MSALRUNTIME_AUTH_PARAMETERS_HANDLE to set the scopes
 * on.
 * @in-param const os_char* scopes - Scopes to be set.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_SetRequestedScopes(MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters, const os_char* scopes);

/*
 * Sets the redirectUri on the given MSALRUNTIME_AUTH_PARAMETERS_HANDLE.
 *
 * @in-param MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters - MSALRUNTIME_AUTH_PARAMETERS_HANDLE to set the scopes
 * on.
 * @in-param const os_char* redirectUri - redirect Uri to be set.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_SetRedirectUri(MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters, const os_char* redirectUri);

/*
 * Sets the claims on the given MSALRUNTIME_AUTH_PARAMETERS_HANDLE.
 *
 * @in-param MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters - MSALRUNTIME_AUTH_PARAMETERS_HANDLE to set the claims
 * on.
 * @in-param const os_char* claims - Claims to be set.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_SetDecodedClaims(MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters, const os_char* claims);

/*
 * Sets the accessToken on the given MSALRUNTIME_AUTH_PARAMETERS_HANDLE to be invalidated.
 *
 * @in-param MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters - MSALRUNTIME_AUTH_PARAMETERS_HANDLE to set the
 * accessToken to renew on.
 * @in-param const os_char* accessTokenToRenew - accessTokenToRenew to be set.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_SetAccessTokenToRenew(MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters, const os_char* accessTokenToRenew);

/*
 * Sets the Proof of possesion parameters on the given MSALRUNTIME_AUTH_PARAMETERS_HANDLE to be invalidated.
 *
 * @in-param MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters - MSALRUNTIME_AUTH_PARAMETERS_HANDLE to set the
 * accessToken to renew on.
 * @in-param const os_char* httpMethod - httpMethod to be set.
 * @in-param const os_char* uriHost - uriHost to be set.
 * @in-param const os_char* uriPath - uriPath to be set. This parameter is optional and it can be empty.
 * @in-param const os_char* nonce - nonce to be set. This parameter is optional and it can be empty.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_SetPopParams(
    MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters,
    const os_char* httpMethod,
    const os_char* uriHost,
    const os_char* uriPath,
    const os_char* nonce);

/*
 * Sets an additional parameter on the given MSALRUNTIME_AUTH_PARAMETERS_HANDLE.
 *
 * @in-param MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters - MSALRUNTIME_AUTH_PARAMETERS_HANDLE to set the
 * additional parameter on.
 * @in-param const os_char* key - key of the parameter to be set.
 * @in-param const os_char* value - value of the parameter to be set.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_SetAdditionalParameter(
    MSALRUNTIME_AUTH_PARAMETERS_HANDLE authParameters,
    const os_char* key,
    const os_char* value);

#ifdef __cplusplus
}
#endif
