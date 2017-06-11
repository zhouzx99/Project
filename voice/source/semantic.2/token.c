/***
 *
 *  token.c
 *
 ***/

#include <string.h>

#include "sentence.h"
#include "matchResult.h"
#include "token.h"

int voice_token_copy(Token* dst, Token* src)
{
    if (dst == NULL || src == NULL) {
        voice_log_error("The input params error for token copy!\n");
        return STATUS_FAILED;
    }

    strcpy(dst->value, src->value);
    dst->length = src->length;
    dst->type = src->type;

    return STATUS_SUCCESS;
}

int voice_token_set(Token* token, const char* value, TOKEN_TYPE_E type)
{
    if (token == NULL || value == NULL || type <= TOKEN_TYPE_NONE) {
        voice_log_error("The input params error for token set!\n");
        return STATUS_FAILED;
    }

    strncpy(token->value, value, sizeof(token->value) - 1);
    token->length = strlen(token->value);

    token->type = type;

    return STATUS_SUCCESS;
}

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
