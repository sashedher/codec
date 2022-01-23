#include <iostream>

using namespace std;

class Item{
    protected:
        int ID,Type,Price;
        string Name;
    public :
    	 Item(){
      
    }
    virtual void print(){
        cout<<" This Function! Well Implemented in Derived classes";      
    }
    float discountPrice(float rate){
        rate=Price*(1-rate);
        return rate;

    }

};

class Pen: public Item{
    public:
        string inkColor;
        float pointSize;
   public:
        Pen( int nID,int nType,int nPrice,std::string nName,std::string ninkColor,float npointSize){
            ID=nID;
            Price=nPrice;
            Type=nType;
            Name=nName;
            inkColor=ninkColor;
            pointSize=npointSize;
        }
    void print(){
        cout<<"\n==================== "<<"ID: "<<ID<<" ====================\n";
        cout<<"Name: "<<Name<<endl;
        cout<<"Price: $"<<Price<<"\tInk Color: "<<inkColor<<"\tPoint Size: "<<pointSize<<endl;
    }
};

class Folder: public Item{
    public:
        string color;
        bool expanding;
	public:
        Folder(int nID,int nType,int nPrice,std::string nName,std::string ncolor,bool nexpanding){
            ID=nID;
            Price=nPrice;
            Type=nType;
            Name=nName;
            color=ncolor;
            expanding=nexpanding;

        }
    void print(){
        cout<<"\n==================== "<<"ID: "<<ID<<" ====================\n"; 
        cout<<"Name: "<<Name<<endl;
        cout<<"Price: $"<<Price<<"\tcolor: "<<color<<"\tExpanding: "<<expanding<<endl;
    }
};

class Paper: public Item{
    public:
        string size;
        int quantity;
	public:
        Paper(int nID,int nType,int nPrice,std::string nName,std::string nsize,int nquantity){
            ID=nID;
            Price=nPrice;
            Type=nType;
            Name=nName;
            size=nsize;
            quantity=nquantity;
    }
    void print(){
    cout<<"\n==================== "<<"ID: "<<ID<<" ====================\n";
    cout<<"Name: "<<Name<<endl;
    cout<<"Price: $"<<Price<<"\tSize: "<<size<<"\tQuantity: "<<quantity<<endl;
    }
};