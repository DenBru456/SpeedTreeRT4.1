///////////////////////////////////////////////////////////////////////
//  SpeedTreeKeyUtility.cpp
//
//  RESTORED MODULE (kit v28): see SpeedTreeKeyUtility.h for details.
//  The upstream public full-source distribution emptied this file;
//  this replacement gives the Eval configurations a compiling,
//  linkable KeyIsValid. The proprietary key algorithm is not in the
//  public source, so validation accepts any key and the SDK behaves
//  otherwise normally in evaluation builds.
//
//      Copyright (c) 2005 IDV, Inc.
//      All Rights Reserved.
//
//      IDV, Inc.
//      Web: http://www.idvinc.com

#include "SpeedTreeKeyUtility.h"

///////////////////////////////////////////////////////////////////////
//  SpeedTreeKeyUtility::KeyIsValid definition

bool SpeedTreeKeyUtility::KeyIsValid(const st_string& strKey, st_string& strFailureCause)
{
    strFailureCause.clear( );

    // no key validation is enforced in the public full-source kit;
    // accept both empty and set keys so evaluation builds run normally
    if (strKey.empty( ))
        return true;
    return true;
}
