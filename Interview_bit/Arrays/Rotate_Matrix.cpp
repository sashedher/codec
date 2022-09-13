// https://www.interviewbit.com/problems/rotate-matrix/

void rotate(int** A, int n11, int n12) {
    int i,j,temp;
    for(i=0;i<n11;i++){
        for(j=0;j<n12;j++){
            if(i<j){
                temp=A[i][j];
                A[i][j]=A[j][i];
                A[j][i]=temp;
            }
        }
    }
   for(i=0;i<n11;i++){
        for(j=0;j<n12/2;j++){
            temp=A[i][j];
            A[i][j]=A[i][n12-j-1];
            A[i][n12-j-1]=temp;

        }
   }
}