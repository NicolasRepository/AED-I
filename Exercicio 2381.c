#include <stdio.h>

typedef struct no{
    char valor[21];
    struct no *prox;
} No;

int itemValido(No *no, char valor[21]){
    No *p = no;
    while(p != NULL){
        if (strcmp(p->valor, valor) == 0) {
            return 0;
        }
        p = p->prox;
    }
    return 1;
}

int compara(const void *a, const void *b){
    return strcmp(*(const char **)a, *(const char **)b);
}

void inserir(No **no2, char valor[21]){
    No *aux, *novo = malloc(sizeof(No));

    if(novo && itemValido(*no2, valor)){
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

void listaParaArray(No *no, char *array[]){
    int i = 0;
    No *p = no;
    while (p != NULL) {
        array[i++] = p->valor;
        p = p->prox;
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

void imprimir(No *no, int n, int k){
    char *array[n];
    listaParaArray(no, array);
    qsort(array, n, sizeof(char *), compara);
    for(int i = 0; i < n; i++){
        if(k-1 == i){
        printf("%s", array[i]);
        printf("\n");
        break;
        }
    }
}

int main(){
    int n, k, total = 0;
    char nome[21] = {};
    scanf("%d", &n);
    scanf("%d", &k);
    getchar();
    No *lista = NULL;
    for(int i = 0; i < n; i++){
        scanf("%s", &nome);
        inserir(&lista, nome);
    }
    imprimir(lista, n, k);
    liberarLista(lista);
    return 0;
}
