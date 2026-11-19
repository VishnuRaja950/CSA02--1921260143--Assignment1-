#include <stdio.h>

int main(void)
{
    int a = 5, b = 2;
    double result1 = a / b;
    float x = 0.1f, y = 0.2f;
    float result2 = x + y;
    double rupees = 162.505;
    long long paise = (long long)(rupees * 100 + 0.5);
    printf("Integer division: %.2f\n", result1);
    printf("Float addition: %.9f\n", result2);
    printf("Converted amount: %lld paise\n", paise);
    double correct = (double)a / b;
    printf("Correct division: %.2f\n", correct);
    return 0;
