#include <stdio.h>
#include <string.h>

int main(){
    int i, j, ni1, ni2, total, mais1;
    char n1[10] = {}, n2[10] = {};
    scanf("%s %s", n1, n2);
    while(n1[0] != '0' || n2[0] != '0'){
        i = strlen(n1);
        j= strlen(n2);
        total = 0;
        mais1 = 0;
        while(i >= 0 && j >= 0){
            ni1 = n1[i] - 48;
            ni2 = n2[j] - 48;
            if(ni1 + ni2 + mais1 > 9){
                total++;
                mais1 = 1;
            }
            else{
                mais1 = 0;
            }
            i--;
            j--;
        }
        if(j > i){
            while(j >= 0 && mais1){
                if(n2[j] + mais1 - 48 > 9){
                    total++;
                }
                else{
                    mais1 = 0;
                }
                j--;
            }
        }
        else{
            while(i >= 0 && mais1){
                if(n1[i] + mais1 - 48 > 9){
                    total++;
                }
                else{
                    mais1 = 0;
                }
                i--;
            }
        }
        if(total == 0){
            printf("No carry operation.\n");
        }
        else{
            printf("%d carry operation", total);
            if(total > 1){
                printf("s.\n");
            }
            else{
                printf(".\n");
            }
        }
        scanf("%s %s", n1, n2);
    }
    return 0;
}
