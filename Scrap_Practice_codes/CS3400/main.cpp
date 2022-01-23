//#include <iostream>
#include <fstream>
#include <string>
#include "EmployeeList.h"

using namespace std;

EmployeeList myCompany;

//Read the dataset file and loads myCompany list
void loadDataset(string fileName){
	ifstream inFile;
	inFile.open(fileName.c_str());

	//Add all employees to the list
	int ID, salary;
	string name, dept;
	while(inFile >> ID >> name >> dept >> salary)
		myCompany.addEmployee(ID,name,dept,salary);

	inFile.close();
}

//Just for convenience...
void continueMessage(string message){
	cout << message << endl;
	cout << "Press Enter to continue.." << endl; cin.get();
}

int main() {
	string fileName = "dataset.txt";
	loadDataset(fileName);

	continueMessage("Dataset file is loaded to the program!");

	//---------------------------------------------------------------------------
	myCompany.print();
	continueMessage("All employees in the company are listed!");

	//---------------------------------------------------------------------------
	int ID = 1;
	string name = "Mike";
	string dept = "Training";
	int salary = 94123;
	myCompany.addEmployee(ID,name,dept,salary);

	continueMessage("New employee is added to the company.");
	//---------------------------------------------------------------------------

	myCompany.print(ID);
	continueMessage("The employee having ID:1 listed.");
	//---------------------------------------------------------------------------

	myCompany.print();
	continueMessage("All employees in the company are listed!");
	//---------------------------------------------------------------------------

	myCompany.print(dept);
	continueMessage("The employees in "+ dept +" are listed.");
	//---------------------------------------------------------------------------

	myCompany.removeEmployee(ID);
	continueMessage("The employee having ID:1 is removed from the company.");
	//---------------------------------------------------------------------------

	if(myCompany.isEmpty())
		cout << "The company does not have any employees" << endl;
	else{
		int size = myCompany.getSize();
		cout << "There are " << size << " employees in the company." << endl;
	}
	//---------------------------------------------------------------------------

	return 0;
}