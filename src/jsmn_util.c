#include <stdlib.h>
#include "jsmn_util.h"

int json_parse(char* json_buf, int json_buf_size, jsmntok_t** t_ptr, tree_node** root_tree_ptr) {
    if (json_buf == NULL || t_ptr == NULL || root_tree_ptr == NULL) {
        return -1;
    }

    int jsmn_tok_cnt;
    jsmn_parser jsmn_p;
    jsmntok_t* jsmn_t;

    jsmn_init(&jsmn_p);
    jsmn_tok_cnt = jsmn_parse(&jsmn_p, json_buf, (sizeof(char) * json_buf_size), NULL, 0);
    if (jsmn_tok_cnt <= 0) {
        return -1;
    }

    jsmn_t = (jsmntok_t *)malloc(sizeof(jsmntok_t) * jsmn_tok_cnt);
    jsmn_init(&jsmn_p);
    jsmn_tok_cnt = jsmn_parse(&jsmn_p, json_buf, (sizeof(char) * json_buf_size), jsmn_t, jsmn_tok_cnt);

    tree_node* root_tree = jsmntok_to_tree(jsmn_t, jsmn_tok_cnt);
    if(root_tree == NULL) {
        return -1;
    }

    *t_ptr = jsmn_t;
    *root_tree_ptr = root_tree;
    return jsmn_tok_cnt;
}
