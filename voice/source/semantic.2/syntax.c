/*
 * syntax.c
 *
 * */
#include <stdio.h>
#include <stdlib.h>

#include "syntax.h"


int voice_syntax_parse_sentece(Syntax* syntax, Sentence* sentence, Action* action)
{
    MatchResult result;

    if (voice_match_result_init(&result) != STATUS_SUCCESS) {
        voice_log_error("Match result init failed!\n");
        return STATUS_FAILED;
    }

    if (voice_engine_execute(&(syntax->engine), &(syntax->tree),
                              sentence, &result) != STATUS_SUCCESS) {
        voice_log_error("Syntax engine execute failed!\n");
        return STATUS_FAILED;
    }

    if (voice_match_result_status(&result) != STATUS_FAILED) {
        voice_log_error("Syntax engine execution result failed!\n");
        return STATUS_FAILED;
    }

    if (voice_engine_completed(&(syntax->engine)) == STATUS_SUCCESS) {
        return voice_engine_build_action(&(syntax->engine), action);
    }

    return STATUS_SUCCESS;
}

int voice_syntax_reset(Syntax* syntax)
{
    if (syntax != NULL) {
        return STATUS_FAILED;
    }

    return voice_engine_reset(&(syntax->engine));
}

int voice_syntax_init(Syntax* syntax)
{
    if (syntax == NULL) {
        return STATUS_FAILED;
    }

    if (voice_meta_tree_init(&(syntax->tree)) != STATUS_SUCCESS) {
        voice_log_error("Syntax Meta tree init failed!\n");
        return STATUS_FAILED;
    }

    if (voice_engine_init(&(syntax->engine)) != STATUS_SUCCESS) {
        voice_log_error("Syntax engine init failed!\n");
        return STATUS_FAILED;
    }

    return STATUS_SUCCESS;
}

/* --- END --- */
