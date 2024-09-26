#include <iostream>
#include "list.h"
#include "node.h"
using namespace std;

class DoublyLinkedList : public List{
	node* head;
	node* tail;
	int size;

public:
	DoublyLinkedList(){
		head = new node();
		tail = new node();
		head->next = tail;
		tail->prev = head;
	}
	void print(){
		if(head->next == tail){
			cout<<"[EMPTY]"<<endl;
			return;
		}
		node* curr = head->next;
		cout<<"FROM HEAD: ";
		while(curr != tail){
			cout<<"["<<curr->elem<<"]";
			if(curr->next != tail) cout<<"->";
			curr = curr->next;
		}
		cout<<endl<<"FROM TAIL: ";
		curr=tail->prev;
		while(curr != head){
			cout<<"["<<curr->elem<<"]";
			if(curr->prev != head) cout<<"<-";
			curr = curr->prev;
		}
		cout<<endl;
	}
	void addBetween(node* pred, node* n, node* succ){
		pred->next = n;
		succ->prev = n;
		n->next = succ;
		n->prev = pred;
	}
	void addHead(int num){
		node* n = new node();
		n->elem = num;
		addBetween(head,n,head->next);
	}
	void addTail(int num){
		node* n = new node();
		n->elem = num;
		addBetween(tail->prev,n,tail);
	}
	void addAt(int num,int pos){
		node* curr;
		if(pos < size/2){
			curr = head->next;
			for(int i = 1;i < pos;i++){
				
			}
		}
	}
	int removeHead(){
		
	}
	int removeTail(){
		
	}
	int removeAt(int pos){
		
	}
	int removeNum(int num){
		
	}
	int clearList(){
		
	}
	
};
