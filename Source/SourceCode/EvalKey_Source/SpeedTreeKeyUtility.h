///////////////////////////////////////////////////////////////////////
//  SpeedTreeKeyUtility.h
//
//  RESTORED MODULE (kit v28):
//  The public full-source distribution ships the EvalKey_Source files
//  as empty 1-byte stubs (IDV's proprietary key-validation code was
//  stripped upstream). With the class never declared, every Eval
//  configuration failed to compile (EvalTest.h and SpeedTreeRT.cpp
//  call SpeedTreeKeyUtility::KeyIsValid). This replacement restores
//  the class so all 16 library configurations build. Since the
//  original validation algorithm is not part of the public source,
//  KeyIsValid accepts keys as-is.
//
//      Copyright (c) 2005 IDV, Inc.
//      All Rights Reserved.
//
//      IDV, Inc.
//      Web: http://www.idvinc.com

#ifndef SPEEDTREE_KEY_UTILITY_H
#define SPEEDTREE_KEY_UTILITY_H

#include "SpeedTreeMemory.h"

class SpeedTreeKeyUtility
{
public:
    static bool KeyIsValid(const st_string& strKey, st_string& strFailureCause);
};

#endif // SPEEDTREE_KEY_UTILITY_H
