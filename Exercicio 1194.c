#include <stdio.h>
#include <string.h>

void posfixa(char *pre, char *in, int n){
    if(n <= 0){
        return;
    }
    int raiz = strchr(in, pre[0]) - in;
    posfixa(pre + 1, in, raiz);
    posfixa(pre + raiz + 1, in + raiz + 1, n - raiz - 1);
    putchar(pre[0]);
}

int main(){
    int c, n;
    char pre[52], in[52];
    scanf("%d", &c);
    while(c--){
        scanf("%d %s %s", &n, pre, in);
        posfixa(pre, in, n);
        putchar('\n');
    }
    return 0;
}
