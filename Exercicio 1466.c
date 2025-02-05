#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proxd;
    struct no *proxe;
} No;

typedef struct lista{
    No **itens;
    int frente, tras;
    int capacidade;
} Lista;

Lista* criarLista(int capacidade){
    Lista *l = malloc(sizeof(Lista));
    l->capacidade = capacidade;
    l->frente = 0;
    l->tras = -1;
    l->itens = malloc(sizeof(No*) * capacidade);
    return l;
}

void enfileirar(Lista *l, No *n){
    if(l->tras < l->capacidade - 1){
        l->tras++;
        l->itens[l->tras] = n;
    }
}

No* desenfileirar(Lista *l){
    if (l->frente <= l->tras){
        No *n = l->itens[l->frente];
        l->frente++;
        return n;
    }
    return NULL;
}

int listaVazia(Lista *l){
    return l->frente > l->tras;
}

void imprimirPorNivel(No *no){
    if(no == NULL){
        return;
    }
    Lista *l = criarLista(500);
    enfileirar(l, no);
    int primeiro = 1;
    while(!listaVazia(l)){
        No *n = desenfileirar(l);
        if (primeiro){
            printf("%d", n->valor);
            primeiro = 0;
        } else {
            printf(" %d", n->valor);
        }
        if(n->proxe){
            enfileirar(l, n->proxe);
        }
        if(n->proxd){
            enfileirar(l, n->proxd);
        }
    }
    printf("\n\n");
    free(l->itens);
    free(l);
}

void inserir(No **no2, int valor){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = valor;
        novo->proxd = NULL;
        novo->proxe = NULL;

        if(*no2 == NULL){
            *no2 = novo;
        }
        else{
            aux = *no2;
            while(aux){
                if(aux->valor < valor){
                    if(aux->proxd){
                        aux = aux->proxd;
                    }
                    else{
                        aux->proxd = novo;
                        break;
                    }
                }
                else{
                    if(aux->proxe){
                        aux = aux->proxe;
                    }
                    else{
                        aux->proxe = novo;
                        break;
                    }
                }
            }
        }
    }
}

void liberarLista(No *no){
    if(no != NULL){
        liberarLista(no->proxe);
        liberarLista(no->proxd);
        free(no);
    }
}

int main(){
    int c, cc, n, valor;
    scanf("%d", &c);
    cc = c;
    while(cc--){
        No *arvore = NULL;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &valor);
            inserir(&arvore, valor);
        }
        printf("Case %d:\n", c-cc);
        imprimirPorNivel(arvore);
        liberarLista(arvore);
    }
    return 0;
}
