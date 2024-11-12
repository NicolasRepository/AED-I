#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char valor[21];
    struct no *prox;
} No;

void inserir(No **no2, char valor[21]){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        strncpy(novo->valor, valor, 20);
        novo->valor[20] = '\0';
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

void imprimir(No *no1, No *no2, char amigo[21]){
    if (strcmp(amigo, "nao") == 0) {
        while(no1){
            printf("%s ", no1->valor);
            no1 = no1->prox;
        }
        while(no2){
            printf("%s", no2->valor);
            if(no2->prox != NULL){
                printf(" ");
            }
            no2 = no2->prox;
        }
    }
    else{
        while(no1){
            if(strcmp(no1->valor, amigo) != 0){
                printf("%s", no1->valor);
                if(no1->prox != NULL){
                    printf(" ");
                }
            }
            else{
                while(no2){
                    printf("%s ", no2->valor);
                    no2 = no2->prox;
                }
                printf("%s", no1->valor);
                if(no1->prox != NULL){
                    printf(" ");
                }
            }
            no1 = no1->prox;
        }
    }
    printf("\n");
}

int main() {
    int n, k, total = 0;
    char linha[20000] = {}, palavra[21] = {}, amigo[21] = {};
    No *lista[2];
    for(int i = 0; i < 2; i++) {
        lista[i] = NULL;
    }
    for(int i = 0; i < 2; i++){
        k = 0;
        total = 0;
        while (fgets(linha, sizeof(linha), stdin) != NULL){
            for (int j = 0; linha[j] != '\0'; j++){
                if(linha[j] == '\n' && j != 0){
                    total++;
                    break;
                }
                if(linha[j] != ' ' && linha[j] != '\n'){
                    palavra[k] = linha[j];
                    k++;
                }
                else{
                    if(k > 0 && palavra[0] != '\n'){
                        palavra[k] = '\0';
                        inserir(&lista[i], palavra);
                        k = 0;
                    }
                }
            }
            if(k > 0 && palavra[0] != '\n'){
                palavra[k] = '\0';
                inserir(&lista[i], palavra);
                k = 0;
            }
            if(total){
                break;
            }
        }
    }

    fgets(amigo, sizeof(amigo), stdin);
    amigo[strcspn(amigo, "\n")] = '\0';

    imprimir(lista[0], lista[1], amigo);
    for(int i = 0; i < 2; i++) {
        liberarLista(lista[i]);
    }
    return 0;
}
