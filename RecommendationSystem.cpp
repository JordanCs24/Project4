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

        courses.insert(course1); // Adds the courses to the set
        courses.insert(course2);
        courses.insert(course3);

        Student studentHolder(studentName);
        studentHolder.addRecommendation(course1);
        studentHolder.addRecommendation(course2);
        studentHolder.addRecommendation(course3);

        students.emplace(studentName, studentHolder);
    }
}


vector<string> RecommendationSystem::generateRecommendationsForStudent(const string& studentName) const{
/*
    Sort recommendations:
    By popularity (descending).
    Alphabetically for ties.
*/
// Takes a student’s name and returns their list of recommended courses, sorted by popularity and alphabetically for ties.
    vector<string>recommendations = students.at(studentName).getRecommendations();

    sort(recommendations.begin(),recommendations.end());

    return recommendations;

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
/*  for (auto &i : students){
        vector<string> randomVec = i.second.getRecommendations();
        out << i.second.getName() << ": " << "[" << i.second.getRecommendations() << "]" << endl;
    }
    */
}

 

// Testing methods

int RecommendationSystem::getTotalStudents() const{
    int studentCount = 0;
    for(auto i : students){
        studentCount++;
    }
    return studentCount;
}

int RecommendationSystem::getTotalCourses() const{
    return courses.size();
}

int RecommendationSystem::getTotalRecommendations() const{
    //Returns the total number of recommendations generated (sum of all recommendation lists).
    return courses.size();
}