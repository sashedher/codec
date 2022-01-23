#include<iostream>
#include<string>
#include<fstream>
#include <sstream>
using namespace std;
int main(){
    int a=0,x=0;
    string name;
 fstream newfile;
    newfile.open("data.txt",ios::in);
    if (newfile.is_open()){  //checking whether the file is op
      string tp;
      while(getline(newfile, tp)){ //read data from file object and put it into string.
             if(tp.empty())
                continue;
        std::istringstream iss(tp);
        for(std::string word; iss >> word;){
            x++;
            if(x==1)
               name=word;
            else if(x!=1)         
               a=word.size();
         }   
        
        x=0;
        cout<<name<<" is "<<a<<" years old\n";
        a=0;
      }
    }
    newfile.close();

}