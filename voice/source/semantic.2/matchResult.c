
/***
 *
 *  matchResult.c
 *
 ***/

#include "token.h"
#include "metaNode.h"
#include "matchResult.h"


int voice_match_result_set_token(MatchResult* result, int offset, Token* token)
{
    if (result != NULL) {
        result->offset = offset;
        result->token = token;
        return STATUS_SUCCESS;
    }
    return STATUS_FAILED;
}

int voice_match_result_set_mete_node(MatchResult* result, MetaNode* node)
{
    if (result != NULL) {
        result->node = node;
        return STATUS_SUCCESS;
    }
    return STATUS_FAILED;
}

int voice_match_result_get_offset(MatchResult* result)
{
    if (result != NULL) {
        return result->offset + voice_token_get_length(result->token);
    }
    return -1;
}

Token* voice_match_result_get_token(MatchResult* result)
{
    if (result != NULL) {
        return result->token;
    }
    return NULL;
}

MetaNode* voice_match_result_get_mete_node(MatchResult* result)
{
    if (result != NULL) {
        return result->node;
    }
    return NULL;
}

int voice_match_result_status(MatchResult* result)
{
    if ( result == NULL || result->offset < 0 || result->token == NULL) {
        return STATUS_FAILED;
    }
    return STATUS_SUCCESS;
}

int voice_match_result_compare(MatchResult* resultA, MatchResult* resultB)
{
    if (resultA->offset < 0 && resultB->offset < 0) {
        return MATCH_RESULT_ERROR;
    } else if (resultB->offset < 0) {
            return MATCH_RESULT_A_BETTER_B;
    } else if (resultA->offset < 0) {
        return MATCH_RESULT_B_BETTER_A;
    } else {
        if (resultA->offset < resultB->offset) {
            return MATCH_RESULT_A_BETTER_B;
        } else if (resultA->offset > resultB->offset) {
            return MATCH_RESULT_B_BETTER_A;
        } else {
            /* for token, first match the longgest token */
            if (voice_token_get_length(resultA->token) > voice_token_get_length(resultB->token)) {
                return MATCH_RESULT_A_BETTER_B;
            } else if (voice_token_get_length(resultA->token) < voice_token_get_length(resultB->token)) {
                return MATCH_RESULT_B_BETTER_A;
            } else {
                return MATCH_RESULT_A_EQUAL_B;
            }
        }
    }
}

int voice_match_result_copy(MatchResult* dst, MatchResult* src)
{
    if (dst != NULL && src != NULL) {
        dst->offset = src->offset;
        dst->token = src->token;
        dst->node = src->node;

        return STATUS_SUCCESS;
    }
    return STATUS_FAILED;
}

int voice_match_result_init(MatchResult* result)
{
    if (result == NULL) {
        return STATUS_FAILED;
    }

    memset(result, 0, sizeof(MatchResult));

    /* set default value for match result */
    result->offset = -1;

    return STATUS_SUCCESS;
}

/* --- END --- */
