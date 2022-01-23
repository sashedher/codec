#include<stdio.h>
int main(){
    int c=0;
    for( int i=1;i<10000000;i+=2){
         int f=0;
        for( int j=2;j<i/2;j++){
            if(i%j==0){
                f=1;
                break;
            }
        }
        if(f==0){
            int s=0,n=i;

            while(n>0){
                s=s+n%10;
                n/=10;
            }
            if(s==14){
                // printf("%d \n",i);
                c++;
            }

        }
        
    }
    printf("%d",c);
    return 0;
}