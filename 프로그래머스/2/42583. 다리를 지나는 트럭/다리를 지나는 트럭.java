import java.util.*;

class Solution {
    
    public class Truck{
        int w;
        int t;
        Truck(int weight , int in_time){
            this.w = weight;
            this.t = in_time;
        }
    }
    
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        int currW = 0;
        
        Queue<Truck> waitQ = new LinkedList<>();
        Queue<Truck> bridgeQ = new LinkedList<>();
        
        // init 
        for(int w : truck_weights){
            waitQ.offer(new Truck(w, 0));
        }
        
       
        
        
        while(!waitQ.isEmpty() || !bridgeQ.isEmpty()){
            // 다리에 올라가는 시간 
            answer ++;
            
            // 다리에 있는 트럭 중 도착 처리
            if(!bridgeQ.isEmpty()){
                Truck head = bridgeQ.peek();
                
                // 현재 도착했는가?
                if(head.t + bridge_length == answer){
                    bridgeQ.poll();
                    currW -= head.w;
                }
            }
            // 다리에 올라갈 수 있는가 
            // 다리에 존재하는 트럭의 무게 + 지나갈 트럭 무게 <= W && 다리에 놓인 트럭대수 < 최대 BL
            if(!waitQ.isEmpty()){
                Truck next = waitQ.peek();
                
                if(currW + next.w <= weight && bridgeQ.size() < bridge_length){
                    
                    waitQ.poll();
                    // 진입시간 무게 기록 
                    currW += next.w;
                    next.t = answer;
                    // 다리 적재 
                    bridgeQ.offer(next);
                }
            }
           
        }
        
        return answer;
    }
}