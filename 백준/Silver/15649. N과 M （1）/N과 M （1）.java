

import java.io.*;
import java.util.*;

public class Main {

    static int n;
    static int m;
    public static int[] answer;
    public static boolean[] visited;

    static StringBuilder sb = new StringBuilder();

    public static void printAnswer(){
        for (int val : answer) {
            sb.append(val).append(' ');
        }
        sb.append('\n'); // 줄바꿈 추가
        return;
    }
    public static void choose(int curr){
        if(curr == m){
            printAnswer();
            return;
        }

        for(int num = 1; num <= n; num++){
            if(visited[num]){
                continue;
            }

            answer[curr] = num;
            visited[num] = true;
            choose(curr + 1);
            visited[num] = false;
        }

    }
   public static void main(String[] args) throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       StringTokenizer st = new StringTokenizer(br.readLine());

       n = Integer.parseInt(st.nextToken());
       m = Integer.parseInt(st.nextToken());

       answer = new int[m];
       visited = new boolean[n + 1];
       choose(0);

       System.out.println(sb);
   }
}