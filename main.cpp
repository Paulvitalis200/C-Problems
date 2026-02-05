#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

using namespace std;

// Write a program that reads student names and their scores (integers) from a file named "grades.txt"
// (assume each line is "Name Score", e.g., "Alice 85"). Use an array to store up to 10 students'
// data in a structure (with fields for name as string and score as int). Then, use a loop and
// decision making to categorize each student's grade (A for 90+, B for 80-89, etc.) and
// output the results to the console. Include a function to compute the average score.
// Emphasized concepts: Structures, arrays, loops, decision making, functions, strings, streams/files.

struct StudentScore {
    string name;
    int score = 0;
};

void readInputFile(string& inputfile, StudentScore student_score[], int& count) {
    ifstream inputFile(inputfile);

    if (!inputFile.is_open()) {
        cerr << "Problem Reading file" << endl;
    } else {
        count = 0;
        string name;
        int score;

        while (count < 10 && inputFile >> name >> score) {
            student_score[count].name = name;
            student_score[count].score = score;

            count++;
        }
        inputFile.close();
    }
};

int main() {

    string filePath = "../data/students_scores.txt";

    int count = 0;
    StudentScore students_and_scores[10] = {};
    readInputFile(filePath, students_and_scores, count);

    for (int i = 0; i < count; ++i) {
        char grade = 'F';
        int score = students_and_scores[i].score;
        if (score >= 90)
            grade = 'A';
        else if (score >= 80)
            grade = 'B';
        else if (score >= 70)
            grade = 'C';
        else if (score >= 60)
            grade = 'D';
        else if (score >= 50)
            grade = 'E';
        cout << i + 1 << ": " << students_and_scores[i].name << ' ' << students_and_scores[i].score << ' ' << grade << endl;
    }
    return 0;
}
