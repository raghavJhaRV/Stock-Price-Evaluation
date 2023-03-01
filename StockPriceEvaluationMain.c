/*
    Great Author :- Raghav Nareshkumar Jha 
    Date :- 26/06/2023
    File :- StockPriceEvaluationMain.c
*/

#include "stockPriceEvaluation.c"

int main(void) // main function
{   
    struct Company info[NO_COMPANIES];
    infocomp(info, NO_COMPANIES);
    
    // input
    
    for (int i = 0; i < NO_COMPANIES; i++) 
    {
        printf("Enter the company name: ");
        scanf_s("%[^\n]s", info[i].compName, MAX_STR);
        utilClearInputBuffer();
        printf("Enter %s's stock symbol: ", info[i].compName);
        scanf_s("%[^\n]s", info[i].compSym, MAX_STR);
        printf("Enter %s's current stock price: ", info[i].compName);
        scanf("%f", &info[i].sharePrice);
        printf("Enter %s's annual dividend per share: ", info[i].compName);
        scanf("%f", &info[i].dividend);
        printf("\n");
        utilClearInputBuffer();
    }

    dividendyield(info, NO_COMPANIES);
    valuation(info, NO_COMPANIES);

    //Output

    printf("%21s %6s %1s %4s %6s %12s\n", "Company", "SYMBOL", "PRICE", "DIV", "YIELD", "VALUATION"); // print the header

    for (int i = 0; i < NO_COMPANIES; i++) // print the data
    {
        printf("%21s %6s %5.2f %5.3f %5.3f %12s ", info[i].compName, info[i].compSym, info[i].sharePrice, info[i].dividend, info[i].yield, info[i].valuation);
        printf("\n");
    }

    return 0;
}