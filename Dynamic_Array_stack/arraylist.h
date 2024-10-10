#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
class ArrayList {
	int size;
	int capacity;
	int* arr;
	
	void dynamic_increase(){
		capacity += ceil(capacity*0.5);
		arr = (int*)realloc(arr, capacity * sizeof(int));
	}
	void dynamic_reduce(){
		capacity -= floor(capacity*0.2);
		arr = (int*)realloc(arr, capacity * sizeof(int));
	}
public:
	ArrayList(){
		size = 0;
		capacity = 5;
		arr = (int*)calloc(capacity, sizeof(int)); 
	}
	void push(int num){
		
		if(size == capacity) dynamic_increase();
		arr[size++] = num;
	}
	void pop(){
		if(size <= capacity *0.5) dynamic_reduce();
		arr[--size] = 0;
	}
	bool isEmpty(){
		return (size == 0);
	}
	int top(){
		return arr[size-1];
	}
	int getSize(){
		return size;	
	}
	void print(){
		for(int i = capacity;i >= 0;i--){
			if(i < size)cout<<"["<<arr[i]<<"]"<<endl;
			else cout<<"[?]"<<endl;
		}
	}
};
