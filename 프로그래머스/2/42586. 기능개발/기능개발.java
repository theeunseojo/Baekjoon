import java.util.*;
// 진행해야하는 요일 배열을 만든다.
// progresses + speeeds * n 에서 n을 구한다. 
// 각 n을 배열에 저장한다.

// 큐에 차례대로 넣는다.
// 앞의 숫자 < 뒤의 숫자 => 배포가 새로 시작
// 지금까지 센 배포 기능 갯수 세어서 배열에 저장 
// 앞의 숫자 >= 뒤의 숫자 => 함께 배포 


class Solution {
    public static Queue <Integer> getDate(int[] progresses, int[] speeds){
        Queue <Integer> list = new LinkedList<>();

        for(int i = 0; i < speeds.length; i++){
            int remain = 100 - progresses[i];
            int day = remain / speeds[i];
            // 나머지가 있다면 
            if (remain % speeds[i] > 0){
                day += 1;
            }

            list.add(day);
        }

        return list;
    }

    public List<Integer> solution(int[] progresses, int[] speeds) {
        List<Integer> answer = new ArrayList<>();
        Queue <Integer> list = getDate(progresses, speeds);
        
        int standard = list.poll();
        int count = 1;
        
        while(!list.isEmpty()){
            
            // 기준 >= 숫자 => 함께 배포
            if(standard >= list.peek()){
                list.poll();
                count++;
            }
            // 기준 < 숫자 => 배포가 새로 시작 
            else{
                answer.add(count);
                count = 1;
                standard = list.poll();
            }
             
        }
        answer.add(count);
        return answer;
    }
}