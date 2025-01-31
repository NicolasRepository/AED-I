#include <stdio.h>

float acimaMedia(int n){
    float alunos[n], media, total = 0;
    for(int i = 0; i < n; i++){
        scanf("%f", &alunos[i]);
        total += alunos[i];
    }
    media = total/n;
    total = 0;
    for(int i = 0; i < n; i++){
        if(alunos[i] > media){
            total++;
        }
    }
    media = total/n;
    return media * 100;
}

int main(){
    int c, n;
    float media;
    scanf("%d", &c);
    for(int i = 0; i < c; i++){
        scanf("%d", &n);
        media = acimaMedia(n);
        printf("%.3f%%\n", media);
    }
    return 0;
}
