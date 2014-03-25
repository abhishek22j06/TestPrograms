// atoiItoa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void itoaUD(int val);
void atoiUD(char str[]);

int main(int argc, char* argv[])
{
	int val=0;
	printf("Enter the value:");
	scanf("%d",&val);
	itoaUD(val);
	atoiUD("9865");
	return 0;
}

void itoaUD(int val)
{
	char *out,temp[12];
	int i,tmp =0;
	i =0;
	while(val!=0)
	{
		tmp = val%10;
		temp[i] = tmp + '0';
		i++;
		val = val/10;	
	}
	temp[i] ='\0';
	out = strrev(temp);
	printf("O/p is %s \n",out);
}
void atoiUD(char str[])
{
	int i,total,len = 0;
	i = total =0;
	len = strlen(str);
	while(i<len)
	{
		total = 10 * total + (str[i]-'0');
		i++;
	}
	printf("Out is %d \n",total);
}