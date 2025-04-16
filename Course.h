/*
Name: Jordan Sowell
Section: CPSC 1020
Date: 4/26/2025
Description: header file for class Course. Represents a course with a unique ID.
*/
#ifndef COURSE_H
#define COURSE_H

#include <string>

using namespace std;

class Course {
private:
    string id;

public:

    Course(const string& id);

    string getId() const;

    bool operator==(const Course& other) const;

    bool operator<(const Course& other) const; // For alphabetical sorting.

};
#endif