#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Define an unordered_map to store student grades (key: student name, value: grade)
    std::unordered_map<std::string, int> studentGrades;

    // Insert some student grades
    studentGrades["Alice"] = 85;
    studentGrades["Bob"] = 92;
    studentGrades["Charlie"] = 78;
    studentGrades["David"] = 90;
    studentGrades["Eve"] = 88;

    // Search for a student's grade
    std::string studentName;
    std::cout << "Enter student name to search for grade: ";
    std::cin >> studentName;

    // Use find() to search for the student name in the unordered_map
    auto it = studentGrades.find(studentName);
    if (it != studentGrades.end()) {
        std::cout << studentName << "'s grade is: " << it->second << std::endl;
    } else {
        std::cout << "Student " << studentName << " not found in records." << std::endl;
    }

    return 0;
}
