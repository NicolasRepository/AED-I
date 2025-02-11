#include <stdio.h>
#include <stdlib.h>

int main(){
    int x1, y1, x2, y2, total;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    while(x1){
        if(x1 == x2 && y1 == y2){
            total = 0;
        }
        else if(x1 == x2 || y1 == y2 || (abs(x1 - x2) == abs(y1 - y2))){
            total = 1;
        }
        else{
            total = 2;
        }
        printf("%d\n", total);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    }
    return 0;
}
