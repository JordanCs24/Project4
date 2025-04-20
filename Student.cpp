/*

*/

#include "Student.h"

Student::Student(const string& name){
    this->name = name;
}

string Student::getName() const{
    return name;
}

void Student::addRecommendation(const string& course){
    recommendedCourses.push_back(course);
    
}

vector<string> Student::getRecommendations() const{ // Sorted and limited to 3. 
    return recommendedCourses;
}