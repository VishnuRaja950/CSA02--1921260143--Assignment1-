#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#define FIXED_CHARGE 5000LL
#define RATE2 225LL
#define RATE3 450LL
#define HOUSEHOLDS 800000LL
typedef unsigned short meter_t;
int main(void)
{
    long long units;
    long long energy_charge=0;
    long long total_bill;
    long long district_total;
    _Static_assert(USHRT_MAX==65535,"Meter must be 16-bit");
    printf("Enter electricity units: ");
    if(scanf("%lld",&units)!=1||units<0){
        printf("Invalid input\n");
        return 1;
    }
    if(units>100)
        energy_charge+=(units<200?units-100:100)*RATE2;
    if(units>200)
        energy_charge+=(units-200)*RATE3;
    total_bill=energy_charge+FIXED_CHARGE;
    district_total=total_bill*HOUSEHOLDS;
    printf("Energy charge: Rs %lld.%02lld\n",energy_charge/100,energy_charge%100);
    printf("Total bill: Rs %lld.%02lld\n",total_bill/100,total_bill%100);
    printf("District total for 800000 houses: Rs %lld.%02lld\n",district_total/100,district_total%100);
    return 0;
}
