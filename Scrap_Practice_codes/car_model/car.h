#include<string>
using std::string;
class car{
    private:
        int  year,price;
        string vin,make,model;
    public:
        car(){
            year=1993;
            price=43000;
            vin="1GD312CG1CF027610";
            make="Lexus";
            model="LS";
        }
        car(string newvin,string newmake,string newmodel,int newyear,int newprice){
            year=newyear;
            price=newprice;
            vin=newvin;
            make=newmake;
            model=newmodel;    
        }
        void setVin(string newvin);
        void setMake(string newmake);
        void setModel(string newmodel);
        void setYear(int newyear);
        void setPrice(int newprice);
        string getVin();
        string getModel();
        string getMake();
        int getYear();
        int getPrice();
        void print();
};