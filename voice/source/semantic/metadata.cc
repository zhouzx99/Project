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

int CMetaData::Match(LANGUAGE* data, CAction& action)
{
    if (_child == NULL) return VOICE_SEMANTIC_OK;

    
}


