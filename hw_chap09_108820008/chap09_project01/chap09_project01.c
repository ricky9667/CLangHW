/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.11.07                                              */
/* Purpose:                        */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

#define MAX_LEN 100

void selection_sort(int* a,int n)
{
//	printf("n=%d\n",n);
	if(n<=1) return;
	int p,i,tmp;

	for(i=1;i<n;i++)
		if(a[i]>a[p]) 
			p=i;
	
	tmp=a[p], a[p]=a[n-1], a[n-1]=tmp;
	return selection_sort(a,n-1);
}

int main()
{
	int i,c,n,a[MAX_LEN];
	printf("Enter list of integers to be sorted: ");
	for(i=0,n=0;i<MAX_LEN;i++)
	{
		scanf("%d",&a[i]);
		n++;
		if((c=getchar())=='\n')
			break;
		ungetc(c,stdin);
	}

	selection_sort(a,n);

	printf("Sorted list: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	puts("");

	return 0;
}
