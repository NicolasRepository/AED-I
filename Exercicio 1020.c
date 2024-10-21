#include <stdio.h>
 
int main() {
	int ano = 0, mes = 0, dia;
	scanf("%d", &dia);
	while(dia > 364){
		ano++;
		dia-=365;
	}
	while(dia > 29){
		mes++;
		dia-=30;
	}
	printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", ano, mes, dia);
    return 0;
}
