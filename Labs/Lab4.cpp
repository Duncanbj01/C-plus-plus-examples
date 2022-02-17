#include <string>
#include <iostream>

using namespace std;
// Write StringStuff class and all its methods here. You can also use a separate .h file if you want, but make sure to include it above.

class StringStuff {
	static void tokenize(string& str, string& delim) {
		for (int i = 0; i < str.length(); i++)
			
				
	

	/*static bool isValidEmail(string& str) {

	}

	static bool isValidPassword(string& str) {

	}*/
};

int main() {
	string str = "This is an English sentence, which serves no purpose.";
	cout << "Sentence: " << str << endl;
	cout << "The words are: " << endl << endl;
	StringStuff::tokenize(str);
	cout << endl;

	/*string emails[] = { "nobody@compsci222.uww.edu",
			"nob@ody@compsci222.uww.edu", "nobody@compsci222.uww.eduroam", "nobody@compsci999.uww.edu" };
	for (int i = 0; i < 4; i++) {
		bool b = StringStuff::isValidEmail(emails[i]);
		cout << emails[i] << " is ";
		if (b)
			cout << "a valid email." << endl;
		else
			cout << "not a valid email." << endl;
	}

	cout << endl;

	string passwords[] = { "Pas$word123",
				"Password@123", "Password@123#456", "password@123456", "PASSWORD@123456", "PASSword123456" };
	for (int i = 0; i < 6; i++) {
		bool b = StringStuff::isValidPassword(passwords[i]);
		cout << passwords[i] << " is ";
		if (b)
			cout << "a valid password." << endl;
		else
			cout << "not a valid password." << endl;
	}*/
}
