#include <stdio.h>

int josephus(int n, int k){
    int sobrevivente = 0;
    for(int i = 2; i <= n; i++){
        sobrevivente = (sobrevivente + k) % i;
    }
    return sobrevivente + 1;
}

int main(){
    int nc, n, k;
    scanf("%d", &nc);
    for(int i = 1; i <= nc; i++){
        scanf("%d %d", &n, &k);
        printf("Case %d: %d\n", i, josephus(n, k));
    }
    return 0;
}
