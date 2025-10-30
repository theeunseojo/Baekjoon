import java.util.Arrays;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        int[] temp = {};
        int index = 0;
        
        for(int[] arr : commands){
            // command 파싱 
            
            int start = arr[0] - 1;
            int end = arr[1];
            int position = arr[2] - 1;
            
            // 새로운 배열 생성 후 정렬 
            temp = Arrays.copyOfRange(array, start, end);
            Arrays.sort(temp);

            answer[index] = temp[position];
            index++;
        }
        return answer;
    }
}