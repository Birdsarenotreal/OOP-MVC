#pragma once
#include "QuestionMatching.h"
#include "QuestionMultiple.h"
#include "QuestionTF.h"
#include <vector>

class QuestionRepo {

private:
	std::vector <Question*> Repo;
	//era mai usor sa fac un vector de fiecare tip, era mai accesibil
public:
	void addQuestion(Question *a);
	void removeQuestion(int id);
	void updateQuestion(int id,Question* newq);

	Question* getElement(int id);
	int getSize();
	void printAll();
	void printBySubj(std::string subj,int &poz4subj);
	void deleteMemo();
	Question* elemByPos(int i);

};