#include <iostream>
#include <fstream>
#include <sstream>
#include<iomanip>

using namespace std;
using std::setw; 
int main() 
{
    ifstream myInputFile;
    //ofstream myOutputFile;

    myInputFile.open("tempData.txt");
    //myOutputFile.open("output.txt");

    string cityName;
    int cityTemp;
    if (myInputFile.fail()) {
        cout << "The file could not be opened!" << endl;
        cout << "The program is closing!" << endl;
    }
    else
    {
        while (!myInputFile.eof())
        {
            myInputFile >> cityName;
            float sum = 0, averageTemp;
            int i=0;
            while (i <= 11) 
            {
                myInputFile >> cityTemp; 
                sum = sum + cityTemp;
                i++;
            }
            averageTemp = sum / 12;
            cout<< "City Name : " << cityName << setw(30) <<"Average Temparature : " << averageTemp << endl;
          //  myOutputFile << "City Name: " << cityName << "\t\t\t" << "Average Temparature: " << averageTemp << endl;
        }
        myInputFile.close();
       // myOutputFile.close();
    }
    return 0;
}