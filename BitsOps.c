// BitOpsTest.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Swapping the even & odd bits
unsigned int swapBits(unsigned int x)
{
	unsigned int even_bits = x & 0xAAAAAAAA;
	unsigned int odd_bits = x & 0x55555555;
	even_bits = even_bits>>1;
	odd_bits = odd_bits<<1; 
	return (even_bits | odd_bits);
}

//Finding the set bits
int findSetBits(unsigned int x)
{
	int cntVal = 0;
	while(x!=0)
	{
		if(x & 1)
			cntVal++;
		x = x>>1;
	}
	return cntVal;
}

//find the status of bits
int bitsetStatus(unsigned int x,int pos)
{
	unsigned int check=1;
	check = check <<pos;
	if( x & check)
		return 1;
	else
		return 0;
}

//multiply with 3.5
int multiply3point5(int val)
{
	return (((val<<3)-val)>>1);
}

//Endianess of arch
void checkEndianess(void)
{
	unsigned int i = 1;
   char *c = (char*)&i;
   if (*c)    
       printf("Little endian\n");
   else
       printf("Big endian\n");
}

int main(int argc, char* argv[])
{
	unsigned int val =23; //00101011
	int bitpos=0;
	printf("%u \n",swapBits(val));
	printf("The set bit cnt: %d\n",findSetBits(val));
	printf("Enter to check the bit status:");
	scanf("%d",&bitpos);
	if(bitsetStatus(val,bitpos))
		printf("The bit %d is set to 1. \n",bitpos);
	else
		printf("The bit %d is set to 0. \n",bitpos);
	printf("The output of 4 by 3.5: %d \n",multiply3point5(4));
	checkEndianess();
	return 0;
}
