/*#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<iomanip>
#include"car.h"
using namespace std;
using std::setw;
string cars[250][5];
void printData(){
     for(int i=0;i<250;i++){
        for(int j=0;j<5;j++){
            std::cout<<cars[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
}

void printMake(){
     string make;
     int flag=1;
std::cout<<"print by Make\n";
std::cout<<"Enter car Make by : ";
cin>>make;
std::cout<<"print by Make\n";
 for(int i=0 ; i< 250; i++){
      if(cars[i][1]==make){
           flag=0;
           for(int j=0 ;j<5; j++){
               std::cout<<cars[i][j]<<"\t";
          }
          std::cout<<"\n";
     }
     
 }
     if (flag==1)
          cout<<"No cars Available,Produced by \n"<<make;
}

void printPrice(){
     int flag=1,price;
std::cout<<"Enter car Price by : ";
cin>>price;
std::cout<<"Printing Cars by Price\n";
 for(int i=0 ; i< 250; i++){
      if(stoi(cars[i][4])<=price){
           flag=0;
           for(int j=0 ;j<5; j++){
               std::cout<<cars[i][j]<<"\t";
          }
          std::cout<<"\n";
     }
 }
     if (flag==1)
          cout<<"No cars Available lessthan \n"<<price;
}

int main(){
    string w;
    char a;
    int l,n,z;
    int x=0,y=0;
    car r;                            //creating object for class and  printing object information using member functions
    car r1("5TFCW5F10CX389971","BMW","X5_M",2010,16500);
    w=r.getVin();
    std::cout<<"car vin : "<<w<<"\n";
    w=r.getMake();
    std::cout<<"car make : "<<w<<"\n";
    w=r.getModel();
    std::cout<<"car model : "<<w<<"\n";
    l=r.getYear();
    std::cout<<"car year : "<<y<<"\n";
    l=r.getPrice();
    std::cout<<"car price : "<<l<<"\n";
    r.print();
    w=r1.getVin();
    std::cout<<"car vin : "<<w<<"\n";
    w=r1.getMake();
    std::cout<<"car make : "<<w<<"\n";
    w=r1.getModel();
    std::cout<<"car model : "<<w<<"\n";
    l=r1.getYear();
    std::cout<<"car year : "<<y<<"\n";
    l=r1.getPrice();
    std::cout<<"car price : "<<l<<"\n";
    r1.print();

    fstream newfile;
    newfile.open("cardata.txt",ios::in);
    if (newfile.is_open()){  //checking whether the file is op
      string tp;
      while(getline(newfile, tp)){ //read data from file object and put it into string.
             if(tp.empty())
                continue;
        std::istringstream iss(tp);
        for(std::string word; iss >> word;){
            cars[x][y]=word;
            y++;
         }
         y=0;  
         x++; 
      }
    }
    newfile.close();
     do{
      std::cout<<"1.View all cars\n"<<"2.View car by Make\n"<<"3.View car by price\n"<<"4.Exit Program\n";
      std::cout<<"Enter your choice from the above menu : ";
      cin>> n;
    
     switch(n) {
       case 1  :printData();
            break; 
       case 2  :printMake();
            break;
       case 3  :printPrice();
            break;
       case 4  :std::cout<<"program exited\t";
            return 0;
            break;                
       default : std::cout<<"invalid choice\n";
      }
      std::cout<<"do you want to continue more {y/n*} : ";
      cin>>a;
    }while(a=='y');
   std::cout<<"Task completed\n Program exited";
   return 0;
}*/