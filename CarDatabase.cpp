#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
//Struct Initialization
struct CarType{
enum {MAX_CHAR_LEN=100};
char Name[MAX_CHAR_LEN];
double MPG;
int Cylinders;
double Displacement;
double Horsepower;
double Weight;
double Acceleration;
int Model;
char Origin[MAX_CHAR_LEN];
bool ValidEntry;
CarType();
};
//Constant
const int MAX_CARS = 500;
//Default Constructor
CarType::CarType(){
for (int index = 0; index < MAX_CHAR_LEN; index++){
  Name[index] = '\0';
  Origin[index] = '\0';
  }
  MPG = 0;
  Cylinders = 0;
  Displacement = 0;
  Horsepower = 0;
  Weight = 0;
  Acceleration = 0;
  Model = 0;
  ValidEntry = false;
}
//Function Initializers
void readCarData(ifstream &inFile, CarType CarList[]);
CarType readCar(ifstream &inFile);
void printCarData(CarType CarList[], int carChoice);
void printByOrigin(CarType CarList[], char userOrigin[]);
void addCar(CarType CarList[]);
void removeCar(CarType CarList[]);
int readInt(const char prompt[]);
double readDouble(const char prompt[]);

//Reading Car In
CarType readCar(ifstream &inFile){
  CarType car; 
    inFile.get(car.Name, CarType::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile >> car.MPG;
    inFile.ignore(100,';');
    inFile >> car.Cylinders;
    inFile.ignore(100,';');
    inFile >> car.Displacement;
    inFile.ignore(100,';');
    inFile >> car.Horsepower;
    inFile.ignore(100,';');
    inFile >> car.Weight;
    inFile.ignore(100,';');
    inFile >> car.Acceleration;
    inFile.ignore(100,';');
    inFile >> car.Model;
    inFile.ignore(100,';');
    inFile.get(car.Origin, CarType::MAX_CHAR_LEN);
    //End of File check
    car.ValidEntry = !inFile.eof();
    return car;
}
//Read Car Data
void readCarData(ifstream &inFile, CarType CarList[]){
int numCars = 0;
    while(inFile.peek() != EOF && numCars < MAX_CARS) {
        CarList[numCars] = readCar(inFile);
        numCars++;
    }
}
//Integer Check
int readInt(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}
//Double Check
double readDouble(const char prompt[]){
    double temp = 0.0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}


//Adding Car
void addCar(CarType CarList[]){
  //Finding first available entry
  for (int i = 0; i < 500; i++){
    if (CarList[i].ValidEntry == false){
      cout << "Entering  information for Car #" << i << endl;
      cout << "Enter  Name: ";
      cin >> CarList[i].Name;
      //Entering into double/int checker
      CarList[i].MPG = readDouble("Enter MPG: ");
      CarList[i].Cylinders = readInt("Enter Cylinders: ");
      CarList[i].Displacement = readDouble("Enter Displacement: ");
      CarList[i].Horsepower = readDouble("Enter Horsepower: ");
      CarList[i].Weight = readDouble("Enter Weight: ");
      CarList[i].Acceleration = readDouble("Enter Acceleration: ");
      CarList[i].Model = readInt("Enter Model: ");
      cout << "Enter Origin: ";
      cin >> CarList[i].Origin;
      CarList[i].ValidEntry = true;
      cout << endl;
      break;
    }
  }
}
//Removing Cars
void removeCar(CarType CarList[]){
  int carRemoval = 0;
  cout << "Enter a car you would like to remove (0-499): ";
  cin >> carRemoval;
  //Checking if Valid Entry
  if (CarList[carRemoval].ValidEntry == true){
    CarList[carRemoval].ValidEntry = false;
    cout << "Car " << carRemoval << " removed." << endl;
    cout << endl;
  }
  else {
    cout << "Invalid Entry!" << endl;
    cout << endl;
  }
}

//Printing Cars
void printCarData(CarType CarList, int carChoice){
//Checking if entry is valid
if (CarList.ValidEntry!=false){
  cout << "Car Number " << carChoice << endl;
  cout << "Name: " << CarList.Name << endl;
  cout << "MPG: " << CarList.MPG << endl;
  cout << "Cylinders: " << CarList.Cylinders << endl;
  cout << "Displacement: " << CarList.Displacement << endl;
  cout << "Horsepower: " << CarList.Horsepower << endl;
  cout << "Weight: " << CarList.Weight << endl;
  cout << "Acceleration: " << CarList.Acceleration << endl;
  cout << "Model: " << CarList.Model << endl;
  cout << "Origin: " << CarList.Origin << endl;
  cout << endl;
  }
  else{
    cout << "Invalid Entry" << endl;
    cout << endl;
  }
}
//Origin Printer
void printByOrigin(CarType *CarList, char userOrigin[]){
for (int i = 0; i < 500; i++){
  //Comparing the entries to see if it should print it.
  if (strcmp(CarList[i].Origin,userOrigin)==0){
    printCarData(CarList[i], i);
  }
}
}

int main(){
//CarDatabase Array
CarType CarList[MAX_CARS];
ifstream CarFile("cars.txt");
//Filling in the array
readCarData(CarFile, CarList);
int choice = 0;
//Menu
while (choice!=5){
  cout << "Welcome to the Car Database" << endl;
  cout << "Enter an input (1-5): " << endl;
  cout << "1. Display a car" << endl;
  cout << "2. Add new car" << endl;
  cout << "3. Remove a car" << endl;
  cout << "4. Print cars by origin" << endl;
  cout << "5. Quit" << endl;
  cout << endl;
  cin >> choice;
  cout << endl;
  //Print Cars
  if (choice==1){
    int carChoice = 0;
    cout << "Enter a car number between 0 and 499: ";
    cin >> carChoice;
    cout << endl;
    printCarData(CarList[carChoice], carChoice);
  }
  //Add Car
  else if (choice==2){
    addCar(CarList);
  }
  //Remove Car
  else if (choice==3){
    removeCar(CarList);
  }
  //Origin
  else if (choice==4){
    char userOrigin[100];
    cout << "Enter an Origin: (Examples: US, Europe, Japan)";
    cin >> userOrigin;
    printByOrigin(CarList, userOrigin);
  }
  //6+ aka nothing
  else if (choice >=6){
    cout << "You had one job..." << endl;
    cout << endl;
  }
}
}