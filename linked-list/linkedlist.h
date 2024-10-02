#include <iostream>
#include "list.h"
#include "node.h"
#include <stdlib.h>
using namespace std;

class DoublyLinkedList : public List{
	node* head;
	node* tail;
	

public:
	void print(){
		node* curr = head;
		while(curr){
			cout<<curr->elem;
			if(curr->next)cout<<"->";
			curr = curr->next;
		}
		cout<<endl;
	}

	void addHead(int num){
    	node* n = (node*)calloc(1,sizeof(node));
    	n->elem = num;
    	if(head == 0){
			head = n;
			tail = n;
		} else {
			n->next = head;
			head = n;
		}
	}

	void addTail(int num){
		node* n = (node*)calloc(1,sizeof(node));
    	n->elem = num;
    	if(head == 0){
			head = n;
			tail = n;
		} else {
			tail->next = n;
			tail = n;
		}
	}

	void addAt(int num, int pos){
		node* n = (node*)calloc(1,sizeof(node));
		node* curr = head;
		n->elem = num;
		for(int i = 1;i < pos-1;i++){
			curr = curr->next;
		}
		n->next = curr->next;
		curr->next = n;
	}

	int removeHead(){
		int ret = head->elem;
		node* toDelete = head;
		head = head->next;
		delete toDelete;
		return ret;
	}

	int removeTail(){
    	node* curr = head;
    	while(curr->next != tail){
    		curr = curr->next;
		}
		int ret = tail->elem;
		delete tail;
		tail = curr;
		curr->next = 0;
		return ret;
	}

	int removeAt(int pos){
    	node* curr = head;
    	if(pos == 1){
    		int ret = removeHead();
    		return ret;
		}
		if(head == tail){
			delete head;
			head = 0;
			tail = 0;
		}
		for(int i = 1;i < pos-1;i++){
    		curr = curr->next;
		}

		node* toDelete = curr->next;
		int ret = toDelete->elem;
		if(curr->next->next)
			curr->next = curr->next->next;
		else{
			curr->next = 0;
			tail = curr;
		}
		delete toDelete;
		return ret;
	}

	int removeNum(int num){
    	node* curr = head;
    	node* prev = head;
    	int ret = 0;
    	while(curr){
    		if(curr -> elem == num){
    			ret++;
    			if(curr == head && curr == tail){
    				head = 0;
    				delete tail;
    				tail = 0;
    				break;
				}
				if(curr == head){
    				head = curr->next;
    				delete curr;
    				curr = head;
    				prev = curr;
    				continue;
				}
				if(curr == tail){
					tail = prev;
					delete curr;
					tail->next = 0;
					curr = 0;
					continue;
				}
				prev->next = curr->next;
				delete curr;
				curr = prev->next;
				continue;
			}
			prev = curr;
    		curr = curr->next;
		}
    	return ret;
	}

	int clearList(){
    	int ret = 0;
    	node* curr = head;
    	while(curr){
    		ret++;
			if(curr->next == 0)break;
    		curr = curr->next;
    		removeHead();
		}
		delete head;
		head = 0;
		tail = 0;
		return ret;
	}

	void rotate(int num){
		int ctr = 0;
		node* curr = head;
		while(curr){
			ctr++;
			curr = curr->next;
		}
		ctr -= num;
		tail->next = head;
		for(int i = 0;i < ctr;i++){
			head = head->next;
			tail = tail->next;
		}
		tail->next = 0;
	}

	
};
