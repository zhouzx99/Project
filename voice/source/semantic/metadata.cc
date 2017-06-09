/*
 * File: metadata.cc
 *
 */

#include "metadata.h"

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

CMatchResult CMetaData::MatchToken(CSentence& data)
{
    return CMatchResult(_list.MatchToken(data), this);
}

CMatchResult CMetaData::MatchBrother(CSentence& data)
{
	CMatchResult current();
	CMatchResult best();
    const CMetaData* metadata = NULL;

    best = current;
	for (metadata = this; metadata != NULL; metadata = metadata->Brother()) {
        current = metadata->MatchToken(data);
        if (current < best) {
            best = current;
        }
    }
    return best;
}

CMatchResult CMetaData::MatchChild(CSentence& data)
{
    CMatchResult result();
    
    if (_child != NULL) {
        result = _child->MatchBrother(data);
    }
    return result;
}

int CMetaData::Match(CSentence& data, CAction& action)
{
    CMatchResult result();

    if (_child == NULL) {
        action.MatchCompleted(true);
        return VOICE_SEMANTIC_OK;
    }

    do {
        result = MatchChild(data);
        if (result.Result()) {
            return action.AddMatchResult(result);
        }
    } while ();
    return VOICE_SEMANTIC_ERROR;
}


