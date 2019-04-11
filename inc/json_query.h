#ifndef _JSON_QUERY_H_
#define _JSON_QUERY_H_

#include "json_tree.h"

#ifdef __cplusplus
extern "C" {
#endif

int query_object(char* json_buf, jsmntok_t* t, tree_node* root_tree, char* object);
int query_array(char* json_buf, jsmntok_t* t, tree_node* root_tree, char* array);
int query_primitive(char* json_buf, jsmntok_t* t, tree_node* root_tree, char* primitive);
int query_string(char* json_buf, jsmntok_t* t, tree_node* root_tree, char* string);

#ifdef __cplusplus
}
#endif

#endif /* __JSON_QUERY_H_ */
