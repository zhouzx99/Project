/*
 * File: matadata.cc
 *
 */

#include "matadata.h"

CMetaData::CMetaData()
{
    _list = CMatchList();

    _parent = NULL;
    _brother = NULL;
    _child = NULL;
}

CMetaData::~CMetaData()
{
}

const CMetaData* CMetaData::Brother(void)
{
    return _brother;
}

int CMetaData::MatchToken(CSentence& data)
{
    return _list.Match(CSentence & data);
}

int CMetaData::MatchChild(CSentence& data, CAction& action)
{
    if (_child == NULL) return VOICE_SEMANTIC_OK;

    return _child->Match(data, action);
}

int CMetaData::MatchBrother(CSentence& data, CAction& action)
{
	CMatchResult current(NULL, -1);
	CMatchResult best(NULL, -1);
    const CMetaData* cur = NULL;

	//
}

int CMetaData::Match(CSentence& data, CAction& action)
{
    if (_child == NULL) return VOICE_SEMANTIC_OK;

    if (_brother != NULL) {
        //
    }
}


