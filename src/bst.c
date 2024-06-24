#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

Node *bst_create(Node *parent, char *key, int value)
{
    Node *bst;
    if ((bst = (Node *)malloc(sizeof(Node))) == NULL)
    {
        printf("Erro alocando BST.\n");
        exit(EXIT_FAILURE);
    }

    strncpy(bst->key, key, BUFF_SZ);
    bst->value = value;
    bst->parent = parent;
    bst->left = NULL;
    bst->right = NULL;

    return bst;
}

bool bst_insert(Node *bst, char *key, int value)
{
    if (strcmp(key, bst->key) == 0)
    {
        bst->value += value;
        return true;
    }

    if (strcmp(key, bst->key) < 0)
    {
        if (bst->left == NULL)
        {
            bst->left = bst_create(bst, key, value);
            return true;
        }

        return bst_insert(bst->left, key, value);
    }

    if (strcmp(key, bst->key) > 0)
    {
        if (bst->right == NULL)
        {
            bst->right = bst_create(bst, key, value);
            return true;
        }

        return bst_insert(bst->right, key, value);
    }

    return false;
}

Node *bst_fetch(Node *bst, char *key)
{
    if (bst == NULL)
        return NULL;

    if (strcmp(key, bst->key) == 0)
        return bst;

    if (strcmp(key, bst->key) < 0)
        return bst_fetch(bst->left, key);

    if (strcmp(key, bst->key) > 0)
        return bst_fetch(bst->right, key);
}

void bst_delete(Node *bst, char *key)
{
    Node *match = bst_fetch(bst, key);

    // If it's a leaf
    if (match->left == NULL && match->right == NULL)
    {
        if (match->parent->left == match)
            match->parent->left = NULL;

        if (match->parent->right == match)
            match->parent->right = NULL;

        free(match);
        return;
    }

    // If has child node to left
    if (match->right == NULL)
    {
        if (match->parent->left == match)
            match->parent->left = match->left;

        if (match->parent->right == match)
            match->parent->right = match->left;

        free(match);
        return;
    }

    // If has child node to left
    if (match->left == NULL)
    {
        if (match->parent->left == match)
            match->parent->left = match->right;

        if (match->parent->right == match)
            match->parent->right = match->right;

        free(match);
        return;
    }

    // If has two children

    // TODO: finish this :(
}

void dfs_count(Node *bst, int *count)
{
    if (bst == NULL)
        return;

    *count++;
    dfs_count(bst->left, count);
    dfs_count(bst->right, count);
}

void dfs_value_count(Node *bst, int *count)
{
    if (bst == NULL)
        return;

    *count += bst->value;
    dfs_count(bst->left, count);
    dfs_count(bst->right, count);
}

/* Retorna o numero total de produtos (nao as quantidades) */
int bst_count(Node *bst)
{
    int count = 0;
    dfs_count(bst, &count);

    return count;
}
/* Retorna a soma total de todas as quantidades de produtos */
int bst_value_count(Node *bst)
{
    int count = 0;
    dfs_value_count(bst, &count);

    return count;
}

void bst_show(Node *bst)
{
    /* For alphabetic order we need to use inorder */
    if (bst == NULL)
        return;

    bst_show(bst->left);
    printf("%s %d\n", bst->key, bst->value);
    bst_show(bst->right);
}

void bst_show_over(Node *bst, int value)
{
    if (bst == NULL)
        return;

    bst_show_over(bst->left, value);

    if (bst->value > value)
        printf("%s %d\n", bst->key, bst->value);

    bst_show_over(bst->right, value);
}

void bst_show_below(Node *bst, int value)
{
    if (bst == NULL)
        return;

    bst_show_below(bst->left, value);

    if (bst->value < value)
        printf("%s %d\n", bst->key, bst->value);

    bst_show_below(bst->right, value);
}

void bst_show_preorder(Node *bst)
{
    if (bst == NULL)
        return;

    printf("%s %d\n", bst->key, bst->value);
    bst_show(bst->left);
    bst_show(bst->right);
}