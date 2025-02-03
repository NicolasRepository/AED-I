#include <stdio.h>

int main(){
    int x, y, xx = 0, yy = 0, pri = 1, tembau = 0, visitado[100][100] = {};
    char ultimo = '>';
    scanf("%d", &x);
    scanf("%d", &y);
    char mapa[100][100];
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            scanf(" %c", &mapa[i][j]);
            if(mapa[i][j] == '*' && !tembau){
                tembau = 1;
            }
        }
    }
    if(!tembau){
        printf("!\n");
        return 0;
    }
    while(mapa[xx][yy] != '*' && (!visitado[xx][yy] || mapa[xx][yy] == '.')){
        visitado[xx][yy] = 1;
        if(mapa[xx][yy] == '.'){
            if(ultimo == '>'){
                yy++;
            }
            else if(ultimo == '<'){
                yy--;
            }
            else if(ultimo == '^'){
                xx--;
            }
            else if(ultimo == 'v'){
                xx++;
            }
        }
        else{
            ultimo = mapa[xx][yy];
            if(mapa[xx][yy] == '>'){
                yy++;
            }
            else if(mapa[xx][yy] == '<'){
                yy--;
            }
            else if(mapa[xx][yy] == '^'){
                xx--;
            }
            else if(mapa[xx][yy] == 'v'){
                xx++;
            }
        }
    }
    if(mapa[xx][yy] == '*'){
        printf("*\n");
    }
    else{
        printf("!\n");
    }
    return 0;
}
