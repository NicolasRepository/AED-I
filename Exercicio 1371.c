#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d", &n);
    while(n){
        int limite = (int)sqrt(n);
        for(int i = 1; i <= limite; i++){
            if(i > 1){
                printf(" ");
            }
            printf("%d", i * i);
        }
        printf("\n");
        scanf("%d", &n);
    }
    return 0;
}
