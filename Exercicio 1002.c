#include <stdio.h>
 
int main() {
	double area, raio;
	scanf("%lf", &raio);
	area = raio * raio * 3.14159;
    printf("A=%.4f\n", area);
    return 0;
}
