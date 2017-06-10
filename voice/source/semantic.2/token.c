/***
 *
 *  token.c
 *
 ***/

#include <string.h>

#include "sentence.h"
#include "matchResult.h"
#include "token.h"


const char* voice_token_get_value(Token* token)
{
    if (token != NULL) {
        return token->value;
    }
    return NULL;
}

TOKEN_TYPE_E voice_token_get_type(Token* token)
{
    if (token != NULL) {
        return token->type;
    }
    return TOKEN_TYPE_ERROR;
}

unsigned int voice_token_get_length(Token* token)
{
    if (token != NULL) {
        return token->length;
    }
    return 0;
}

int voice_token_match(Token* token, Sentence* sentence, MatchResult* result)
{
    int offset = -1;
    char* pos = NULL;

    /* strstr function to find the matched position */
    pos = strstr(voice_sentence_get_data(sentence), token->value);
    if (pos != NULL) {
        offset = (int)(pos - voice_sentence_get_data(sentence));
        return voice_match_result_set_token(result, offset, token);
    }

    return voice_match_result_set_token(result, -1, NULL);
}

int voice_token_init(Token* token)
{
    if (token == NULL) {
        return STATUS_FAILED;
    }

    memset(token, 0, sizeof(Token));

    return STATUS_SUCCESS;
}

/* --- END --- */
