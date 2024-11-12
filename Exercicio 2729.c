#include <stdio.h>


typedef struct no {
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

void inserir(No **no2, char valor[21], int *qt){
    No *aux, *novo = malloc(sizeof(No));

    if(novo && itemValido(*no2, valor)){
        (*qt)++;
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

void imprimir(No *no, int n){
    char *array[n];
    listaParaArray(no, array);
    qsort(array, n, sizeof(char *), compara);
    for (int i = 0; i < n; i++) {
        printf("%s", array[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int n, k, total = 0;
    char linha[20000] = {}, palavra[21] = {};
    scanf("%d", &n);
    getchar();
    int qt[n];
    for (int i = 0; i < n; i++) {
        qt[i] = 0;
    }
    No *lista[n];
    for(int i = 0; i < n; i++) {
        lista[i] = NULL;
    }
    for(int i = 0; i < n; i++){
        k = 0;
        total = 0;
        while (fgets(linha, sizeof(linha), stdin) != NULL){
            for (int j = 0; linha[j] != '\0'; j++){
                if(linha[j] == '\n' && j != 0){
                    total++;
                    break;
                }
                if(linha[j] != ' '){
                    palavra[k] = linha[j];
                    k++;
                }
                else{
                    if(k > 0){
                        palavra[k] = '\0';
                        inserir(&lista[i], palavra, &qt[i]);
                        k = 0;
                    }
                }
            }
            if(k > 0){
                palavra[k] = '\0';
                inserir(&lista[i], palavra, &qt[i]);
                k = 0;
            }
            if(total){
                break;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        imprimir(lista[i], qt[i]);
        liberarLista(lista[i]);
    }
    return 0;
}
