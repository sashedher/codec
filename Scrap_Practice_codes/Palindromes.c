#include<stdio.h>
int main()
{
   int c=0;
   for(int i=0;i<100000;i++){
	   int s=0,t=i;
	   while(t>0){
		   s=s*10+t%10;
		   t/=10;
	   }
	   if(s==i)
	    c++;
   }                
    printf("%d",c);   
  return 0;
}
// int k,c=0;


// 		for(k=0;k<100000;k++)
// 		{
// 			if(k<10){
// 				c++;
// 			}
			
// 			else if(k>9 && k<100)
// 			{
				
// 				if(k/10==k%10){
// 					printf("L15-%d\n",k);
// 					++c;
// 				}
// 			}
// 			else if(k>99 && k<1000)
// 			{
// 				//printf("%d",k);
// 				if((k/100)==(k%10))
// 					c++;
// 			}
// 			else if(k>999 && k<10000)
// 			{
// 				if((k/1000==k%10) && (( (k/100)%10)==( (k/10)%10) ))
// 						c++;
// 			}
// 			else if(k>9999 && k<100000)
// 			{
// 				if((k/10000==k%10) && ((k/1000)%10==((k/10)%10)))
// 					c++;
// 			}
			
			
// 		}