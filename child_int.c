#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	int n,square;

	n = atoi(argv[1]);

	square  = n * n;

	printf("Number = %d\n", n);
	printf("Square = %d\n", square);

	return 0;
}
