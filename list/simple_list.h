#ifndef SIMPLE_LIST_H
#define SIMPLE_LIST_H

typedef struct node_s
{
    int data;
    struct node_head_s *hd;
    struct node_s *next;
}node_t;

typedef struct node_head_s
{
    size_t len;
    node_t *list[0];
}node_head_t;

node_head_t * create();
size_t list_length(node_head_t *head);
int insert(node_head_t *head,node_t *p,int index);
int lpush(node_head_t *head,node_t *p);
int rpush(node_head_t *head,node_t *p);

#endif