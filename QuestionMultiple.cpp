#include "QuestionMultiple.h"


void QuestionMultiple::setPickTextOp1(std::string s) {

	bool thrown = false;
	while (!thrown) {
		try {
			this->op1.Optiontext = s;
			if (s.size() <= 0) {
				throw 5;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "Choose a non empty text for the option, try again:\n";
			std::getline(std::cin, s);
		}

	}	
};
void QuestionMultiple::setStudentPickOp1(bool pick) {

	bool thrown = false;
	while (!thrown) {
		try {
			this->op1.studentPick = pick;
			if (pick < 0 || pick>1) {
				throw 5;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "Choose a valid value for the question.(0 for false, 1 for true), try again:\n";
			std::cin >> pick;
		}
	}

	
};
void QuestionMultiple::setcorrectPickOp1(bool pick) {
	bool thrown = false;
	while (!thrown) {
		try {
			this->op1.correctPick = pick;
			if (pick < 0 || pick>1) {
				throw 5;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "Choose a valid value for the question.(0 for false, 1 for true), try again:\n";
			std::cin >> pick;
		}
	}
};

void QuestionMultiple::setPickTextOp2(std::string s) {
	bool thrown = false;
	while (!thrown) {
		try {
			this->op2.Optiontext = s;
			if (s.size() <= 0) {
				throw 5;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "Choose a non empty text for the option, try again:\n";
			std::getline(std::cin, s);
		}

	}
};
void QuestionMultiple::setStudentPickOp2(bool pick) {
	bool thrown = false;
	while (!thrown) {
		try {
			this->op2.studentPick = pick;
			if (pick < 0 || pick>1) {
				throw 5;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "Choose a valid value for the question.(0 for false, 1 for true), try again:\n";
			std::cin >> pick;
		}
	}
};
void QuestionMultiple::setcorrectPickOp2(bool pick) {
	bool thrown = false;
	while (!thrown) {
		try {
			this->op2.correctPick = pick;
			if (pick < 0 || pick>1) {
				throw 5;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "Choose a valid value for the question.(0 for false, 1 for true), try again:\n";
			std::cin >> pick;
		}
	}
};

void QuestionMultiple::setPickTextOp3(std::string s) {
	bool thrown = false;
	while (!thrown) {
		try {
			this->op3.Optiontext = s;
			if (s.size() <= 0) {
				throw 5;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "Choose a non empty text for the option, try again:\n";
			std::getline(std::cin, s);
		}

	}
};
void QuestionMultiple::setStudentPickOp3(bool pick) {
	bool thrown = false;
	while (!thrown) {
		try {
			this->op3.studentPick = pick;
			if (pick < 0 || pick>1) {
				throw 5;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "Choose a valid value for the question.(0 for false, 1 for true), try again:\n";
			std::cin >> pick;
		}
	}
};
void QuestionMultiple::setcorrectPickOp3(bool pick) { 
	bool thrown = false;
	while (!thrown) {
		try {
			this->op3.correctPick = pick;
			if (pick < 0 || pick>1) {
				throw 5;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "Choose a valid value for the question.(0 for false, 1 for true), try again:\n";
			std::cin >> pick;
		}
	}
};


std::string QuestionMultiple::getTextOp1() {
	return this->op1.Optiontext;
};
bool QuestionMultiple::getStudentPickOp1() {
	return this->op1.studentPick;
};
bool QuestionMultiple::getCorrectPickOp1() {
	return this->op1.correctPick;
};

std::string QuestionMultiple::getTextOp2() {
	return this->op2.Optiontext;
};
bool QuestionMultiple::getStudentPickOp2() {
	return this->op3.studentPick;
};
bool QuestionMultiple::getCorrectPickOp2() {
	return this->op2.correctPick;
};

std::string QuestionMultiple::getTextOp3() {
	return this->op3.Optiontext;
};
bool QuestionMultiple::getStudentPickOp3() {
	return this->op3.studentPick;
};
bool QuestionMultiple::getCorrectPickOp3() {
	return this->op3.correctPick;
};

void QuestionMultiple::toString() {

	std::string printed;
	printed += std::to_string(id) + ". ";
	printed += this->getText() + ":\n";
	printed += "          ";
	printed += "*" + this->getTextOp1() + "\n";
	printed += "          ";
	printed += "*" + this->getTextOp2() + "\n";
	printed += "          ";
	printed += "*" + this->getTextOp3() + "\n";
	std::cout << printed;

}

QuestionMultiple::QuestionMultiple() = default;