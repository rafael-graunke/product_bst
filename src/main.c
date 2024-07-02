#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bst.h"

void print_menu(void)
{
    printf("### Produtos ###\n\n 1 - Insere Produto\n 2 - Busca Produto\n 3 - Remove Produto\n 4 - Total Produtos\n 5 - Quantidade Total Produtos\n ");
    printf("6 - Exibe Produtos Total\n 7 - Exite Produtos por Letra\n 8 - Exibe por Quantidade Abaixo\n 9 - Exibe por Quantidade Acima\n 10 - Percuso Prefixada\n ");
    printf("0 - Sair\n");
}

int get_key(char c)
{
    return toupper(c) - 'A';
}

int main(void)
{
    int key, count, option = -1;
    char letter;
    Node *bst[26];

    for (int i = 0; i < 26; i++)
        bst[i] = NULL;

    int value;
    char name[BUFF_SZ];
    while (option != 0)
    {
        print_menu();
        scanf("%d", &option);
        getchar();
        switch (option)
        {
        case 1:
            printf("Produto: ");
            scanf("%s", name);
            printf("\nQuantidade: ");
            scanf("%d", &value);
            key = get_key(name[0]);
            if (bst[key] == NULL)
            {
                bst[key] = bst_create(NULL, name, value);
                break;
            }
            bst_insert(bst[key], name, value);
            break;
        case 2:
            printf("Busca Produto:\n");
            printf("Produto: ");
            scanf("%s", name);
            printf("\n");
            key = get_key(name[0]);
            if (bst[key] != NULL)
                bst_fetch_print(bst[key], name);
            break;
        case 3:
            printf("Deletar Produto:\n");
            printf("Produto: ");
            scanf("%s", name);
            printf("\n");
            key = get_key(name[0]);
            if (bst[key] != NULL)
            {
                Node *match = bst_fetch(bst[key], name);
                /*
                    Since variables "references" are just a copy of the pointer,
                    if the matched node is the root, we have to free it and set it
                    as NULL from here :(.
                */
                if (match->left == NULL && match->right == NULL && match->parent == NULL)
                {
                    free(bst[key]);
                    bst[key] = NULL;
                    break;
                }
                bst_delete(match);
            }
            break;
        case 4:
            count = 0;
            for (int i = 0; i < 26; i++)
                count += bst_count(bst[i]);
            printf("Total de Produtos:\n");
            printf("%d\n", count);
            break;
        case 5:
            count = 0;
            for (int i = 0; i < 26; i++)
                count += bst_value_count(bst[i]);
            printf("Quantidade Total de Produtos:\n");
            printf("%d\n", count);
            break;
        case 6:
            printf("Exibe Produtos Total:\n");
            for (int i = 0; i < 26; i++)
                bst_show(bst[i]);
            break;
        case 7:
            printf("Exite Produtos por Letra:\n");
            printf("Letra:\n");
            letter = getchar();
            getchar(); // Clear \n
            key = get_key(name[0]);
            if (bst[key] == NULL)
            {
                printf("Nenhum Produto Registrado.\n");
                break;
            }
            bst_show_by_letter(bst[key], letter);
            break;
        case 8:
            printf("Exibe por Quantidade Abaixo:\n");
            printf("Quantidade:\n");
            scanf("%d", &value);
            for (int i = 0; i < 26; i++)
                bst_show_below(bst[i], value);
            break;
            break;
        case 9:
            printf("Exibe por Quantidade Acima:\n");
            printf("Quantidade:\n");
            scanf("%d", &value);
            for (int i = 0; i < 26; i++)
                bst_show_over(bst[i], value);
            break;
            break;
        case 10:
            printf("Percuso Prefixada:\n");
            printf("Letra:\n");
            letter = getchar();
            getchar(); // Clear \n
            key = get_key(letter);
            if (bst[key] == NULL)
            {
                printf("Nenhum Produto Registrado.\n");
                break;
            }
            bst_show_preorder(bst[key]);
            break;
        }
    }

    return EXIT_SUCCESS;
}