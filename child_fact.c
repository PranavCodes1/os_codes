#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	int i,n;
	
	n = atoi(argv[1]);

	printf("Number = %d\n", n);
	
	int fact = 1;
	for(i=1;i<=n;i++)
		
	{
		fact = fact * i;
	}
		

	printf("Factorial = %d\n", fact);

return 0;
}

