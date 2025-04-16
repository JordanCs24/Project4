/*
Name: Jordan Sowell
Section: CPSC 1020
Date: 4/26/2025
Description: Represents a student and their recommended courses 
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Course.h"

using namespace std;

class Student {

private:
    string name;
    vector<string> recommendedCourses; // Stores up to 3 recommended courses.

public:

    Student(const string& name);

    string getName() const;

    void addRecommendation(const string& course);

    vector<string> getRecommendations() const; // Sorted and limited to 3.

};

#endif