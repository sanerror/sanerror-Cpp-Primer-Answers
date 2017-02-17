#include <iostream>
#include "ex13_34_36_37.h"

using namespace std;

int main(){
	Message firstMail("Hello!");
	Message signInMail("Hi!");
	Folder mailBox;

	firstMail.debug_print();
	firstMail.save(mailBox);
	mailBox.debug_print();

	signInMail.debug_print();
	signInMail.save(mailBox);
	mailBox.debug_print();

	firstMail = firstMail; // important
	firstMail.debug_print();
	mailBox.debug_print();
	return 0;
}