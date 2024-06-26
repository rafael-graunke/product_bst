#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void print_menu(void)
{
    printf("### Produtos ###\n\n 1 - Insere Produto\n 2 - Busca Produto\n 3 - Remove Produto\n 4 - Total Produtos\n 5 - Quantidade Total Produtos\n ");
    printf("6 - Exibe Produtos Total\n 7 - Exite Produtos por Letra\n 8 - Exibe por Quantidade Acima\n 9 - Exibe por Quantidade Abaixo\n 10 - Percuso Prefixada\n ");
    printf("0 - Sair\n");
}

int main(void)
{
    int option = -1;
    Node *bst = NULL;
    int value;
    char name[BUFF_SZ];
    int count;
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
            if (bst == NULL)
            {
                bst = bst_create(NULL, name, value);
                break;
            }
            bst_insert(bst, name, value);
            break;
        case 2:
            if (bst == NULL)
            {
                printf("Nenhum Produto Registrado.\n");
                break;
            }
            printf("Busca Produto:\n");
            printf("Produto: ");
            scanf("%s", name);
            printf("\n");
            bst_fetch_print(bst, name);
            break;
        case 3:
            if (bst == NULL)
            {
                printf("Nenhum Produto Registrado.\n");
                break;
            }
            printf("Deletar Produto:\n");
            printf("Produto: ");
            scanf("%s", name);
            printf("\n");
            Node *match = bst_fetch(bst, name);
            /*
                Since variables "references" are just a copy of the pointer,
                if the matched node is the root, we have to free it and set it
                as NULL from here :(.
            */
            if (match->left == NULL && match->right == NULL && match->parent == NULL)
            {
                free(bst);
                bst = NULL;
                break;
            }
            bst_delete(match);
            break;
        case 4:
            if (bst == NULL)
            {
                printf("Nenhum Produto Registrado.\n");
                break;
            }
            count = bst_count(bst);
            printf("Total de Produtos:\n");
            printf("%d\n", count);
            break;
        case 5:
            if (bst == NULL)
            {
                printf("Nenhum Produto Registrado.\n");
                break;
            }
            count = bst_value_count(bst);
            printf("Quantidade Total de Produtos:\n");
            printf("%d\n", count);
            break;
        case 6:
            if (bst == NULL)
            {
                printf("Nenhum Produto Registrado.\n");
                break;
            }
            printf("Exibe Produtos Total:\n");
            bst_show(bst);
            break;
        case 7:
            if (bst == NULL)
            {
                printf("Nenhum Produto Registrado.\n");
                break;
            }
            printf("Exite Produtos por Letra:\n");
            printf("Letra:\n");
            char letter = getchar();
            bst_show_by_letter(bst, letter);
            break;
        case 8:
            if (bst == NULL)
            {
                printf("Nenhum Produto Registrado.\n");
                break;
            }
            printf("Exibe por Quantidade Abaixo:\n");
            printf("Quantidade:\n");
            scanf("%d", &value);
            bst_show_over(bst, value);
            break;
            break;
        case 9:
            if (bst == NULL)
            {
                printf("Nenhum Produto Registrado.\n");
                break;
            }
            printf("Exibe por Quantidade Acima:\n");
            printf("Quantidade:\n");
            scanf("%d", &value);
            bst_show_below(bst, value);
            break;
            break;
        case 10:
            if (bst == NULL)
            {
                printf("Nenhum Produto Registrado.\n");
                break;
            }
            printf("Percuso Prefixada:\n");
            bst_show_preorder(bst);
            break;
        }
    }

    return EXIT_SUCCESS;
}