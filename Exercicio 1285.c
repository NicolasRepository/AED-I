#include <stdio.h>

int main(){
    int n, m, num, total, digitos[4], usado[10], k, status;
    while(scanf("%d %d", &n, &m) != EOF){
        total = 0;
        for(int i = n; i <= m; i++){
            for(int j = 0; j < 10; j++){
                usado[j] = 0;
            }
            num = i;
            k = 0;
            status = 1;
            for(int j = 0; num > 0; j++){
                digitos[j] = num % 10;
                if(usado[num % 10] && status){
                    status = 0;
                    break;
                }
                else{
                    usado[num % 10]++;
                }
                num /= 10;
                k++;
            }
            if(status){
                total++;
            }
        }
        printf("%d\n", total);
    }
    return 0;
}
