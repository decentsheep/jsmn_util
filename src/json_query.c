#include <string.h>
#include "json_query.h"

static int target_jsmntok(char* json_buf, jsmntok_t* t, tree_node* root_tree, char* target) {
    if (json_buf == NULL || t == NULL || root_tree == NULL || target == NULL) {
        return -1;
    }
    tree_node* curr_parent_node = root_tree;
    tree_node* child_node = NULL;
    char* pre = target;
    char* cur = strstr(target, ".");
    if (cur == NULL) {
        cur = pre + strlen(pre);
    }
    //unit = strtok(target, ".");
    int target_idx = -1;
    while(*pre != '\0') {
        child_node = curr_parent_node->first_child;
        while(child_node != NULL) {
            char* key = &json_buf[t[child_node->tok_idx].start];
            if (strncmp(key, pre, cur - pre) == 0) {
                break;
            }
            else {
                child_node = child_node->sibling;
            }
        }
        if (child_node == NULL) {
            return -1;
        }
        else {
            curr_parent_node = child_node->first_child;
            target_idx = curr_parent_node->tok_idx;
            if (*cur == '\0') {
                pre = cur;
            }
            else {
                cur += 1;
                pre = cur;
                cur = strstr(cur, ".");
                if (cur == NULL) {
                    cur = pre + strlen(pre);
                }
            }
        }
    }
    return target_idx;
};

int query_object(char* json_buf, jsmntok_t* t, tree_node* root_tree, char* object) {
    if (json_buf == NULL || t == NULL || root_tree == NULL || object == NULL) {
        return -1;
    }
    int ret = -1;
    ret = target_jsmntok(json_buf, t, root_tree, object);
    if (ret == -1 || t[ret].type != JSMN_OBJECT) {
        return -1;
    }
    else {
        return ret;
    }
};

int query_array(char* json_buf, jsmntok_t* t, tree_node* root_tree, char* object) {
    if (json_buf == NULL || t == NULL || root_tree == NULL || object == NULL) {
        return -1;
    }
    int ret = -1;
    ret = target_jsmntok(json_buf, t, root_tree, object);
    if (ret == -1 || t[ret].type != JSMN_ARRAY) {
        return -1;
    }
    else {
        return ret;
    }
};

int query_primitive(char* json_buf, jsmntok_t* t, tree_node* root_tree, char* object) {
    if (json_buf == NULL || t == NULL || root_tree == NULL || object == NULL) {
        return -1;
    }
    int ret = -1;
    ret = target_jsmntok(json_buf, t, root_tree, object);
    if (ret == -1 || t[ret].type != JSMN_PRIMITIVE) {
        return -1;
    }
    else {
        return ret;
    }
};

int query_string(char* json_buf, jsmntok_t* t, tree_node* root_tree, char* object) {
    if (json_buf == NULL || t == NULL || root_tree == NULL || object == NULL) {
        return -1;
    }
    int ret = -1;
    ret = target_jsmntok(json_buf, t, root_tree, object);
    if (ret == -1 || t[ret].type != JSMN_STRING) {
        return -1;
    }
    else {
        return ret;
    }
};
