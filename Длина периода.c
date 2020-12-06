#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int c, number;
	int dlina = 0, rem = 1, result = 1;
	printf("\nEnter a number: "); 
	scanf("%d",&number);

	if (number>1)
	{
		while (dlina++!=number+1)
		rem=(10 * rem)% number;
		c=rem;
		rem=(10 * rem) % number;

		while(rem!=c)
		{
			rem=(10*rem) % number;
			result++;
		}

		if(result==1 && c==0) result--;
		printf("Length of the fraction period = %d.\n\n", result);
	}
	else 
	{printf("Number %d <= 1.\n\n", result);}

return 0;
}