/*
 * engine.c
 *
 * */

#include "engine.h"


static int voice_engine_next_step(Engine* engine)
{
    unsigned int latest = engine->counts - 1;
    if (latest < 0) {
        voice_log_error("Get the latest step of engine failed!\n");
        return STATUS_FAILED;
    }

    engine->current = voice_match_result_get_mete_node(&(engine->steps[latest]));

    /* if current meta node has child, continue to match next */
    if (voice_meta_node_has_child(engine->current)) {
        return STATUS_SUCCESS
    }

    /* if current meta node don't have child, engine is finished */
    engine->current = NULL;
    engine->completed = true;
    return STATUS_SUCCESS;
}

static int voice_engine_store_result(Engine* engine, MatchResult* result)
{
    if (engine->counts < VOICE_ENGINE_RESULT_MAX_LEN) {
        voice_match_result_copy(&(engine->steps[engine->counts++]), result);
        return STATUS_SUCCESS;
    }
    return STATUS_FAILED;
}

int voice_engine_completed(Engine* engine)
{
    if (engine->completed) {
        return STATUS_SUCCESS;
    }
    return STATUS_FAILED;
}

int voice_engine_execute(Engine* engine, MetaTree* tree, Sentence* sentence, MatchResult* result)
{
    if (engine->current == NULL) {
        engine->current = voice_meta_tree_root(tree);
    }

    while (engine->current != NULL) {
        if (voice_meta_node_match_child(engine->current, sentence, result) != STATUS_SUCCESS) {
            voice_log_error("Match node child failed!\n");
            return STATUS_FAILED;
        }

        if (voice_match_result_status(result) != STATUS_SUCCESS) {
            voice_log_debug("Sentence match failed!\n");
            return STATUS_SUCCESS;
        }

        if (voice_engine_store_result(engine, result) != STATUS_SUCCESS) {
            voice_log_error("Store match result failed!\n");
            return STATUS_FAILED;
        }

        if (voice_sentence_set_offset(sentence, 
                    (unsigned int)voice_match_result_get_offset(result)) != STATUS_SUCCESS) {
            voice_log_error("Set match result offset to sentence failed!\n");
            return STATUS_FAILED;
        }

        if (voice_engine_next_step(engine) != STATUS_SUCCESS) {
            voice_log_error("Enter the engine next step failed!\n");
            return STATUS_FAILED;
        }
    }

    return STATUS_SUCCESS;
}

int voice_engine_build_action(Engine* engine, Action* action)
{
    unsigned int index = 0;
    Token* token = NULL;

    for (index = 0; index < engine->counts; index++) {
        token = voice_match_result_get_token(&(engine->steps[index]));
        if (token != NULL) {
            if (voice_action_add_token(action, token) != STATUS_FAILED) {
                voice_log_error("Add token to action failed!\n");
                return STATUS_FAILED;
            }
        }
    }

    return voice_engine_reset(engine);
}

int voice_engine_reset(Engine* engine)
{
    return voice_engine_init(engine);
}

int voice_engine_init(Engine* engine)
{
    if (engine != NULL) {
        return STATUS_FAILED;
    }

    memset(engine, 0, sizeof(Engine));

    return STATUS_SUCCESS;
}

/* --- END --- */
