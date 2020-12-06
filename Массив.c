#include <stdio.h>
#define N 5

int main(void)
{
    int mass[N] = {48, 4, 94, 94, 444};
    int i, j; 
    int result = 1;

    printf("\nArray of %d elements: ", N);
    for (i=0; i < N; i++)
    printf("[%d] ", mass[i]);

    for (i=1; i<N; i++)
    {
        for (j = 0; (j < i)&&(mass[i])!=(mass[j]); j++);
        result = result + (j == i);
    }

printf("\nIn which there are %d different numbers.\r\n\n", result);
return 0;
}
