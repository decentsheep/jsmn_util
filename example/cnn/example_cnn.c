#include <stdlib.h>
#include <stdio.h>
#include "jsmn_util.h"

int main() {
    int r;
    jsmntok_t* t;
    tree_node* root_tree;

    FILE* fp = fopen("example_cnn.json", "r");
    if (fp == NULL) {
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    rewind(fp);

    char *json_buf = malloc(sizeof(char) * fsize);
    fread(json_buf, sizeof(char), fsize, fp);

    r = json_parse(json_buf, fsize, &t, &root_tree);

    int res = 0;
    printf("query_string: reshape_0.type ...... \n");
    res = jsmn_query_string(json_buf, t, root_tree, "reshape_0.type");
    printf("res: %d\n", res);
    printf("reshape_0.type:\n%.*s\n\n", t[res].end - t[res].start, &json_buf[t[res].start]);


    printf("query_primitive: conv2d_0.param.knl_h ...... \n");
    res = jsmn_query_primitive(json_buf, t, root_tree, "conv2d_0.param.knl_h");
    printf("res: %d\n", res);
    printf("query conv2d_0.param.knl_h:\n%.*s\n\n", t[res].end - t[res].start, &json_buf[t[res].start]);

    printf("query_array: conv2d_1.param ...... \n");
    res = jsmn_query_array(json_buf, t, root_tree, "conv2d_1.param");
    printf("res: %d\n", res);
    printf("query conv2d_1.param:\n%.*s\n\n", t[res].end - t[res].start, &json_buf[t[res].start]);

    printf("query_object: conv2d_2 ...... \n");
    res = jsmn_query_object(json_buf, t, root_tree, "conv2d_2");
    printf("res: %d\n", res);
    printf("query conv2d_2:\n%.*s\n\n", t[res].end - t[res].start, &json_buf[t[res].start]);

    fclose(fp);
    free(json_buf);
    free(t);
    free(root_tree);
    return 0;
}

