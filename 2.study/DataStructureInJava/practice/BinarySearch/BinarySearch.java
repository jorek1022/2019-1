/*  2019 03 13 
    practice
    Roje Lee
    DataStructure in Java
    BinarySearch
*/

public class BinarySearch{
    public static void main(String[] args)
    {
        // 배열의 선언 및 초기화
        int[] arr = {1, 4, 7, 9, 11, 35, 40};
        int left = 0;
        int right = arr.length-1;
        int mid;

        // 찾는 숫자는?
        int num = 7;

        // right가 left보다 작을 동안
        while(right >= left)
        {
            mid = (left + right) / 2;
            if(num == arr[mid])
            {
                System.out.println("The "+ num + "'s index : " + mid);
                break;
            }
            if(num < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
}


