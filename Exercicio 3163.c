#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int valor;
    struct no *prox;
    int tem0;
} No;

void inserir(No **no2, int valor, int tem0){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = valor;
        novo->tem0 = tem0;
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
}

void liberarLista(No *no){
    No *aux;
    while(no != NULL){
        aux = no;
        no = no->prox;
        free(aux);
    }
}

void imprimir(No *no[4]){
    int teste = 1, falhas = 0, pri = 0;
    while(teste){
        for(int i = 0; i < 4; i++){
            if(no[i]){
                if(pri){
                    printf(" ");
                }
                else{
                    pri++;
                }
                printf("A");
                if(no[i]->tem0 && no[i]->valor != 0){
                    printf("0");
                }
                printf("%d", no[i]->valor);
                no[i] = no[i]->prox;
            }
            else{
                falhas++;
            }
        }
        if(falhas > 3){
            teste = 0;
        }
        else{
            falhas = 0;
        }
    }
}

int main() {
    int status = 1, direcao = 0, traducao, tem0;
    char linha[5];
    No *lista[4] = {NULL};

    while(status){
            fgets(linha, sizeof(linha), stdin);
            if(linha[0] == 'A'){
                traducao = 0;
                tem0 = 0;
                for(int i = 1; i < 4; i++){
                    if(linha[1] == '0' && traducao == 0){
                        tem0 = 1;
                    }
                    if(linha[i] != '\0' && linha[i] != '\n'){
                        traducao = traducao*10 + (linha[i] - '0');
                    }
                }
                inserir(&lista[direcao], traducao, tem0);
            }
            else if(linha[0] == '-'){
                if(linha[1] == '2'){
                    direcao = 2;
                }
                else if(linha[1] == '3'){
                    direcao = 1;
                }
                else{
                    direcao = linha[1] - '1';
                }
            }
            else if(linha[0] == '0'){
                status = 0;
            }
    }

    imprimir(lista);
    printf("\n");
    for(int i = 0; i < 4; i++) {
        liberarLista(lista[i]);
    }

    return 0;
}
