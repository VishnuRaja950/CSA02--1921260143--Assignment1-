#include <stdio.h>

int main(void)
{
    int units = 150;
    int fixed_charge = 5000;
    int amount;
    amount = fixed_charge + (units - 100) * 225;
    printf("Units consumed: %d\n", units);
    printf("Total bill: Rs %d.%02d\n",
           amount / 100, amount % 100);
    return 0;
}
