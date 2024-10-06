#include <iostream>
using namespace std;

struct Person {
	string firstName;
	string lastName;
	int age;
	int requests[4];

	void print_name() {
		cout << firstName << " " << lastName <<endl;
	}
};
