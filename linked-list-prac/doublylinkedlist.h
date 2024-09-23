#include <iostream>
#include "dnode.h"
#include <algorithm>
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
			cout<<"["<<curr->elem<<"]";
			if(curr->next)cout<<"->";
			curr = curr->next;
		}
		cout<<endl;
		curr = tail;
		cout<<"FROM TAIL: ";
		while(curr){
			cout<<"["<<curr->elem<<"]";
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
		if(size == 1){
			size--;
			delete curr;
			head = 0;
			tail = 0;
			return ret;
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
		delete curr;
		size--;
		return ret;
	}
	void addHead(int num){
		dnode* n = (dnode*)calloc(1,sizeof(dnode));
		n->elem = num;
		if(size == 0){
			head = n;
			tail = n;
		} else {
			head->prev = n;
			n->next = head;
			head = n;
		}
		size++;
	}
	void addTail(int num){
		add(num);
	}
	int removeAt(int pos){
		dnode* curr = head;
		int ret;
		if(size == 1){
			size--;
			ret = curr->elem;
			delete curr;
			head = 0;
			tail = 0;
			return ret;
		}
		if(pos < size/2){
			for(int i = 1;i < pos;i++){
				curr = curr->next;
			}
		} else {
			curr = tail;
			for(int i = size;i > pos;i--){
				curr = curr->prev;
			}
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
		delete curr;
		size--;
		return ret;
	}
	void addAt(int pos,int num){
		dnode* curr = head;
		dnode* n = (dnode*)calloc(1,sizeof(dnode));
		n->elem = num;
		n->next = 0;
		n->prev = 0;
		if(pos==1){
			head->prev = n;
			n->next = head;
			size++;
			return;
		}
		if(pos < size/2){
			for(int i = 1;i < pos;i++){
				curr = curr->next;
			}
		} else {
			curr = tail;
			for(int i = size;i > pos;i--){
				curr = curr->prev;
			}
		}
		n->next = curr;
		n->prev = curr->prev;
		curr->prev->next = n;
		curr->prev = n;
	}
	int removeAll(int num){
		dnode* curr = head;
		int ret = 0;
		while(curr->next){
			if(curr->elem == num){
				ret++;
				if(curr != head){
					curr->prev->next = curr->next;
				} else {
					curr->next->prev = 0;
					head = curr->next;
				}
				if(curr != tail){
					curr->next->prev = curr->prev;
				} else {
					curr->prev->next = 0;
					tail = curr->prev;
				}
				size--;
				dnode* temp = curr->next;
				delete curr;
				curr = temp;
				continue;
			}
			curr = curr->next;
		}
		return ret;
	}
	void reverse(){
		dnode* curr = head;
		dnode* otherside = tail;
		for(int i = 1;i <= size / 2;i++){
			swap(curr->elem,otherside->elem);
			curr = curr->next;
			otherside = otherside->prev;
		}
	}
    void sort(){
	}
};
