#include <stdio.h>

int main(){
    int a, b[11], d, c, cM, cM2, impedido;
    scanf("%d %d", &a, &d);
    while(a){
        cM = 999999;
        cM2 = 999999;
        for(int i = 0; i < a; i++){
            scanf("%d", &b[i]);
        }
        while(d--){
            scanf("%d", &c);
            if(c < cM){
                cM2 = cM;
                cM = c;
            }
            else if(c < cM2){
                cM2 = c;
            }
        }
        impedido = 0;
        for(int i = 0; i < a; i++){
            if(b[i] < cM2){
                impedido++;
                break;
            }
        }
        if(impedido){
            printf("Y\n");
        }
        else{
            printf("N\n");
        }
        scanf("%d %d", &a, &d);
    }
    return 0;
}
