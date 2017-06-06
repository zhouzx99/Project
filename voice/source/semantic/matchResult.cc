/*
 * File: matchResult.cc
 *
 */

#include "matchResult.h"

CMatchResult::CMatchResult(CToken* token, int start)
{
}

CMatchResult::CMatchResult(CMatchResult& res)
{
	_token = res._token;
	_start = res._start;
}

CMatchResult::~CMatchResult()
{
}

bool CMatchResult::operator<(CMatchResult& res)
{
	if (_start < 0) {
		if (res._start >= 0) {
			return true;
		}
	} else {
		if (_start < res._start) {
			return true;
		}
	}

    return false;
}

/* --- END --- */
