/*
 * File: matchResult.cc
 *
 */

#include "matchResult.h"

CMatchResult::CMatchResult(CToken* token, int start)
{
}

CMatchResult::~CMatchResult()
{
}

bool CMatchResult::operator<(CMatchResult& res)
{
    if (_start < res._start) {
        return true;
    }
    return false;
}

/* --- END --- */
