#include <iostream>
using namespace std;

class Student {
private:
    int roll;
    string name;
    float marks;

public:
    void input() {
        cout << "\nEnter Roll Number: ";
        cin >> roll;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() const {
        cout << "\n-----------------------------";
        cout << "\nRoll No : " << roll;
        cout << "\nName    : " << name;
        cout << "\nMarks   : " << marks;
        cout << "\n-----------------------------";
    }

    int getRoll() const {
        return roll;
    }
};

int main() {
    Student students[100];
    int count = 0;
    int choice;

    do {
        cout << "\n\n========== STUDENT MANAGEMENT SYSTEM ==========";
        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Search Student by Roll Number";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            if(count >= 100) {
                cout << "\nDatabase is full. Cannot add more students.\n";
            } else {
                students[count].input();
                count++;
                cout << "\nStudent record added successfully.\n";
            }
            break;

        case 2:
            if(count == 0) {
                cout << "\nNo student records available.\n";
            } else {
                cout << "\nDisplaying all student records:\n";
                for(int i = 0; i < count; i++) {
                    students[i].display();
                }
            }
            break;

        case 3: {
            if(count == 0) {
                cout << "\nNo records available to search.\n";
                break;
            }

            int searchRoll;
            bool found = false;

            cout << "\nEnter Roll Number to search: ";
            cin >> searchRoll;

            for(int i = 0; i < count; i++) {
                if(students[i].getRoll() == searchRoll) {
                    cout << "\nStudent found:\n";
                    students[i].display();
                    found = true;
                    break;
                }
            }

            if(!found) {
                cout << "\nStudent not found.\n";
            }
            break;
        }

        case 4:
            cout << "\nExiting program. Thank you.\n";
            break;

        default:
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while(choice != 4);

    return 0;
}