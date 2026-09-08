// (Print a table) Write a program that displays the following table: Hint: without loops
// a	 	a^2		a^3
// 1 	 	1 		1
// 2 	 	4 		8
// 3  	 	9 		27
// 4 		16 		64
// Modifying this program to use loops and string formating
# include <iostream>
using namespace std;

int main() {
   
    cout << "a\t" << "a^2\t" << "a^3\n";
    int a;
    int a2;
    int a3;
    a = 1;
    do {
        a2 = a*a;
        a3 = a*a*a;
        cout <<a <<"\t" <<a2 <<"\t" <<a3 <<"\n";
        a++;
    } while (a<5);
    return 0;
// Try

}
// Compile std to be found by g++
// g++-16 -std=c++23 -fmodules -fsearch-include-path -c bits/std.cc

// Compile code
// g++-16 -std=c++23 -fmodules multiplication_table.cpp -o output/multiplication_table && output/multiplication_table