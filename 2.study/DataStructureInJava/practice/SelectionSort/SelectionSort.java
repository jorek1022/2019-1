/*
    2019 03 13 WED
    이로제
    DataStructure In Java
    SelectionSort
*/

public class SelectionSort {
    public static void main(String[] args) 
    {
        // 배열의 선언 및 초기화
        int[] arr = {30, 4, 36, 21, 5, 3, 11, 9, 30};

        // 값을 바꾸기 위한 임시 저장소 temp
        int temp;

        // for문을 위한 변수 i, j
        int i,j=0;


        // SelectionSort의 main code

        //arr[i]를 기준으로삼아,
        for(i=0; i<arr.length-1; i++)
        {
            // 그 뒤의 값들과 비교하여 sorting 해줌
            for(j=i+1; j<arr.length; j++)
            {
                if(arr[i] > arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }   // if end
            }   // second for end
        }   // first for end

        // Sorting 후의 배열 출력
        for(i=0; i<arr.length; i++)
        {
            System.out.print(arr[i]+" ");
        }
	}
}