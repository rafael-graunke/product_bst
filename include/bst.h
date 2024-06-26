#ifndef _BST_H_
#define _BST_H_

#include <stdbool.h>
#define BUFF_SZ 256

typedef struct s_node
{
    char key[BUFF_SZ];
    int value;
    struct s_node *parent;
    struct s_node *left;
    struct s_node *right;
} Node;

Node *bst_create(Node *parent, char *key, int value);
bool bst_insert(Node *bst, char *key, int value);
Node *bst_fetch(Node *bst, char *key);
void bst_delete(Node *bst);
/* Retorna o numero total de produtos (nao as quantidades) */
int bst_count(Node *bst);
/* Retorna a soma total de todas as quantidades de produtos */
int bst_value_count(Node *bst);
void bst_show_by_letter(Node *bst, char letter);
void bst_show(Node *bst);
void bst_show_over(Node *bst, int value);
void bst_show_below(Node *bst, int value);
void bst_show_preorder(Node *bst);
void bst_fetch_print(Node *bst, char *key);

#endif