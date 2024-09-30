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
    // Empty code block
    return 0;  // Placeholder return value
	}

	int removeTail(){
    // Empty code block
    return 0;  // Placeholder return value
	}

	int removeAt(int pos){
    // Empty code block
    return 0;  // Placeholder return value
	}

	int removeNum(int num){
    // Empty code block
    return 0;  // Placeholder return value
	}

	int clearList(){
    // Empty code block
    return 0;  // Placeholder return value
	}

	void rotate(int num){
    // Empty code block
	}

	
};
