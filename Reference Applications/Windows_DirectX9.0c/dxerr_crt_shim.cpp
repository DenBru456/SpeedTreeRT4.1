////////////////////////////////////////////////////////////////////////
//  dxerr_crt_shim.cpp
//
//  The June 2010 DirectX SDK's dxerr.lib was built against the
//  VC9-era CRT and imports __vsnwprintf / __vsnprintf (old internal
//  names).  The VS2015+ CRT removed them.
//
//  IMPORTANT: these cannot be re-defined directly - a C function
//  literally named __vsnwprintf gets __cdecl-decorated to
//  ___vsnwprintf (one more underscore), which does NOT match the
//  symbol dxerr.lib wants.  Instead this shim defines differently
//  named functions and maps both possible spellings onto them via
//  /alternatename linker aliases.

#include <stdio.h>
#include <stdarg.h>
#include <wchar.h>

#if defined(_MSC_VER) && _MSC_VER >= 1900

extern "C" int __cdecl st_dxshim_vsnwprintf(wchar_t* pBuffer, size_t nCount,
                                            const wchar_t* pFormat, va_list ap)
{
    return _vsnwprintf(pBuffer, nCount, pFormat, ap);   // MSVC has no POSIX 'vsnwprintf'
}

extern "C" int __cdecl st_dxshim_vsnprintf(char* pBuffer, size_t nCount,
                                           const char* pFormat, va_list ap)
{
    return vsnprintf(pBuffer, nCount, pFormat, ap);
}

#pragma comment(linker, "/alternatename:__vsnwprintf=_st_dxshim_vsnwprintf")
#pragma comment(linker, "/alternatename:___vsnwprintf=_st_dxshim_vsnwprintf")
#pragma comment(linker, "/alternatename:__vsnprintf=_st_dxshim_vsnprintf")
#pragma comment(linker, "/alternatename:___vsnprintf=_st_dxshim_vsnprintf")

#endif // _MSC_VER >= 1900
