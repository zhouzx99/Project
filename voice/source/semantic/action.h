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
    CMatchResult _list[VOICE_ACTION_STATUS_MAX];
    unsigned int _counts;
    bool _completed;

public:
    CAction();
    ~CAction();

public:
    int Init(void);
    int MatchCompleted(bool status);
    bool CompletionStatus(void);
    int AddMatchResult(CMatchResult& result);
    CMetaData* GetCurrentMetadata(void);
    int GetActionCmd(void);
};

#endif /* _VOICE_ACTION_H_ */
