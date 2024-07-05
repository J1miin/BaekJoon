#include <stdio.h>
int main(void) {
    
    int n, i, j, cnt, sum, arr[100000] = {0};
 
    while (1) {
        cnt = 0, sum = 0;
        scanf("%d", &n);
        if (n == -1)
            return 0;
 
        for (i = 1, j = 0; i < n; ++i) {
            if (n % i == 0) { //i가 n의 약수라면
                arr[j++] = i;
                printf("%d",arr[j]);
                ++cnt;
                sum += i;
            }
        }
        
        if (n == sum) {
            printf("%d = %d", n, arr[0]);
            for (i = 1; i < cnt; ++i) {
                printf(" + %d", arr[i]);
            }
            printf("\n");
        }
        else
            printf("%d is NOT perfect.\n", n);
 
    }
 
    return 0;
}