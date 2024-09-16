#include <stdio.h>
int main(){
    int c;
    int n;
    int score[1000];
    double mean=0;

    
    
    scanf("%d",&c);
    
    for(int i=0;i<c;i++){
        scanf("%d",&n);
       double sum=0;
       int over_person=0;
        
        for(int j=0;j<n;j++){
            scanf("%d",&score[j]);      
            sum+=score[j];
        }
        mean=(double)sum/n;
        for(int j=0;j<n;j++){
            if(score[j]>mean){
                over_person++;
            }
        }
        
       printf("%.3f%%\n",(double)over_person*100/n);
       
    }
   return 0;
}

