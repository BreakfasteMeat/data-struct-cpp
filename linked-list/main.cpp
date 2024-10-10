#include <iostream>
#include "linkedlist.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char Op;
	List* list = new DoublyLinkedList();
	int num, pos;
	do{
		cout<<"Enter Op: ";cin>>Op;
		switch(Op){
			case 'p':
				list->print();
			break;
			case 'a':
				cout<<"Add head, tail, or at [h,t,@]: ";
				cin>>Op;
				switch(Op){
					case 'h':
						cout<<"Enter a number: ";
						cin>>num;
						list->addHead(num);
						break;
					case 't':
						cout<<"Enter a number: ";
						cin>>num;
						list->addTail(num);
						break;
					case '@':
						cout<<"Enter a number: ";
						cin>>num;
						cout<<"Enter a position: ";
						cin>>pos;
						list->addAt(num,pos);
						break;
				}
				break;
			case 'r':
				cout<<"Remove head, tail, or at [h,t,@]: ";
				cin>>Op;
				switch(Op){
					case 'h':
						cout<<"Removed "<<list->removeHead();
						break;
					case 't':
						cout<<"Removed "<<list->removeTail();
						break;
					case '@':
						cout<<"Enter a position: ";
						cin>>pos;
						cout<<"Removed "<<list->removeAt(pos);
						break;
				}
				cout<<endl;
				break;
			case 'R':
				cout<<"Enter number to remove: ";
				cin>>num;
				cout<<"Removed "<<list->removeNum(num)<<" Element/s"<<endl;
				break;
			case 'X':
				cout<<"Removed "<<list->clearList()<<" Element/s"<<endl;
				break;
			case '1':
				cout<<"Enter number to rotate: ";
				cin>>num;
				list->rotate(num);
				break;
			case '=':
				cout<<"Enter number: ";
				cin>>num;
				list->retain(num);
			case 'f':
				list->flip();
				cout<<"Flipped list"<<endl;
		}
	}while(Op != 'x');
	return 0;
}
