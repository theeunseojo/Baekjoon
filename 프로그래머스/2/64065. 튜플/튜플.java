// 문자열을 파싱하여 리스트로 만든다
// 어떻게 파싱할건가? 
// {{}}을 우선 파싱한다.
// },{ 로 쪼갠다. 
// 다시 , 로 쪼갠다. 

import java.util.*;

class Solution {
    
    public static String[] parseString(String s){
        String[] list;
        // {{ }} 을 제거한다.
        int len = s.length();
        // start index = 2 ~ end index = len - 2까지 자른다.
        s = s.substring(2, len - 2);
        
        // },{ 을 기준으로 split
        list = s.split("\\},\\{");
      
        // 길이 오름차순
        Arrays.sort(list, (a, b) -> a.length() - b.length());
        return list;  
    }
    
    public static List<Integer> converToInt(String[] parse){
        List<Integer> answer = new ArrayList<>();
        // 배열을 돌면서
        // , split 
        for(String str : parse){
            String[] temp = str.split(",");
            
            // int 형 변환
            for(String numStr: temp){
                int num = Integer.parseInt(numStr);
                
                // 있으면 넣지 않는다.
                if(!answer.contains(num)){
                    answer.add(num);
                }
            }
        }
        return answer;
    }
    public int[] solution(String s) {
       
        String[] parse = parseString(s);
        List<Integer> list = converToInt(parse);
        int[] answer = new int[list.size()];
        for(int i = 0; i < list.size(); i++){
            answer[i] = list.get(i);
        }
        
        return answer;
    }
}