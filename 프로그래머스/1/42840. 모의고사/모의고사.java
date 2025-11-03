import java.util.HashMap;
import java.util.Map;
import java.util.Collections;
import java.util.List;

class Solution {
    public int[] solution(int[] answers) {
        int[] answer = {};
        
        int[] pattern1 = {1,2,3,4,5};
        int[] pattern2 = {2,1,2,3,2,4,2,5};
        int[] pattern3 = {3,3,1,1,2,2,4,4,5,5};
        
        Map<Integer, Integer> hs = new HashMap<>();
        
        for(int i = 0; i < answers.length; i++){
            // 1번 맞은 갯수
            if(pattern1[i % pattern1.length] == answers[i]){
                hs.put(1, hs.getOrDefault(1, 0) + 1);
            }
            // 2번 맞은 갯수
            if(pattern2[i % pattern2.length] == answers[i]){
                 hs.put(2, hs.getOrDefault(2, 0) + 1);
            }
            // 3번 맞은 갯수 
            if(pattern3[i % pattern3.length] == answers[i]){
                 hs.put(3, hs.getOrDefault(3, 0) + 1);
            }
        }
        
        // 정렬 
        
        // 최고점수에 맞는 애들만 리스트 만들어서 중복자 처리하기 
        Integer maxScore = Collections.max(hs.values());
        
        answer = hs.entrySet().stream()
            .filter(entry -> entry.getValue().equals(maxScore))
            .map(entry -> entry.getKey())
            .mapToInt(n->n)
            .toArray();
        
        
        
        
        return answer;
    }
}