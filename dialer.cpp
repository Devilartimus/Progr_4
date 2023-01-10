#pragma once
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include "get.cpp"

typedef struct
{
    char m_name[20];
    char m_phoneNumber[20];
}PhoneBook;

void printDialer(const PhoneBook *person, const int count)
{
    printf("\n\t______________________________________"
           "\n\t|     Surname     |  Phone Number  |"
           "\n\t|************************************|");
    for (int i=0; i<count; i++)
        printf("\n\t|%17s|%18s|"
               "\n\t|____________________________________|",
               (person+i)->m_name, (person+i)->m_phoneNumber);
}

void dialer()
{
    char s_name[10][20]={ "1 person", "2 person", "3 person", "4 person", "5 person",
                          "6 person", "7 person", "8 person", "9 person", "10 person" };
    char s_numbers[10][20]={ "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
    int count=10;
    PhoneBook List[50];
    for (int i=0; i<count; i++)
    {
        strcpy((List+i)->m_name, s_name[i]);
        strcpy((List+i)->m_phoneNumber, s_numbers[i]);
    }

    printf("\n\tThe database stores phone numbers and surnames of who they belong to."
           "\n\tDo you want to output a phone number by a given surname - (1),"
           "\n\tprint the last name by the specified phone number - (2)"
           "\n\tview the entire list - (3)"
           "\n\tenter a new entry in the phone book - (4)");

    int choice=0;
    while (1)
    {
        printf("\n\n\tYour choice: ");
        getInt(&choice, 1, 4);

        while (1)
        {
            bool flag;
            switch (choice)
            {
            case 1://вывести номер телефона по заданной фамилии
                printf("\n\tEnter Surname: ");
                char name[20];
                gets(name);
                flag=true;

                for(int i=0; i<count; i++)
                    if (!strcmp((List+i)->m_name, name))
                    {
                        printf("\n\tPhone number: %s", (List+i)->m_phoneNumber);
                        flag=false;
                        break;
                    }

                if (flag)
                {
                   printf("\n\tThis surname is not in the database. Try again.\n");
                   continue;
                }
                else
                    break;

            case 2://вывести фамилию по заданному номеру телефона
                printf("\n\tEnter phone number: ");
                char number[20];
                gets(number);
                flag=true;

                for (int i=0; i<count; i++)
                    if (!strcmp((List+i)->m_phoneNumber, number))
                    {
                        printf("\n\tSurname: %s", (List+i)->m_name);
                        flag=false;
                        break;
                    }

                if (flag)
                {
                    printf("\n\tThis phone number is not in the database. Try again\n");
                    continue;
                }
                else
                    break;

            case 3: //просмотреть весь список
                printDialer(List, count);
                break;

            case 4: //ввод новой записи в тел.книгу
                printf("\n\tSurname: ");
                gets((List+count)->m_name);
                printf("\n\tPhone number: ");
                gets((List+count)->m_phoneNumber);

                flag=false;
                for (int i=0; i<count; i++)
                    if (!strcmp((List+count)->m_name, (List+i)->m_name)
                            && !strcmp((List+count)->m_phoneNumber, (List+i)->m_phoneNumber))
                    {
                        printf("\n\tThere is already such a record! Try again.");
                        count--;
                        flag=true;
                    }
                else
                        printf("\n\tThe entry has been entered successfully.");
                count++;
                break;

            default:
                printf("\n\tError. Something wrong...");
            }
            break;
        }

        printf("\n\tDo you want to continue? (Yes/No)");
        char ans[10];
        while (gets(ans) && strcmp(ans, "Yes") && strcmp(ans, "No"))
            printf("\n\tError! Enter corrct answer.\n\t\t\t");

        if (!strcmp(ans, "Yes"))
            continue;
        else
            break;
    }
}
