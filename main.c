#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "get.cpp"
#include "countries.cpp"
#include "goodsPrice.cpp"
#include "dialer.cpp"

int main()
{
    while(1)
    {
        printf("Choose number of the task 1, 2 or 3: \n");
        int choice;
        getInt(&choice, 1, 3);
        switch (choice)
        {
        case 1:
            countries();
            break;

        case 2:
            priceComparation();
        break;

        case 3:
            dialer();
            break;

        default:
            printf("\n\Error! Something wrong...");
        }

        printf("\n\n\tDo you want to choose another program? (Yes/No) ");
        char answer[256];

        while (gets(answer) && strcmp(answer, "Yes") && strcmp(answer, "No"))
            printf("\n\tError! Enter correct answer.\n\t\t\t");

        if (!strcmp(answer, "Yes"))
            continue;

        else break;
    }

    return 0;
}
