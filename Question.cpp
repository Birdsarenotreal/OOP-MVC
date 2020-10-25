#include <iostream>
#include <string>
#include "Question.h"


Question::Question() = default;

Question::Question(int id, Type type, std::string text, std::string subject) {
		this->id = id;
		this->type = type;
		this->text = text;
		this->subject = subject;
	}
int Question::getId() {
	return this->id;
}
void Question::setId(int id) {

	bool thrown = false;
	while (!thrown) {
		try {
			this->id = id;
			if (id <= 0) {
				throw 1;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "Id cannot be negative, Error code: " << x << ", Try again:\n";
			std::cin >> id;
		}
	}
	
}

Type Question:: getType() {
	return this->type;
}

std::string Question :: getText() {
	return this->text;
}
void Question :: setText(std::string string) {
	
	bool thrown = false;
	while (!thrown) {
		try {
			this->text = string;
			if (string.size() == 0) {
				throw 3;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "You must choose a non empty text for the question, Error code: " << x << ", Try again:\n";
			std::getline(std::cin, string);
		}
	}
	
}

std::string Question :: getSubj() {
	return this->subject;
}
void Question :: setSubj(std::string sub) {
	
	bool thrown = false;
	
	while (!thrown) {
		try {
			this->subject = sub;
			if (sub.size() == 0) {
				throw 3;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "You must choose a non empty text for the subject, Error code: " << x << ", Try again:\n";
			std::cin.ignore();
			std::getline(std::cin, sub);
		}
	}
	
}

void Question::setType(Type type) {

	bool thrown = false;

	while (!thrown) {
		try {
			this->type = type;
			if (type < 0 or type>2) {
				throw 2;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "You must choose one of the correct question types, Error code: " << x << ", Try again:\n";
			int temptype;
			std::cin >> temptype;
			type = (Type)temptype;
		}
	}
	
}

void Question::toString() {

};

/*bool Question::validation() {};*/



