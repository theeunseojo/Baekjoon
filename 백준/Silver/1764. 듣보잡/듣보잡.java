

import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        HashSet<String> people = new HashSet<>();

        List<String> list = new ArrayList<>();


       for(int i = 0; i < n + m; i++){
           String input = sc.next();

           if(people.contains(input)){
               list.add(input);
           }else{
               people.add(input);
           }
       }

        //sort
        Collections.sort(list);
        System.out.println(list.size());
        for(String str: list){
            System.out.println(str);
        }




    }
}