/*
 * File: sentence.cc
 *
 */

#include "sentence.h"


CSentence::CSentence()
{
    _data = LANGUAGE();
    _pos  = 0;
}

CSentence::CSentence(LANGUAGE& str)
{
    _data = str;
    _pos  = 0;
}


CSentence::~CSentence()
{
}

int CSentence::Init(void)
{
    return VOICE_SEMANTIC_OK;
}

int CSentence::Reset(void)
{
    _pos = 0;
    return VOICE_SEMANTIC_OK;
}

int CSentence::AddMatchResult(CMatchResult& result)
{
    if (result.Result()) {
        _pos += result.GetCurrentOffset();
        return VOICE_SEMANTIC_OK;
    }
    return VOICE_SEMANTIC_ERROR;
}

int CSentence::Match(CToken& token)
{
    return _data.Compare(token.Value(), _pos);
}

/* --- END --- */
