#include <iostream>
#include <fstream>
#include "item.h"

using namespace std;

void loadDataset(Item** &itemArr, int &N, string fileName){

	//Open the file
	ifstream inFile;
	inFile.open(fileName.c_str());

	//Read the first line
	string line;
	getline(inFile,line);
	N = atoi(line.c_str());

	//Allocate space for all items in the file
	itemArr = new Item*[N];

	//Read each item and load into the array
	int i = 0;
	while(getline(inFile,line)){

		int ind1 = line.find("#");
		int ind2 = line.find("#",ind1+1);
		int ind3 = line.find("#",ind2+1);
		int ind4 = line.find("#",ind3+1);
		int ind5 = line.find("#",ind4+1);

		int ID = atoi(line.substr(0,ind1).c_str());
		int type = atoi(line.substr(ind1+1, ind2-ind1-1).c_str());
		int price = atoi(line.substr(ind2+1, ind3-ind2-1).c_str());
		string name = line.substr(ind3+1, ind4-ind3-1);


		if(type == 1){//If the item is a Pen
			string inkColor = line.substr(ind4+1, ind5-ind4-1);
			float pointSize = atof(line.substr(ind5+1).c_str());

			//Create a Pen object and send it to item array
			itemArr[i] = new Pen(ID,type,price,name,inkColor,pointSize);
		}
		else if (type == 2){//If the item is a Folder
			string color = line.substr(ind4+1, ind5-ind4-1);
			bool expanding = atoi(line.substr(ind5+1).c_str());

			//Create a Folder object and send it to item array
			itemArr[i] = new Folder(ID,type,price,name,color,expanding);
		}
		else{//If the item is a Paper
			string size = line.substr(ind4+1, ind5-ind4-1);
			int quantity = atof(line.substr(ind5+1).c_str());

			//Create a Paper object and send it to item array
			itemArr[i] = new Paper(ID,type,price,name,size,quantity);
		}
		i++;
	}
	inFile.close();
}

int main(){

	string fileName = "dataset.txt"; //Dataset file

	//Item array to hold all different items
	Item** itemArr;

	//Size of the array
	int N;

	//Load the array with items
	loadDataset(itemArr,N,fileName);

	//Print all items in the array
	for(int i=0;i<N;i++){
		itemArr[i]->print();
		cout << "--> DISCOUNTED PRICE: $" << itemArr[i]->discountPrice(0.15) << endl;
	}

	return 0;
}
// #include<iostream>

// using namespace std;
// class Node {
//       private:
//          int data;
//          Node *next,*prev;
//     public:
//         Node(int d,Node* n,Node* p){
//             data=d;
//             next=n;
//             prev=p;
//         }
//         Node(){
//             next=NULL;
//             prev=NULL;
//         }
//         Node* getPrev(){return prev;}
//         Node* getNext(){return next;}
//         void setNext(Node* n){next=n;}
//         void setPrev(Node* p){prev=p;}
//         int getData(){return data;}
//         void setData(int x){data=x;}
// };

// class Dlist{
// private:
//     Node* head=NULL,*tail=NULL;
// public:
//     int count=0;
//     Dlist(){
//         head=NULL;
//         tail=NULL;
//     }
//     void insertNode(int d){
//         count++;
//         Node* temp=new Node(d,NULL,NULL);
//         if(temp==NULL){return ;}
//         if(head==NULL){ 
//             head=temp;
//             tail=head;
//             return;

//         }
//         else{
//             temp->setNext(head);
//             head->setPrev(temp);
//             head=temp;
//             head->setPrev(NULL);
//         }
//         return;
//     }
//     void insertTail(int z){
//         count++;
//          Node* temp=new Node(z,NULL,NULL);
//          if(temp==NULL){return ;}
//          if(tail==NULL){
//              head=temp;
//              tail=head;
//              return;
//          }
//         else{
//             temp->setPrev(tail);
//          tail->setNext(temp);
//          tail=tail->getNext();
//         tail=temp;
//         }
//         return;         
//     }

//     void prinDnode(){
//         Node *t=new Node();
//         t=head;
//         while(((t->getData())==0) && t!=NULL){
//             t=t->getNext();
//         }
//         for(;t!=NULL;t=t->getNext()){
//             cout<<t->getData();
//         }
//         cout<<"\n";
//     }
//     Dlist* lisAdd(Dlist* x,int c,int p){
//         p+=1;
//         Dlist *ad=new Dlist();
//         Node *temp=new Node();
//         temp=tail;
//         while(p--){
//             if(temp!=NULL){
//             ad->insertNode(temp->getData());
//             temp=temp->getPrev();
//             }
//             else if(p>0){
//                 ad->insertNode(0);
//             }
//             else{
//                 ad->insertNode(c);
//             }
//         }
//         return ad;
//     }
//     Dlist* lisAddv2(Dlist* x,int p,int c){
//         int sum=0,carry=0;
//         Dlist *ad= new Dlist();
//         Node *temp=new Node();
//         temp=tail;
//         while(p--){
//             ad->insertNode(temp->getData());
//             temp=temp->getPrev();
           
//         }
//         carry=c;         
//         while(carry!=0) {
//             sum=(temp->getData()+carry)%10;
//             carry=(temp->getData()+carry)/10;
//             temp->setData(sum);
//             ad->insertNode(sum);
//             temp=temp->getPrev();
//                 if(!temp) break;
//         }
//         if (carry!=0)
//             ad->insertNode(carry);
//         while(temp!=NULL){
//             ad->insertNode(temp->getData());
//             temp=temp->getPrev();
//         }
//         return ad;

//     }
//     Dlist* lisMul(Dlist* x,int c,int p){
//         int sum=0,carry=0;
//         Dlist *R=new Dlist();
//         Node *temp=new Node();
//         temp=tail;
//         while(temp!=NULL){
//             sum=((c*(temp->getData()))+carry)%10;
//             carry=((c*(temp->getData()))+carry)/10;
//             R->insertNode(sum);
//             temp=temp->getPrev();
//         }
//         if(carry)
//             R->insertNode(carry);
//         while (p--)
//         {
//             R->insertTail(0);
//         }
//         return R;
        
//     }


//     // ~Dlist(){
//     //     Node* x= head;
//     //      while ( x!= NULL) {
//     //       Node *temp = x;
//     //       x = x->getNext();
//     //       delete temp; 
//     //   }
//     // }
// };
// int main(){
//     string num;
//     int t,q,c,p,i,sl,tem;
//     char o;
//     cin>>t;
//     while(t--){
//         cin>>num;
//         cin>>q;    
//         Dlist *A=new Dlist();
//         sl=num.length();    
//         for(i=sl;i>0;i--){
//             tem=int(num[i-1])-48;
//             A->insertNode(tem);
//         }
//         while(q--){
//         cin>>o>>c>>p;
        
//            if(o=='a'){
//                sl=A->count;
//                if(p>=sl){
//                     A=A->lisAdd(A,c,p);
//                 }
//                 else{
//                     A=A->lisAddv2(A,p,c);
//                 }

//            }
//            if(o=='m'){
//                 A=A->lisMul(A,c,p);
//            }
//         }
        
//      A->prinDnode();
//      A=NULL;
//     }
//     return 0;
// }

