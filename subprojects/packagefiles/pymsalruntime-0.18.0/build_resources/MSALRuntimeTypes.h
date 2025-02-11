// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once
#include "stdint.h"

#if MSAUTH_PLATFORM_MACOS || MSAUTH_PLATFORM_LINUX
#define MSALRUNTIME_EXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DECLARE_MSALRUNTIME_HANDLE // Prevent DECLARE_HANDLE macro redefined in winnt.h
#define DECLARE_MSALRUNTIME_HANDLE(name) \
    struct name##__                      \
    {                                    \
        int unused;                      \
    };                                   \
    typedef struct name##__* name
#endif

#ifdef _WIN32
// the actual build from microsoft do not use __stdcall type.
//#define MSALRUNTIME_API __stdcall
#define MSALRUNTIME_API
typedef wchar_t utf16_char;
typedef utf16_char os_char;
typedef void* WINDOW_HANDLE;
#elif MSAUTH_PLATFORM_LINUX
#define MSALRUNTIME_API
typedef char16_t utf16_char;
typedef utf16_char os_char;
typedef int64_t WINDOW_HANDLE;
#else
#define MSALRUNTIME_API
typedef char utf8_char;
typedef utf8_char os_char;
// On x-plat WINDOW_HANDLE's are defined to be int64_t.
typedef int64_t WINDOW_HANDLE;
#endif

typedef int bool_t;

// We are defining the typedef enum in this way to bypass a bug in Cython
// to make Python interop layer compiling on macOS.
// https://github.com/cython/cython/issues/1529
typedef enum MSALRUNTIME_RESPONSE_STATUS
{
    Msalruntime_Response_Status_Unexpected = 0,
    Msalruntime_Response_Status_Reserved = 1,
    Msalruntime_Response_Status_InteractionRequired = 2,
    Msalruntime_Response_Status_NoNetwork = 3,
    Msalruntime_Response_Status_NetworkTemporarilyUnavailable = 4,
    Msalruntime_Response_Status_ServerTemporarilyUnavailable = 5,
    Msalruntime_Response_Status_ApiContractViolation = 6,
    Msalruntime_Response_Status_UserCanceled = 7,
    Msalruntime_Response_Status_ApplicationCanceled = 8,
    Msalruntime_Response_Status_IncorrectConfiguration = 9,
    Msalruntime_Response_Status_InsufficientBuffer = 10,
    Msalruntime_Response_Status_AuthorityUntrusted = 11,
    Msalruntime_Response_Status_UserSwitch = 12,
    Msalruntime_Response_Status_AccountUnusable = 13,
    Msalruntime_Response_Status_UserDataRemovalRequired = 14,
    Msalruntime_Response_Status_KeyNotFound = 15,
    Msalruntime_Response_Status_AccountNotFound = 16,
    Msalruntime_Response_Status_TransientError = 17,
    Msalruntime_Response_Status_AccountSwitch = 18,
    Msalruntime_Response_Status_RequiredBrokerMissing = 19,
    Msalruntime_Response_Status_DeviceNotRegistered = 20,
    Msalruntime_Response_Status_FallbackToNativeMsal = 21
} MSALRUNTIME_RESPONSE_STATUS;

// We are defining the typedef enum in this way to bypass a bug in Cython
// to make Python interop layer compiling on macOS.
// https://github.com/cython/cython/issues/1529
typedef enum MSALRUNTIME_LOG_LEVEL
{
    Msalruntime_Log_Level_Trace = 1,
    Msalruntime_Log_Level_Debug = 2,
    Msalruntime_Log_Level_Info = 3,
    Msalruntime_Log_Level_Warning = 4,
    Msalruntime_Log_Level_Error = 5,
    Msalruntime_Log_Level_Fatal = 6
} MSALRUNTIME_LOG_LEVEL;

// We are defining the typedef enum in this way to bypass a bug in Cython
// to make Python interop layer compiling on macOS.
// https://github.com/cython/cython/issues/1529
typedef enum MSALRUNTIME_SSO_POLICY_TYPE
{
    Msalruntime_Sso_Policy_Unknown = 0,
    Msalruntime_Sso_Policy_PermissionRequired = 1,
    Msalruntime_Sso_Policy_AlwaysAllowed = 2,
    Msalruntime_Sso_Policy_Error = 3
} MSALRUNTIME_SSO_POLICY_TYPE;

#ifndef MSALRUNTIME_SUCCEED
// Success case when the error handle is 0 or NULL.
#define MSALRUNTIME_SUCCEED 0
#endif

struct MSALRUNTIME_HANDLE
{
    int unused;
};
DECLARE_MSALRUNTIME_HANDLE(MSALRUNTIME_AUTH_PARAMETERS_HANDLE);
DECLARE_MSALRUNTIME_HANDLE(MSALRUNTIME_AUTH_RESULT_HANDLE);
DECLARE_MSALRUNTIME_HANDLE(MSALRUNTIME_SIGNOUT_RESULT_HANDLE);
DECLARE_MSALRUNTIME_HANDLE(MSALRUNTIME_READ_ACCOUNT_RESULT_HANDLE);
DECLARE_MSALRUNTIME_HANDLE(MSALRUNTIME_DISCOVER_ACCOUNTS_RESULT_HANDLE);
DECLARE_MSALRUNTIME_HANDLE(MSALRUNTIME_ACCOUNT_HANDLE);
DECLARE_MSALRUNTIME_HANDLE(MSALRUNTIME_ERROR_HANDLE);
DECLARE_MSALRUNTIME_HANDLE(MSALRUNTIME_ASYNC_HANDLE);
DECLARE_MSALRUNTIME_HANDLE(MSALRUNTIME_LOG_CALLBACK_HANDLE);

/*
 * The callback function to inform that async operation has completed and the resource is set.
 *
 * @in-param MSALRUNTIME_AUTH_RESULT_HANDLE authResult - Instance of MSALRUNTIME_AUTH_RESULT_HANDLE created by
 * MSALRUNTIME_RequestTokenInteractively/SilentlyAsync.
 * @in-param void* callbackData - callbackData to be sent by caller to be set by MSALRuntime.
 */
typedef void(MSALRUNTIME_API* MSALRUNTIME_COMPLETION_ROUTINE)(MSALRUNTIME_AUTH_RESULT_HANDLE authResult, void* callbackData);

/*
 * The callback function to inform that async signout operation has completed and the resource is set.
 *
 * @in-param MSALRUNTIME_SIGNOUT_RESULT_HANDLE signoutResult - Instance of MSALRUNTIME_SIGNOUT_RESULT_HANDLE created by
 * MSALRUNTIME_SignOutAsync.
 * @in-param void* callbackData - callbackData to be sent by caller to be set by MSALRuntime.
 */
typedef void(MSALRUNTIME_API* MSALRUNTIME_SIGNOUT_COMPLETION_ROUTINE)(
    MSALRUNTIME_SIGNOUT_RESULT_HANDLE signoutResult,
    void* callbackData);

/*
 * The callback function to inform that async read account operation has completed and the resource is set.
 *
 * @in-param MSALRUNTIME_READ_ACCOUNT_RESULT_HANDLE readAccountResult - Instance of
 * MSALRUNTIME_READ_ACCOUNT_RESULT_HANDLE created by MSALRUNTIME_ReadAccountByIdAsync.
 * @in-param void* callbackData - callbackData to be sent by caller to be set by MSALRuntime.
 */
typedef void(MSALRUNTIME_API* MSALRUNTIME_READ_ACCOUNT_COMPLETION_ROUTINE)(
    MSALRUNTIME_READ_ACCOUNT_RESULT_HANDLE readAccountResult,
    void* callbackData);

/*
 * The callback function to inform that async discover accounts operation has completed and the resource is set.
 *
 * @in-param MSALRUNTIME_DISCOVER_ACCOUNTS_RESULT_HANDLE discoverAccountsResult - Instance of
 * MSALRUNTIME_DISCOVER_ACCOUNTS_RESULT_HANDLE created by MSALRUNTIME_DiscoverAccountsAsync.
 * @in-param void* callbackData - callbackData to be sent by caller to be set by MSALRuntime.
 */
typedef void(MSALRUNTIME_API* MSALRUNTIME_DISCOVER_ACCOUNTS_COMPLETION_ROUTINE)(
    MSALRUNTIME_DISCOVER_ACCOUNTS_RESULT_HANDLE discoverAccountsResult,
    void* callbackData);

/*
 * The callback function to inform that a logging operation has occurred.
 *
 * @in-param os_char* logMessage - the buffer that holds the log entry.
 * @in-param MSALRUNTIME_LOG_LEVEL logLevel the logLevel that is associated with the logMessage.
 * @in-param void* callbackData - callbackData to be sent by caller to be set by MSALRuntime.
 */
typedef void(MSALRUNTIME_API* MSALRUNTIME_LOG_CALLBACK_ROUTINE)(
    const os_char* logMessage,
    const MSALRUNTIME_LOG_LEVEL logLevel,
    void* callbackData);

#ifdef __cplusplus
}
#endif
