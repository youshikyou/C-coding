#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


#define bool char
#define true 1
#define false 0

int factorial(int);
int sum(int);
void hannuota(int n , char A, char B, char C) {
	if (n == 1) {
		printf("put the %d th plate from %c to %c \n", n, A, C);
	}

	else {
		hannuota(n - 1, A, C, B);
		printf("put the %d th plate from %c to %c \n",n, A, C);
		hannuota(n - 1, B, A, C);
	}

	return;
}

int fi(int n) {
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	else {
		return fi(n - 1) + fi(n - 2);
	}

}

int main() {

	int val,val1;
	val = factorial(5);
	val1 = sum(100);
	printf("%d, %d", val,val1);

	char A = 'A';
	char B = 'B';
	char C = 'C';
	hannuota(5, A, B, C);
	
	val = fi(8);
	printf("%d ", val);

	return 0;
}

int factorial(int n) {

	if (n == 1||n == 0) {
		return 1;
	}
	else
		return n*factorial(n - 1);

}

int sum(int n) {
	if (n == 0) {
		return 0;
	}
	else
		return n + sum(n - 1);
}
