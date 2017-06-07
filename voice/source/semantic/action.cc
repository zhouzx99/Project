/*
 * File: action.cc
 *
 */

#include "action.h"

CAction::CAction()
{
    _list[VOICE_ACTION_STATUS_MAX] = { CMatchResult() };
    _completed = false;
    _counts = 0;
}

CAction::~CAction()
{
}

int CAction::Init(void)
{
    return VOICE_SEMANTIC_OK;
}

void CAction::MatchCompleted(bool status)
{
    _completed = status;
}

bool CAction::CompletionStatus(void)
{
    return _completed;
}

int CAction::AddMatchResult(CMatchResult& result)
{
    if (result.Result()) {
        _list[_counts++] = result;
        return VOICE_SEMANTIC_OK;
    }
    return VOICE_SEMANTIC_ERROR;
}

CMetaData* CAction::GetCurrentMetadata(void)
{
    if (_counts > 0) {
        return _list[_counts - 1].GetMatchedMetadata();
    }

    return NULL;
}

int CAction::GetActionCmd(void)
{
    if (CompletionStatus()) {
    	// TODO: add process for command gen

#if 1
    	VOICE_PRINT("------------------------------------\n");
        for (int i = 0; i < _counts; i++) {
            CToken* token = _list[i].GetMatchedToken();
            VOICE_PRINT("  Step %d: %s \n", i+1, token==NULL?"<None>":token->Value());
        }
    	VOICE_PRINT("------------------------------------\n");
#endif
    	return VOICE_SEMANTIC_OK;
    }
    return VOICE_SEMANTIC_ERROR;
}

/* --- END --- */
