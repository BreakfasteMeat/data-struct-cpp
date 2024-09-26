#include <iostream>
#include "node.h"
//#include "list.h"

using namespace std;
class LinkedList : public List{
	int size = 0;
	node* head;
	node* tail;
	
	public:
		void add(int num){
			node* n = new node();
			n->next = 0;
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
		
		void print(){
			cout<<endl;
			node* curr = head;
			cout<<"Size - "<<size<<endl;
			while(curr){
				if(curr != head)cout<<" -> ";
				cout<<curr->elem;
				curr = curr->next;
				
			}
			if(size == 0)cout<<"(EMPTY)";
			cout<<endl<<endl;
		}
		
		int get(int pos){
			node* curr = head;
			for(int i = 0;i < pos-1;i++){
				curr = curr->next;
			}
			return curr->elem;
		}
		
		int remove(int num){
			int ctr = 2;
			node* curr = head;
			if(head->elem == num){
				head = head->next;
				delete curr;
				return 1;
			} else {
				
				node* prev = curr;
				curr = curr->next;
				while(curr->elem != num){
					prev = curr;
					curr = curr->next;
					ctr++;
				}
				
				prev->next = curr->next;
				if(curr == tail){
					tail = prev;	
				}
				delete curr;
			}
			
			return ctr;
		}
		void addHead(int num){
			node* n = new node();
			n->elem = num;
			if(size == 0){
				head = n;
				tail = n;
			} else {
				n->next = head;
				head = n;
			}
			size++;
		}
		void addTail(int num){
			add(num);
		}
		void addAt(int pos, int num){
			node* n = new node();
			n->elem = num;
			if(pos == 1){
				addHead(num);
			} else if(pos == size + 1){
				add(num);
			} else {
				node* curr = head;
				for(int i = 1;i < pos-1;i++){
					curr = curr->next;
				}
				n->next = curr->next;
				curr->next = n;
				size++;
			}
			
		}
		int removeAt(int pos){
			node* curr = head;
			if(pos == 1){
				head = head->next;
				delete curr;
			} else {
				for(int i = 1;i < pos-1;i++){
					curr = curr->next;
				}
				node* prev = curr;
				curr = curr->next;
				prev->next = curr->next;
				if(pos == size){
					prev->next = 0;
					tail = prev;	
				}
				delete curr;
			}
			size--;
		}
		int removeAll(int num){
			int ctr = 0;
			node* curr = head;
			node* prev = head;
			for(int i = 1;i <= size;i++){
				if(curr->elem == num){
					ctr++;
					if(i == 1){
						head = curr->next;
						delete curr;
						curr = head;
						prev = head;
					} else if(i == size){
						tail = prev;
						prev->next = 0;
						delete curr;
					} else {
						prev->next = curr->next;
						delete curr;
						curr = prev->next;
					}
					i--;
					size--;
				} else {
					prev = curr;
					curr = curr->next;
				}
			}
			
			return ctr;
		}
		void qsort(){
//			node * stack[size];
//			int stackLen = 1;
//			stack[0] = 0;
//			node * cur = head;
//			node *temp;
//			
//			while (stackLen) {
//				if (cur->)
//				
//				if {stack[stackLen - 1] == 0 && cur->next->elem < head->elem} {
//					stack[stackLen - 1] = head;
//					head = cur->next;
//					
//					cur->next = head->next;
//					head->next = stack[stackLen - 1];
//					stack[stackLen - 1] = head;
//					
//					continue;
//				}
//				else if (cur->next->elem < stack[stackLen - 1]->next->elem) {
//					temp = cur->next;
//					cur->next = temp->next;
//					
//					temp->next = stack[stackLen - 1]->next;
//					stack[stackLen - 1] = temp;
//					
//					continue;
//				}
//				
//				cur = cur->next;
//			}
		}
	    void reverse(){
		}
	    void sort(){}
		void deleteList(){}
		int retain(int num){}
		int corner(int left, int right){}
};
