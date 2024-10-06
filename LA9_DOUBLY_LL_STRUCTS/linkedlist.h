#include "node.h"

class LinkedList {
	node* head;
	node* tail;
	node* lastSenior;
	int size;

	public:
	LinkedList() {
		head = new node;
		tail = new node;
		head->next = tail;
		tail->prev = head;
		lastSenior = head;
		size = 0;
	}

	// TODO add a person
	void add(Person* p) {
	    node* n = new node();
	    n->person = p;
	    if(p->age < 60){
	        n->next = tail;
		    n->prev = tail->prev;
	        tail->prev->next = n;
	        tail->prev = n;
	    } else {
	        n->next = lastSenior->next;
	        n->prev = lastSenior;
	        lastSenior->next->prev = n;
	        lastSenior->next = n;
	        lastSenior = n;
	    }
	    size++;
	}

	// TODO serve the request
	Person* serveRequest(char ch) {
	    node* curr = head->next;
	    int r_num;
	    if(ch == 'B') r_num = 0;
	    else if(ch == 'M') r_num = 1;
	    else if(ch == 'C') r_num = 2;
	    else if(ch == 'D') r_num = 3;
	    while(!(curr->person->requests[r_num])){
	        curr = curr->next;
	        if(curr == tail) break;
	    }
	    if(curr == tail)return NULL;
	    if(curr == lastSenior) lastSenior = lastSenior->prev;
	    int *arr = curr->person->requests;
	    arr[r_num] -= 1;
	    if(!(arr[0]) && !(arr[1]) && !(arr[2]) && !(arr[3])){
	        Person *p = new Person();
	        p = curr->person;
	        size--;
	        curr->prev->next = curr->next;
	        curr->next->prev = curr->prev;
	        delete curr;
	        return p;
	    }
	    
	    return curr->person;
	}
	
    int hasOneRequest(node* n){
        int* arr = n->person->requests;
        int num = 0 + arr[0] + arr[1] + arr[2] + arr[3];
        return num == 1;
    }
	// TODO serve the request
	Person* fastLane() {
	    node* curr = head->next;
	    while(!(hasOneRequest(curr)) && curr != tail){
	        curr = curr->next;
	        if(curr == tail) break;
	    }
	    if(curr == tail)return NULL;
	    
	    Person *p = new Person();
        p = curr->person;
        size--;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        return p;
	}
	
	// TODO advance
	void advance(string name, int forward) {
	    node* curr = head->next;
	    node* toTransfer;
	    while(curr->person->firstName != name && curr->person->lastName != name){
	        curr = curr->next;
	    }
	    toTransfer = curr;
	    for(int i = 0;i < forward;i++){
	        toTransfer = toTransfer->prev;
	        if(toTransfer == head){
	            toTransfer = toTransfer->next;
	            break;
	        }
	    }
	    if(toTransfer == curr)return;
	    
	    curr->next->prev = curr->prev;
	    curr->prev->next = curr->next;
	    
	    curr->next = toTransfer;
	    curr->prev = toTransfer->prev;
	    
	    toTransfer->prev->next = curr;
	    toTransfer->prev = curr;
	    
	    
	    
	}


	// TODO delay
	void delay(string name, int back) {
	    node* curr = head->next;
	    node* toTransfer;
	    while(curr->person->firstName != name && curr->person->lastName != name){
	        curr = curr->next;
	    }
	    toTransfer = curr;
	    for(int i = 0;i < back;i++){
	        toTransfer = toTransfer->next;
	        if(toTransfer == tail){
	            toTransfer = toTransfer->prev;
	            break;
	        }
	    }
	    if(toTransfer == curr)return;
	    
	    
	    curr->prev->next = curr->next;
	    curr->next->prev = curr->prev;
	    
	    curr->next = toTransfer->next;
	    curr->prev = toTransfer;
	    
	    toTransfer->next->prev = curr;
	    toTransfer->next = curr;
	    
	}


	// TODO trade places
	void trade(string name1, string name2) {
        node* curr = head->next;
	    node* toTransfer;
	    while(curr->person->firstName != name1 && curr->person->lastName != name1){
	        curr = curr->next;
	    }
	    toTransfer = head->next;
	    while(toTransfer->person->firstName != name2 && toTransfer->person->lastName != name2){
	        toTransfer = toTransfer->next;
	    }
	    if(curr->next == toTransfer){
	        curr->prev->next = toTransfer;
	        toTransfer->next->prev = curr;
	        curr->next = toTransfer->next;
	        toTransfer->next = curr;
	        toTransfer->prev = curr->prev;
	        curr->prev = toTransfer;
	        return;
	    } else if(curr->prev == toTransfer){
	        curr->next->prev = toTransfer;
	        toTransfer->prev->next = curr;
	        toTransfer->next = curr->next;
	        curr->next = toTransfer;
	        curr->prev = toTransfer->prev;
	        toTransfer->prev = curr;
	        return;
	    }
	    
	    curr->next->prev = toTransfer;
	    curr->prev->next = toTransfer;
	    
	    toTransfer->next->prev = curr;
	    toTransfer->prev->next = curr;
	    
	    node* temp = toTransfer->next;
	    toTransfer->next = curr->next;
	    curr->next = temp;
	    
	    temp = curr->prev;
	    curr->prev = toTransfer->prev;
	    toTransfer->prev = temp;
	    
	    
	}
	// TODO print
	void print() {
	    node* curr = head->next;
	    int ctr = 1;
		cout << "Counter: " << size << endl;

		cout << "From First: " << endl;
		while(curr != tail){
		    cout<<ctr++<<". ";
		    cout<<curr->person->firstName<<" "<<curr->person->lastName;
		    cout<<" ("<<curr->person->age<<") ";
		    cout<<"- req: ";
		    if(curr->person->requests[0])cout<<"B ";
		    if(curr->person->requests[1])cout<<"M ";
		    if(curr->person->requests[2])cout<<"C ";
		    if(curr->person->requests[3])cout<<"D ";
		    cout<<endl;
		    curr = curr->next;
		}
		ctr = size;
        curr = tail->prev;
		cout << "From Last: " << endl;
        while(curr != head){
		    cout<<ctr--<<". ";
		    cout<<curr->person->firstName<<" "<<curr->person->lastName;
		    cout<<" ("<<curr->person->age<<") ";
		    cout<<"- req: ";
		    if(curr->person->requests[0])cout<<"B ";
		    if(curr->person->requests[1])cout<<"M ";
		    if(curr->person->requests[2])cout<<"C ";
		    if(curr->person->requests[3])cout<<"D ";
		    cout<<endl;
		    curr = curr->prev;
		}
	}
};
