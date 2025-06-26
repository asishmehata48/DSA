#include<stdio.h>
#include<conio.h>
int main(){
    int n, i;
    int fibo(int);
    printf("Enter the number of terms in Fibonacci sequence: ");
    scanf("%d", &n);
    printf("Fibonacci sequence up to %d terms:\n", n);
    for(i = 0; i < n; i++){
        printf("%d ", fibo(i));
    }
    getch();
}
// Function to calculate Fibonacci number
int fibo(int n){
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fibo(n - 1) + fibo(n - 2);
}