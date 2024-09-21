#include <iostream>
#include "list.h"
#include "linkedlist.h"
#include "doublylinkedlist.h"
#include "arraylist.h"

using namespace std;

int main(int argc, char** argv) {
	char op;
	cout<<"Enter type of dynamic data struct [A,L,D]: ";
	cin>>op;
	op = toupper(op);
	List* list;
	string list_name;
	if(op == 'A'){
		list = new ArrayList();	
		list_name = "Array";
	}
	else if(op == 'L'){
		list = new LinkedList();
		list_name = "Singly Linked List";
	}
	else if(op == 'D'){
		list = new DoublyLinkedList();
		list_name = "Doubly Linked List";
	}
	int x,y;
	do{

		cout<<"Choose " << list_name<< " Operation: ";
		cin>>op;
		switch(op){
			case 'a':
				cout<<"Enter a number: ";
				cin>>x;
				list->add(x);
				break;
			case 'p':
				list->print();
				break;
			case 'g':
				cout<<"Enter position: ";
				cin>>x;
				y = list->get(x);
				cout<<"Found "<<y<<" in position "<<x<<endl;
				break;
			case 'r':
				cout<<"Enter number to remove: ";
				cin>>x;
				y = list->remove(x);
				cout<<"Removed "<<x<<" in position "<<y<<endl;
				break;
			case 't':
				cout<<"Enter a number: ";
				cin>>x;
				list->addTail(x);
				break;
			case 'h':
				cout<<"Enter a number: ";
				cin>>x;
				list->addHead(x);
				break;
			case '@':
				cout<<"Enter position: ";
				cin>>x;
				cout<<"Remove or add: ";
				cin>>op;
				if(op == 'r'){
					list->removeAt(x);
				} else if(op == 'a'){
					cout<<"Enter number to add: ";
					cin>>y;
					list->addAt(x,y);
				}
				break;
			case 'R':
				cout<<"Enter number: ";
				cin>>x;
				y = list->removeAll(x);
				cout<<"Removed "<<y<<" Element/s"<<endl;
				break;
//			case 's':
//				cout<<"List Sorted"<<endl;
//				list->sort();
		}
	}while(op != 'x');
	return 0;
}
