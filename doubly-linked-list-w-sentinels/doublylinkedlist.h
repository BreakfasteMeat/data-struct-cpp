#include <iostream>
#include "list.h"
#include "node.h"
using namespace std;

class DoublyLinkedList : public List{
	node* head;
	node* tail;
	int size;
	void remove_node(node* n){
		node* pred = n->prev;
		node* succ = n->next;
		pred->next = n->next;
		succ->prev = n->prev;
		size--;
		delete n;
	}
	void addBetween(node* pred, node* n, node* succ){
		pred->next = n;
		succ->prev = n;
		n->next = succ;
		n->prev = pred;
		size++;
	}

public:
	DoublyLinkedList(){
		head = (node *)new sentinelNode;
		tail = (node *)new sentinelNode;
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
		node* n = new node();
		n->elem = num;
		node* curr;
		if(pos < size/2){
			curr = head->next;
			for(int i = 1;i < pos-1;i++){
				curr = curr->next;
			}
		} else {
			curr = tail->prev;
			for(int i = size;i > pos-1;i--){
				curr = curr->prev;
			}
		}
		addBetween(curr,n,curr->next);
	}
	int removeHead(){
		int ret = head->next->elem;
		remove_node(head->next);
		return ret;
	}
	int removeTail(){
		int ret = tail->prev->elem;
		remove_node(tail->prev);
		return ret;
	}
	int removeAt(int pos){
		node* curr;
		if(pos < size/2){
			curr = head->next;
			for(int i = 1;i < pos;i++){
				curr = curr->next;
			}
		} else {
			curr = tail->prev;
			for(int i = size;i > pos;i--){
				curr = curr->prev;
			}
		}
		int ret = curr->elem;
		remove_node(curr);
		return ret;
		
	}
	int removeNum(int num){
		node* curr = head->next;
		int ctr = 0;
		while(curr != tail){
			if(curr->elem == num){
				node* temp = curr->next;
				remove_node(curr);
				curr = temp;
				ctr++;	
			} else
				curr = curr->next;
		}
		return ctr;
	}
	int clearList(){
		int ret = size;
		node* curr = head->next;
		node* toDelete;
		while(curr != tail){
			toDelete = curr;
			curr = curr->next;
			remove_node(toDelete);
		}
		return ret;	
	}
	void rotate(int num){
		tail->prev->next = head->next;
		head->next->prev = tail->prev;
		node* curr = head->next;
		for(int i = 0;i < num;i++){
			curr = curr->next;
		}
		head->next = curr;
		tail->prev = curr->prev;
		tail->prev->next = tail;
		head->next->prev = head;
	}
	~DoublyLinkedList(){
		cout<<"Deleting myself from here."<<endl;
		node* curr = head;
		while(curr != tail){
			curr = curr->next;
			free(curr->prev);
		}
		free(curr);
	}
};
