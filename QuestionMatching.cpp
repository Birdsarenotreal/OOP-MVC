#include "QuestionMatching.h"
void QuestionMatching::setOption1(std::string op) {
	bool thrown = false;
	while (!thrown) {
		try {
			this->option1 = op;
			if (op.size() <= 0) {
				throw 5;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "Choose a non empty text for the option, try again:\n";
			std::getline(std::cin,op);
		}
	}
	
}
std::string QuestionMatching::getOption1() {
	return this->option1;
}

void QuestionMatching::setOption2(std::string op) {
	bool thrown = false;
	while (!thrown) {
		try {
			this->option2 = op;
			if (op.size() <= 0) {
				throw 5;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "Choose a non empty text for the option, try again:\n";
			std::getline(std::cin, op);
		}
	}
}
std::string QuestionMatching::getOption2() {
	return this->option2;
}

void  QuestionMatching:: setOption3(std::string op) {
	bool thrown = false;
	while (!thrown) {
		try {
			this->option3 = op;
			if (op.size() <= 0) {
				throw 5;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "Choose a non empty text for the option, try again:\n";
			std::getline(std::cin, op);
		}
	}
}
std::string  QuestionMatching::getOption3() {
	return this->option3;
}

void QuestionMatching::setOption4(std::string op) {
	bool thrown = false;
	while (!thrown) {
		try {
			this->option4 = op;
			if (op.size() <= 0) {
				throw 5;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "Choose a non empty text for the option, try again:\n";
			std::getline(std::cin, op);
		}
	}
}
std::string QuestionMatching::getOption4() {
	return this->option4;
}

QuestionMatching::QuestionMatching() = default;

void QuestionMatching:: setOption5(std::string op) {
	bool thrown = false;
	while (!thrown) {
		try {
			this->option5 = op;
			if (op.size() <= 0) {
				throw 5;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "Choose a non empty text for the option, try again:\n";
			std::getline(std::cin, op);
		}
	}
}
std::string QuestionMatching::getOption5() {
	return this->option5;
}

void QuestionMatching::setOption6(std::string op) {
	bool thrown = false;
	while (!thrown) {
		try {
			this->option6 = op;
			if (op.size() <= 0) {
				throw 5;
			}
			thrown = true;
		}
		catch (int x) {
			std::cout << "Choose a non empty text for the option, try again:\n";
			std::getline(std::cin, op);
		}
	}
}
std::string QuestionMatching::getOption6() {
	return this->option6;
}

void QuestionMatching::setCorrectOptions(int op1,int op2,int op3) {
	this->matches.op4 = op1;
	this->matches.op5 = op2;
	this->matches.op6 = op3;

}
int QuestionMatching::getCorrectOption1() {
	return this->matches.op4;
};
int QuestionMatching::getCorrectOption2() {
	return this->matches.op5;
};
int QuestionMatching::getCorrectOption3() {
	return this->matches.op6;
};

void QuestionMatching::toString() {

	std::string printed;
	printed += std::to_string(id) + ". ";
	printed += this->getText()+":\n";
	printed += "        1)" + this->getOption1() + "           ";
	printed += "        4)" + this->getOption4() + "\n";
	printed += "        2)" + this->getOption2() + "           ";
	printed += "        5)" + this->getOption5() + "\n";
	printed += "        3)" + this->getOption3() + "           ";
	printed += "        6)" + this->getOption6() + "\n";

	std::cout << printed;
}

/*std::istream &operator>>(std::istream input, QuestionMatching &quest) {
	input >> quest.id;
	int typetemp;
	input >> typetemp; quest.type = (Type)typetemp;
	input >> quest.text;
	input >> quest.subject;
	input >> quest.option1;
	input >> quest.option2;
	input >> quest.option3;
	input >> quest.option4;;
	input >> quest.option5;;
	input >> quest.option6;;
	input >> quest.matches.op4;
	input >> quest.matches.op5;
	input >> quest.matches.op6;

	return input;
}*/
QuestionMatching::QuestionMatching(int id, Type type, std::string text, std::string subject, std::string op1, std::string op2, std::string op3, std::string op4, std::string op5, std::string op6, int cop1, int cop2, int cop3) {
	this->id = id;
	this->type = type;
	this->text = text;
	this->subject = subject;
	this->option1 = op1;
	this->option2 = op2;
	this->option3 = op3;
	this->option4 = op4;
	this->option5 = op5;
	this->option6 = op6;
	this->matches.op4 = cop1;
	this->matches.op5 = cop2;
	this->matches.op6 = cop3;

}


