#include <stdio.h>

int mdc(int a, int b){
    while(b){
        int aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

int main(){
    int n, f1, f2, num;
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &f1, &f2);
        num = mdc(f1, f2);
        printf("%d\n", num);
    }
    return 0;
}
