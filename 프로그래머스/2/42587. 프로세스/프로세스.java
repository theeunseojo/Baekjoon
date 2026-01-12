import java.util.*;
// A B C D
// 2 1 3 2
// C D A B 
// 3 2 2 1 

// location 2 C => return 1 
// 원래 location index -> 우선순위 정렬된 위치 
// 우선순위 - 프로세스명

class Solution {
    
    // 원래 location 프로세스1, 프로세스2, 프로세스3, 프로세스4
    // 2 1 3 2 
    // location : 우선순위 = 3 - 3, 4 - 2 , 1 - 2, 2 - 1 
    // count 세기 
    
    public class Process{
        int location;
        int priority;
        
        Process(int location, int priority){
            this.location = location;
            this.priority = priority;
        }
    }
    
    public int solution(int[] priorities, int location) {
        int answer = 0;
        Queue <Process> q = new LinkedList<>();
        Queue <Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        // q에 저장
        // pq에 우선순위 저장
        // locaiton : 우선순위 
        for(int i = 0; i < priorities.length; i++){
            q.add(new Process(i, priorities[i]));
            pq.add(priorities[i]);
        }
        
        int count = 0; 
    
        while(!q.isEmpty()){
            // q에서 꺼낸 값과 우선순위를 비교한다.
            Process curr = q.poll();
            int currP = curr.priority;
            int currL = curr.location;
            // 같지 않으면
            // q에 다시 넣음
            // 같으면 
            // count 증가 & 우선순위에서 제거 
            // location과 count가 일치하는지 확인 
            if(currP == pq.peek()){
                count++;
                pq.poll();
                if(currL == location){
                    answer = count;
                }
            }else{
                q.add(curr);
            }
            
        }
        
        return answer;
    }
}