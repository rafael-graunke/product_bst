#ifndef _STORE_H_
#define _STORE_H_

#include "bst.h"

typedef struct
{
    Node **indexes;
} Store;

Store *store_create(void);
bool store_insert(Store *store, char *product, int count);
Node *store_fetch(Store *store, char *product);
void store_delete(Store *store, char *product);

#endif