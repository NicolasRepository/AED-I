#include <stdio.h>
 
int main(){
    int n, m, c, total, comeco, comeco2;
    scanf("%d %d %d", &n, &m, &c);
    while(n){
        total = 0;
        if(c){
            comeco = 0;
            comeco2 = 1;
        }
        else{
            comeco = 1;
            comeco2 = 2;
            for(int j = 1; j < m - 7; j+=2){
                total++;
            }
        }
        for(int i = comeco; i < n - 7; i+=2){
            for(int j = 0; j < m - 7; j+=2){
                total++;
            }
        }
        for(int i = comeco2; i < n - 7; i+=2){
            for(int j = 1; j < m - 7; j+=2){
                total++;
            }
        }
        printf("%d\n", total);
        scanf("%d %d %d", &n, &m, &c);
    }
    return 0;
}
