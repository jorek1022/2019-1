/*
    2019 03 13 WED
    이로제
    DataStructure In Java
    Recursive Binary Search 
*/

public class BSearchRecur
{
    public int bSearchRecur(int arr[], int first, int last, int target)
    {
        int mid;

        if(first > last)
            return -1;
        mid = (first + last) / 2;
        if(arr[mid] == target)
            return mid;
        else if(target < arr[mid])
            return bSearchRecur(arr, first, mid-1, target);
        else
            return bSearchRecur(arr, mid+1, last, target);
    }

    public static void main(String[] args)
    {
        int arr[] = {1, 3, 5, 7, 9};
        int idx;

        idx = new BSearchRecur().bSearchRecur(arr, 0, arr.length-1, 7);
        if(idx == -1)
            System.out.println("Search failed!!");
        else
            System.out.println("idx : " + idx);
    }
}