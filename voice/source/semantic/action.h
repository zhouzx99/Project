/*
 * action.h
 *
 * */

#ifndef _VOICE_ACTION_H_
#define _VOICE_ACTION_H_

#include "metadata.h"

typedef enum {
    VOICE_ACTION_STATUS_ERROR = -1,
    VOICE_ACTION_STATUS_NONE = 0,
    VOICE_ACTION_STATUS_ROOM = 1,
    VOICE_ACTION_STATUS_ACTION = 2,
    VOICE_ACTION_STATUS_OBJ = 3,

    VOICE_ACTION_STATUS_FINISH = 4,

    VOICE_ACTION_STATUS_MAX = 5,
} VOICE_ACTION_STATUS;


class CAction {
private:
    LANGUAGE* _list[VOICE_ACTION_STATUS_MAX];
    VOICE_ACTION_STATUS _status;

public:
    CAction();
    ~CAction();

public:
    int Init(void);
    VOICE_ACTION_STATUS Status(void);
    int ChangeStatus(VOICE_ACTION_STATUS status);
    int PushMetaData(LANGUAGE* token, VOICE_SEMANTIC_LANGUAGE_TYPE type);
    int ActionCmd(void);
};

#endif /* _VOICE_ACTION_H_ */
