#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "simple_list.h"

int main()
{
    printf("size %d %d \n",sizeof(node_head_t),sizeof(size_t));
    node_head_t *head = create();
    assert(head != NULL);
    if(!head)
    {
        printf("Oops: system error!\n");
        exit(-1);
    }
    printf("%d %d %d\n",sizeof(*head),head->len,sizeof(node_t));
    return 0;
}

node_head_t * create()
{
    char ch;
    node_head_t *head;
    head = (node_head_t *)malloc(sizeof(*head)+sizeof(node_t));
    node_t v1 ;
    v1.data = 100;
    v1.next = NULL;
    v1.hd = head;
    insert(head,&v1,2);
    assert(head != NULL);
    if(head)
    {
        head->len = 0 ;
    }
    return head;
}
size_t list_length(node_head_t *head)
{
    assert(head != NULL);
    if(head)
    {
        return head->len;
    }
    return 0;
}

int insert(node_head_t *head,node_t *p,int index)
{
    int i;
    node_t *pre;
    node_t *next;
    assert(head != NULL && p != NULL);

    if(head && p)
    {
        if(head->len < index)
        {
            return lpush(head,p);
        }
        pre = head->list;
        for(i=1;i<index;i++)
        {
            pre = pre->next;
        }
        next = pre->next;
        pre->next = p;
        p->next = next;
        head->len++ ;
        return index;

    }
    return -1;
}

int lpush(node_head_t *head,node_t *p)
{
    assert(head != NULL && p != NULL);
    node_t *next;
    node_t *pre;
    pre = head->list;
    next = pre->next;
    head->list[0] = p;
    p->next = next;
    head->len++;
    return 0;
}
