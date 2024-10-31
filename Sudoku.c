#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

// Função para imprimir a tabela
int tabelaPrint(int tabela[9][9], int tabelaR[9][9]){
	int k = 0;
	for(int i = 0; i < 13; i++){
		if(i % 4 == 0){
			printf("-------------------------\n");
			k++;
		}
		else{
			printf("| ");
			for(int j = 0; j < 9; j++){
				if(tabela[i-k][j] != 0){
					if(tabelaR[i-k][j] > 0){
						printf("\033[1;33m%d\033[0m ", tabela[i-k][j]);
					}
					else{
						printf("%d ", tabela[i-k][j]);
					}
				}
				else{
					printf("  ");
				}
				if((j+1) % 3 == 0){
					printf("| ");
				}
			}
			printf("\n");
		}
	}
}

// Função para testar se o jogo terminou
int testeT(int tabela[9][9]){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(tabela[i][j] == 0){
				return 0;
			}
		}
	}
	return 1;
}

// Função para testar se um número de certa posição é editável
int testeE(int tabelaR[9][9], int x, int y){
	if(tabelaR[x][y] == 1){
		return 0;
	}
		return 1;
}

// Função para testar se um número é válido em certa posição
int testeV(int numero, int tabela[9][9], int x, int y){
	int xx = x/3, yy = y/3;
	for(int i = 0; i < 9; i++){
		if(numero == tabela[x][i]){
			return 0;
		}
	}
	for(int i = 0; i < 9; i++){
		if(numero == tabela[i][y]){
			return 0;
		}
	}
	for(int i = 3 * xx; i < 3 * xx + 3; i++){
		for(int j = 3 * yy; j < 3 * yy + 3; j++){
			if(numero == tabela[i][j]){
				return 0;
			}
		}
	}

	return 1;
}

// Função para adicionar valores à tabela
void tabelaAdd(int tabela[9][9], int tabelaR[9][9]){
	int numero = -1, x = 0, y = 0;
	printf("Digite o numero que deseja adicionar e a sua coordenada na tabela(numero linha coluna): ");
	while(numero < 0 || numero > 9 || x > 9 || x < 0 || y > 9 || y < 0){
		scanf("%d %d %d", &numero, &x, &y);
		if(numero == y && y == x && x == 0){
			for(int i = 0; i < 9; i++){
				for(int j = 0; j < 9; j++){
					if(tabelaR[i][j] == 0){
						tabela[i][j] = 0;
					}
				}
			}
		}
	}
	x--;
	y--;
	if((testeV(numero, tabela, x, y) == 1 || numero == 0) && testeE(tabelaR, x, y) == 1 && x != -1){
		tabela[x][y] = numero;
    system("cls");
	}
	else{
    	system("cls");
		if(x != -1){
			printf("\033[1;31mLocal invalido\033[0m\n");
		}
	}
}

void adicionar(int tabelaPadroes[9][9], int k, int l, int possi[9][9][9], int n, int nn, int total){
	int loop = 0;
	if(nn >= total){
		loop++;
	}
	while(loop == 0){
		if (tabelaPadroes[k][l] > 0){
			if(possi[k][l][n] == 1 && n < 9){
				tabelaPadroes[k][l] = n+1;
      			loop++;
			}
			else if(n > 7){
				adicionar(tabelaPadroes, k, l, possi, 0, nn, total);
	       		l++;
				if(l > 8){
      		     	k++;
       			    l = 0;
       		    	if(k > 8){
       			    	k = 0;
					}
      			}
				loop++;
				adicionar(tabelaPadroes, k, l, possi, tabelaPadroes[k][l], nn, total);
			}
			else{
				n++;
			}
		}
		else{
			l++;
			if(l > 8){
  		     	k++;
   			    l = 0;
		    	if(k > 8){
			    	k = 0;
				}
      		}
      		loop++;
			adicionar(tabelaPadroes, k, l, possi, tabelaPadroes[k][l], nn, total);
		}
	}
}

int testeFunciona2(int tabelaTeste[9][9], int x, int y, int tabelaCompleta[9][9]){
	int status = 0, tabelaPadroes[9][9] = {}, invalido, tabelaReservas[9][9], cont = 0, possi[9][9][9] = {}, pri, possi2, possi3, temsoum, temsoum2 = 0;
	long long int total = 1, n = 0;

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			tabelaReservas[i][j] = tabelaTeste[i][j];
		}
	}
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(tabelaTeste[i][j] == 0){
				cont++;
			}
		}
	}
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(tabelaTeste[i][j] == 0){
				pri = 0;
				temsoum = 0;
				for(int n = 0; n < 9; n++){
					if(testeV(n+1, tabelaTeste, i, j)){
						if(pri == 0){
							tabelaPadroes[i][j] = n+1;
							pri++;
						}
						possi[i][j][n] = 1;
						temsoum++;
					}
				}
				if(temsoum == 1){
					tabelaTeste[i][j] = tabelaCompleta[i][j];
					i = 0;
					j = 0;
					temsoum2++;
				}
			}
		}
	}

//	printf("%d %d\n", temsoum2, cont);3
	if(temsoum2 < cont){
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				tabelaTeste[i][j] = tabelaReservas[i][j];
			}
		}
		return 0;
	}

//			printf("ping\n");
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			tabelaTeste[i][j] = tabelaReservas[i][j];
		}
	}
	return 1;
}

// Função para gerar números aleatórios no tabuleiro
int aleatorio(int tabela[9][9], int tabelaR[9][9], int tabelaRR[9][9], int qt){
	int r, s, teste = 0, erro = 0, tabelaG[9][9] = {};
	srand(time(0));

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			tabelaR[i][j] = 1;
		}
	}
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			tabelaRR[i][j] = 0;
		}
	}
	for(int i = 0; i < 9; i++){
		if(erro > 0){
			i = 0;
			erro = 0;
			for(int i = 0; i < 9; i++){
				for(int j = 0; j < 9; j++){
					tabela[i][j] = 0;
				}
			}
		}
		for(int j = 0; j < 9; j++){
				teste = 0;
				for(int n = 0; n < 10; n++){
					if(testeV(n, tabela, i, j) == 1){
					teste++;
					}
				}
				if(teste == 0){
					erro++;
					break;
				}
			s = 0;
			while(s == 0){
				r = rand() % 9 + 1;
				if(testeV(r, tabela, i, j) == 1){
					tabela[i][j] = r;
					tabelaG[i][j] = r;
					s++;
				}
			}
		}
	}

	// Essa parte vai escolher cantos aleatórios para apagar do tabuleiro
	int rx, ry, cont = 0, qt2 = 81 - qt, status, guarda, tabelaNaoPode[9][9] = {}, naopode = 0, testeF, cont2 = 81, xx, yy, xxx[9] = {}, yyy[9]= {}, maior, maiorx, maiory, unico, numero, tabelaReserva[9][9];
	srand(time(0));
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			tabelaReserva[i][j] = tabela[i][j];
			tabelaR[i][j] = 1;
		}
	}

	for(int k = 0; k < qt2; k++){
		rx = rand() % 9;
		ry = rand() % 9;
			if(tabela[rx][ry] != 0 && tabelaNaoPode[rx][ry] == 0){
				guarda = tabela[rx][ry];
				status = 0;
				tabela[rx][ry] = 0;
					testeF = testeFunciona2(tabela, rx, ry, tabelaReserva);
	//				printf("solucoes: %d\n", testeF);
				if(testeF != 1){
					tabela[rx][ry] = guarda;
					tabelaNaoPode[rx][ry] = 1;
					naopode++;
					cont++;
					k--;
	//				tabelaPrint(tabela, tabela);
	//				tabelaPrint(tabelaNaoPode, tabelaNaoPode);
					printf(".");
				}
				else{
					cont2--;
					tabelaR[rx][ry] = 0;
				}
	//				printf("%d %d\n", naopode, cont2);
			}
			else{
				k--;
			}
		if(cont > 500000 || cont2 == naopode){
			k = -1;
			cont = 0;
			cont2 = 81;
			naopode = 0;
			for(int i = 0; i < 9; i++){
				for(int j = 0; j < 9; j++){
					tabela[i][j] = tabelaReserva[i][j];
					tabelaNaoPode[i][j] = 0;
					tabelaR[i][j] = 1;
				}
			}
		}
	}
}

// Função para executar o jogo sudoku
int jogo(){
    int tabela[9][9] = {}, tabelaR[9][9] = {}, qt = -1, termino = 0, tabelaRR[9][9] = {};
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			tabelaR[i][j] = 1;
		}
	}
	system("color 0F");
    printf("Jogo Sudoku\n");
    printf("Digite a quantidade de numeros iniciais: ");
    while (qt < 0 || qt > 81){
    	scanf("%d", &qt);
	}
    system("cls");
	printf("Carregando");
    aleatorio(tabela, tabelaR, tabelaRR, qt);
    system("cls");
    while(termino == 0){
    	tabelaPrint(tabela, tabelaR);
    	tabelaAdd(tabela, tabelaR);
		if(testeT(tabela) == 1){
			termino++;
    		tabelaPrint(tabela, tabelaR);
			printf("Voce ganhou!\n\n");
		}
	}
}

int main()
{
	int status = 0;
	char yn = 'j';
	while (status == 0){
		jogo();
		printf("Deseja jogar denovo? y/n: ");
		while(yn != 'y' && yn != 'n'){
			scanf("%c", &yn);
		}
		yn = 'j';
		system("cls");
		if(yn == 'n'){
			status++;
		}
	}
}
