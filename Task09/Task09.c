#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define METER_MAX 65535U
#define SLAB1 100U
#define SLAB2 200U
#define RATE2 225LL
#define RATE3 450LL
#define FIXED 5000LL
 
typedef unsigned short meter_t;
static unsigned int used_units(meter_t old, meter_t now) {
    return (unsigned int)(unsigned short)(now-old);
}
static long long energy_paise(unsigned int u) {
    long long p=0;
    if (u>SLAB1) {
        unsigned int n=u<SLAB2?u-SLAB1:SLAB2-SLAB1;
        p+=(long long)n*RATE2;
    }
    if (u>SLAB2) p+=(long long)(u-SLAB2)*RATE3;
    return p;
}
static long long bill_paise(unsigned int u) {
    return FIXED+energy_paise(u);
}
int main(void) {
    unsigned int oldv,newv,u;
    if (USHRT_MAX!=65535U) {
        fprintf(stderr,"This program requires a 16-bit unsigned short.\n");
        return 1;
    }
    printf("Enter previous and current meter readings (0..65535): ");
    if (scanf("%u%u",&oldv,&newv)!=2 || oldv>METER_MAX || newv>METER_MAX) {
        fprintf(stderr,"Invalid meter readings.\n"); return 1;
    }
    u=used_units((meter_t)oldv,(meter_t)newv);
    long long p=bill_paise(u);
    printf("Units consumed: %u\n",u);
    printf("Energy charge: Rs %lld.%02lld\n",energy_paise(u)/100,energy_paise(u)%100);
    printf("Fixed charge: Rs 50.00\n");
    printf("Total bill: Rs %lld.%02lld\n",p/100,p%100);
    return 0;
}
