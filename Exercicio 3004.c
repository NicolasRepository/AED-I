#include <stdio.h>
 
int main(){
    int n, x1, x2, y1, y2;
    scanf("%d", &n);
    while(n--){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if((x1 < x2 && y1 < y2) || (y1 < x2 && x1 < y2)){
            printf("S\n");
        }
        else{
            printf("N\n");
        }
    }
    return 0;
}
