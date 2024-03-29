/*++
Copyright (c) Microsoft Corporation
Licensed under the MIT license.

Module Name:
- userdpiapi.hpp

Abstract:
- This module is used for abstracting calls to ntdll DLL APIs to break DDK dependencies.

Author(s):
- Michael Niksa (MiNiksa) July-2016
--*/
#pragma once

#include "conddkrefs.h"

class NtPrivApi sealed
{
public:
    [[nodiscard]] static NTSTATUS s_GetProcessParentId(_Inout_ PULONG ProcessId);

    ~NtPrivApi();

private:
    [[nodiscard]] static NTSTATUS s_NtOpenProcess(_Out_ PHANDLE ProcessHandle,
                                                  _In_ ACCESS_MASK DesiredAccess,
                                                  _In_ POBJECT_ATTRIBUTES ObjectAttributes,
                                                  _In_opt_ CLIENT_ID* ClientId);

    [[nodiscard]] static NTSTATUS s_NtQueryInformationProcess(_In_ HANDLE ProcessHandle,
                                                              _In_ PROCESSINFOCLASS ProcessInformationClass,
                                                              _Out_ PVOID ProcessInformation,
                                                              _In_ ULONG ProcessInformationLength,
                                                              _Out_opt_ PULONG ReturnLength);

    [[nodiscard]] static NTSTATUS s_NtClose(_In_ HANDLE Handle);

    static NtPrivApi& _Instance();
    HMODULE _hNtDll;

    NtPrivApi();
};
