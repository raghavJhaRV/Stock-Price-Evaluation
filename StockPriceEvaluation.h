/*
    Great Author :- Raghav Nareshkumar Jha 
    Date :- 24/06/2023
    File :- StockPriceEvaluation.h
*/


#define MAX_STR 40
#define NO_COMPANIES 5
#define VALUATION  5.00

int scanf_s(const char *format, ...); // this is a function that is not in the standard library

struct Company //   struct Company info[NO_COMPANIES];
{
    char compName[MAX_STR];
    char compSym[MAX_STR];
    float sharePrice;
    float dividend;
    float yield;
    char valuation[MAX_STR];
};

void infocomp(struct Company info[], int size);
void dividendyield(struct Company info[], int size);
void valuation(struct Company info[], int size);
