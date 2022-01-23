#ifndef __EMPLOYEELIST_H__
#define __EMPLOYEELIST_H__
#include <iostream>

using std::string;
using std::cout;
using std::endl;

/* Employee class has many attributes (created here publically because of the Given requirement)
    ID         : integer to store the id of the employee
    name       : string to store the name of the employee
    department : string to store the name of the employee
    salary     : integer to store the salary of the employee
    next       : points to the next employee in the list
*/
class Employee{
    public:
        //data memebers (attributes)
        int ID;
        string name;
        string department;
        int salary;
        Employee *next;
        //declaring the constructor of the Employee class
        Employee(int ID, string name, string department, int salary);
};

/* EmployeeList class has only two attributes (private) 
    head      : a Employee's class pointer, used to track of the list 
    size      : string to store the name of the employee
    It is used to create the list and addEmployee and delete it as well
*/
class EmployeeList{
    private:
        Employee *head;
        int size;
    public:
        //constructor of the class
        EmployeeList();

        //destructor of the class
        ~EmployeeList();
        
        //addEmployee method to add Employee to the list
        void addEmployee(int ID, string name, string department, int salary);

        //removeEmployee method to remove Employee from the list
        void removeEmployee(int ID);

        //print method all employees of the list
        void print();

        //print method only the employees belongs to the input department string
        void print(string department);

        //print method only the Employee which id is same as input ID
        void print(int ID);

        //getSize method return the size of the EmployeeList
        int getSize();

        //isEmpty method return the true, if EmployeeList is empty else false
        bool isEmpty();
};

#endif //__EMPLOYEELIST_H__
