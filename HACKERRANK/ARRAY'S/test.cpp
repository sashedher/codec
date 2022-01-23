#include<stdio.h>
int main(){
    int a[5]={-2,72,99,1,-62};
    int *p=(int*)(&a+1);
    printf("%d,%d",*(a+1),*(p-1));
    return 0;

}