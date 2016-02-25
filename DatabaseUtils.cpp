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

    string queryDatabase(vector<StudentRecord> studentRecord ){
        string records = "";
        for (StudentRecord student : studentRecord){
            records = records + student.Name + " " + student.Surname + " " + student.StudentNumber +" " +
                      student.classRecord.term1 + " " + student.classRecord.term2 + " " +
                    student.classRecord.term3 + " " + student.classRecord.term4 + " " + "\n";
            //cout << student << endl;
        }
        return records;
    }

    vector<StudentRecord> addFromDatabase(std::string studentInfo,std::vector<StudentRecord> stdRecords){
        stringstream ssin(studentInfo);
        string name;
        string surname;
        string studentNum;
        string term1;
        string term2;
        string term3;
        string term4;

        ssin >>name;
        ssin >>surname;
        ssin >> studentNum;
        ssin >>term1;
        ssin >>term2;
        ssin >>term3;
        ssin >>term4;
        ClassRecord classRecord {term1, term2 , term3 , term4};
        StudentRecord studentFromDatabase {name, surname, studentNum, classRecord};
        return add_student(studentFromDatabase,stdRecords);

    }

    vector<StudentRecord> add_student(StudentRecord studentRecord,std::vector<StudentRecord> studentRecords){
        //studentRecords.reserve(10);
        studentRecords.push_back(studentRecord);

        return studentRecords;
    }



}
