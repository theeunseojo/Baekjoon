class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = {0, 0};
        
        
        int width  = 0;
        int height = 0;
        int total = brown + yellow;
        
        for(int h = 3; h < total; h++){
            if(total % h == 0){
                height = h;
                width = total / h;
                
                if((width - 2) * (height -2) == yellow){
                    answer[0] = width;
                    answer[1] = height;
                    return  answer;
                }
            }
        }
       
        
        return answer;
    }
}