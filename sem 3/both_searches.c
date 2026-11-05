#include<stdio.h>
#include<stdlib.h>
int linearsearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
 
        // If x greater, ignore left half
        else if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // if we reach here, then element was
    // not present
    return -1;
}
int main()
{
    int arr[] = {23,34,45,56,67,89};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 67;
 
    int index = linearsearch(arr, n, x);
    if (index == -1)
        printf("Element is not present in the array");
    else
        printf("Element found at position %d",index);


    int result = binarySearch(arr, 0, n, x);
    (result == -1) ? printf("\nElement is not present in array"): printf("\nElement is present at ""index %d",result);
    return 0;
}