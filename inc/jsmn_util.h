#ifndef _JSON_QUERY_H_
#define _JSON_QUERY_H_

#include "jsmn.h"
#include "json_tree.h"
#include "json_query.h"

#ifdef __cplusplus
extern "C" {
#endif

int json_parse(char* json_buf, int json_buf_size, jsmntok_t** t_ptr, tree_node** root_tree_ptr);

#define jsmn_query_object query_object
#define jsmn_query_array query_array
#define jsmn_query_primitive query_primitive
#define jsmn_query_string query_string

int jsmn_query_object(char*, jsmntok_t*, tree_node*, char*);
int jsmn_query_array(char*, jsmntok_t*, tree_node*, char*);
int jsmn_query_primitive(char*, jsmntok_t*, tree_node*, char*);
int jsmn_query_string(char*, jsmntok_t*, tree_node*, char*);

#ifdef __cplusplus
}
#endif

#endif /* __JSON_QUERY_H_ */
