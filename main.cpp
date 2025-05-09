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

int main(int argc, char* argv[]){

    ifstream fs;
    ostream output;
    string studentName;
    string courses;
    string line;
    vector<string> recommendedCourse;
    RecommendationSystem Test;
    cout << "Welcome to Course Recommender!" << endl;
    Test.loadData(argv[1]);
    fs >> studentName;
    
    //Test.generateRecommendationsForStudent("Bob");
    Test.getTotalStudents();
    Test.outputRecommendations(output);

    return 0;
}