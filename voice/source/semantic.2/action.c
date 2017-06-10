/***
 *
 *  action.c
 *
 ***/
 
#include "action.h"


int voice_action_generate_result(Action* action)
{
    unsigned int index = 0;

    voice_log_info(" ---- Gen Result ----\n");
    for (index = 0; index < action->length; index++) {
        voice_log_info("  Step %d: token: %s, type: %d\n", index + 1,
                    voice_token_get_value(action->list[index]),
                    voice_token_get_type(action->list[index]));
    }

    return STATUS_SUCCESS;
}

int voice_action_add_token(Action* action, Token* token)
{
    if (token == NULL) {
        return STATUS_FAILED;
    }

    action->list[action->length++] = token;

    return STATUS_SUCCESS;
}

int voice_action_init(Action* action)
{
    if (action == NULL) {
        return STATUS_FAILED;
    }

    memset(action, 0, sizeof(Action));

    return STATUS_SUCCESS;
}

/* --- END --- */
