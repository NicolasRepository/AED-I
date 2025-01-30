//Nicolas Almeida Faria
//RA: 178194

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, c, t, x;
    char string[51];
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        fgets(string, 51, stdin);
        x = strlen(string);
        string[strcspn(string, "\n")] = '\0';
        scanf("%d", &c);
        getchar();
        for(int j = 0; j < x && c != 0 && string[j] != '\0'; j++){
            t = string[j];
            t -= c;
            if(t < 'A'){
                t = t + 'Z' - 'A' + 1;
            }
            string[j] = t;
        }
        printf("%s\n", string);
    }
    return 0;
}
