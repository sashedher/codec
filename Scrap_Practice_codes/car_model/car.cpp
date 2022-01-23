#include"car.h"
#include<iostream>
using namespace std;
void car::setVin(string newvin){
    vin=newvin;
}
void car::setMake(string newmake){
    make=newmake;
}
void car::setModel(string newmodel){
    model=newmodel;
}
void car::setYear(int newyear){
    year=newyear;
}
void car::setPrice(int newprice){
    price=newprice;
}
string car::getVin(){
   return vin;
}
string car::getModel(){
    return model;
}
string car::getMake(){
    return make;
}
int car::getYear(){
    return year;
}
int car::getPrice(){
    return price;
}
void car::print(){
     cout<<vin<<"\t"<<make<<"\t"<<model<<"\t"<<year<<"\t"<<price<<endl;
}

