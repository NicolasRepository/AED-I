#include <stdio.h>

int fibonacci(int x){
    if(x < 2){
        return x;
    }
    else{
        return fibonacci(x-1) + fibonacci(x-2);
    }
}

int fibonacci2(int x, int x2){
    if(x < 2){
        return 1;
    }
    else if(x != x2){
        return 1 + fibonacci2(x-1, x) + fibonacci2(x-2, x);
    }
    else{
        return fibonacci2(x-1, x) + fibonacci2(x-2, x);
    }
}

int main() {
    int n, x, total, result;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        result = fibonacci(x);
        total = fibonacci2(x, x);
        printf("fib(%d) = %d calls = %d\n", x, total, result);
    }
    return 0;
}
