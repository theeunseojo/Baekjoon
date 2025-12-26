

import java.util.Scanner;

public class Main {
    public static int[][] arr;
    public static StringBuilder sb = new StringBuilder();

    public static boolean isSame(int x, int y , int size){
        int original = arr[x][y];
        for(int i = x; i < x + size; i++){
            for(int j = y; j < y + size; j++){
                if(original != arr[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    public static void compress(int x, int y , int size){
        if(isSame(x, y, size)){
            sb.append(arr[x][y]);
            return;
        }

        int newSize = size / 2;
        // 4등분
        sb.append("(");
        compress(x, y, newSize);
        compress(x, y + newSize, newSize);
        compress(x + newSize, y, newSize);
        compress(x + newSize, y + newSize , newSize);

        sb.append(")");
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        arr = new int[n][n];

        for(int i = 0; i < n; i++){
            String line = sc.next();
            for(int j = 0; j < n; j++){
                arr[i][j] = line.charAt(j) - '0';
            }
        }

        compress(0, 0, n);
        System.out.print(sb.toString());
    }
}