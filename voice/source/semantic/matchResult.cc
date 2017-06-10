/*
 * File: matchResult.cc
 *
 */

#include "matchResult.h"

CMatchResult::CMatchResult()
{
    _token = NULL;
    _start = -1;
    _data  = NULL;
}

CMatchResult::CMatchResult(CToken* token, int start)
{
    _token = token;
    _start = start;
    _data  = NULL;
}

CMatchResult::CMatchResult(CMatchResult res, CMetaData* data)
{
    _token = res._token;
    _start = res._start;
    _data  = data;
}

CMatchResult::CMatchResult(CMatchResult& res)
{
    _token = res._token;
    _start = res._start;
    _data  = res._data;
}

CMatchResult::CMatchResult(const CMatchResult& res)
{
    _token = res._token;
    _start = res._start;
    _data  = res._data;
}

CMatchResult::~CMatchResult()
{
}

unsigned int CMatchResult::GetCurrentOffset()
{
    if (_token != NULL && _start >= 0) {
        return _token->Length() + _start;
    }
    return 0;
}

CMetaData* CMatchResult::GetMatchedMetadata()
{
    return _data;
}

CToken* CMatchResult::GetMatchedToken()
{
    return _token;
}

bool CMatchResult::Result(void)
{
    if (_token != NULL && _start >= 0) {
        return true;
    }
    return false;
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
