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
    while (option != 0)
    {
        print_menu();
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            int value;
            char name[BUFF_SZ];
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
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        }
    }

    return EXIT_SUCCESS;
}