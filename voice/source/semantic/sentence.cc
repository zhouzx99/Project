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

int CSentence::Match(CToken& token)
{
    int ret = _data.Compare(token, _pos);
    if (ret > 0) {
        _pos += ret;
        return VOICE_SEMANTIC_OK;
    }
    return VOICE_SEMANTIC_ERROR;
}

/* --- END --- */
