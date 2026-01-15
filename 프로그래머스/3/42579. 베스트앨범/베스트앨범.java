import java.util.*;

class Solution {
    
    public class Genre{
        int total;
        List<Song> song;
        Genre(int total, List<Song> song){
            this.total = total;
            this.song = song;
        }
    }
    
    public class Song{
        int id;
        int play;
        Song(int id, int play){
            this.id = id;
            this.play = play;
        }
    }
    
    public List<Integer> solution(String[] genres, int[] plays) {
         List<Integer> answer = new ArrayList<>();
        Map<String, Genre> mp = new HashMap<>();
        
        // 장르별로 노래 저장 
        for(int i = 0; i < plays.length; i++){
            String key = genres[i];
            // init 
            if (!mp.containsKey(key)) {
                mp.put(key, new Genre(0, new ArrayList<>()));
            }
            Genre ge = mp.get(key);
            
            // update
            ge.total += plays[i];
            ge.song.add(new Song(i, plays[i]));
        }
        // 변환
        List<Genre> genreList = new ArrayList<>(mp.values());
        // 정렬 
        // 장르 총 재생횟수 내림차순 
        Collections.sort(genreList, (o1, o2) -> o2.total - o1.total);
        // 장르 내 재생 횟수 내림차순, 같다면 고유번호가 낮은 먼저 노래
        for(Genre g : genreList){
            Collections.sort(g.song, (o1, o2) -> {
                // 재생횟수가 같다면 고유번호가 올림차순
                if(o1.play == o2.play){
                    return o1.id - o2.id;
                }
                
                return o2.play - o1.play;
            });
            
             // 2개씩 선정해서 answer 저장
            for(int i = 0; i < g.song.size() && i < 2; i++){
                Song tmp = g.song.get(i);
                answer.add(tmp.id);
            }
        }
        
       
        
       
        return answer;
    }
}