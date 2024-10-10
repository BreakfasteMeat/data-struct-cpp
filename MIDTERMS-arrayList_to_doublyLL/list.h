#include <iostream>
using namespace std;

class list {
public:
	virtual void addFirst(int num) = 0;
	virtual void addLast(int num) = 0;
	virtual void addAt(int pos,int p) = 0;
	virtual int removeFirst() = 0;
	virtual int removeLast() = 0;
	virtual int removeAt(int pos) = 0;
	virtual int corner(int left, int right) = 0;
	virtual int retain(int num) = 0;
	virtual int swap(int index_a, int index_b) = 0;
	virtual int removeByValue(int num) = 0;
	virtual void advance() = 0;
	virtual void delay() = 0;
	virtual void print() = 0;
	virtual int reverseSublist(int start, int end) = 0;
	virtual int findMiddle() = 0;
	virtual bool isPalindrome() = 0;
	virtual void partition(int pivot) = 0;
};
