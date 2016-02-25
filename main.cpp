#include <iostream>
#include "header.h"
#include "DatabaseUtils.h"
#include <fstream>
#include <vector>

using namespace std;
using namespace SCRSHA001;
int main() {
    int choice = -1;
    std::vector<StudentRecord> studentRecord;



    while (true) {
        cout << "0: Add student" << endl;
        cout << "1: Read database" << endl;
        cout << "2: Save database" << endl;
        cout << "3: display given student data" << endl;
        cout << "4: Grade student" << endl;
        cout << "q: Quit "<< endl;
        cout << "Enter a number (or q to quit) and press return... "<< endl;
        cin >> choice;

        if (choice == 0){
            string name;
            string surname;
            string studentNum;
            SCRSHA001::ClassRecord classRecord;
            cout << "Name:" <<endl;
            cin >> name;
            cout << "Surname:" <<endl;
            cin >> surname;
            cout << "StudentNumber:" <<endl;
            cin >> studentNum;
            cout << "ClassRecord:" <<endl;
            cout << "Term records: (eg 56 65 71 72)" <<endl;
            cin >> classRecord.term1 >> classRecord.term2 >> classRecord.term3 >> classRecord.term4;

            StudentRecord newStudent {name,surname,studentNum,classRecord};
            studentRecord = add_student(newStudent ,studentRecord);

            cout << newStudent.classRecord.term4 <<endl;
        }
        else if (choice ==1){
            //std:vector<string>::iterator it = studentRecord.begin();
            cout << SCRSHA001::queryDatabase(studentRecord) <<endl;
        }
        else{
            break;
        }
    }
    return 0;
}




