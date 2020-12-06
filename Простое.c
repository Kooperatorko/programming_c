#include <stdio.h>

int main ()
{
	int n, k; 
	int m = 2;
	printf("\nEnter a number: ");
	scanf("%d", &n);

	if (n>1)
	{
		for (k=2 ; k<n ; k++) 
		{
			if (n % k != 0)
			{m++;}
			else
			{m--;}
		}
	}
	else 
	{printf("Number <= 1.\n");}

	if (m == n)
	{printf("The number is simple.\n\n");}
	else
	{printf ("The number is not simple.\n\n");}

return 0;
}