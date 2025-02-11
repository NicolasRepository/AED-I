#include <stdio.h>
 
int main(){
    float tempo, s, v1, v2;;
    while(scanf("%f %f %f", &s, &v1, &v2) != EOF){
        if(v1 <= v2){
            printf("impossivel\n");
        }
        else{
            tempo = s/(v1-v2);
            printf("%.2f\n", tempo);
        }
    }
    return 0;
}
