#include "Course.h"

Course::Course(const string& id){
    this->id = id;
}

string Course::getId() const{
    return id;
}

bool Course::operator==(const Course& other) const{
   return (id == other.id);
}

bool Course::operator<(const Course& other) const{ // For alphabetical sorting.
    return (id < other.id);
}