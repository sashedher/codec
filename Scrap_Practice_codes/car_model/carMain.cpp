#include<iostream>
#include"car.h"
#include<iomanip>
#include<fstream>
using namespace std;
car noofcars[250];
int x=0;
void printData(){
    for (int i = 0; i < x; i++)
        noofcars[i].print();
    
}

void printMake(){
    string make;
    int flag=1;
    cout<<"Enter Car Manufactured by {Make}: ";
    cin>>make;
    for (int i = 0; i < x; i++){
        if(noofcars[i].getMake()==make){
             flag=0;
             noofcars[i].print();
        }
    }
    if(flag==1)
        cout<<"No cars found manufactured by "<<make<<endl;
}

void printPrice(){
    int price,flag=1;
    cout<<"Enter Price : ";
    cin>>price;
    for (int i = 0; i < x; i++){
        if(noofcars[i].getPrice()<=price){
             flag=0;
             noofcars[i].print();
        }
    }
    if(flag==1)
        cout<<"No cars found with in price "<<price<<endl;
}

int main(){
 string vin,make,model;
 int year,price,n;
 char a;
 car r;

    ifstream newfile;
    newfile.open("cardata.txt");
    if (newfile.fail()){
        cout << "File CARSDATA not Found!\n";
        return 0;
    }
    else {
        while (newfile >> vin >> make >> model >> year >> price)
        {
            car c(vin,make, model, year, price);
            noofcars[x] = c;
            x++;
        }
    }
    newfile.close();
   
     r.print();                           //printing Object details invoked using default constructer
   
   r.setVin("4A4AP3AU0EE129880");         //using Set functions for object r
   r.setMake("Nissan");
   r.setModel("370Z");
   r.setYear(2011);
   r.setPrice(39500);

   vin=r.getVin();                         //using Get functions for object r ,for data assigned using set funtions
   make=r.getMake();
   model=r.getModel();
   year=r.getYear();
   price=r.getPrice();
                                            //printing data collected from get functions
   cout<<vin<<"\t"<<make<<"\t"<<model<<"\t"<<year<<"\t"<<price<<endl;
   
    do{
      std::cout<<"\n1.View all cars\n"<<"2.View car by Make\n"<<"3.View car by price\n"<<"4.Exit Program\n";
      std::cout<<"\nEnter your choice from the above menu : ";
      cin>> n;
    
     switch(n) {
       case 1  :printData();
            break; 
       case 2  :printMake();
            break;
       case 3  :printPrice();
            break;
       case 4  :std::cout<<"\nProgram Exited";
            return 0;
            break;                
       default : std::cout<<"Invalid Choice\n";
      }
      std::cout<<"\nDo you want to continue more {'y'-to continue/type anyother to exit} : ";
      cin>>a;
    }while(a=='y');
   std::cout<<"\nTask completed\nProgram Exited";
return 0;
}