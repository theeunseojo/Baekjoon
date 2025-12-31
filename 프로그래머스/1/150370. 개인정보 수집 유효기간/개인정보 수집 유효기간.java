import java.util.*;

class Solution {
    public static int DateToInt(String date){
        String[] splitData = date.split("\\.");
        int year = Integer.parseInt(splitData[0]);
        int month = Integer.parseInt(splitData[1]);
        int day = Integer.parseInt(splitData[2]);
        
        return year * 12 * 28 + month * 28 + day;
    }
    
    public static Map<String, Integer> splitTerms(String[] terms){
        Map<String, Integer> termList = new HashMap<>();
        for(String term : terms){
            String[] data = term.split(" ");
            termList.put(data[0], Integer.parseInt(data[1]));
        }
        return termList;
    }
    
    public List<Integer> solution(String today, String[] terms, String[] privacies) {
        List<Integer> answer = new ArrayList<>();
        Map<String,Integer> termList = splitTerms(terms);
        
        int todayData = DateToInt(today);
       
        // 개인정보 날짜 + 유효기간 <= 오늘이면
        // 파기해야할 개인정보 배열에 추가
        for(int i = 0; i < privacies.length; i++){
            String data = privacies[i];
            
            String[] list = data.split(" ");
            
            int privateDate = DateToInt(list[0]);
            
            int validDate = termList.get(list[1]) * 28;
            
            if(todayData >= privateDate + validDate){
                answer.add(i + 1);
            }
            
            
        }
       
        return answer;
    }
}
