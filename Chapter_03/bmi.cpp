// Write a program that prompts the user to enter a weight in pounds and height in inches and
// then displays the BMI. Note that one pound is 0.45359237 kilograms and one inch is
// 0.0254 meters. Listing 4.6 gives the program.

// Conditions
// Below 18.5 Underweight
// 18.5–24.9 Normal
// 25.0–29.9 Overweight
// Above 30.0 Obese

// Enter weight in pounds:
// Enter Weight in pounds: 146
// Enter height in inches: 70
// BMI is 20.95
// Normal
# include <iostream>
using namespace std;

int main(){
    cout <<"Enter weight in pounds: ";
    double weight;
    cin >> weight;
    cout <<"Enter height in inches: ";
    double height;
    cin >> height;
    //changing weight to kg
    weight = weight*0.45359237; 
    //changing height to m
    height = height*0.0254; 
    double BMI = weight/height;
    cout <<"BMI is " <<BMI;
    if (BMI < 18.5){
        cout <<"\nUnderweight";
    }
    else if (BMI >= 18.5 && BMI<24.9){
        cout <<"\nNormal";
    }
    else if (BMI >= 25.0 && BMI<29.9){
        cout <<"\nOverweight";
    }
    else if (BMI >30.0){
        cout <<"\nObese";}
    else {cout << "Enter a valid number.";}
    return 0;
}