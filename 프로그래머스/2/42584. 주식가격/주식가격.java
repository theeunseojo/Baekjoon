import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        
        for(int i = 0; i < prices.length; i++){
            
            for(int j = i + 1; j < prices.length; j++){
                int curr = prices[i];
                int future = prices[j];
                
                // 카운팅하기
                answer[i] += 1;
                
                // 현재가격보다 미래 가격이 떨어진다면
                if(curr > future){
                    break;
                }
            
            }
        }
        return answer;
    }
}