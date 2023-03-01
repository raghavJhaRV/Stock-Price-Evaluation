/*
    Great Author :- Raghav Nareshkumar Jha 
    Date :- 25/06/2023
    File :- StockPriceEvaluation.c
*/

#include <stdio.h>
#include <string.h>
#include "StockPriceEvaluation.h"

void infocomp(struct Company info[], int size) // initialize the array
{
    for (int i = 0; i < size; i++) // don't pass size just use NO_Companies const
    {
        info[i].compName[0] = '\0';
        info[i].compSym[0] = '\0';
        info[i].valuation[0] = '\0';
        info[i].sharePrice = 0;
        info[i].yield = 0;
        info[i].dividend = 0;
    }
}

void dividendyield(struct Company info[], int size) // calculate the dividend yield
{

    for (int i = 0; i < NO_COMPANIES; i++)
    {
        if (info[i].sharePrice > 0 && info[i].dividend < info[i].sharePrice)
        {
            info[i].yield = (info[i].dividend / info[i].sharePrice) * 100;
            // info[i].yield *= 100;
        }
    }

    
}

void valuation(struct Company info[], int size) // calculate the valuation
{
    for (int i = 0; i < NO_COMPANIES; i++)  // don't pass size just use NO_Companies const
    {

        if (info[i].yield > VALUATION)
        {
            strcpy(info[i].valuation, "UNDER VALUED"); 
        }

        else if (info[i].yield < VALUATION)
        {
            strcpy(info[i].valuation, "OVER VALUED");
        }

        else if (info[i].yield == VALUATION)
        {
            strcpy(info[i].valuation, "PERFECTLY VALUED");
        }
    }
}

void utilClearInputBuffer(void) // clear the input buffer
{
    char c;
    do
    {
        c = getchar(); // get the character
    } while (c != '^' && c != '\n');
}