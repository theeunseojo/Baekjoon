

import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        // H = 항의번호 * 31^항의번호 mod 1234567891
        Scanner sc = new Scanner(System.in);

        int length = sc.nextInt();
        String str = sc.next();

        int[] arr = new int[27];

        for(int i = 1; i <= 26; i++){
            arr[i] = i;
        }

        int result = 0;
        for(int i = 0; i < length; i++){

            int index = str.charAt(i) - 'a' + 1;
            //System.out.println(index);
            result = (result + (int)Math.pow(31, i) * arr[index]) % 1234567891;
        }

        System.out.println(result);
    }
}