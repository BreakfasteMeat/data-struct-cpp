#include "list.h"
#include "node.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class LinkedList : public List {
	node *head, *tail;
	int size;

public:
	void addFirst(int num) {
		// STEP 1: Create node n
		node* n = (node*) calloc( 1, sizeof(node) );
		n->elem = num;
		// STEP 2: Connect n to head
		n->next = head;
		if (head) {
			head->prev = n;
		}
		// STEP 3: Reassign head
		head = n;
		if (!tail) {
			tail = n;
		}
		// STEP 4: Update size
		size++;
	}
	void addLast(int num) {
		// STEP 1: Create node n
		node* n = new node;
		n->elem = num;
		n->next = NULL;
		// STEP 2: Connect tail to n
		if (tail) {
			tail->next = n;
		} else {
			head = n;
		}
		n->prev = tail;
		// STEP 3: Reassign tail
		tail = n;
		// STEP 4: Update size
		size++;
	}

	void removeFirst() {
		if (!head) {
			return;
		}
		head = head->next;
		if (head) {
			free(head->prev);
			head->prev = 0;
		} else {
			free(tail);
			tail = 0;
		}
		size--;
	}

	void removeLast() {
		if (!tail) {
			return;
		}
		tail = tail->prev;
		if (tail) {
			free(tail->next);
			tail->next = 0;
		} else {
			free(head);
			head = 0;
		}
		size--;
	}

	void add(int num) {
		addLast(num);
	}
	void addAt(int num,int pos){
        node* curr = head;
        node* n = (node*)calloc(1,sizeof(node));
        n->elem = num;
        if(size == 0){
            head = n;
            tail = n;
            size++;
            return;
        }
        if(pos == 1){
            head->prev = n;
            n->next = head;
            head = n;
            size++;
            return;
        } else if(pos == size + 1){
            tail->next = n;
            n->prev = tail;
            tail = n;
            size++;
            return;
        }
        
        int half = size/2;
        if(size%2 != 0) half++;
        if(pos <= half){
            for(int i = 1;i < pos - 1;i++){
                curr = curr->next;
            }
        } else {
            curr = tail;
            for(int i = size;i >= pos;i--){
                curr = curr->prev;
            }
        }
        n->next = curr->next;
        n->prev = curr;
        curr->next->prev = n;
        curr->next = n;
        size++;
    }
	int remove(int num) {
	    node* curr = head;
	    int ctr = 1;
	    if(size == 1){
	        head = 0;
	        tail = 0;
	        delete curr;
	        size--;
	        return ctr;
	    }
	    while(curr->elem != num){
	        ctr++;
	        if(ctr > size){
	            return -1;
	        }
	        curr = curr->next;
	    }
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
	    delete curr;
    	return ctr;
	}
    int removeAt(int pos){
        node* curr = head;
        int ret;
        if(pos == 1){
            int ret = head->elem;
            removeFirst();
            return ret;
        } else if(pos == size){
            int ret = tail->elem;
            removeLast();
            return ret;
        }
        int half = size/2;
        if(size % 2 != 0)half++;
        if(pos <= half){
            for(int i = 1;i < pos;i++){
                curr = curr->next;
            }
        } else {
            curr = tail;
            for(int i = size;i > pos;i--){
                curr = curr->prev;
            }
        }
        ret = curr->elem;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        size--;
        return ret;
    }

	int get(int pos) {
	    if(pos <= 0 || pos > size) return -1;
	    node* curr = head;
	    int ctr = 1;
	    int halfway = size / 2;
	    if(size % 2 != 0)halfway++;
	    if(pos <= halfway){
	        for(int i = 1;i < pos;i++){
	            ctr++;
	            curr = curr->next;
	        }
	        cout<<"From head, number of comparisons: "<<ctr<<endl;
	    } else {
	    curr = tail;
	        for(int i = size;i > pos;i--){
	            ctr++;
	            curr = curr->prev;
	        }
	        cout<<"From tail, number of comparisons: "<<ctr<<endl;
	    }
        return curr->elem;
	}

    int retain(int num){
        node* curr = head;
        node* lastCheck = 0;
        int ctr = size;
        while(curr){
            if(curr->elem >= num){
            ctr --;
                if(lastCheck == 0){
                    lastCheck = curr;
                    head = lastCheck;
                    lastCheck->prev = 0;
                } else if(curr->prev != lastCheck){
                    lastCheck->next = curr;
                    curr->prev = lastCheck;
                    lastCheck = curr;
                } else {
                    lastCheck = curr;
                }
            }
            curr = curr->next;
        }
        if(ctr == size){
            head = 0;
            tail = 0;
            size = 0;
            return ctr;
        }
        tail = lastCheck;
        lastCheck->next = 0;
        size -= ctr;
        return ctr;
    }
    int corner(int left, int right){
        node* l = head;
        node* r = tail;
        if(left+right == size){
            return 0;
        }
        for(int i = 1;i < left;i++){
            l = l->next;
        }
        for(int i = size;i > (size-right+1);i--){
            r = r->prev;
        }
        
        node* lnext = l->next;
        node* rprev = r->prev;
        l->next = r;
        r->prev = l;
        lnext->prev = 0;
        rprev->next = 0;
        int numRemovedElements = size - (left+right);
        if(left == 0 && right == 0){
            head = 0;
            tail = 0;
            size = 0;
            return numRemovedElements;
        }else if(left == 0)head = r;
        else if(right == 0)tail = l;
        size-=numRemovedElements;
        return numRemovedElements;
    }

    void print() {
    	node* curr;
    	if (size == 0) {
    		cout << "Empty" << endl;
		} else {
			cout << "From HEAD: ";
    		curr = head;
	    	while (true) {
	    		cout << curr->elem;
	    		if (curr != tail) {
	    			cout << " -> ";
				} else {
					cout << endl;
                    break;
				}
	    		curr = curr->next;
			}
			cout << "From TAIL: ";
    		curr = tail;
	    	while (true) {
	    		cout << curr->elem;
	    		if (curr != head) {
	    			cout << " <- ";
				} else {
					cout << endl;
                    break;
				}
	    		curr = curr->prev;
			}
		}
    }
};
