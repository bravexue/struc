#ifndef _SLIST_H
#define _SLIST_H

#include <stdio.h>
#include <stddef.h>
 
#define chain_get_node(mptr,s,m) ((s*)((char*)(mptr)-offsetof(s,m)))


typedef struct chain_single {
    struct chain_single *next;
} schain_t;


typedef struct slist {
     int len;
     struct chain_single *head;
} slist_t;

void slist_init(slist_t *plist);
void slist_destroy(slist_t *plist);

void slist_add_head(slist_t *plist, schain_t *pchain);
void slist_insert(slist_t *plist, int i, schain_t *pchain);
void slist_delete(slist_t *plist, int i);

int slist_len(slist_t list);
schain_t *slist_get_chain(slist_t list, int i);
void slist_travel(slist_t list, void (*visit)(schain_t *));

void slist_visit(schain_t *pschain);


typedef struct{
     int val;
     schain_t schain;
} slist_node_t;

#endif
