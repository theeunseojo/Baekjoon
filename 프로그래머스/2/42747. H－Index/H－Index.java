import java.util.Arrays;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;

        Arrays.sort(citations);
        
        int n = citations.length;
        for(int i = 0; i < n; i++){
            int hIndex = n - i;
            
            if(citations[i] >= hIndex){
                return hIndex;
            }
        
        }
        return answer;
    }
}