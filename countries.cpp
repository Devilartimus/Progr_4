#pragma once
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "get.cpp"

typedef struct
{
    char m_name[20];
}City;

typedef struct
{
    char c_name[20];
    City c_city[9];
}Country;

void createCities(Country *countriesCIS)
{
    char s_cities[9][9][20]={
                                        { "Baku", "Ganja","Sumgait","Lankaran","Mingechevir","Moldavia","Shirvan","Nakhichevan","Shamkir" },
                                        { "Yerevan", "Gyumri","Vagharshapat","Kapan","Vanadzor","Hrazdan","Alaverdi","Stepanavan","Dilijan" },
                                        { "Minsk", "Brest","Grodno","Gomel","Vitebsk","Mogilev","Bobruisk","Baranovichi","Novopolotsk" },
                                        { "Almaty", "NurSultan","Shymkent","Aktobe","Karaganda","Taraz","Pavlodar","Ust-Kamenogorsk","Semey" },
                                        { "Bishkek","Osh","Jalal-Abad","Karakol","Kyzyl-kiya","Uzgen","Balykchy","Kara-Balta","Naryn" },
                                        { "Balti", "Bendery","Bessarabka","Biruinets","Brichany","Bykovets","Vadul-lui-Vode","Vatra","Vulcanesti" },
                                        { "Moscow", "Saint Petersburg","Novosibirsk","Yekaterinburg","Kazan","Nizhny Novgorod","Chelyabinsk","Samara","Tomsk" },
                                        { "Bokhtar", "Buston","Vakhdat","Hissar","Guliston","Dushanbe","Istaravshan","Istiqlol","Isfara" },
                                        { "Tashkent", "Namangan","Samarkand","Andijan","Nukus","Bukhara","Karshi","Fergana","Kokand" }
                                };
    for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                strcpy(((countriesCIS+i)->c_city+j)->m_name, s_cities[i][j]);
}

void printTable(Country *countriesCIS)
{
    printf("\n\t____________________________________"
           "\n\t|     Country     |      Town      |"
           "\n\t|**********************************|");
    for (int i=0; i<9; i++)
    {
        printf("\n\t|%15s|%-16s|",(countriesCIS+i)->c_name, ((countriesCIS+i)->c_city)->m_name);
        for (int j=0; j<9; j++)
            printf("\n\t|\t\t|%-16s|", ((countriesCIS+i)->c_city+j)->m_name);
        printf("\n\t|________________________________|");
    }
}

void printCities(Country *country)
{
    printf("\n\t____________________________________"
           "\n\t|%15s|%-16s|", country->c_name, (country->c_city)->m_name);
    for (int j=1; j<9; j++)
        printf("\n\t||\t\t |%-17s|", (country->c_city+j)->m_name);
    printf("\n\t|__________________________________|");
}

void countries()
{
    Country countriesCIS[9];
    char s_country[9][15]={ "Azerbaijan", "Armenia","Belarus","Kazakhstan","Kyrgyzstan","Moldova","Russia","Tajikistan","Uzbekistan" };

    for(int i=0; i<9; i++)
        strcpy((countriesCIS+i)->c_name, s_country[i]);

    createCities(countriesCIS);

    int choice=0;
    printf("\n\tThe CIS countries are stored in the database. Want to enter the country manually - (1),"
           "\n\tor view the entire list of countries and corresponding cities - (2)?"
           "\n\tYour choice: ");
    getInt(&choice, 1, 2);

    if (choice==2)
        printTable(countriesCIS);
    else
    {
        while (1)
        {
            char country[15];
            bool flag=true;
            printf("\n\tEnter name of the country: \n\t");
            gets(country);
            for (int i=0; i<9; i++)
                if (!strcmp(s_country[i], country))
                {
                    printCities(countriesCIS+i);
                    flag=false;
                    break;
                }
            if (flag)
            {
                printf("\n\t Error. This country is not in the database! Try another country.\n");
                continue;
            }
            else
                break;
            }
        }
    }
