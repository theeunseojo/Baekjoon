import java.util.*;
class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        Map<String, Integer> map = new HashMap<>();
        
        
        for(int i = 0; i < participant.length; i++){
            String key = participant[i];
            if(map.containsKey(key)){
                map.put(key, map.get(key) + 1);
               
            }
            else{
                map.put(key,1);
            }
        }
        
        // 2. 동명이인 제거 
        for(int i = 0; i < completion.length; i++){
            String key = completion[i];
            map.put(key, map.get(key) - 1);
        }
        
        // 3. 제거 안된 참가자 확인 
        for(String s : map.keySet()){
            if(map.get(s) > 0){
                answer = s;
            }
        }
        return answer;
    }
}