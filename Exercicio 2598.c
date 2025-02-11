#include <stdio.h>
 
int main(){
    int c, n, m, radares;
    scanf("%d", &c);
    while(c--){
        scanf("%d %d", &n, &m);
        radares = n/m;
        if(n % m != 0){
            radares++;
        }
        printf("%d\n", radares);
    }
    return 0;
}
