//a program that grades the test and displays the result. To do this, the program compares each
//student’s answers with the key, counts the number of correct answers, and displays it.
# include <iostream>
# include <vector>
using namespace std;

int main(){
    vector<vector<char>>answers = {
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
{'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
{'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},
{'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},
{'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
{'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
{'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
{'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
{'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}
};
vector<char> key = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};
for (int student = 0; student < answers.size();student++){
int total_mark = 0;
for (int col = 0; col < key.size(); col++ ){
    if (answers [student][col] == key [col]){
        total_mark = total_mark + 1;
    }
}
cout <<"Total marks for student " <<student <<": " <<total_mark <<"\n";
}
return 0;}