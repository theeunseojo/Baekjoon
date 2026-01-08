import java.util.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        Stack<Character> st = new Stack<>();
        
        for(int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);
            // 우선 '(' 이거나 비어 있으면 push 
            // peek 값이 ( 이고 , 넣을게 ) 이면 pop 시킴 
            if(st.isEmpty()|| ch == '('){
                st.push(ch);
                
            }else if(st.peek() == '(' && ch == ')'){
                st.pop();
            }
        }
        
        // 스택에 아무 값이 남아있으면 false
        // 아무 값이 안 남아 있으면 true
        return st.isEmpty();
    }
}