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

void selection_sort(int a[MAX_LEN],int n)
{
	if(n<=1) return; // return when sorting is finished
	int p=0,i,tmp; 
	for(i=1;i<n;i++)
		if(a[i]>a[p]) 
			p=i; // p saves the largest number of the array
	
	tmp=a[p], a[p]=a[n-1], a[n-1]=tmp; // swap the largest and the last number
	return selection_sort(a,n-1); // make end -1 and recall the function
}

int main()
{
	int i,c,n,a[MAX_LEN];
	printf("Enter list of integers to be sorted: ");
	for(i=0,n=0;i<MAX_LEN;i++)
	{
		scanf("%d",&a[i]); // input
		n++; // count number of integers
		if((c=getchar())=='\n') 
			break; // break if you get a '\n'
		ungetc(c,stdin); // push the character back to stdin
	}

	selection_sort(a,n); // sort

	printf("Sorted list: "); // output the sorted list
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	puts("");

	return 0;
}