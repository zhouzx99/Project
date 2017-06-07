/*
 * File: syntax.cc
 *
 */

#include "syntax.h"

CSyntax::CSyntax()
{
    _timeout = 0;
    _root   = CMetaData();
    _action = CAction();
}

CSyntax::~CSyntax()
{
}

int CSyntax::Init(void)
{
    return VOICE_SEMANTIC_OK;
}

int CSyntax::BuildSyntaxTree(void)
{
    return VOICE_SEMANTIC_OK;
}

int CSyntax::TimeOut(int ms)
{
    if (_timeout > 0) {
	_timeout -= ms;
	if (_timeout <= 0) {
	    _timeout = 0;
	    return _action.Init();
	}
    }
    return VOICE_SEMANTIC_OK;
}

int CSyntax::Parse(CSentence& data)
{
    VOICE_SEMANTIC_STATUS ret = VOICE_SEMANTIC_ERROR;

    do {
    ret = _root.Match(data, _action);
    if (ret == VOICE_SEMANTIC_OK 
        && _action.Status() == VOICE_ACTION_STATUS_FINISH) {
        ret = _action.ActionCmd();
    }
    } while (ret == VOICE_SEMANTIC_OK);
    return ret;
}

/* --- END --- */
