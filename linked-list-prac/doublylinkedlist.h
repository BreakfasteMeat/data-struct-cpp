#include <iostream>
#include "dnode.h"
//#include "list.h"

using namespace std;
class DoublyLinkedList : public List{
	dnode* head;
	dnode* tail;
	int size = 0;

public:
	void add(int num){
		dnode* n = new dnode();
		n->next = 0;
		n->prev = 0;
		n->elem = num;
		if(size == 0){
			head = n;
			tail = n;
		} else {
			n->prev = tail;
			tail->next = n;
			tail = n;
		}
		size++;
	}
	void print(){
		dnode* curr = head;
		cout<<"FROM HEAD: ";
		while(curr){
			cout<<curr->elem;
			if(curr->next)cout<<"->";
			curr = curr->next;
		}
		cout<<endl;
		curr = tail;
		cout<<"FROM TAIL: ";
		while(curr){
			cout<<curr->elem;
			if(curr->prev)cout<<"<-";
			curr = curr->prev;
		}
		cout<<endl;
	}
	int get(int pos){
		dnode* curr;
		int currPos;
		if(pos > size/2){
			curr = tail;
			currPos = size;
			while(currPos != pos){
				curr=curr->prev;
				currPos--;
			}
		} else {
			curr = head;
			currPos = 1;
			while(currPos != pos){
				curr=curr->next;
				currPos++;
			}
		}
		return curr->elem;
	}
	int remove(int num){
		dnode* curr = head;
		int ret = 1;
		while(curr->elem != num){
			curr = curr->next;
			ret++;
		}
		if(curr != head){
			curr->prev->next = curr->next;
		} else {
			head = curr->next;
			curr->next->prev = 0;
		}
		if(curr != tail){
			curr->next->prev = curr->prev;
		} else {
			tail = curr->prev;
			curr->prev->next = 0;
		}
		return ret;
		delete curr;
	}
	void addHead(int num){
		
	}
	void addTail(int num){
	}
	void removeAt(int pos){
		
	}
	void addAt(int pos,int num){
	}
	int removeAll(int num){
	}
};
