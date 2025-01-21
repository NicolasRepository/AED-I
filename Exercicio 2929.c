#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int valor;
    struct no *prox;
} No;

void inserir(No **no2, int valor, No **min_stack){
    No *novo = malloc(sizeof(No));
    if (novo){
        novo->valor = valor;
        novo->prox = *no2;
        *no2 = novo;

        if(*min_stack == NULL || valor < (*min_stack)->valor){
            No *novo_min = malloc(sizeof(No));
            novo_min->valor = valor;
            novo_min->prox = *min_stack;
            *min_stack = novo_min;
        }
        else{
            No *novo_min = malloc(sizeof(No));
            novo_min->valor = (*min_stack)->valor;
            novo_min->prox = *min_stack;
            *min_stack = novo_min;
        }
    }
}

void retirar(No **no2, No **min_stack){
    if(*no2 == NULL){
        printf("EMPTY\n");
        return;
    }

    No *temp = *no2;
    *no2 = (*no2)->prox;

    No *temp_min = *min_stack;
    *min_stack = (*min_stack)->prox;

    free(temp_min);
    free(temp);
}

void min(No *min_stack){
    if (min_stack == NULL){
        printf("EMPTY\n");
    }
    else{
        printf("%d\n", min_stack->valor);
    }
}

void liberarLista(No *no){
    No *aux;
    while (no != NULL){
        aux = no;
        no = no->prox;
        free(aux);
    }
}

int main(){
    int n, traducao;
    char linha[16];
    No *lista = NULL;
    No *min_stack = NULL;

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++){
        fgets(linha, sizeof(linha), stdin);
        if (linha[0] == 'P'){
            if (linha[1] == 'U'){
                char *inicio = linha + 5;
                traducao = strtol(inicio, NULL, 10);
                inserir(&lista, traducao, &min_stack);
            }
            else{
                retirar(&lista, &min_stack);
            }
        }
        else{
            min(min_stack);
        }
    }

    liberarLista(lista);
    return 0;
}
