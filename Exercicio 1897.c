#include <stdio.h>

int min(int n, int m, int mini){
    if(n*2 == m || n*3 == m || n/2 == m || n/3 == m || n+7 == m || n-7 == m || mini > 10){
        return mini;
    }
    else{
        int totais[6], menor;
        totais[0] = min(n*2, m, mini+1);
        totais[1] = min(n*3, m, mini+1);
        totais[2] = min(n/2, m, mini+1);
        totais[3] = min(n/3, m, mini+1);
        totais[4] = min(n+7, m, mini+1);
        totais[5] = min(n-7, m, mini+1);
        menor = totais[0];
        for(int i = 1; i < 6; i++){
            if(totais[i] < menor){
                menor = totais[i];
            }
        }
        return menor;
    }
}

int main() {
    int n, m, total;
    scanf("%d %d", &n, &m);
    total = min(n, m, 1);
    printf("%d\n", total);
    return 0;
}
