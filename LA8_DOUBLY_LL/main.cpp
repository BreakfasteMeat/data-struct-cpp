// Warning: Do not modify this file.
// Go to linkedlist.h's remove method

#include <iostream>
#include "linkedlist.h"

int main() {
	List* list = new LinkedList();
    int input, res, num, pos, left, right;
    char op;
    do {
    	cout << "Enter op: ";
    	cin >> op;
    	switch (op) {
    		case 'a' :
		    	cin >> input;
		    	list->add(input);
		    	break;
            case 'g':
		    	cin >> input;
                res = list->get(input);
                if (res == -1) {
                    cout << "Invalid position: " << input << endl;
                } else {
                    cout << "Element at position " << input << " is " << res << endl;
                }
		    	break;
		    case 'p':
		    	list->print();
		    	break;
		    case 'r':
		    	cin >> input;
                cout << "Removed position " << list->remove(input) << endl;
		    	break;
            case '@':
                cin >> num >> pos;
                list->addAt(num, pos);
		    case 'R':
                cin >> pos;
                cout << "Removed " << list->removeAt(pos) << endl;
		    case '=':
                cin >> input;
                cout << "Removed " << list->retain(input) << " element/s" << endl;
                break;
        	case 'c':
                cin >> left;
                cin >> right;
                cout << "Removed " << list->corner(left, right) << " element/s" << endl;
                break;
		    case 'x':
		    	cout << "Exiting";
		    	break;
		}
	} while (op != 'x');
    return 0;
}
