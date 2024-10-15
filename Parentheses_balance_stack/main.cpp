#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool isBalanced(string);
int main(int argc, char** argv) {
	string parenth;
	while(true){
		system("cls");
		cout<<endl;
		cout<<"Input: ";
		cin>>parenth;
		if(isBalanced(parenth)){
			cout<<"Is balanced";
		} else {
			cout<<"Is not balanced";
		}
		
		cout<<endl<<"Press enter to continue.";
		getch();
	}
	return 0;
}

bool isBalanced(string parenth){
	int size = 0;
	char* stack = (char*)calloc(20,sizeof(char));//STACK
	
	for(int i = 0;i < parenth.length();i++){
		char curr = parenth[i];
		
		if(curr == '(' || curr == '[' ||curr == '{' ){
			stack[size++] = curr;
		} else {
			if((curr == '}' && stack[size-1] != '{') ||
			   (curr == ')' && stack[size-1] != '(') ||
			   (curr == ']' && stack[size-1] != '[')) return false;
			   else size--;
		}		
	}
	if(size){
		//cout<<"Stack not empty "<<size<<endl;
		return false;
	}
	return true;
}
