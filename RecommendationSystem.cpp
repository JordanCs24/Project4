#include "RecommendationSystem.h"

void RecommendationSystem::loadData(const string& filename){
    ifstream fs;
    string studentName;
    string line;
    string course;
    fs.open(filename);
    if(!fs.is_open()){
        cout << "Couldn't open: " << filename;
    }
    while(fs.good()){
        getline(fs,line);

        istringstream strLine(line);
        strLine >> studentName;

        studentName.erase(remove(studentName.begin(), studentName.end(),':')); // removes the ':' character

        Student studentHolder(studentName);

        while(strLine >> course){
            course.erase(remove(course.begin(), course.end(),','));
            courses.insert(course);
            studentHolder.addRecommendation(course);
        }

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
    vector<string> randomVec;

   for(auto &it : students){
        randomVec = it.second.getRecommendations();
        out << it.second.getName() << ": [";
        for(auto &i : randomVec){
            out << i << ", ";
        }
        out << "]" << endl;
   }
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