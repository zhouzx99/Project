/*
 * metaTree.c
 *
 * */

#include <stdio.h>
#include <string.h>
#include "metaTree.h"

static MetaNode* g_meta_tree_root = NULL;
static MetaNode* g_meta_node_list[VOICE_META_TREE_NODE_MAX_CNTS] = {NULL};
static int g_meta_node_cnts = 0;

#define voice_meta_tree_create_node(node)       \
            do{ \
                if (g_meta_node_cnts  >= VOICE_META_TREE_NODE_MAX_CNTS) return STATUS_FAILED;  \
                node = (MetaNode*)malloc(sizeof(MetaNode)); \
                if (node == NULL || voice_meta_node_init(node) != STATUS_SUCCESS) { \
                    return STATUS_FAILED;  \
                }   \
                g_meta_node_list[g_meta_node_cnts++] = node;    \
            }while(0)
#define voice_meta_tree_destroy_all()      \
            do{ \
                int index = 0;          \
                for (index = g_meta_node_cnts - 1; index >= 0; index--) { \
                    free(g_meta_node_list[index]);   \
                    g_meta_node_list[index] = NULL;  \
                } \
            }while(0)


static int voice_meta_tree_build(void)
{
    MetaNode* root = NULL;
    MetaNode* prev = NULL;
    MetaNode* node = NULL;
    Token token;

    /* create root */
    voice_meta_tree_create_node(node);
    root = node;

    /* create the first child node */
    voice_meta_tree_create_node(node);
    voice_meta_node_add_child(root, node);
    /* Add token */
    voice_token_init(&token);
    voice_token_set(&token, "room", TOKEN_TYPE_ROOM);
    voice_meta_node_add_token(node, &token);
    prev = node;


    /* create the first child node */
    voice_meta_tree_create_node(node);
    voice_meta_node_add_child(prev, node);
    /* Add token */
    voice_token_init(&token);
    voice_token_set(&token, "open", TOKEN_TYPE_OPERA);
    voice_meta_node_add_token(node, &token);

    voice_token_init(&token);
    voice_token_set(&token, "close", TOKEN_TYPE_OPERA);
    voice_meta_node_add_token(node, &token);
    prev = node;


    /* create the first child node */
    voice_meta_tree_create_node(node);
    voice_meta_node_add_child(prev, node);
    /* Add token */
    voice_token_init(&token);
    voice_token_set(&token, "light", TOKEN_TYPE_OBJECT);
    voice_meta_node_add_token(node, &token);

    g_meta_tree_root = root;
    return STATUS_SUCCESS;
}

static int voice_meta_tree_destory(MetaNode* root)
{
    voice_meta_tree_destroy_all();
    return STATUS_SUCCESS;
}


MetaNode* voice_meta_tree_root(MetaTree* tree)
{
    if (tree != NULL) {
        return tree->root;
    }
    return NULL;
}

int voice_meta_tree_init(MetaTree* tree)
{
    if (tree == NULL) {
        return STATUS_FAILED;
    }

    if (g_meta_tree_root == NULL) {
        if (voice_meta_tree_build() != STATUS_SUCCESS) {
            return STATUS_FAILED;
        }
    }
    tree->root = g_meta_tree_root;

    return STATUS_SUCCESS;
}

/* --- END --- */
