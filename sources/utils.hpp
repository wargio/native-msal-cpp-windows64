// SPDX-FileCopyrightText: 2023 deroad <wargio@libero.it>
// SPDX-License-Identifier: MIT

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <codecvt>
#include <sstream>
#include <iomanip>
#include <windows.h>
#include <wincrypt.h>

#define MACRO_STR(s) #s

/*
 * MSAL methods to get a strings
 * allows to pass nullptr and get the length
 * then allocate and write to the buffer.
 */
#define MSAL_GET_STRING(handle, func, value) \
	do { \
		int32_t _length = 0; \
		func(handle, nullptr, &_length); \
		if (_length > 0) { \
			os_char *_w_value = new os_char[_length]; \
			if (func(handle, _w_value, &_length) == MSALRUNTIME_SUCCEED) { \
				value = toUtf8(_w_value); \
			} \
			delete[] _w_value; \
		} \
	} while (0)

#define PRINT_FIELD(handle, func) \
	do { \
		std::string out; \
		MSAL_GET_STRING(handle, func, out); \
		std::cout << MACRO_STR(func) " \"" << out << "\"" << std::endl; \
	} while (0)

inline std::wstring toUtf16(const std::string &utf8) {
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;
	return converterX.from_bytes(utf8);
}

inline std::wstring toUtf16(const char *os_utf8) {
	const std::string utf8(os_utf8 ? os_utf8 : "");
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;
	return converterX.from_bytes(utf8);
}

inline std::string toUtf8(const std::wstring &utf16) {
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;
	return converterX.to_bytes(utf16);
}

inline std::string toUtf8(const wchar_t *os_utf16) {
	const std::wstring utf16(os_utf16 ? os_utf16 : L"");
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;
	return converterX.to_bytes(utf16);
}

inline std::wstring uuidGen() {
	HCRYPTPROV provider;
	BYTE uuid[16];
	std::wstring result;

	if (!CryptAcquireContext(
				&provider, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)) {
		return result;
	}

	if (!CryptGenRandom(provider, sizeof(uuid), (BYTE *)uuid)) {
		return result;
	}

	CryptReleaseContext(provider, 0);

	std::ostringstream hex_string;

	hex_string << std::setfill('0');
	for (int i = 0; i < sizeof(uuid); i++) {
		if (i == 4 || i == 6 || i == 8 || i == 10) {
			hex_string << "-";
		}
		hex_string << std::setw(2) << std::hex << static_cast<int>(uuid[i]);
	}

	return toUtf16(hex_string.str());
}

inline HWND consoleWindow() {
	return GetAncestor(GetConsoleWindow(), 3);
}

inline void printAccount(MSALRUNTIME_ACCOUNT_HANDLE handle) {
	PRINT_FIELD(handle, MSALRUNTIME_GetAccountId);
	PRINT_FIELD(handle, MSALRUNTIME_GetHomeAccountId);
	PRINT_FIELD(handle, MSALRUNTIME_GetEnvironment);
	PRINT_FIELD(handle, MSALRUNTIME_GetRealm);
	PRINT_FIELD(handle, MSALRUNTIME_GetLocalAccountId);
	PRINT_FIELD(handle, MSALRUNTIME_GetUserName);
	PRINT_FIELD(handle, MSALRUNTIME_GetGivenName);
	PRINT_FIELD(handle, MSALRUNTIME_GetFamilyName);
	PRINT_FIELD(handle, MSALRUNTIME_GetMiddleName);
	PRINT_FIELD(handle, MSALRUNTIME_GetDisplayName);
	PRINT_FIELD(handle, MSALRUNTIME_GetClientInfo);
	PRINT_FIELD(handle, MSALRUNTIME_GetAdditionalFieldsJson);
	PRINT_FIELD(handle, MSALRUNTIME_GetHomeEnvironment);
}

inline void printAuthResult(MSALRUNTIME_AUTH_RESULT_HANDLE handle) {
	PRINT_FIELD(handle, MSALRUNTIME_GetIdToken);
	PRINT_FIELD(handle, MSALRUNTIME_GetRawIdToken);
	PRINT_FIELD(handle, MSALRUNTIME_GetAccessToken);
	PRINT_FIELD(handle, MSALRUNTIME_GetGrantedScopes);
	PRINT_FIELD(handle, MSALRUNTIME_GetAuthorizationHeader);
	PRINT_FIELD(handle, MSALRUNTIME_GetTelemetryData);
}

#endif /* UTILS_HPP */
