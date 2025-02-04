#include <stdio.h>

int main(){
    int hi, mi, hf, mf, ht, mt;
    scanf("%d %d %d %d", &hi, &mi, &hf, &mf);
    ht = hf - hi;
    if(mi> mf){
        ht--;
    }
    mt = mf - mi;
    while(mt < 0){
        mt+=60;
    }
    while(ht < 0){
        ht+=24;
    }
    if(ht == 0 && mt == 0){
        ht = 24;
    }
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", ht, mt);
    return 0;
}
