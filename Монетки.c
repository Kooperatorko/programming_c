#include <stdlib.h> 
#include <stdio.h> 

int rec(int, int);  
int nom[5]={0,1,2,5,10}; 
int main() 

{ 
	int number; 
	printf("\nВведите число: "); 
	scanf("%d",&number); 
	printf("Вариантов набора: %d\n\n",rec(number,4));  

return 0; 
} 

int rec(int s, int b)
{ 
	if(nom[b]==1)return 1; 
	else if(s>nom[b])return (rec(s,b-1)+rec(s-nom[b],b)); 
	else if(s==nom[b])return (rec(s,b-1)+1); 
	else return rec(s,b-1); 
} 