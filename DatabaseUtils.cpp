//
// Created by Shaaheen Sacoor on 2/24/2016.
// SCRSHA001
// File that contains all the utility methods used to interact with the database (Vector or File)
//

#include "DatabaseUtils.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
namespace SCRSHA001{

    /*
     *  Method to set up the vector as a database from the information stored in a database text file
     */
    vector<StudentRecord> setUpDatabaseFromFile(){
        cout << "function setUpDatabaseFromFile()called" << endl; //stub
        std::vector<StudentRecord> studentRecord; //Vector container

        ifstream MyFile("StudentDatabase.txt"); //Try access txt database
        if (!MyFile) {
            //If file not created then create it
            std::ofstream outfile ("StudentDatabase.txt");
            outfile.close();
        }

        ifstream MyFile1("StudentDatabase.txt"); //Access the txt database
        string line;
        while ( getline(MyFile1,line) ){ //Iterate over file line by line
            studentRecord = addFromDatabase(line,studentRecord); //Get the student record from info in a line in txt file
        }

        MyFile.close();

        return studentRecord;
    }

    /*
     *  Method to convert a StudentRecord struct to a string
     */
    string studentRecordToString(StudentRecord student){
        return student.Name + " " + student.Surname + " " + student.StudentNumber +" " +
               student.classRecord;
    }

    /*
     *  Method to run through the vector database and get all student records in one string
     */
    string queryDatabase(vector<StudentRecord> studentRecord ){
        cout << "function queryDatabase(vector<StudentRecord> studentRecord)called" << endl; //stub
        string records = "";

        //Iterate over records and add string of the StudentRecord struct for each student
        for (StudentRecord student : studentRecord){
            records = records + studentRecordToString(student) + "\n";
        }
        return records;
    }

    /*
     * Method to take a string line from the database txt file and convert that line string into a Student record
     * - Extracts the info from the database into the StudentRecord struct
     */
    vector<StudentRecord> addFromDatabase(string studentInfo,vector<StudentRecord> stdRecords){
        cout << "function addFromDatabase(string studentInfo, vector<StudentRecord> stdRecords)called" << endl; //stub
        stringstream ssin(studentInfo); //create a string stream of the line holding student information from the db txt file
        //Variables in struct
        string name;
        string surname;
        string studentNum;
        string classRecord = "";

        //Place values from stream (line) into appropriate variables
        ssin >>name;
        ssin >>surname;
        ssin >> studentNum;

        //The rest of the line is associated with the class record
        string item;
        while (ssin >> item){
            classRecord = classRecord + item + " ";
        }
        classRecord = classRecord.substr(0,classRecord.size() - 1); //Take away ending space

        //Create a StudentRecord from the information extracted from the db txt file line
        StudentRecord studentFromDatabase {name, surname, studentNum, classRecord, 1};
        return add_student(studentFromDatabase,stdRecords);

    }

    /*
     *  Method to add a StudentRecord struct to the vector database
     */
    vector<StudentRecord> add_student(StudentRecord studentRecord,std::vector<StudentRecord> studentRecords){
        studentRecords.push_back(studentRecord);

        return studentRecords;
    }

    /*
     *  Method to save the vector database to the database file
     *  - Will overwrite database file incase there is a change on already existing data
     */
    void saveDatabaseToFile(vector<StudentRecord> studentRecords){
        cout << "function saveDatabaseToFile(vector<StudentRecord> studentRecords) called" << endl; //sttub
        fstream  databaseFile;
        databaseFile.open("StudentDatabase.txt", ios::out); //Open db txt file for writing
        for (StudentRecord student:studentRecords){
            databaseFile << studentRecordToString(student)<<endl; //write each student record to file
        }
        databaseFile.close();
    }

    /*
     *  Method to attempt to find a specific student (from student number) in the vector database
     */
    StudentRecord findStudentInDatabase(std::string studentNum, std::vector<StudentRecord> stdRecords){
        cout << "function findStudentInDatabase(std::string studentNum, std::vector<StudentRecord> stdRecords called" << endl; //stub
        int index = 0;
        for (StudentRecord student:stdRecords){ //Iterate through vector container
            if (student.StudentNumber == studentNum){ //if found student in db then return
                student.canFind = index; //store the index of the position the student is found in database
                return student;
            }
            index ++;
        }
        return StudentRecord{"","","","",0};
    }

    /*
     *  Method to calculate the grade average of a student based on their class records
     */
    double calculateGradeAverage(StudentRecord studentRecord){
        stringstream stream(studentRecord.classRecord); //stream from the class record string
        int totalMarks = 0;
        int numMarks = 0;
        int termMark;
        while (stream >> termMark){
            totalMarks = totalMarks  + termMark; //add together all marks in the class record string
            numMarks ++; //count the number of marks recorded
        }
        return ((totalMarks+0.0)/numMarks); //divide total marks by number of marks to get average
    }


}
