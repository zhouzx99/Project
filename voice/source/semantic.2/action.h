/***
 *
 *  action.h
 *
 ***/

#ifndef _VOICE_ACTION_H_
#define _VOICE_ACTION_H_

typedef struct _Token Token;

typedef struct _Action {
    bool valid;
    Token* list[VOICE_ACTION_TOKEN_MAX_LEN];
    unsigned int length;
} Action;

int voice_action_init(Action* action);
int voice_action_add_token(Token* token);
int voice_action_generate_result(Action* action);

#endif /* _VOICE_ACTION_H_ */


