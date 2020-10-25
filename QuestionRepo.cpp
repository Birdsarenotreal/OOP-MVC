#include "QuestionRepo.h"
void QuestionRepo::addQuestion(Question *a) {

	bool existing = false;

	for (int i = 0; i < this->Repo.size(); i++) {
		if (a->getId() == Repo[i]->getId()) {
			existing = true;
		}
	}

	try {
		if (existing) {
			throw 5;
		}
		this->Repo.push_back(a);
	}
	catch (int x) {
		std::cout << "Id of the question is already in the database.\n";
	}
};

void QuestionRepo::removeQuestion(int id) {

	bool existing = false;

	for (int i = 0; i < this->Repo.size(); i++) {
		if (this->Repo.at(i)->getId() == id) {
			this->Repo.erase(this->Repo.begin() + i);
			existing = true;
			break;
		}
	}
	if (!existing) {
		std::cout << "There is no such question in the database";
	}
};

Question* QuestionRepo::getElement(int id) {

	for (int i = 0; i <= this->Repo.size(); i++) {
		if (this->Repo[i]->getId() == id) {
			return this->Repo[i];
		}
	}
}
int QuestionRepo::getSize() {
	return this->Repo.size();
}

void QuestionRepo::updateQuestion(int id, Question* newq) {
	
	for (int i = 0; i<this->Repo.size(); i++) {
		if (this->Repo[i]->getId() == id) {
			this->Repo[i] = newq;
			break;
		}
	}

}

void QuestionRepo::printAll() {
	for (int i = 0; i < this->getSize(); i++) {
		this->Repo[i]->toString();
		std::cout << "\n";
	}
}

void QuestionRepo::printBySubj(std::string subj,int &pos4subj) {
	pos4subj = -1;
	for (int i = 0; i < this->getSize(); i++) {
		if (this->Repo[i]->getSubj() == subj) {
			if (pos4subj == -1) {
				pos4subj = i;
			}
			this->Repo[i]->toString();
			std::cout << "\n";
		}
	}
}

void QuestionRepo::deleteMemo() {
	for (int i = 0; i < this->Repo.size(); i++) {
		delete this->Repo[i];
	}
}

Question* QuestionRepo::elemByPos(int i) {
	return this->Repo[i];
}



