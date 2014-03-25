// 2DArrAlloc.cpp : Defines the entry point for the console application.
// Dynamic 2D allocation by abhishek22j06@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int alloc2D(int ***pnAccess,int indexRows,int indexCols);
int fill2D(int **pnAccess,int *pData,int inRows,int inCols);
void printf2d(int **pnAccess,int inRows,int inCols);
void free2D(int ***pnAccess,int inRows,int inCols);

int main(int argc, char* argv[])
{
	int a[9]={1,2,3,4,5,6,7,8,9};
	int **pnAccess;
	if(alloc2D(&pnAccess,3,3)!=-1)
	{
		if(fill2D(pnAccess,a,3,3)!=-1)
		{
			printf2d(pnAccess,3,3);
		}
		free2D(&pnAccess,3,3);
	}
	return 0;
}

int alloc2D(int ***pnAccess,int indexRows,int indexCols)
{
	int **pAc=NULL;
	int iRows,iCols,returnVal,count;
	returnVal = -1;
	iRows = indexRows;
	iCols = indexCols;
	printf("Allocating 2d array.\n");
	pAc = (int **)malloc(sizeof(int *)*iRows);
	for(count=0;count<iRows;count++)
	{
		pAc[count] = (int *)malloc(sizeof(int)*iCols);
	}
	if(pAc!=NULL)
	{
		printf("Array allocation success.\n");
		*pnAccess = pAc;
		return 1;
	}
	return returnVal;
}
int fill2D(int **pnAccess,int *pData,int inRows,int inCols)
{
	int cnt =0;
	int iRows,iCols;
	if(pnAccess == NULL || pData == NULL)
		return -1;
	printf("Filling the data.\n");
	for(iRows = 0;iRows<inRows;iRows++)
	{
		for(iCols=0;iCols<inCols;iCols++)
		{
			pnAccess[iRows][iCols] = pData[cnt++]; 
		}
	}
	return 1;
}
void printf2d(int **pnAccess,int inRows,int inCols)
{
	int iRows,iCols;
	printf("Printing arrat.\n");
	for(iRows = 0;iRows<inRows;iRows++)
	{
		for(iCols=0;iCols<inCols;iCols++)
		{
			printf("%d ",pnAccess[iRows][iCols]); 
		}
		printf("\n");
	}

}
void free2D(int ***pnAccess,int inRows,int inCols)
{
	int iRows,iCols;
	int **pAc = *pnAccess;
	printf("Freeing memory.\n");
	for(iRows =0;iRows<inRows;iRows++)
	{
		free(pAc[iRows]);
	}
	free(pAc);
	printf("Memory freed successfully.\n");
}
