JSMN_UTIL
====
jsmn_util is a light weight, pure c, json query library, based on jsmn [https://github.com/zserge/jsmn.git][1]

Aim
---
In order to use json on resource-limited embeded systems, jsmn is a good choice. But jsmn only stores json infomation with an array of jsmntok_t, which is not convenient for query certain information. This library jsmn_util aims to provide a useful json query interface.

Usage
-----
jsmn_util is based on cmake, just run:

	$mkdir build && cmake .. && make

API
---
you can find jsmn_util apis in inc/jsmn_util.h, there are currently 2 kinds of apis: json_parse and jsmn_query_xx
json_parse:

	int json_parse(char* json_buf, int json_buf_size, jsmntok_t** t_ptr, tree_node** root_tree_ptr);

in which, `json_buf` is the json string, it is an input, `json_buf_size` is json string length, it is an input, `t_ptr` is address of jsmntok_t pointer, it is an output, `root_tree_ptr` is address of tree_node pointer, it is an output.
If json parse successfully, this api will return jsmn token num, and you will get jsmntok_t array start address in memory t_ptr points to, and a root address of json tree in memory root_tree_ptr points to.
If anything wrong, you get an -1 as return value.
jsmn_query_xx:

	int jsmn_query_object(char*, jsmntok_t*, tree_node*, char*);
	int jsmn_query_array(char*, jsmntok_t*, tree_node*, char*);
	int jsmn_query_primitive(char*, jsmntok_t*, tree_node*, char*);
	int jsmn_query_string(char*, jsmntok_t*, tree_node*, char*);

it take json string, jsmntok_t array(api json_parse() output), root address of json tree (api json_parse() output), and a json evaluation path as input parameters, it will return an index in jsmntok_t array.
suppose there is an json string like:	`{"name" : "mike", "phones" : [123, 456], "details" : {"job" : "student", "habbit" : ["computer games", "play guitar"]}}`, you can fetch `name` and `phones` and `job` and `habbit` like below:

	jsmn_query_string(json_string, jsmntok_t_array, tree_node_ptr, "name")
	jsmn_query_array(json_string, jsmntok_t_array, tree_node_ptr, "phones")
	jsmn_query_string(json_string, jsmntok_t_array, tree_node_ptr, "details.job")
	jsmn_query_array(json_string, jsmntok_t_array, tree_node_ptr, "details.habbit")

as you can see, the json evaluation path is separated by `.`

Example
-------
There is an example in example/cnn/example_cnn.json, which is an simple cnn structure json, when you run above build steps, you will get a elf `example_cnn` in build, just try and run.

[1]: https://github.com/zserge/jsmn.git
