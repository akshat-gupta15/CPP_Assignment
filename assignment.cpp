#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    int age;
    int reg_no;
    string name;
    string parentage;
    int semester;
    int roll_no;
    int attendance;
    int marks[5];

public:
    //  get details of the student
    void getDetails()
    {
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter registration number: ";
        cin >> reg_no;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter Parentage: ";
        cin >> parentage;
        cout << "Enter semester: ";
        cin >> semester;
        cout << "Enter roll number: ";
        cin >> roll_no;
        cout << "Enter attendance (classes attended): ";
        cin >> attendance;
        cout << "Enter marks for 5 subjects: ";
        for (int i = 0; i < 5; i++)
        {
            cin >> marks[i];
        }
    }

    // show all details of the student
    void showDetails() const
    {
        cout << "Age: " << age << "\n";
        cout << "Registration Number: " << reg_no << "\n";
        cout << "Name: " << name << "\n";
        cout << "Parentage: " << parentage << "\n";
        cout << "Semester: " << semester << "\n";
        cout << "Roll Number: " << roll_no << "\n";
        cout << "Attendance: " << attendance << "\n";
        cout << "Marks: ";
        for (int i = 0; i < 5; i++)
        {
            cout << marks[i] << " ";
        }
        cout << "\n";
    }

    // average percentage of marks
    float calcPercentage()
    {
        int totalMarks = 0;
        for (int i = 0; i < 5; i++)
        {
            totalMarks += marks[i];
        }
        return float(totalMarks) / 5;
    }

    // check if the student has attendance shortage (< 75%)
    void showShortage(int total_classes)
    {
        float attendancePercentage = (float(attendance) / total_classes) * 100;
        if (attendancePercentage < 75)
        {
            cout << "Roll Number: " << roll_no << ", Name: " << name
                 << ", Attendance: " << attendance << " (Shortage: " << attendancePercentage << "%)\n";
        }
    }

    // students with 90% or higher marks
    void show90()
    {
        if (calcPercentage() >= 90)
        {
            cout << "Roll Number: " << roll_no << ", Name: " << name
                 << ", Percentage: " << calcPercentage() << "%\n";
        }
    }

    // roll number and percentage
    int getRollNo() { return roll_no; }
    float getPercentage() { return calcPercentage(); }
};

// display top 5 students based on percentage
void showTop5(Student students[], int numStudents)
{
    for (int i = 0; i < numStudents - 1; i++)
    {
        for (int j = 0; j < numStudents - i - 1; j++)
        {
            if (students[j].getPercentage() < students[j + 1].getPercentage())
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // Display top 5 students
    cout << "Top 5 Students:\n";
    for (int i = 0; i < 5 && i < numStudents; i++)
    {
        cout << "Roll Number: " << students[i].getRollNo()
             << ", Name: " << students[i].name
             << ", Percentage: " << students[i].getPercentage() << "%\n";
    }
}

int main()
{
    int totalClasses;
    int numStudents;

    // number of students and total classes conducted
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cout << "Enter the total number of classes: ";
    cin >> totalClasses;

    Student students[numStudents];

    // details of each student
    for (int i = 0; i < numStudents; i++)
    {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        students[i].getDetails();
    }

    // Show details and check for attendance shortage and 90%+ marks
    for (int i = 0; i < numStudents; i++)
    {
        cout<<"Details of students: "<<endl;
        students[i].showDetails();
        students[i].showShortage(totalClasses);
        students[i].show90();
    }

    showTop5(students, numStudents);

    return 0;
}