#include "quicksort.h"

void quicksort(int a[], int low, int high)
{
    if(low >= high) return;

    /* gets the middle number of the array and 
    classify numbers that are larger or smaller tham a[mid] */
    int mid = split(a, low, high);

    // sort the rest by using divide and conquer
    quicksort(a, low, mid-1);
    quicksort(a, mid+1, high);
}

int split(int a[], int l, int r)
{
    int i=l-1, j=l;
    while(j<=r)
    {
        // swaps the smaller number to the front
        if(a[j]<=a[r])
        {
            int tmp = a[++i]; // iterate i
            a[i] = a[j];
            a[j] = tmp;
        }
        j++; // iterate j
    }
    return i;
}