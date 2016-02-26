//
// Created by Shaaheen on 2/24/2016.
//

#ifndef DATABASEUTILS_H
#define DATABASEUTILS_H

#include <string>
#include <vector>

namespace SCRSHA001{

    struct StudentRecord{
        std::string Name;
        std::string Surname;
        std::string StudentNumber;
        std::string classRecord;
        int canFind;
    };

    std::vector<StudentRecord> setUpDatabaseFromFile();

    std::string studentRecordToString(StudentRecord studentRecord);

    std::string queryDatabase(std::vector<StudentRecord> studentRecord );

    std::vector<StudentRecord> addFromDatabase(std::string studentInfo,std::vector<StudentRecord> stdRecords);

    std::vector<StudentRecord> add_student(StudentRecord stdRec,std::vector<StudentRecord> stdRecords);

    void saveDatabaseToFile(std::vector<StudentRecord> studentRecords);

    StudentRecord findStudentInDatabase(std::string studentNum, std::vector<StudentRecord> stdRecords);

    double calculateGradeAverage(StudentRecord studentRecord);

}


#endif //ASSIGNMENT_1_DATABASEUTILS_H
