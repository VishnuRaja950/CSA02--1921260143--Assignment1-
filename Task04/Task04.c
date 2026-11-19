#include <stdio.h>
#define RUPEES_TO_PAISE(r) ((long long)(r) * 100LL)
#define SQUARE(x) ((x) * (x))
#define MAX_VALUE(a,b) (( (a) > (b) ) ? (a) : (b))
static inline long long square_fn(long long x) { return x*x; }
static inline int max_fn(int a,int b) { return a>b?a:b; }
int main(void) {
    int a=4, b=7, i=1, j=3;
    printf("square=%d\n",SQUARE(a+1));
    printf("max=%d\n",MAX_VALUE(i,j));
    printf("paise=%lld\n",RUPEES_TO_PAISE(12));
    printf("inline square=%lld inline max=%d\n",
           square_fn(5),max_fn(i,j));
    return 0;
}
