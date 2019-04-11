#ifndef _JSON_TREE_H_
#define _JSON_TREE_H_

#include "jsmn.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tree_node {
    int tok_idx;
    int child_num;
    struct tree_node *sibling;
    struct tree_node *first_child;
}tree_node;

tree_node* jsmntok_to_tree(jsmntok_t *t, int tok_num);

#ifdef __cplusplus
}
#endif

#endif /* __JSON_TREE_H_ */
