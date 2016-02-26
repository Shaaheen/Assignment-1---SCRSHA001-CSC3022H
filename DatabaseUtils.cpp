//
// Created by Shaaheen on 2/24/2016.
//

#include "DatabaseUtils.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
namespace SCRSHA001{

    vector<StudentRecord> setUpDatabaseFromFile(){
        cout << "function setUpDatabaseFromFile()called" << endl;
        std::vector<StudentRecord> studentRecord;

        ifstream MyFile("StudentDatabase.txt");
        if (!MyFile) {
            //If file not created then create it
            std::ofstream outfile ("StudentDatabase.txt");

           // outfile << "my text hdvn vd jknnjere!" << std::endl;

            outfile.close();
        }

        ifstream MyFile1("StudentDatabase.txt");
        string line;
        while ( getline(MyFile1,line) ){
            //cout << line << "\n";
            studentRecord = addFromDatabase(line,studentRecord);
            //studentRecord.push_back(line);
        }

        //cout << studentRecord.at(0).StudentNumber << endl;
        MyFile.close();

        return studentRecord;
    }

    string studentRecordToString(StudentRecord student){
        return student.Name + " " + student.Surname + " " + student.StudentNumber +" " +
               student.classRecord;
    }

    string queryDatabase(vector<StudentRecord> studentRecord ){
        cout << "function queryDatabase(vector<StudentRecord> studentRecord)called" << endl;
        string records = "";
        for (StudentRecord student : studentRecord){
            records = records + studentRecordToString(student) + "\n";
            //cout << student << endl;
        }
        return records;
    }

    vector<StudentRecord> addFromDatabase(string studentInfo,vector<StudentRecord> stdRecords){
        cout << "function addFromDatabase(string studentInfo, vector<StudentRecord> stdRecords)called" << endl;
        stringstream ssin(studentInfo);
        string name;
        string surname;
        string studentNum;
        string classRecord = "";

        ssin >>name;
        ssin >>surname;
        ssin >> studentNum;

        string item;
        while (ssin >> item){
            classRecord = classRecord + item + " ";
        }
        classRecord = classRecord.substr(0,classRecord.size() - 1);
        StudentRecord studentFromDatabase {name, surname, studentNum, classRecord, 1};
        return add_student(studentFromDatabase,stdRecords);

    }

    vector<StudentRecord> add_student(StudentRecord studentRecord,std::vector<StudentRecord> studentRecords){
        studentRecords.push_back(studentRecord);

        return studentRecords;
    }

    void saveDatabaseToFile(vector<StudentRecord> studentRecords){
        cout << "function saveDatabaseToFile(vector<StudentRecord> studentRecords) called" << endl;
        fstream  databaseFile;
        databaseFile.open("StudentDatabase.txt", ios::out);
        for (StudentRecord student:studentRecords){
            databaseFile << studentRecordToString(student)<<endl;
        }
        databaseFile.close();
    }

    StudentRecord findStudentInDatabase(std::string studentNum, std::vector<StudentRecord> stdRecords){
        cout << "function findStudentInDatabase(std::string studentNum, std::vector<StudentRecord> stdRecords called" << endl;
        int index = 0;
        for (StudentRecord student:stdRecords){
            if (student.StudentNumber == studentNum){
                student.canFind = index;
                return student;
            }
            index ++;
        }
        return StudentRecord{"","","","",0};
    }



}
