#include <stdio.h>
 
int main(){
    int n, i;
    float c;
    scanf("%d", &n);
    while(n--){
        i = 0;
        scanf("%f", &c);
        while(c > 1){
            i++;
            c /= 2;
        }
        printf("%d dias\n", i);
    }
    return 0;
}
