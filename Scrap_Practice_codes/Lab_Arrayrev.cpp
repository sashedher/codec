#include<iostream>
using namespace std; 
int l1=10,l2=6,l3=3,l4=12;
string *lb1=new string[l1];
string *lb2=new string[l2];
string *lb3=new string[l3];
string *lb4=new string[l4];
string *dep[4];

void View_Current_Status(){
   std::cout<<"\nlab1 --> "; 
    for (int i = 0; i < l1; i++) 
        std::cout <<i+1<<"."<< dep[0][i] << "  "; 
    
   std::cout<<"\nlab2 --> ";    
    for (int i = 0; i < l2; i++) 
        std::cout <<i+1<<"."<< dep[1][i] << "  "; 
    
    std::cout<<"\nlab3 --> ";    
    for (int i = 0; i < l3; i++) 
        std::cout <<i+1<<"."<< dep[2][i] << "  "; 
    
   std::cout<<"\nlab4 --> ";    
    for (int i = 0; i < l4; i++) 
        std::cout <<i+1<<"."<< dep[3][i] << "  ";   
  }
  
void Log_In(){
    int x,y;
    string name;
    std::cout<<"Enter Lab Number {1,2,3,4}\t\t:\t"; 
    std::cin>>x;
   switch (x)
    {
    case 1 : std::cout<<"Enter System Number between 1 to "<<l1<<"\t:\t";
             std::cin>>y;    
             break;
    case 2 : std::cout<<"Enter System Number between 1 to "<<l2<<"\t:\t";
             std::cin>>y;    
             break;
    case 3 : std::cout<<"Enter System Number between 1 to "<<l3<<"\t:\t";
             std::cin>>y;    
             break;
    case 4 : std::cout<<"Enter System Number between 1 to "<<l4<<"\t:\t"; 
             std::cin>>y;    
             break;
    default:std::cout<<"Invalid Lab Number\n";
    }
    if (dep[x-1][y-1]=="Free")
    {
        std::cout<<"Enter your User_Name to Login\t:\t";
        std::cin>>name;
        dep[x-1][y-1]=name;
        std::cout<<"Login Sucessful\n";
    }
    else
    {
        std::cout<<"Login Failed,System Already Assigned\n";
    }   
}

void Logout(){
    int x,y;
    std::cout<<"Enter Lab Number {1,2,3,4}\t\t:\t"; 
    std::cin>>x;
    switch (x)
    {
    case 1 : std::cout<<"Enter System Number between 1 to "<<l1<<"\t:\t";
             std::cin>>y;    
             break;
    case 2 : std::cout<<"Enter System Number between 1 to "<<l2<<"\t:\t";
             std::cin>>y;    
             break;
    case 3 : std::cout<<"Enter System Number between 1 to "<<l3<<"\t:\t";
             std::cin>>y;    
             break;
    case 4 : std::cout<<"Enter System Number between 1 to "<<l4<<"\t:\t"; 
             std::cin>>y;    
             break;
    default:std::cout<<"Invalid Lab Number\n";
    }
    if (dep[x-1][y-1]!="Free")
    {
        
        dep[x-1][y-1]="Free";
        std::cout<<"\nLogout Sucessful\n";
    }
    else
    {
        std::cout<<"\nLogout Failed,System not yet Assigned\n";
    }  
}

string* repeatArray(string* oldArray, int size,int osize) {
    int newSize = size + osize;
    string* newArray = new string[newSize];
    for (int i = 0; i < osize; i++) {
        newArray[i] = oldArray[i];
    }
    for (int i = osize; i < newSize; i++) {
        newArray[i] = "Free";
    }
   std::cout<<"Systems Added Sucessfully\n";
    delete [] oldArray;
    return newArray;
}

int addcom()
{
    int x,n;
    cout<<"Enter lab Number {1,2,3,4}\t\t:\t";
    cin>>x;
    switch(x){
        case 1 : std::cout<<"Enter No.of Computers to Add\t\t:\t";
                 cin>>n;
                 lb1=repeatArray(lb1,n,l1);
                 l1=n+l1;
                 dep[0]=lb1;
        break;
        case 2 :  std::cout<<"Enter No.of Computers to Add\t\t:\t";
                  cin>>n;
                  lb2=repeatArray(lb2,n,l2);
                  l2=n+l2;
                  dep[1]=lb2;
        break;
         case 3 : std::cout<<"Enter No.of Computers to Add\t\t:\t";
                  cin>>n;
                  lb3=repeatArray(lb3,n,l3);
                  l3=n+l3;
                  dep[2]=lb3; 
        break;
         case 4 : std::cout<<"Enter No.of Computers to Add\t\t:\t";
                  cin>>n;
                  lb4=repeatArray(lb4,n,l4);
                  l4=n+l4;
                  dep[3]=lb4;
        break;
        default : cout<<"Invalid Lab Number\n";
        return 0;
    }
    cout<<"\nLab Status After Adding  'N' Computers\n";
    View_Current_Status();
    return 0;
}

int main(){
    int c;
    char r;
    dep[0]=lb1,dep[1]=lb2,dep[2]=lb3,dep[3]=lb4;
    for(int i=0; i < l1; i++)                   /*Intializing systems of all labs to free intially*/
        lb1[i]="Free";
    for(int i=0; i < l2; i++)
        lb2[i]="Free";
    for(int i=0;i<l3;i++)
        lb3[i]="Free";
    for(int i=0;i<l4;i++)
        lb4[i]="Free";
    lb1[3]="Jack";                           /*Intializing some users to the Systems for login logout operations */
    lb1[6]="Mary";
    lb1[9]="Alice";
    lb2[1]="Jhon";                           
    lb2[4]="Mike";                       
    lb4[1]="Tom";
    lb4[8]="Jimmy";
    lb4[4]="Tim";
    lb4[9]="Kate";
    do{                                       /*do while loop for to run again*/
     std::cout<<"\n1.View Current Status\n2.Log_In\n3.Log_Out\n4.Exit\n5.Add any Computers to a lab\n";
      std::cout<<"\nEnter your choice from the above menu\t:\t";
      std::cin>> c;
     switch(c) {                            /*switch-case  statements for menu driven program*/
       case 1  : View_Current_Status();
            break; 
       case 2  : Log_In();
            break;
       case 3  : Logout();
            break;          
       case 4  : std::cout<<"\nProgram Exited\nTask Completed";
            return 0;
       case 5  : addcom();     
            break;                
       default : std::cout<<"invalid choice\n";
      }
      std::cout<<"\n\nDo you want to continue more {y/n*}\t:\t";
      std::cin>>r;
    }while(r=='y');
    cout<<"\nTask Completed Sucessfully\n";
    delete[] lb1;
    delete[] lb2;
    delete[] lb3;
    delete[] lb4;
    return 0;
}