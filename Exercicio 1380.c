#include <stdio.h>

int divisao(int total) {
    int mat = 0, imat = 1, popul = 0;
    for (int i = 0; i < total; i++) {
        popul = (imat + mat) % 1000;
        imat = mat;
        mat = popul;
    }
    return popul;
}

int main() {
    int t;
    scanf("%d", &t);
    char k[1000001];
    int qt[t];
    for (int i = 0; i < t; i++) {
        scanf("%s", k);
        int mod1500 = 0;
        for (int j = 0; k[j] != '\0'; j++) {
            mod1500 = (mod1500 * 10 + (k[j] - '0')) % 1500;
        }
        qt[i] = divisao(mod1500);
    }
    for (int i = 0; i < t; i++) {
        printf("%03d\n", qt[i]);
    }
    return 0;
}
