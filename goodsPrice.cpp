#pragma once
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "get.cpp"

typedef struct
{
    char m_name[50];
    int rub;
    int kop;
}Goods;

void priceComparation()
{
    Goods product[2];

    for (int i=0; i<2; i++)
    {
        printf("\n\tEnter the product name #%d ", i+1);
        gets((product+i)->m_name);

        printf("\n\t Enter the price of this product in rubles: ");
        for (bool flag = scanf("%d", &((product+i)->rub));
             flag==0||(product+i)->rub <1;)
        {
            printf("\n\tError! Try again\n\t\t\t");
            if(flag==0)
                scanf("%*s");
            flag = scanf("%d", &((product+i)->rub));
        }

        printf("\n\tEnter the price of this product in kopecks [1,99]: ");
        for (bool flag = scanf("%d", &((product+i)->kop));
             flag ==0 || (product+i)->kop <1 || (product+i)->kop >=100;)
        {
            printf("\n\tError! Try again.\n\t\t\t");
            if (flag==0)
                scanf("%*s");
            flag=scanf("%d", &((product+i)->kop));
        }
        getchar();
    }

    printf("\n\tThe most expensive product introduced is: "
           "%s", (product->rub*100+product->kop > (product+1)->rub*100+(product+1)->kop)
           ? product->m_name : (product+1)->m_name);
}
