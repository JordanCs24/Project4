/*

*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <assert.h>
#include "Course.h"
#include "Student.h"
#include "Course.h"
#include "RecommendationSystem.h"

using namespace std;
void eraseAColumn(string &name);
void eraseAComma(string &course);

int main(int argc, char* argv[]){

    ifstream fs;
    string studentName;
    string courses;
    string line;
    vector<string> recommendedCourse;
    RecommendationSystem Test;
    cout << "Welcome to Course Recommender!" << endl;
    Test.loadData(argv[1]);
    

    return 0;
}