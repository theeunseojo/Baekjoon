import java.util.*;
// 스코빌 지수가 가장 낮은 스코빌 지수 + 두번째.. * 2
// 모든 음식이 K 이상이 될때까지 반복
// return 최소 횟수 
// 모든 음식 10^7
// 완전탐색 & 정렬 -> 시간초과
// 1. minheap으로 정렬 2. 최소값이 K이상이될때까지 섞는다
class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> mh = new PriorityQueue<>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        for(int i = 0; i < scoville.length; i++){
            mh.add(scoville[i]);
        }
        
        int fir = mh.remove();
        
        
        while(!(fir >= K)){
            int sec = mh.remove();
            if(fir == 0 && sec == 0) return -1;
            fir += sec * 2;
            answer += 1;
        }
        return answer;
    }
}