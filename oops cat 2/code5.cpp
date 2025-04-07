#include <iostream>
#include <vector>
using namespace std;

struct Student {
    string name;
    vector<int> marks;
    double average;
};

int main() {
    int numStudents, numSubjects;
    
    // Input number of students and subjects
    cout << "Enter number of students: ";
    cin >> numStudents;
    cout << "Enter number of subjects: ";
    cin >> numSubjects;
    
    vector<Student> students(numStudents);
    
    // Input student details and calculate average
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> students[i].name;
        
        int sum = 0;
        students[i].marks.resize(numSubjects);
        
        cout << "Enter " << numSubjects << " subject marks for " << students[i].name << ": ";
        for (int j = 0; j < numSubjects; j++) {
            cin >> students[i].marks[j];
            sum += students[i].marks[j];
        }
        
        students[i].average = (double)sum / numSubjects;
    }
    
    // Print students with average marks below 40
    cout << "Students with average marks below 40:" << endl;
    for (const auto &student : students) {
        if (student.average < 40) {
            cout << student.name << endl;
        }
    }
    
    return 0;
}
