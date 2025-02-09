#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome[51];
    float preco;
    struct no *prox;
} No;

void inserir(No **no2, char nome[51], float preco){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        strncpy(novo->nome, nome, 50);
        novo->nome[50] = '\0';
        novo->preco = preco;
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

float buscarValor(No *no, char nome[51], int qt){
    No *aux = no;
    while(aux){
        if(strcmp(aux->nome, nome) == 0){
            return aux->preco * qt;
        }
        aux = aux->prox;
    }
    return 0;
}

void liberarLista(No *no){
    No *aux;
    while(no != NULL){
        aux = no;
        no = no->prox;
        free(aux);
    }
}

int main(){
    int n, m, p, qt;
    float preco, total;
    char nome[51];
    scanf("%d", &n);
    while(n--){
        No *lista = NULL;
        scanf("%d", &m);
        while(m--){
            getchar();
            scanf("%s %f", &nome, &preco);
            inserir(&lista, nome, preco);
        }
        total = 0;
        scanf("%d", &p);
        while(p--){
            getchar();
            scanf("%s %d", &nome, &qt);
            total += buscarValor(lista, nome, qt);
        }
        printf("R$ %.2f\n", total);
        liberarLista(lista);
    }
    return 0;
}
