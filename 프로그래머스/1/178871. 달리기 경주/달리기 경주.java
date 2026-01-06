// calling을 순회한다.
// player 조회한다. 
// 순서를 변경한다
// <플레이어 앞 사람 , 등수>
// <플레이어, 등수 - 1> 
// swap 배열
import java.util.*;
class Solution {
    public static Map<String, Integer> playerMap = new HashMap<>();
    public static Map<Integer, String> rankMap = new HashMap<>();
    
    public static void swap(String callee, int rank){
        // 앞지르기
        playerMap.replace(callee, rank - 1);
        
        // 플레이어 앞사람
        String front = rankMap.get(rank - 1);
        playerMap.replace(front, rank);
       
        // rank 수정
        rankMap.replace(rank, front);
        rankMap.replace(rank - 1, callee);
        
    }
    public static String[] solution(String[] players, String[] callings) {
        String[] answer = new String[players.length];
        // player - 등수 map
        
        
        playerMap.put(players[0], 1);
        rankMap.put(1, players[0]);
        
        for(int i = 1; i < players.length; i++){
            int rank = i + 1;
            playerMap.put(players[i], rank);
            rankMap.put(rank, players[i]);
        }
        
        // 앞지르기 
        for(String callee : callings){
            int rank = playerMap.get(callee);
            swap(callee, rank);
        }
        
        for (int i = 0; i < players.length; i++) {
            // i는 0부터 시작하니까, 등수는 i + 1
            answer[i] = rankMap.get(i + 1);
        }
        
       
        return answer;
    }
}