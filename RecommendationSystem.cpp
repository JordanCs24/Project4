#include "RecommendationSystem.h"

void RecommendationSystem::loadData(const string& filename){
    ifstream fs;
    string studentName;
    string course1, course2, course3;
    fs.open(filename);
    if(!fs.is_open()){
        cout << "Couldn't open: " << filename;
    }
    while(fs >> studentName && fs >> course1 && fs >> course2 && fs >> course3){

        studentName.erase(remove(studentName.begin(), studentName.end(),':')); // removes the ':' character
        
        course1.erase(remove(course1.begin(), course1.end(),',')); // removes the ',' character
        course2.erase(remove(course2.begin(), course2.end(),',')); // removes the ',' character
        course3.erase(remove(course3.begin(), course3.end(),',')); // removes the ',' character

        cout << "Courses: " << course1 << " " << course2 << " " << course3 << endl;
        courses.insert(course1); // Adds the courses to the set
        courses.insert(course2);
        courses.insert(course3);
        Student *recommendStudent = new Student(studentName);
        recommendStudent->addRecommendation(course1);
        recommendStudent->addRecommendation(course2);
        recommendStudent->addRecommendation(course3);
// Add a student object with allocated memory to create a student object
        students.emplace(studentName,recommendStudent);
        delete recommendStudent;
    }

}

vector<string> RecommendationSystem::generateRecommendationsForStudent(const string& studentName) const{
/*
    Sort recommendations:
    By popularity (descending).
    Alphabetically for ties.
*/

}

void RecommendationSystem::outputRecommendations(ostream& out) const{
    /*
Alice: [CPSC102, CPSC301]

Bob: [CPSC101, CPSC299]

Carol: [CPSC204, CPSC299]

 

Total Students: 3

Total Courses: 5

Total Recommendations: 6
    */
   
    for (auto &i : students){
        out << i.first() << ": " << "[" << i.second.getRecommendations().at() << "]" <<endl;
    }
}

 

// Testing methods

int RecommendationSystem::getTotalStudents() const{
    return students.size();
}

int RecommendationSystem::getTotalCourses() const{
    return courses.size();
}

int RecommendationSystem::getTotalRecommendations() const{
    return 1;
}