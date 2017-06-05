/*
 * File: action.cc
 *
 */

#include "action.h"

CAction::CAction()
{
    _status = VOICE_ACTION_STATUS_NONE;
    _list[VOICE_ACTION_STATUS_MAX] = {NULL};
}

CAction::~CAction()
{
}

int CAction::Init(void)
{
    return VOICE_SEMANTIC_OK;
}

VOICE_ACTION_STATUS CAction::Status(void)
{
    return _status;
}

int CAction::ChangeStatus(VOICE_ACTION_STATUS status)
{
    if (status > VOICE_ACTION_STATUS_ERROR && status < VOICE_ACTION_STATUS_MAX) {
	_status = status;
	return VOICE_SEMANTIC_OK;
    }
    return VOICE_SEMANTIC_ERROR;
}

int CAction::PushMetaData(LANGUAGE* token, VOICE_SEMANTIC_LANGUAGE_TYPE type)
{
    if (token == NULL) return VOICE_SEMANTIC_ERROR;

    if (type == VOICE_SEMANTIC_LANGUAGE_TYPE_ROOM) {
	_list[VOICE_ACTION_STATUS_ROOM] = token;
    } else if (type == VOICE_ACTION_STATUS_ACTION) {
	_list[VOICE_ACTION_STATUS_ACTION] = token;
    } else if (type == VOICE_SEMANTIC_LANGUAGE_TYPE_OBJ) {
	_list[VOICE_ACTION_STATUS_OBJ] = token;
    } else {
	VOICE_PRINT("Error: Unknown language type %d, please check!\n", type);
	return VOICE_SEMANTIC_ERROR;
    }

    return VOICE_SEMANTIC_OK;
}

int CAction::ActionCmd(void)
{
    if (_status == VOICE_ACTION_STATUS_FINISH) {
	// TODO: add process for command gen

#if 1
	VOICE_PRINT("------------------------------------\n");
	VOICE_PRINT("   ROOM: %s\n", _list[VOICE_ACTION_STATUS_ROOM]);
	VOICE_PRINT(" ACTION: %s\n", _list[VOICE_ACTION_STATUS_ACTION]);
	VOICE_PRINT(" OBJECT: %s\n", _list[VOICE_ACTION_STATUS_OBJ]);
	VOICE_PRINT("------------------------------------\n");
#endif
	return VOICE_SEMANTIC_OK;
    }
    return VOICE_SEMANTIC_ERROR;
}

/* --- END --- */
