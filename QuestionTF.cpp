#include "QuestionTF.h"

void QuestionTF:: setState(bool newstate) {
		
		bool thrown = false;

		while (!thrown) {
			try {
				if (newstate >1 || newstate <0) {
					throw 2;
				}
				this->State = newstate;
				thrown = true;
			}
			catch (int x) {
				std::cout << "You must choose one of the correct inputs(0 for false,1 for true, Error code: " << x << ", Try again:\n";
				std::cin >> newstate;
			}
		}
}

bool QuestionTF::getState() {
	return this->State;
}

QuestionTF::QuestionTF(int id, Type type, std::string text, std::string subject, bool State1) {
	this->State = State1;
	this->setId(id);
	this->setType(type);
	this->setText(text);
	this->setSubj(subject);
}
QuestionTF::QuestionTF() = default;

void QuestionTF::toString() {
	std::string printed;
	printed += std::to_string(id) + ". ";
	printed += getText() + "           T/F";
	std::cout << printed;
}

/*std::istream &operator>>(std::istream input, QuestionTF &quest) {
	input >> quest.id;
	int type1;
	input >> type1; quest.type=((Type)type1);
	input >> quest.text;
	input >> quest.text;
	input >> quest.State;


	return input;
}*/