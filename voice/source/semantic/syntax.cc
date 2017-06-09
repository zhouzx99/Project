/*
 * File: syntax.cc
 *
 */

#include "syntax.h"

CSyntax::CSyntax()
{
    _timeout = 0;
    _root   = NULL;
    _action = CAction();
}

CSyntax::CSyntax(CMetaData* root)
{
    _timeout = 0;
    _root   = root;
    _action = CAction();
}

CSyntax::~CSyntax()
{
}

int CSyntax::Init(void)
{
    return _action.Init();
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

    if (_root == NULL) {
        return ret;
    }

    do {
        ret = _root->Match(data, _action);
        if (ret == VOICE_SEMANTIC_OK 
            && _action.CompletionStatus()) {
            ret = _action.GetActionCmd();
        }
    } while (ret == VOICE_SEMANTIC_OK);

    return ret;
}

/* --- END --- */
