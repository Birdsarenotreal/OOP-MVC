#include "Controller.h"

Controller::Controller(QuestionRepo &repo) {
	this->Repo = repo;
}

Controller::Controller() = default;

void Controller::editTF(int id, Type type, std::string text, std::string subject, bool State,int newid) {
	QuestionTF* quest=new QuestionTF;
	quest->setId(id);
	quest->setText(text);
	quest->setSubj(subject);
	quest->setState(State);
	this->Repo.updateQuestion(newid, quest);
};
void Controller::editMatch(int id, Type type, std::string text, std::string subject, std::string op1, std::string op2, std::string op3, std::string op4, std::string op5, std::string op6, correctMatches matches,int newid) {
	QuestionMatching* quest = new QuestionMatching;
	quest->setId(id);
	quest->setText(text);
	quest->setSubj(subject);
	quest->setOption1(op1);
	quest->setOption2(op2);
	quest->setOption3(op3);
	quest->setOption4(op4);
	quest->setOption5(op5);
	quest->setOption6(op6);
	quest->setCorrectOptions(matches.op4, matches.op5, matches.op6);
	this->Repo.updateQuestion(newid, quest);
};

void Controller::editMultiple(int id, Type type, std::string text, std::string& subject, Multiple temp1, Multiple temp2, Multiple temp3,int newid) {
	
	QuestionMultiple* quest = new QuestionMultiple;

	quest->setId(id);
	quest->setText(text);
	quest->setSubj(subject);
	quest->setPickTextOp1(temp1.Optiontext);
	quest->setPickTextOp2(temp2.Optiontext);
	quest->setPickTextOp3(temp3.Optiontext);
	quest->setcorrectPickOp1(temp1.correctPick);
	quest->setcorrectPickOp2(temp2.correctPick);
	quest->setcorrectPickOp3(temp3.correctPick);

	this->Repo.updateQuestion(newid, quest);
}

void Controller::removeElem(int id) {
	Repo.removeQuestion(id);
};


void Controller::displayBySubj(std::string subj,int &poz) {
	if (subj =="Blank") {
		this->Repo.printAll();
	}
	else {
		this->Repo.printBySubj(subj,poz);
	}
}

void Controller::displayAll() {
	this->Repo.printAll();
}

int Controller::getSize() {
	return this->Repo.getSize();
}

void Controller::addTF(int& id, Type& type, std::string& text, std::string& subject, bool& State1) {

	QuestionTF* A = new QuestionTF;
	A->setId(id);
	A->setText(text);
	A->setSubj(subject);
	A->setState(State1);
	A->setType(type);
	Repo.addQuestion(A);

}

void Controller::addMatch(int& id, Type& type, std::string& text, std::string& subject, std::string& op1, std::string& op2, std::string& op3, std::string& op4, std::string& op5, std::string& op6, correctMatches& matches) {

	QuestionMatching* A = new QuestionMatching;
	A->setId(id);
	A->setText(text);
	A->setSubj(subject);
	A->setOption1(op1);
	A->setOption2(op2);
	A->setOption3(op3);
	A->setOption4(op4);
	A->setOption5(op5);
	A->setOption6(op6);
	A->setCorrectOptions(matches.op4, matches.op5, matches.op6);
	A->setType(type);
	Repo.addQuestion(A);

}

void Controller::addMult(int& id, Type& type, std::string& text, std::string& subject, Multiple& op1, Multiple& op2, Multiple& op3) {
	
	QuestionMultiple* A = new QuestionMultiple;
	A->setId(id);
	A->setText(text);
	A->setSubj(subject);
	A->setPickTextOp1(op1.Optiontext);
	A->setPickTextOp2(op2.Optiontext);
	A->setPickTextOp3(op3.Optiontext);
	A->setcorrectPickOp1(op1.correctPick);
	A->setcorrectPickOp2(op2.correctPick);
	A->setcorrectPickOp3(op3.correctPick);
	A->setType(type);
	Repo.addQuestion(A);
}

void Controller::clearMemory() {
	this->Repo.deleteMemo();
}

Question* Controller::getById(int id) {
	return this->Repo.getElement(id);
}

Question* Controller::getByPos(int pos) {
	return this->Repo.elemByPos(pos);
}

/*bool Controller::validation(Question* quest, bool userInput) {

};
bool Controller::validation(Question* quest, bool userInput1, bool userInput2, bool userInput3) {

};
bool Controller::validation(Question* quest, int op1, int op2, int op3) {

};*/

void Controller::addStudentQ(Question* quest) {
	this->Repo.addQuestion(quest);
};
