// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#include "MSALRuntimeTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Releases the allocated MSALRUNTIME_ACCOUNT_HANDLE in the MSALRuntime.
 *
 * @in-param MSALRUNTIME_ACCOUNT_HANDLE account - the handle for the account.
 *
 * @return - success if null handle, otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API MSALRUNTIME_ReleaseAccount(MSALRUNTIME_ACCOUNT_HANDLE account);

/*
 * Obtain the accountId from the account handle.
 *
 * @in-param MSALRUNTIME_ACCOUNT_HANDLE account - the handle for the account.
 * @out-param os_char* accountId - the buffer that is used to copy the accountId into.
 * @in-out-param int32_t* bufferSize - the size of the buffer (number of characters + null terminator).
 * It is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetAccountId(MSALRUNTIME_ACCOUNT_HANDLE account, os_char* accountId, int32_t* bufferSize);

/*
 * Obtain the home accountId from the account handle.
 *
 * @in-param MSALRUNTIME_ACCOUNT_HANDLE account - the handle for the account.
 * @out-param os_char* homeAccountId - the buffer that is used to copy the home accountId into.
 * @in-out-param int32_t* bufferSize - the size of the buffer (number of characters + null terminator).
 * It is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetHomeAccountId(MSALRUNTIME_ACCOUNT_HANDLE account, os_char* homeAccountId, int32_t* bufferSize);

/*
 * Obtain the environment from the account handle.
 *
 * @in-param MSALRUNTIME_ACCOUNT_HANDLE account - the handle for the account.
 * @out-param os_char* environment - the buffer that is used to copy the environment into.
 * @in-out-param int32_t* bufferSize - the size of the buffer (number of characters + null terminator).
 * It is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetEnvironment(MSALRUNTIME_ACCOUNT_HANDLE account, os_char* environment, int32_t* bufferSize);

/*
 * Obtain the realm from the account handle.
 *
 * @in-param MSALRUNTIME_ACCOUNT_HANDLE account - the handle for the account.
 * @out-param os_char* realm - the buffer that is used to copy the realm into.
 * @in-out-param int32_t* bufferSize - the size of the buffer (number of characters + null terminator).
 * It is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetRealm(MSALRUNTIME_ACCOUNT_HANDLE account, os_char* realm, int32_t* bufferSize);

/*
 * Obtain the local accountId from the account handle.
 *
 * @in-param MSALRUNTIME_ACCOUNT_HANDLE account - the handle for the account.
 * @out-param os_char* local accountId - the buffer that is used to copy the local accountId into.
 * @in-out-param int32_t* bufferSize - the size of the buffer (number of characters + null terminator).
 * It is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetLocalAccountId(MSALRUNTIME_ACCOUNT_HANDLE account, os_char* localAccountId, int32_t* bufferSize);

/*
 * Obtain the user name from the account handle.
 *
 * @in-param MSALRUNTIME_ACCOUNT_HANDLE account - the handle for the account.
 * @out-param os_char* userName - the buffer that is used to copy the user name into.
 * @in-out-param int32_t* bufferSize - the size of the buffer (number of characters + null terminator).
 * It is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetUserName(MSALRUNTIME_ACCOUNT_HANDLE account, os_char* userName, int32_t* bufferSize);

/*
 * Obtain the given name from the account handle.
 *
 * @in-param MSALRUNTIME_ACCOUNT_HANDLE account - the handle for the account.
 * @out-param os_char* givenName - the buffer that is used to copy the given name into.
 * @in-out-param int32_t* bufferSize - the size of the buffer (number of characters + null terminator).
 * It is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetGivenName(MSALRUNTIME_ACCOUNT_HANDLE account, os_char* givenName, int32_t* bufferSize);

/*
 * Obtain the family name from the account handle.
 *
 * @in-param MSALRUNTIME_ACCOUNT_HANDLE account - the handle for the account.
 * @out-param os_char* familyName - the buffer that is used to copy the family name into.
 * @in-out-param int32_t* bufferSize - the size of the buffer (number of characters + null terminator).
 * It is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetFamilyName(MSALRUNTIME_ACCOUNT_HANDLE account, os_char* familyName, int32_t* bufferSize);

/*
 * Obtain the Middle name from the account handle.
 *
 * @in-param MSALRUNTIME_ACCOUNT_HANDLE account - the handle for the account.
 * @out-param os_char* middleName - the buffer that is used to copy the middle name into.
 * @in-out-param int32_t* bufferSize - the size of the buffer (number of characters + null terminator).
 * It is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetMiddleName(MSALRUNTIME_ACCOUNT_HANDLE account, os_char* middleName, int32_t* bufferSize);

/*
 * Obtain the display name from the account handle.
 *
 * @in-param MSALRUNTIME_ACCOUNT_HANDLE account - the handle for the account.
 * @out-param os_char* name - the buffer that is used to copy the name into.
 * @in-out-param int32_t* bufferSize - the size of the buffer (number of characters + null terminator).
 * It is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetDisplayName(MSALRUNTIME_ACCOUNT_HANDLE account, os_char* name, int32_t* bufferSize);

/*
 * Obtain the client info from the account handle.
 *
 * @in-param MSALRUNTIME_ACCOUNT_HANDLE account - the handle for the account.
 * @out-param os_char* clientInfo - the buffer that is used to copy the clientInfo into. This will be base64url encoded.
 * @in-out-param int32_t* bufferSize - the size of the buffer (number of characters + null terminator).
 * It is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetClientInfo(MSALRUNTIME_ACCOUNT_HANDLE account, os_char* clientInfo, int32_t* bufferSize);

/*
 * Obtain the additional fields json from the account handle.
 * For extensibility. "{"extra_field": "extra_value"}"
 *
 * @in-param MSALRUNTIME_ACCOUNT_HANDLE account - the handle for the account.
 * @out-param os_char* additionalFieldsJson - the buffer that is used to copy the additional fields json into..
 * @in-out-param int32_t* bufferSize - the size of the buffer (number of characters + null terminator).
 * It is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetAdditionalFieldsJson(MSALRUNTIME_ACCOUNT_HANDLE account, os_char* additionalFieldsJson, int32_t* bufferSize);

/*
 * Obtain the home environment from the account handle.
 *
 * @in-param MSALRUNTIME_ACCOUNT_HANDLE account - the handle for the account.
 * @out-param os_char* homeEnvironment - the buffer that is used to copy the home environment into.
 * @in-out-param int32_t* bufferSize - the size of the buffer (number of characters + null terminator).
 * It is updated by the method to indicate the actual size of the buffer.
 *
 * @return - null handle, success.
 * Handle with InsufficientBuffer status, if the buffer is too small, then bufferSize contains the new size to be
 * allocated. Otherwise fail.
 */
MSALRUNTIME_ERROR_HANDLE MSALRUNTIME_API
MSALRUNTIME_GetHomeEnvironment(MSALRUNTIME_ACCOUNT_HANDLE account, os_char* homeEnvironment, int32_t* bufferSize);

#ifdef __cplusplus
}
#endif
