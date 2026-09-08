# include <iostream> 
# include <chrono>
# include <iomanip>
# include <ctime>
using namespace std;

int main(){
    cout<< "Enter your first name: ";
    string first_name;
    cin >> first_name;
    cout<< "Enter your last name: ";
    string last_name;
    cin >> last_name;
    cout<< "Enter your Study Program: ";
    string study_program;
    cin >> study_program;
    cout<< "Enter your academic year: ";
    string academic_year;
    cin >> academic_year;

    auto today = chrono::system_clock::now();
    time_t current_time = chrono::system_clock::to_time_t(today);

    cout <<"Date: " <<put_time(localtime(&current_time), "%d %B %Y");
    cout <<"\nTo: " <<first_name <<" " <<last_name <<"\n \n" <<"Dear " <<first_name <<"\n \n";
    cout <<"CONGRATULATIONS! I am pleased to inform you that the Makerere University\n";
    cout <<"Admissions Board has approved your application for admission to the\n";
    cout <<academic_year <<"academic year.";
    cout <<"You have been offered a place for the following course:\n";
    cout <<"PROGRAM: " <<study_program <<"\n"; 
    cout <<"As a student of Makerere University, you will be part of a historic\n";
    cout <<"institution dedicated to academic excellence and innovation. Please ensure\n";
    cout <<"you report to the Academic Registrar's office with your original\n" ;
    cout <<"academic documents for verification during the orientation week.\n \n";
    cout <<"We look forward to welcoming you to the Makerere University.\n \n";
    cout <<"Yours sincerely,\n" <<"Registrar.";


return 0;
}


// Dear John,

// CONGRATULATIONS! I am pleased to inform you that the Makerere University 
// Admissions Board has approved your application for admission to the 
// 2027/2028 academic year.

// You have been offered a place for the following course:
// PROGRAM: Bachelor of Science in Computer and Communication Engineering

// As a student of Makerere University, you will be part of a historic 
// institution dedicated to academic excellence and innovation. Please ensure 
// that you report to the Academic Registrar's office with your original 
// academic documents for verification during the orientation week.

// We look forward to welcoming you to the Makerere University.

// Yours sincerely,

// Write a program that outputs an acceptance letter for Makerere University. It should prompt a user to enter their first name, last name, study program, academic year.
// The program should have autodates

// Example:

// Date: 27th August 2026

// To: John Okello,

// Dear John,

// CONGRATULATIONS! I am pleased to inform you that the Makerere University 
// Admissions Board has approved your application for admission to the 
// 2027/2028 academic year.

// You have been offered a place for the following course:
// PROGRAM: Bachelor of Science in Computer and Communication Engineering

// As a student of Makerere University, you will be part of a historic 
// institution dedicated to academic excellence and innovation. Please ensure 
// that you report to the Academic Registrar's office with your original 
// academic documents for verification during the orientation week.

// We look forward to welcoming you to the Makerere University.

// Yours sincerely,


// John Doe
// Registrar