#include <stdio.h>

int LSearch(int ar[], int len, int target)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(ar[i] == target)
            return i;
    }
    return -1;
}

int main(void)
{
    int arr[] = {3, 5, 2, 4, 9};
    int idx;
    
    idx = LSearch(arr, sizeof(arr)/sizeof(int), 4);
    if(idx == -1)
        printf("search failed \n");
    else
        printf("index of saved target: %d \n", idx);

    return 0;
}