
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

// Structure for Student
struct Student
{
    int rollNo;
    string name;
    string branch;
    float marks;
    Student *next;
};

// Head pointer
Student *head = NULL;

// Stack for Undo Deletion
stack<Student> deletedStudents;

// Function to check duplicate roll number
bool isDuplicate(int roll)
{
    Student *temp = head;

    while (temp != NULL)
    {
        if (temp->rollNo == roll)
            return true;

        temp = temp->next;
    }

    return false;
}

// 1. Add Student
void addStudent()
{
    Student *newStudent = new Student;

    cout << "\nEnter Roll Number: ";
    cin >> newStudent->rollNo;

    if (isDuplicate(newStudent->rollNo))
    {
        cout << "\nRoll Number Already Exists!\n";
        delete newStudent;
        return;
    }

    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, newStudent->name);

    cout << "Enter Branch: ";
    getline(cin, newStudent->branch);

    cout << "Enter Marks: ";
    cin >> newStudent->marks;

    newStudent->next = NULL;

    if (head == NULL)
    {
        head = newStudent;
    }
    else
    {
        Student *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newStudent;
    }

    cout << "\nStudent Added Successfully!\n";
}

// 2. Display All Students
void displayStudents()
{
    if (head == NULL)
    {
        cout << "\nNo Student Records Found!\n";
        return;
    }

    Student *temp = head;

    cout << "\n========== STUDENT RECORDS ==========\n";

    while (temp != NULL)
    {
        cout << "\nRoll Number: " << temp->rollNo;
        cout << "\nName: " << temp->name;
        cout << "\nBranch: " << temp->branch;
        cout << "\nMarks: " << temp->marks;
        cout << "\n-------------------------------------";

        temp = temp->next;
    }
}

// 3. Search Student
void searchStudent()
{
    int roll;

    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    Student *temp = head;

    while (temp != NULL)
    {
        if (temp->rollNo == roll)
        {
            cout << "\nStudent Found!\n";
            cout << "Roll Number: " << temp->rollNo;
            cout << "\nName: " << temp->name;
            cout << "\nBranch: " << temp->branch;
            cout << "\nMarks: " << temp->marks << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "\nStudent Not Found!\n";
}

// 4. Update Student
void updateStudent()
{
    int roll;

    cout << "\nEnter Roll Number to Update: ";
    cin >> roll;

    Student *temp = head;

    while (temp != NULL)
    {
        if (temp->rollNo == roll)
        {
            cin.ignore();

            cout << "Enter New Name: ";
            getline(cin, temp->name);

            cout << "Enter New Branch: ";
            getline(cin, temp->branch);

            cout << "Enter New Marks: ";
            cin >> temp->marks;

            cout << "\nRecord Updated Successfully!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "\nStudent Not Found!\n";
}

// 5. Delete Student
void deleteStudent()
{
    int roll;

    cout << "\nEnter Roll Number to Delete: ";
    cin >> roll;

    Student *temp = head;
    Student *previous = NULL;

    while (temp != NULL)
    {
        if (temp->rollNo == roll)
        {
            // Save deleted record in Stack
            Student saved = *temp;
            saved.next = NULL;
            deletedStudents.push(saved);

            if (previous == NULL)
            {
                head = temp->next;
            }
            else
            {
                previous->next = temp->next;
            }

            delete temp;

            cout << "\nStudent Deleted Successfully!\n";
            return;
        }

        previous = temp;
        temp = temp->next;
    }

    cout << "\nStudent Not Found!\n";
}

// 6. Sort Students by Marks (Descending)
void sortStudents()
{
    if (head == NULL || head->next == NULL)
    {
        cout << "\nNot Enough Records to Sort!\n";
        return;
    }

    for (Student *i = head; i->next != NULL; i = i->next)
    {
        for (Student *j = head; j->next != NULL; j = j->next)
        {
            if (j->marks < j->next->marks)
            {
                swap(j->rollNo, j->next->rollNo);
                swap(j->name, j->next->name);
                swap(j->branch, j->next->branch);
                swap(j->marks, j->next->marks);
            }
        }
    }

    cout << "\nStudents Sorted Successfully (Highest Marks First)!\n";
}

// 7. Find Topper
void findTopper()
{
    if (head == NULL)
    {
        cout << "\nNo Student Records Found!\n";
        return;
    }

    Student *temp = head;
    Student *topper = head;

    while (temp != NULL)
    {
        if (temp->marks > topper->marks)
        {
            topper = temp;
        }

        temp = temp->next;
    }

    cout << "\n========== TOPPER DETAILS ==========\n";
    cout << "Roll Number: " << topper->rollNo;
    cout << "\nName: " << topper->name;
    cout << "\nBranch: " << topper->branch;
    cout << "\nMarks: " << topper->marks << endl;
}

// 8. Count Total Students
void countStudents()
{
    int count = 0;
    Student *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "\nTotal Students: " << count << endl;
}

// 9. Undo Last Deletion
void undoDeletion()
{
    if (deletedStudents.empty())
    {
        cout << "\nNothing to Undo!\n";
        return;
    }

    Student restored = deletedStudents.top();

    // Prevent duplicate roll numbers
    if (isDuplicate(restored.rollNo))
    {
        cout << "\nCannot Restore! Roll Number Already Exists.\n";
        return;
    }

    deletedStudents.pop();

    Student *newStudent = new Student;

    newStudent->rollNo = restored.rollNo;
    newStudent->name = restored.name;
    newStudent->branch = restored.branch;
    newStudent->marks = restored.marks;

    // Insert at beginning
    newStudent->next = head;
    head = newStudent;

    cout << "\nLast Deleted Student Restored Successfully!\n";
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n\n========================================";
        cout << "\n      STUDENT RECORD MANAGEMENT SYSTEM";
        cout << "\n========================================";

        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Delete Student";
        cout << "\n6. Sort Students by Marks";
        cout << "\n7. Find Topper";
        cout << "\n8. Count Total Students";
        cout << "\n9. Undo Last Deletion";
        cout << "\n10. Exit";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            sortStudents();
            break;

        case 7:
            findTopper();
            break;

        case 8:
            countStudents();
            break;

        case 9:
            undoDeletion();
            break;

        case 10:
            cout << "\nThank You for Using the System!\n";
            break;

        default:
            cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while (choice != 10);

    // Free allocated memory
    while (head != NULL)
    {
        Student *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
