/*
 * File: token.cc
 *
 */

#include "token.h"

CToken::CToken()
{}

CToken::~CToken()
{}

LANGUAGE* CToken::Value()
{
    return &_value;
}

unsigned int CToken::Length()
{
    return _value.Length();
}

VOICE_SEMANTIC_LANGUAGE_TYPE CToken::Type()
{
    return _type;
}

VOICE_SEMANTIC_STATUS CToken::Set(LANGUAGE* val, VOICE_SEMANTIC_LANGUAGE_TYPE type)
{
    VOICE_SEMANTIC_LANGUAGE_SET(&_value, val);
    _type = type;
    return VOICE_SEMANTIC_OK;
}

CMatchResult CToken::Match(CSentence& data)
{
    return CMatchResult(this, data.Match(*this));
}

