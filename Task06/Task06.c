#include <stdio.h>

int main(void) {
    char household[20];
    unsigned int units;
    long long paise;
    printf("Household ID: ");
    if (scanf("%19s",household)!=1) { puts("Invalid ID"); return 1; }
    printf("Units: ");
    if (scanf("%u",&units)!=1) { puts("Invalid units"); return 1; }
    paise=5000LL;
    if (units>100) {
        unsigned int n=units<200?units-100:100;
        paise+=(long long)n*225LL;
    }
    if (units>200) paise+=(long long)(units-200)*450LL;
    printf("House %s: Rs %lld.%02lld\n",household,paise/100,paise%100);
    return 0;
}
