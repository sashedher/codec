#include<iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<iomanip>
using namespace std;
using std::setw; 
char tr[16][31];
void View_Current_Seats()
{
     cout<<setw(3)<<"";
     for (int j = 1; j < 31; ++j)
         cout<<setw(3)<<j;
     cout<<"\n";    
     for (int i = 1; i < 16; ++i) {
           cout<<setw(3)<<i;
        for (int j = 1; j < 31; ++j) {
                 cout<<setw(3)<<tr[i][j];
        }
        cout<<"\n";
     }
}
void Sell_Ticket(){
    int row,col;
    cout<<"enter row number \n";
    cin>>row;
    cout<<"enter column number\n";
    cin>>col;
    if (tr[row][col]!='-')
    {
       cout<<"Selecte Seat not available for booking\n ";
    }
    else
    {
       tr[row][col]='#';
       cout<<"Booking Confirmed\n";
    }
}
void Refund_Ticket(){
    int row,col;
    cout<<"enter row number\n";
    cin>>row;
    cout<<"enter column number\n";
    cin>>col;
    if (tr[row][col]!='#')
    {
       cout<<"Selecte Seat not available for refund\n ";
    }
    else
    {
       tr[row][col]='-';
       cout<<"Refund Sucessful\n";
    }
}
void Save_Data_File(){
    
    ofstream myOutputFile;
    myOutputFile.open("cinema_updated1.txt");
      for (int i = 1; i < 16; ++i) {
        for (int j = 1; j < 31; ++j) {
            if (tr[i][j]=='#')
            {
                   myOutputFile<<i<<" "<<j<<"\n";
            }
         }    
      }
      myOutputFile.close();
      cout<< "Data saved\n";
   
}
int main(){ 
 int n,row,col,temp,x=0;
 char r;
    for (int i = 1; i < 16; ++i) {
        for (int j = 1; j < 31; ++j) {
          //  cin >> numbers[i][j]; 
          tr[i][j]='-';
        }
    }
    fstream newfile;
    newfile.open("cinema_updated1.txt",ios::in);
    if (newfile.is_open()){  //checking whether the file is op
      string tp;
      while(getline(newfile, tp)){ //read data from file object and put it into string.
             if(tp.empty())
                continue;
        std::istringstream iss(tp);
        for(std::string word; iss >> word;){
            x++;
            if(x==1)
               row=stoi(word);
            if(x==2)   
               col=stoi(word);
         }   
       // cout<<row<<"\t"<<col<<"\n";
        tr[row][col]='#';
        x=0;
      }
    }
    newfile.close();
   do{
      cout<<"1.View Current Seats\n"<<"2.Sell Ticket\n"<<"3.Refund Ticket\n"<<"4.Save Data File\n"<<"5.Exit Program\n";
      cout<<"Enter your choice from the above menu\n";
      cin>> n;
    
     switch(n) {
       case 1  :View_Current_Seats();
            break; 
       case 2  :Sell_Ticket();
            break;
       case 3  :Refund_Ticket();
            break;
       case 4  :Save_Data_File();
            break;
       case 5  :cout<<"program exited\t";
            return 0;
            break;                
       default : cout<<"invalid choice\n";
      }
      cout<<"do you want to continue more then press 'y' to exit press any other key\n";
      cin>>r;
    }while(r=='y');
    cout<<"task completed\n";
   return 0;
}