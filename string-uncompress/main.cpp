#include <iostream>
#include <stack>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	stack<string> chars;
	stack<int>nums;
	string curr = "";
	string res = "";
	string input;
	cout<<"Enter string: ";
	cin>>input;
	for(int i = 0;i < input.length();i++){
		if(isdigit(input[i])){
			chars.push(curr);
			curr = "";
			nums.push(input[i] - '0');
		} else if(isalpha(input[i])){
			curr += input[i];
		} else if(input[i] == ']'){
			int repeat = nums.top();
			nums.pop();
			string temp = "";
			for(int i = 0;i < repeat;i++){
				temp += curr;
			}
			curr = chars.top() + temp;
			chars.pop();
		}
	}
	cout<<"Result: "<<curr;
	
	return 0;
}
