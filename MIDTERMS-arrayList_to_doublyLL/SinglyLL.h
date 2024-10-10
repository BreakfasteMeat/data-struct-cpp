#include <iostream>
struct node{
	int elem;
	node* next;
};
class SinglyLL : public list{
	node* head;
	node* tail;
	int size = 0;
	void addFirst(int num){
		node* n = (node*)calloc(1,sizeof(node));
		n->elem = num;
		if(size == 0){
			head = n;
			tail = n;
		} else {
			n->next = head;
			n = head;
		}
		size++;
	}
	void addLast(int num){
		node* n = (node*)calloc(1,sizeof(node));
		n->elem = num;
		if(size == 0){
			head = n;
			tail = n;
		} else {
			tail->next = n;
			tail = n;
		}
		size++;
	}
	void addAt(int pos,int p){
	}
	int removeFirst(){
	}
	int removeLast(){
	}
	int removeAt(int pos){
	}
	int corner(int left, int right){
	}
	int retain(int num){
	}
	int swap(int index_a, int index_b){
	}
	int removeByValue(int num){
	}
	void advance(){
	}
	void delay(){
	}
	void print(){
		node* curr = head;
		cout<<endl;
		
		while(curr){
			cout<<curr->elem;
			if(curr->next)cout<<"->";
			curr=curr->next;
		}
	}
	int reverseSublist(int start, int end){
	}
	int findMiddle(){
	}
	bool isPalindrome(){
	}
	void partition(int pivot){
	}
};
