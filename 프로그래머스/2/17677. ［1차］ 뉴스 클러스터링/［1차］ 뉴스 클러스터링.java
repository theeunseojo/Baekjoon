import java.util.*;

class Solution {
    
    public static List<String> breakString(String str){
        List<String> list = new ArrayList<>();
        
        
        for(int i = 0; i < str.length() - 1; i++){
            // 소문자로 통일
            String newStr = str.substring(i, i + 2).toLowerCase();
            // 알파벳인지 확인
            if(isAlphabet(newStr)){
                 list.add(newStr);
            }
            
        }
        
        return list;
    }
    
    public static boolean isAlphabet(String str){
        for(int i = 0; i < str.length(); i++){
            char ch = str.charAt(i);
            if(ch >= 'a' && ch <= 'z'){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
    
    public int solution(String str1, String str2) {
        int answer = 0;
        List<String> list1 = new ArrayList<>();
        List<String> list2 = new ArrayList<>();
        
        // 1. 두글자씩 끊기 & 소문자로 통일하기 & 특수문자 
        list1 = breakString(str1);
        list2 = breakString(str2);
        
        int sizeOfList2 = list2.size();
        List<String> inter = new ArrayList<>();
       
       
        for (String s : list1) {
        if (list2.contains(s)) { // list2에 있는 단어라면
            inter.add(s);     // 교집합에 추가
            list2.remove(s);    
        }
    }

        // 합집합 크기 = list1 크기 + list2 크기 - 교집합 크기 
        int unionSize = list1.size() + sizeOfList2 - inter.size();
        
        if(unionSize == 0 ){
            return 65536;
        }else{
             double jad = (double) inter.size() /  unionSize;
            
             answer = (int) (jad * 65536);
        }
      
    
        return answer;
    }
}