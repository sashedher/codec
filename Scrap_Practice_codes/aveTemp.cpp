#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<iomanip>
using std::setw;
using namespace std;
int main(){
   int c=0,sum=0,tem;
   float avg=0;
   std::string city;
   fstream newfile;
   newfile.open("tempData.txt",ios::in); //open a file to perform read operation using file object
   if (newfile.is_open()){   //checking whether the file is op
      string tp;
      while(getline(newfile, tp)) //read data from file object and put it into string.
      {
         if(tp.empty())
            continue;
 
         std::istringstream iss(tp);
 
         for(std::string word; iss >> word;)
         {
          c++;
          if(c==1)
          {
            city=word;
            std::cout<<setw(10)<<"City :"<<city;
          }
          if(c>1)
          {
            tem=stoi(word);
            sum=sum+tem;
          }
          
        }
        avg=(float)sum/(c-1);
       std::cout<<setw(70)<<"Average Temperature :"<<avg;  
       std::cout<<"\n";
        c=0;
        sum=0;
        avg=0;
      }
        newfile.close(); //close the file object.
   }
}
