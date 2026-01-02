
import java.util.*;

class Solution {
    public static Map<String, HashSet<String>> list = new HashMap<>();
    public static Map<String, Integer> mailCount = new HashMap<>();
    public static void makeList(String[] id_list, String[] report_list){
        // make index 
        for(String id : id_list){
            list.put(id, new HashSet<>());
            mailCount.put(id, 0);
        }
        
        // make value
        for(String report : report_list){
            String[] split = report.split(" ");
            String reporter = split[0];
            String target = split[1];
            
            list.get(target).add(reporter);
        }
    }
    
    // 신고당한 횟수가 k이상이면 , 신고한 사람에게 메일로 발송한다.
    public static void makeMailCount(int k){
        
        for(String target : list.keySet()){
            HashSet<String> reporters = list.get(target);
            int reportedSize = reporters.size();
            
            if(reportedSize >= k){
                // reporters 순회하기 
                for(String reporter : reporters){
                    // mailCount
                    mailCount.put(reporter, mailCount.get(reporter) + 1);
                }
            }
        }
    }
    
    public int[] solution(String[] id_list, String[] report, int k) {
        
        // make list 신고당한사람 : 신고한사람 
        makeList(id_list, report);
        // 메일발송 
        makeMailCount(k);
        
       int[] answer = new int[id_list.length];
        for (int i = 0; i < id_list.length; i++) {
            answer[i] = mailCount.get(id_list[i]);
        }
       
        return answer;
    }
}