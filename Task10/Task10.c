#include <stdio.h>
int main(void) {
    const int counts[]={4000,60000,800000};
    for (int k=0;k<3;k++) {
        int n=counts[k];
        long long exact=(long long)n*16250LL; /* Rs 162.50 in paise */
        float total=0.0f;
        for (int i=0;i<n;i++) total+=162.50f;
        printf("n=%d paise=%lld rupees=%.2f float=%.2f diff=%.6f\n",
               n,exact,exact/100.0,(double)total,
               (double)total-(double)exact/100.0);
    }
    return 0;
