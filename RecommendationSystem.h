/*
Name: Jordan Sowell
Section: CPSC 1020
Date: 4/26/2025
Description: header file for class recommendationSystem. It Manages students, courses, and generates recommendations.
*/

#ifndef RECOMMENDATIONSYSTEM_H
#define RECOMMENDATIONSYSTEM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include "Student.h"

using namespace std; 

class RecommendationSystem {
private:

    map<string, Student> students; // Map of student names to Student objects.

    set<string> courses;          // Set of all unique courses.

public:

    void loadData(const string& filename);

    vector<string> generateRecommendationsForStudent(const string& studentName) const;

    void outputRecommendations(ostream& out) const;

 

    // Testing methods

    int getTotalStudents() const;

    int getTotalCourses() const;

    int getTotalRecommendations() const;

};
#endif