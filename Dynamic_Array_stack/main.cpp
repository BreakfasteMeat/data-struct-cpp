#include <iostream>
#include <windows.h>
#include <conio.h>
#include "arraylist.h"
using namespace std;

int main() {
    int choice, value;
    ArrayList* myStack = new ArrayList();
    

    do {
        // Display menu and stack
        system("cls");
        myStack->print();
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek (Top Element)" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Get Size" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Push an element onto the stack
                cout << "Enter a value to push: ";
                cin >> value;
                myStack->push(value);
                cout << value << " has been pushed to the stack." << endl;
                break;

            case 2:
                // Pop an element from the stack
                if (!myStack->isEmpty()) {
                    cout << "Popped value: " << myStack->top() << endl;
                    myStack->pop();
                } else {
                    cout << "Stack is empty, nothing to pop!" << endl;
                }
                break;

            case 3:
                // Peek the top element
                if (!myStack->isEmpty()) {
                    cout << "Top value: " << myStack->top() << endl;
                } else {
                    cout << "Stack is empty, no top element!" << endl;
                }
                break;

            case 4:
                // Check if the stack is empty
                if (myStack->isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;

            case 5:
                // Get the size of the stack
                cout << "Stack size: " << myStack->getSize() << endl;
                break;

            case 6:
                // Exit the loop
                cout << "Exiting the program. Goodbye!" << endl;
                continue;
                break;

            default:
                // Invalid choice
                cout << "Invalid choice, please try again." << endl;
        }
        cout<<"Press any enter to continue";
        getch();
    } while (choice != 6);  // Continue looping until the user selects "Exit"

    return 0;
}

