#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    uint64_t wh;
    int hour;
    uint64_t rate=225;
    unsigned int peak_percent=20;
    printf("Enter energy (Wh) and hour (0-23): ");
    if(scanf("%" SCNu64 "%d",&wh,&hour)!=2||hour<0||hour>23){
        printf("Invalid input\n");
        return 1;
    }
    if(wh>(UINT64_MAX-500)/rate){
        printf("Energy amount too large\n");
        return 1;
    }
    uint64_t base=(wh*rate+500)/1000;
    uint64_t total=base;
    if(hour>=18&&hour<22){
        uint64_t multiplier=100+peak_percent;
        if(base>(UINT64_MAX-50)/multiplier){
            printf("Peak charge too large\n");
            return 1;
        }
        total=(base*multiplier+50)/100;
    }
    printf("Base charge: Rs %" PRIu64 ".%02" PRIu64 "\n",base/100,base%100);
    printf("Final charge: Rs %" PRIu64 ".%02" PRIu64 "\n",total/100,total%100);
    return 0;
}
