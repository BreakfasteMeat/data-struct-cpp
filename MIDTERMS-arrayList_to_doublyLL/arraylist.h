#include <iostream>
#include <stdlib.h>
using namespace std;
class ArrayList : public list{
	int size;
	int capacity;
	int *arr;
public:
	ArrayList(){
		size = 0;
		capacity = 5;
		arr = (int*)calloc(capacity, sizeof(int));
		
	}
	void addFirst(int num){
		if(size == capacity){
			capacity += capacity*0.5;
			arr = (int*)realloc(arr,capacity * sizeof(int));
		}
		for(int i = size;i > 0;i--){
			arr[i] = arr[i-1];
		}
		arr[0] = num;
		size++;
		
	}
	void addLast(int num){
		if(size == capacity){
			capacity += capacity*0.5;
			arr = (int*)realloc(arr,capacity * sizeof(int));
		}
		arr[size++] = num;
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
		cout<<endl;
		cout<<"Size: "<<size<<" Capacity: "<<capacity<<endl;
		
		for(int i = 0;i < size;i++){
			cout<<"["<<arr[i]<<"]";
		}
		cout<<endl;
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
