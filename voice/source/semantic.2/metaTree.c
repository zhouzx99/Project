/*
 * metaTree.c
 *
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "metaTree.h"

static MetaNode* g_meta_tree_root = NULL;
static MetaNode* g_meta_node_list[VOICE_META_TREE_NODE_MAX_CNTS] = {NULL};
static int g_meta_node_cnts = 0;

#define voice_meta_tree_create_node(node)       \
            do{ \
                if (g_meta_node_cnts  >= VOICE_META_TREE_NODE_MAX_CNTS) return NULL;  \
                node = (MetaNode*)malloc(sizeof(MetaNode)); \
                if (node == NULL || voice_meta_node_init(node) != STATUS_SUCCESS) { \
                    return NULL;  \
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

static MetaNode* voice_meta_tree_build_root_node(void)
{
    MetaNode* node = NULL;

    /* create the first child node */
    voice_meta_tree_create_node(node);

    return node;
}

static MetaNode* voice_meta_tree_build_room_node(void)
{
    int index = 0;
    Token token;
    MetaNode* node = NULL;

    const char roomList[][] = {"厨房", "客厅", "卧室"};
    unsigned int roomCnts = 3;

    /* create the first child node */
    voice_meta_tree_create_node(node);

    for (index = 0; index < roomCnts; index++) {
        /* Add token */
        voice_token_init(&token);
        voice_token_set(&token, roomList[index], TOKEN_TYPE_ROOM);
        voice_meta_node_add_token(node, &token);
    }

    return node;
}

static MetaNode* voice_meta_tree_build_opera_node(void)
{
    int index = 0;
    Token token;
    MetaNode* node = NULL;

    const char operaList[][] = {"开", "关"};
    unsigned int operaCnts = 2;

    /* create the first child node */
    voice_meta_tree_create_node(node);

    for (index = 0; index < operaCnts; index++) {
        /* Add token */
        voice_token_init(&token);
        voice_token_set(&token, operaList[index], TOKEN_TYPE_OPERA);
        voice_meta_node_add_token(node, &token);
    }

    return node;
}

static MetaNode* voice_meta_tree_build_object_node(void)
{
    int index = 0;
    Token token;
    MetaNode* node = NULL;

    const char objList[][] = {"灯", "所有灯"};
    unsigned int objCnts = 2;

    /* create the first child node */
    voice_meta_tree_create_node(node);
    for (index = 0; index < objCnts; index++) {
        /* Add token */
        voice_token_init(&token);
        voice_token_set(&token, objList[index], TOKEN_TYPE_OBJECT);
        voice_meta_node_add_token(node, &token);
    }

    return node;
}


static int voice_meta_tree_build(void)
{
    MetaNode* root = NULL;
    MetaNode* prev = NULL;
    MetaNode* node = NULL;

    root = voice_meta_tree_build_root_node();
    if (root == NULL) {
        return STATUS_FAILED;
    }

    /* root -> room -> obj -> opera */
    node = voice_meta_tree_build_room_node();
    if (node == NULL) {
        return STATUS_FAILED;
    }
    voice_meta_node_add_child(root, node);
    prev = node;

    node = voice_meta_tree_build_object_node();
    if (node == NULL) {
        return STATUS_FAILED;
    }
    voice_meta_node_add_child(prev, node);
    prev = node;

    node = voice_meta_tree_build_opera_node();
    if (node == NULL) {
        return STATUS_FAILED;
    }
    voice_meta_node_add_child(prev, node);

    /* root -> opera -> obj */
    node = voice_meta_tree_build_opera_node();
    if (node == NULL) {
        return STATUS_FAILED;
    }
    voice_meta_node_add_child(root, node);
    prev = node;

    node = voice_meta_tree_build_object_node();
    if (node == NULL) {
        return STATUS_FAILED;
    }
    voice_meta_node_add_child(prev, node);

    /* root -> opera -> room -> obj */
    node = voice_meta_tree_build_room_node();
    if (node == NULL) {
        return STATUS_FAILED;
    }
    voice_meta_node_add_child(prev, node);
    prev = node;

    node = voice_meta_tree_build_object_node();
    if (node == NULL) {
        return STATUS_FAILED;
    }
    voice_meta_node_add_child(prev, node);

    /* finished */
    g_meta_tree_root = root;
    return STATUS_SUCCESS;
}

int voice_meta_tree_destory(MetaTree* tree)
{
    voice_meta_tree_destroy_all();
    g_meta_tree_root = NULL;

    if (tree->root != NULL) {
        tree->root = NULL;
    }
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
