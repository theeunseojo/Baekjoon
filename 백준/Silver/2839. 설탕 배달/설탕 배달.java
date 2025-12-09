
import java.util.Scanner;


    public class Main {

        public static void main(String[] args){
        // 입력
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int answer = -1;
        int cnt3 = 0;
        while(n >= 0){
            if(n % 5 == 0){
                answer = n / 5  + cnt3;
                break;
            }
            n = n - 3;
            cnt3 ++;

        }
        System.out.println(answer);


    }

}
