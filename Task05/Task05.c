#include <stdio.h>
#define SLAB1_UNITS 100
#define SLAB2_UNITS 200
#define RATE2_PAISE 225LL
#define RATE3_PAISE 450LL
#define FIXED_CHARGE_PAISE 5000LL
long long compute_bill(int units)
{
    if (units < 0)
        return -1;
    long long p = FIXED_CHARGE_PAISE;
    if (units > SLAB1_UNITS) {
        int n = units < SLAB2_UNITS
                ? units - SLAB1_UNITS : 100;
        p += (long long)n * RATE2_PAISE;
    }
    if (units > SLAB2_UNITS) {
        p += (long long)(units - SLAB2_UNITS)
             * RATE3_PAISE;
    }
    return p;
}
int main(void)
{
    int units = 150;
#ifdef DEBUG
    printf("DEBUG: units=%d, fixed=%lld\n",
           units, (long long)FIXED_CHARGE_PAISE);
#endif
    long long p = compute_bill(units);
    printf("Bill = Rs %lld.%02lld\n", p / 100, p % 100);
    return 0;
}
