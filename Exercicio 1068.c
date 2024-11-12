#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char valor;
    struct no *prox;
} No;

void inserirFinal(No **no2, char valor){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = valor;
        novo->prox = NULL;

        if(*no2 == NULL){
            *no2 = novo;
        }
        else{
            aux = *no2;
            while(aux->prox){
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }
    else{
        printf("Erro na alocação de memória\n");
    }
}

void liberarLista(No *no){
    No *aux;
    while(no != NULL){
        aux = no;
        no = no->prox;
        free(aux);
    }
}

int verificar(No *no){
    int abre = 0, fecha = 0;
    while(no != NULL){
        if(no->valor == '('){
            abre++;
        }
        else if(no->valor == ')'){
            fecha++;
            if(fecha > abre){
                return 0;
            }
        }
        no = no->prox;
    }

    if(abre != fecha){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    int resultado[10000] = {}, linhaIndex = 0;
    char linha[1000] = {}, valor;
    No *lista = NULL;

    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        for(int i = 0; linha[i] != '\0'; i++){
            valor = linha[i];
            inserirFinal(&lista, valor);
        }
        resultado[linhaIndex] = verificar(lista);
        liberarLista(lista);
        lista = NULL;
        linhaIndex++;
    }

    for(int i = 0; i < linhaIndex; i++){
        if(resultado[i]){
            printf("correct\n");
        }
        else{
            printf("incorrect\n");
        }
    }
    return 0;
}
