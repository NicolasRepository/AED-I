#include <stdio.h>

int testeV(int numero, int matriz[9][9], int x, int y){
	int xx = x/3, yy = y/3;
	for(int i = 3 * xx; i < 3 * xx + 3; i++){
		for(int j = 3 * yy; j < 3 * yy + 3; j++){
			if(numero == matriz[i][j] && (i != x || j != y)){
				return 0;
			}
		}
	}
	for(int i = 0; i < 9; i++){
		if(numero == matriz[x][i] && i != y){
			return 0;
		}
	}
	for(int i = 0; i < 9; i++){
		if(numero == matriz[i][y] && i != x){
			return 0;
		}
	}
	return 1;
}

int main(){
    int n, numero, matriz[9][9] = {};
    scanf("%d", &n);
    int erro[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 9; j++){
            for(int k = 0; k < 9; k++){
                scanf("%d", &numero);
                matriz[j][k] = numero;
            }
        }
        erro[i] = 0;
        for(int j = 0; j < 9; j++){
            for(int k = 0; k < 9; k++){
                if(!(testeV(matriz[j][k], matriz, j, k))){
                    erro[i]++;
                    break;
                }
            }
            if(erro[i] > 0){
            	break;
			}
        }
    }
    for(int i = 0; i < n; i++){
        printf("Instancia %d\n", i+1);
        if(erro[i] == 0){
            printf("SIM\n\n");
        }
        else{
            printf("NAO\n\n");
        }
    }
    return 0;
}
