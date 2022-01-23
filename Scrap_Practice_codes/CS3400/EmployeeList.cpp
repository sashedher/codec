#include "EmployeeList.h"


//defining the Employee class Constructor; which initialize each variable with 
//appropriate passed input and set next to NULL
Employee::Employee(int ID, string name, string department, int salary){
   this->ID = ID;
   this->name = name;
   this->department = department;
   this->salary = salary;
   next = NULL;
}

//defining the EmployeeList class Constructor; which initialize the head to 
//NULL and size to 0
EmployeeList::EmployeeList(){
   head = NULL;
   size = 0;
} 

EmployeeList::~EmployeeList(){
   Employee *tempEmployee = head;
   while (tempEmployee != NULL){
      Employee *deleteEmployee = tempEmployee;
      tempEmployee = tempEmployee->next;
      delete deleteEmployee;
   }
} 
//defining addEmployee method of EmployeeList class
//It create a Employee class object and if head is null then set head to newEmployee object
//else add it to appropriate place according to salary order
void EmployeeList::addEmployee(int ID, string name, string department, int salary){

   //creating a newEmployee object
   Employee *newEmployee =  new Employee(ID,name,department,salary);

   //If list is empty, set head to the newEmployee object
   if (head == NULL){
      head = newEmployee;
   }
   //else add it to appropriate location
   else{
       
      //creating a tempEmployee pointer to access list
      Employee *tempEmployee = head;

      //Condition 1 :
      //new employee salary is lesser than the salary of First Employee in the list then
      //set the next employee to newEmployee as tempEmployee and update head as newEmployee
      if (tempEmployee->salary > newEmployee->salary){
         newEmployee->next = tempEmployee;
         head = newEmployee;
      }
      else{
         bool isAdded = false;
         while(tempEmployee->next != NULL){
            //Condition 2: new employee salary is between start and end; if matches set isAdded to true 
            if(tempEmployee->salary < newEmployee->salary && tempEmployee->next->salary > newEmployee->salary){
               newEmployee->next = tempEmployee->next;
               tempEmployee->next = newEmployee;
               isAdded = true;
               break;
            }
            tempEmployee = tempEmployee->next;
         }
        
         //Condititon 3 : newEmployee's salary greater than salary of the last Employee in the list
         //add newEmployee to the last location only if it is not added yet
         if (tempEmployee->next == NULL && isAdded == false){
            tempEmployee->next = newEmployee;
         }
      }

      //increment the size of the list
      size++;

   }
}

//defining removeEmployee methods which remove Employee with ID; if found in the linkedlist
void EmployeeList::removeEmployee(int ID){
   
   //if list is not Empty;  
   if (head != NULL){
      //setting head to tempEmployee pointer
      Employee *tempEmployee = head;
      
      //Checking if the first element has same id as input ID
      //update head to next Employee in the list and remove the Employee pointer
      if (tempEmployee->ID ==  ID){
         head  = tempEmployee->next;
         delete tempEmployee;
         size--;
      }
      else{
         //Checking if the ID is between first and the last employee inclusive
         while(tempEmployee->next  != NULL){
            //if ID matches; remove the employee pointer
            if (tempEmployee->next->ID ==  ID){

               // copy the pointer to another variable for deletion
               Employee *deleteEmployee = tempEmployee->next;

               //update the tempEmployee->next to tempEmployee->next->next
               tempEmployee->next = tempEmployee->next->next;

               //delete the deleteEmployee object
               delete deleteEmployee;

               //decrement the size of the list
               size--;

               //break the loop
               break;
            }
            tempEmployee = tempEmployee->next;
         }
      }
   }
}

//print() method  prints all the employees
void EmployeeList::print(){
   Employee *tempEmployee = head;
   while(tempEmployee != NULL){
      cout << tempEmployee->ID << " " << tempEmployee->name << " " << tempEmployee->department << " " << tempEmployee->salary << endl;
      tempEmployee = tempEmployee->next;
   }
}

//print(string department) method  prints all the employees which department is matched as given department 
void EmployeeList::print(string department){
   Employee *tempEmployee = head;
   while(tempEmployee != NULL){
      if (tempEmployee->department == department){
         cout << tempEmployee->ID << " " << tempEmployee->name << " " << tempEmployee->department << " " << tempEmployee->salary << endl;
      }
      tempEmployee = tempEmployee->next;
   }
}

//print(int ID) method only print the information of the Employee which id is matched as given ID
void EmployeeList::print(int ID){
   Employee *tempEmployee = head;
   while(tempEmployee != NULL){
      if (tempEmployee->ID == ID){
         cout << tempEmployee->ID << " " << tempEmployee->name << " " << tempEmployee->department << " " << tempEmployee->salary << endl;
      }
      tempEmployee = tempEmployee->next;
   }
}

//getSize method returns the size of the list
int EmployeeList::getSize(){
   return size;
}

//isEmpty method to return true; if head is NULL else return false
bool EmployeeList::isEmpty(){
   if (head == NULL)
      return true;
   else
      return false;
}
