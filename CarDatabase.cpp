#include <iostream>
#include <fstream>
using namespace std;
//Struct Initialization
struct CarType{
enum {MAX_CHAR_LEN=100};
char CarName[MAX_CHAR_LEN];
double MPG;
int Cylinders;
double Displacement;
double Horsepower;
double Weight;
double Acceleration;
int Model;
char Origin[MAX_CHAR_LEN];
bool ValidEntry;
};

CarType readCarData(ifstream &inFile, CarType CarList[]);


CarType readCarData(ifstream &inFile, CarType CarList[]){

}

int main(){
//CarDatabase Array
CarType CarList[500];
ifstream CarFile("cars.txt");
readCarData(CarFile, CarList);
}