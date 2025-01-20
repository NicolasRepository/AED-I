#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculo(int fun[], int cli[], int funO[], int funQ, int cliQ, int tempo, int cliO, int funT[], int tempoTotal, int funTT[]){
    if(cliO < cliQ){
        int i = 0;
        while(funO[i] != -1 && i < funQ){
            i++;
        }
        if(i < funQ){
            funO[i] = cliO;
            funT[i] = fun[i] * cli[cliO];
            funTT[i] += funT[i];
            tempoTotal = funTT[i] > tempoTotal ? funTT[i] : tempoTotal;
            cliO++;
            return calculo(fun, cli, funO, funQ, cliQ, tempo, cliO, funT, tempoTotal, funTT);
        }
        else{
            int menor = funT[0];
            i = 0;
            for(int j = 1; j < funQ; j++){
                if(funT[j] < menor){
                    menor = funT[j];
                    i = j;
                }
            }
            for(int k = 0; k < funQ; k++){
                funT[k] -= menor;
            }
            tempo += menor;
            funT[i] = fun[i] * cli[cliO];
            funTT[i] += funT[i];
            tempoTotal = funTT[i] > tempoTotal ? funTT[i] : tempoTotal;
            cliO++;
            return calculo(fun, cli, funO, funQ, cliQ, tempo, cliO, funT, tempoTotal, funTT);
        }
    }
    else{
        int maior = 0;
        for(int i = 0; i < funQ; i++){
            if(funTT[i] > maior){
                maior = funTT[i];
            }
        }
        return maior;
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int fun[n], cli[m], funO[n], cliO[m], tempo = 0, funT[n], funTT[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &fun[i]);
        funO[i] = -1;
        funT[i] = 0;
        funTT[i] = 0;
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &cli[i]);
    }

    tempo = calculo(fun, cli, funO, n, m, tempo, 0, funT, 0, funTT);

    printf("%d\n", tempo);
    return 0;
}
