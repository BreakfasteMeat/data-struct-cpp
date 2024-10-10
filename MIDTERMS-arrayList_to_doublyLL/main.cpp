#include <iostream>
#include "list.h"
#include "arraylist.h"
#include "SinglyLL.h"
#include "DoublyLL.h"
#include <stdlib.h>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    list* currentList = 0; // Pointer to the current list being used
    int choice = 0, num, pos, start, end, left, right, index_a, index_b, pivot;
    bool running = true;
    list* arraylist = new ArrayList();
    list* singlyLL = new SinglyLL();
	list* doublyLL = new DoublyLL();
	currentList = arraylist;
    // Example of switching between different list types
    while (running) {
        // Display the current list contents (assuming a print function exists)
        if (currentList != 0) {
            cout << "Current List: ";
            currentList->print();
        } else {
            cout << "No list type selected yet." << endl;
        }

        // Menu
        cout << "\nMENU:\n";
        cout << "1. Switch to ArrayList\n";
        cout << "2. Switch to SinglyLL\n";
        cout << "3. Switch to DoublyLL\n";
        cout << "4. Add First\n";
        cout << "5. Add Last\n";
        cout << "6. Add At\n";
        cout << "7. Remove First\n";
        cout << "8. Remove Last\n";
        cout << "9. Remove At\n";
        cout << "10. Corner Operation\n";
        cout << "11. Retain Elements\n";
        cout << "12. Swap\n";
        cout << "13. Remove By Value\n";
        cout << "14. Reverse Sublist\n";
        cout << "15. Find Middle\n";
        cout << "16. Check Palindrome\n";
        cout << "17. Partition\n";
        cout << "18. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                currentList = arraylist;
                cout << "Switched to ArrayList\n";
                break;
            case 2:
                currentList = singlyLL;
                cout << "Switched to SinglyLL\n";
                break;
            case 3:
                currentList = doublyLL;
                cout << "Switched to DoublyLL\n";
                break;
            case 4:
                cout << "Enter number to add at first: ";
                cin >> num;
                currentList->addFirst(num);
                break;
            case 5:
                cout << "Enter number to add at last: ";
                cin >> num;
                currentList->addLast(num);
                break;
            case 6:
                cout << "Enter position and number to add: ";
                cin >> pos >> num;
                currentList->addAt(pos, num);
                break;
            case 7:
                currentList->removeFirst();
                break;
            case 8:
                currentList->removeLast();
                break;
            case 9:
                cout << "Enter position to remove at: ";
                cin >> pos;
                currentList->removeAt(pos);
                break;
            case 10:
                cout << "Enter left and right for corner operation: ";
                cin >> left >> right;
                currentList->corner(left, right);
                break;
            case 11:
                cout << "Enter number to retain: ";
                cin >> num;
                currentList->retain(num);
                break;
            case 12:
                cout << "Enter two indices to swap: ";
                cin >> index_a >> index_b;
                currentList->swap(index_a, index_b);
                break;
            case 13:
                cout << "Enter number to remove by value: ";
                cin >> num;
                currentList->removeByValue(num);
                break;
            case 14:
                cout << "Enter start and end for sublist reversal: ";
                cin >> start >> end;
                currentList->reverseSublist(start, end);
                break;
            case 15:
                cout << "Middle element: " << currentList->findMiddle() << endl;
                break;
            case 16:
                if (currentList->isPalindrome()) {
                    cout << "The list is a palindrome.\n";
                } else {
                    cout << "The list is not a palindrome.\n";
                }
                break;
            case 17:
                cout << "Enter pivot for partition: ";
                cin >> pivot;
                currentList->partition(pivot);
                break;
            case 18:
                running = false;
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
        system("cls");
        
    }

    // Clean up memory
    delete currentList;

    return 0;
}
