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
            std::ofstream outfile ("StudentDatabase.txt");

            outfile << "my text hdvn vd jknnjere!" << std::endl;

            outfile.close();
        }

        ifstream MyFile1("StudentDatabase.txt");
        string line;
        while ( getline(MyFile1,line) ){
            //cout << line << "\n";
            cout << line << "\n";
            studentRecord = addFromDatabase(line,studentRecord);
            //studentRecord.push_back(line);
        }

        //cout << studentRecord.at(0).StudentNumber << endl;
        MyFile.close();

        return studentRecord;
    }

    string queryDatabase(vector<StudentRecord> studentRecord ){



}
