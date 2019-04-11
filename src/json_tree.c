#include <stdlib.h>
#include "json_tree.h"

static void add_sibling(tree_node* first_child, tree_node* new_child) {
    if (first_child == NULL || new_child == NULL) {
        return;
    }
    tree_node* sibling = first_child;
    while(sibling->sibling != NULL) {
        sibling = sibling->sibling;
    }
    sibling->sibling = new_child;
}

static void add_child(tree_node* parent, tree_node* child) {
    if (parent == NULL || child == NULL) {
        return;
    }
    if (parent->first_child == NULL) {
        parent->first_child = child;
    }
    else {
        add_sibling(parent->first_child, child);
    }
}

tree_node* jsmntok_to_tree(jsmntok_t *t, int tok_num) {
    tree_node* tree_root = (tree_node*)malloc(sizeof(tree_node) * tok_num);
    if (tree_root == NULL) {
        return NULL;
    }

    //here is an implicit fact: t[0] is root jsmn token, so tree_root[0] is also root json_tree node
    for(int i = 0; i < tok_num; i++) {
        tree_root[i].tok_idx = i;
        tree_root[i].child_num = t[i].size;
        tree_root[i].sibling = NULL;
        tree_root[i].first_child = NULL;
        if (t[i].parent != -1) {
            add_child(&tree_root[t[i].parent], &tree_root[i]);
        }
    }
    return tree_root;
}
