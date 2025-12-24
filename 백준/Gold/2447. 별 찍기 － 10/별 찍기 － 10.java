
import java.util.Scanner;

public class Main {
    static int n;
    static char[][] arr;
    // n 크기 사각형에서 (i,j) 좌표에 별을 찍는다.
    public static void draw_star(int size, int i , int j){
        if (size == 1) {
            arr[i][j] = '*';
            return;
        }
        // 구멍인가?
        if ((i / (size / 3)) % 3 == 1 && (j / (size / 3)) % 3 == 1) {
            return;
        }


        draw_star(size/3, i , j);
    }

   public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        arr = new char[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                arr[i][j] = ' ';
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                draw_star(n, i , j);
            }
        }

        // 출력 
       StringBuilder sb = new StringBuilder();
       for (int i = 0; i < n; i++) {
           for (int j = 0; j < n; j++) {
               sb.append(arr[i][j]);
           }
           sb.append('\n');
       }
       System.out.print(sb.toString());
   }
}