

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

        long result = 0;
        long pow = 1;
        for(int i = 0; i < length; i++){

            int index = str.charAt(i) - 'a' + 1;
            //System.out.println(index);

            result +=  arr[index] * pow;
            pow = (pow * 31) % 1234567891;
        }

        System.out.println(result % 1234567891);
    }
}