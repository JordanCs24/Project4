#include "RecommendationSystem.h"

void RecommendationSystem::loadData(const string& filename){
    ifstream fs;
    string line;
    string studentName;
    string course1, course2, course3;
    stringstream breakup;
    fs.open(filename);
    if(!fs.is_open()){
        cout << "Couldn't open: " << filename;
    }
    while(fs >> studentName && fs >> course1 && fs >> course2 && fs >> course3){
        cout << "Student Name: " << studentName << endl;
        cout << "Courses: " << course1 << " " << course2 << " " << course3 << endl;
    }
    fs.close();
}

vector<string> RecommendationSystem::generateRecommendationsForStudent(const string& studentName) const{
    
}

void RecommendationSystem::outputRecommendations(ostream& out) const{

}

 

// Testing methods

int RecommendationSystem::getTotalStudents() const{

}

int RecommendationSystem::getTotalCourses() const{

}

int RecommendationSystem::getTotalRecommendations() const{

}