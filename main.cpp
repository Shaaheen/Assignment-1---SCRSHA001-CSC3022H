//
// Created by Shaaheen Sacoor on 2/24/2016.
// SCRSHA001
// Main driver implementation to run the gui interface
//

#include <iostream>
#include "header.h"
#include "DatabaseUtils.h"
#include <fstream>
#include <vector>

using namespace std;
using namespace SCRSHA001;

void clear(void){ system("clear");}

int main() {
    string choice;
    std::vector<StudentRecord> studentRecord = setUpDatabaseFromFile();

    while (true) {
        choice = "-1";

        cout << "0: Add student" << endl;
        cout << "1: Read database" << endl;
        cout << "2: Save database" << endl;
        cout << "3: display given student data" << endl;
        cout << "4: Grade student" << endl;
        cout << "q: Quit "<< endl;
        cout << "Enter a number (or q to quit) and press return... "<< endl;
        cin >> choice;

        if (choice == "1"){
            string name;
            string surname;
            string studentNum;
            string classRecord = "";

            cout << "Name:" <<endl;
            cin >> name;
            cout << "Surname:" <<endl;
            cin >> surname;
            cout << "StudentNumber:" <<endl;
            cin >> studentNum;
            cout << "ClassRecord: (eg 56 65 71 72)\n";
            getline(cin,classRecord);
            getline(cin,classRecord);

            int canfind = 1;
            StudentRecord newStudent {name,surname,studentNum,classRecord,canfind};

            StudentRecord checkIfAlreadyExists = findStudentInDatabase(studentNum,studentRecord);
            if (checkIfAlreadyExists.canFind !=0){
                studentRecord[checkIfAlreadyExists.canFind] = newStudent;
            }
            else{
                studentRecord = add_student(newStudent ,studentRecord);
            }

        }
        else if (choice == "2"){
            cout << SCRSHA001::queryDatabase(studentRecord) <<endl;
        }
        else if (choice == "3"){
            saveDatabaseToFile(studentRecord);
        }
        else if (choice == "4"){
            string studentNumSearch;
            cout << "Type in student number" <<endl;
            cin >> studentNumSearch;
            StudentRecord foundStudent = findStudentInDatabase(studentNumSearch,studentRecord);
            if (foundStudent.canFind !=0){
                cout << studentRecordToString(foundStudent) <<endl;
            }
            else{
                cout << "Student not found in database" << endl;
            }

        }
        else if (choice == "5"){
            string studentNumSearch;
            cout << "Type in student number" <<endl;
            cin >> studentNumSearch;
            StudentRecord foundStudent = findStudentInDatabase(studentNumSearch,studentRecord);
            if (foundStudent.canFind !=0){
                cout << "The Grade Average of " << foundStudent.StudentNumber << " is: " <<endl;
                cout << calculateGradeAverage(foundStudent) << endl;
            }
            else{
                cout << "Student not found in database" << endl;
            }
        }
        else if (choice == "clear"){
            clear();
        }
        else{
            break;
        }
    }
    return 0;
}




