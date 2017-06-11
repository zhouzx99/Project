/*
 * metaNode.c
 *
 * */

#include "metaNode.h"

static int voice_meta_node_match_token(MetaNode* node, Sentence* sentence, MatchResult* result)
{
    unsigned int index = 0;
    MatchResult tokenRet;

    for (index = 0; index < node->counts; index++) {
        if (voice_match_result_init(&tokenRet) != STATUS_SUCCESS) {
            voice_log_error("Match result index %d init failed!\n", index);
            return STATUS_FAILED;
        }

        if (voice_token_match(&(node->list[index]), sentence, &tokenRet) != STATUS_SUCCESS) {
            voice_log_error("Token %d match sentence failed!\n", index);
            return STATUS_FAILED;
        }

        if (voice_match_result_set_mete_node(&tokenRet, node) != STATUS_SUCCESS) {
            voice_log_error("Store meta node to match result %d failed!\n", index);
            return STATUS_FAILED;
        }

        if (voice_match_result_compare(&tokenRet, result) == MATCH_RESULT_A_BETTER_B) {
            if (voice_match_result_copy(result, &tokenRet) != STATUS_SUCCESS) {
                voice_log_error("Copy match result %d failed!\n", index);
                return STATUS_FAILED;
            }
        }
    }

    return STATUS_SUCCESS;
}

int voice_meta_node_match_child(MetaNode* node, Sentence* sentence, MatchResult* result)
{
    MetaNode* child = NULL;
    MatchResult childRet;

    for (child = node->child; child != NULL; child = child->brother) {
        if (voice_match_result_init(&childRet) != STATUS_SUCCESS) {
            voice_log_error("Match result init failed!\n");
            return STATUS_FAILED;
        }

        if (voice_meta_node_match_token(child, sentence, &childRet) != STATUS_SUCCESS) {
            voice_log_error("Meta node match token failed!\n");
            return STATUS_FAILED;
        }

        if (voice_match_result_compare(&childRet, result) == MATCH_RESULT_A_BETTER_B) {
            if (voice_match_result_copy(result, &childRet) != STATUS_SUCCESS) {
                voice_log_error("Copy match result failed!\n");
                return STATUS_FAILED;
            }
        }
    }
    return STATUS_SUCCESS;
}

BOOL voice_meta_node_has_child(MetaNode* node)
{
    if (node != NULL && node->child != NULL) {
        return TRUE;
    }
    return FALSE;
}

int voice_meta_node_add_brother(MetaNode* node, MetaNode* brother)
{
    MetaNode* brotherNode = NULL;

    if (node == NULL || brother == NULL) {
        return STATUS_FAILED;
    }

    for (brotherNode = node; brotherNode->brother != NULL;
                    brotherNode = brotherNode->brother);
    brotherNode->brother = brother;
    brother->parent = brotherNode->parent;

    return STATUS_SUCCESS;
}

int voice_meta_node_add_child(MetaNode* node, MetaNode* child)
{
    if (node == NULL || child == NULL) {
        return STATUS_FAILED;
    }

    if (node->child == NULL) {
        node->child = child;
        child->parent = node;
        return STATUS_SUCCESS;
    } else {
        return voice_meta_node_add_brother(node->child, child);
    }
}

int voice_meta_node_add_token(MetaNode* node, Token* token)
{
    Token* current = NULL;

    if (node == NULL || token == NULL) {
        voice_log_error("the input params error for voice meta node set token!\n");
        return STATUS_FAILED;
    }

    if (node->counts < VOICE_META_NODE_TOKEN_MAX_SIZE) {
        current = &(node->list[node->counts++]);
        return voice_token_copy(current, token);
    }
    return STATUS_FAILED;
}

int voice_meta_node_init(MetaNode* node)
{
    if (node == NULL) {
        return STATUS_FAILED;
    }

    memset(node, 0, sizeof(MetaNode));

    return STATUS_SUCCESS;
}

/* --- END --- */
