void swap(int *p,int *q){
    int t;
    t=*p;*p=*q;*q=t;
}

void sortBub(int *B,int n){
    int flag,i,j;
    flag=0;
    for(i=n;i>0;i--){
        for(j=0;j<i-1;j++){
            if(B[j]>B[j+1]){
                swap(&B[j],&B[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
        
    }
}

void sortSelc(int* B,int n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(B[j]<B[min])
                min=j;
            
        }
        swap(&B[i],&B[min]);
    }
}

void sortInser(int* B,int n){
     int i,j;
     for(i=1;i<n;i++){
         j=0;
         while(i>j){
                if(B[i]<B[j]){
                    swap(&B[j],&B[i]);
                }
             j++;    
            } 
     }

}

int partition(int* C,int l,int h){
    int i,j,x;
    x=C[h];
    i=l-1;
    for(j=l;j<h;j++){
        if(C[j]<=x){
            i+=1;
            swap(&C[i],&C[j]);
        }
    }
    swap(&C[i+1],&C[h]);
    return i+1;
}

void sortQuick(int* B,int l,int h){
    int q;
    if(l<h){
        q=partition(B,l,h);
        sortQuick(B,l,q-1);
        sortQuick(B,q+1,h);
    }
}


/* QuickSort using Linear Search
int partitionlinser(int* C,int l,int h){
    int i,j,x;
    i=l;j=h;
    x=C[l];
    while(true){
        do{
            i+=1;
        }while(C[i]>=x);
       do{
            j-=1;
        }while(C[j]<=x);
        if(i<j) swap(C[i],C[j]);
        else break;
        break;
    }
    swap(C[j],C[l]);
    return j;
}
void sortQuickLinSer(int* B,int l,int h){
    int q;
    if(l<h){
        cout<<" hd ";
        q=partitionlinser(B,l,h);
        sortQuickLinSer(B,l,q-1);
        sortQuickLinSer(B,q+1,h);
    }
}*/