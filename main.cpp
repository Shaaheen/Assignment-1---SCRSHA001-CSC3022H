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

void clear(void){ system("clear");} //To allow the console to clear

int main() {
    string choice; //records the choice the user made
    std::vector<StudentRecord> studentRecord = setUpDatabaseFromFile(); //Database vector which gets data from the database txt file

    while (true) {
        choice = "-1";

        //Basic UI interface
        cout << "1: Add student" << endl;
        cout << "2: Read database" << endl;
        cout << "3: Save database" << endl;
        cout << "4: Display given student data" << endl;
        cout << "5: Grade student" << endl;
        cout << "c: Clear command line" << endl;
        cout << "q: Quit "<< endl;
        cout << "Enter a number (or q to quit) and press return... "<< endl;
        cin >> choice; //record choice made

        if (choice == "1"){ //Add a student
            //Variables for the StudentRecord struct
            string name;
            string surname;
            string studentNum;
            string classRecord = "";

            //Ask user to input variables for new student
            cout << "Name:" <<endl;
            cin >> name;
            cout << "Surname:" <<endl;
            cin >> surname;
            cout << "StudentNumber:" <<endl;
            cin >> studentNum;
            cout << "ClassRecord: (eg 56 65 71 72)\n";
            getline(cin,classRecord);
            getline(cin,classRecord);

            int canfind = 1; //to show that student record should be accessible
            StudentRecord newStudent {name,surname,studentNum,classRecord,canfind}; //Create new StudentRecord

            //Will try to retrieve a record with the same student number
            StudentRecord checkIfAlreadyExists = findStudentInDatabase(studentNum,studentRecord);
            if (checkIfAlreadyExists.canFind !=0){ //if not 0, then it must exist
                //canFind variable stores the position of a student record in the vector database
                studentRecord[checkIfAlreadyExists.canFind] = newStudent; //replaces existing entry
            }
            else{
                studentRecord = add_student(newStudent ,studentRecord); //add new entry to database vector
            }

        }
        else if (choice == "2"){
            cout << SCRSHA001::queryDatabase(studentRecord) <<endl; //get all records
        }
        else if (choice == "3"){
            saveDatabaseToFile(studentRecord); //saves the vector database into a file
        }
        else if (choice == "4"){
            string studentNumSearch;
            cout << "Type in student number" <<endl;
            cin >> studentNumSearch;
            //Attempts to find a student in the database based on their student number
            StudentRecord foundStudent = findStudentInDatabase(studentNumSearch,studentRecord);
            if (foundStudent.canFind !=0){ //if found
                cout << studentRecordToString(foundStudent) <<endl; //print the record
            }
            else{
                cout << "Student not found in database" << endl;
            }

        }
        else if (choice == "5"){ //grade average - similar as above
            string studentNumSearch;
            cout << "Type in student number" <<endl;
            cin >> studentNumSearch;
            StudentRecord foundStudent = findStudentInDatabase(studentNumSearch,studentRecord);
            if (foundStudent.canFind !=0){
                cout << "The Grade Average of " << foundStudent.StudentNumber << " is: " <<endl;
                cout << calculateGradeAverage(foundStudent) << endl; //Get the grade average
            }
            else{
                cout << "Student not found in database" << endl;
            }
        }
        else if (choice == "c"){
            clear();
        }
        else{
            break;
        }
    }
    return 0;
}




