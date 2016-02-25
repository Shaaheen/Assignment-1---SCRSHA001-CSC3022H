//
// Created by Shaaheen on 2/24/2016.
//

#ifndef DATABASEUTILS_H
#define DATABASEUTILS_H

#include <string>
#include <vector>

namespace SCRSHA001{
    struct ClassRecord{
        std::string term1;
        std::string term2;
        std::string term3;
        std::string term4;
    };

    struct StudentRecord{
        std::string Name;
        std::string Surname;
        std::string StudentNumber;
        ClassRecord classRecord;
    };

    std::vector<StudentRecord> setUpDatabaseFromFile();

    std::string queryDatabase(std::vector<StudentRecord> studentRecord );

    std::vector<StudentRecord> addFromDatabase(std::string studentInfo,std::vector<StudentRecord> stdRecords);

    std::vector<StudentRecord> add_student(StudentRecord stdRec,std::vector<StudentRecord> stdRecords);



}


#endif //ASSIGNMENT_1_DATABASEUTILS_H
