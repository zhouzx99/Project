/*
 * metaTree.c
 *
 * */

#include "metaTree.h"

static MetaNode* g_meta_tree_root = NULL;

static int voice_meta_tree_build(void)
{
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
