#include <stdio.h>
#include <math.h>

int main(){
    int t, w, h, x0, y0, nivel, cx, cy, pontos[4][2], distx, disty, dano, raio, pegou, arestax, arestay;
    double dist;
    char tipo[6];
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %d %d %d", &w, &h, &x0, &y0);
        getchar();
        scanf("%s", &tipo);
        scanf("%d %d %d", &nivel, &cx, &cy);
        getchar();
        pontos[0][0] = x0;
        pontos[0][1] = y0;
        pontos[1][0] = x0 + w;
        pontos[1][1] = y0;
        pontos[2][0] = x0 + w;
        pontos[2][1] = y0 + h;
        pontos[3][0] = x0;
        pontos[3][1] = y0 + h;
        if(tipo[0] == 'f'){
            dano = 200;
            if(nivel == 1){
                raio = 20;
            }
            else if(nivel == 2){
                raio = 30;
            }
            else{
                raio = 50;
            }
        }
        else if(tipo[0] == 'w'){
            dano = 300;
            if(nivel == 1){
                raio = 10;
            }
            else if(nivel == 2){
                raio = 25;
            }
            else{
                raio = 40;
            }
        }
        else if(tipo[0] == 'e'){
            dano = 400;
            if(nivel == 1){
                raio = 25;
            }
            else if(nivel == 2){
                raio = 55;
            }
            else{
                raio = 70;
            }
        }
        else{
            dano = 100;
            if(nivel == 1){
                raio = 18;
            }
            else if(nivel == 2){
                raio = 38;
            }
            else{
                raio = 60;
            }
        }
        pegou = 0;
        if(pontos[0][0] <= cx && pontos[0][1] <= cy && pontos[3][0] >= cx && pontos[3][1] >= cy){
            pegou = 1;
        }
        else{
            for(int j = 0; j < 4; j++){
                distx = pontos[j][0] - cx;
                if(distx < 0){
                    distx*=-1;
                }
                disty = pontos[j][1] - cy;
                if(disty < 0){
                    disty*=-1;
                }
                dist = sqrt(distx*distx + disty*disty);
                if(dist <= raio){
                    pegou = 1;
                    break;
                }
            }
        }
        if(pegou){
            printf("%d\n", dano);
        }
        else{
            if(cx < x0){
                arestax = x0;
            }
            else if(cx > x0 + w){
                arestax = x0 + w;
            }
            else {
                arestax = cx;
            }
            if(cy < y0){
                arestay = y0;
            }
            else if(cy > y0 + h){
                arestay = y0 + h;
            }
            else {
                arestay = cy;
            }
            distx = arestax - cx;
            disty = arestay - cy;
            dist = sqrt(distx * distx + disty * disty);
            if(dist <= raio){
                pegou = 1;
                printf("%d\n", dano);
            }
            else{
                printf("0\n");
            }
        }
    }
    return 0;
}
