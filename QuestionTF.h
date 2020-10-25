#pragma once
#include "Question.h"
class QuestionTF : public Question
{
private:
	bool State = false;
public:
	QuestionTF(int id,Type type,std::string text,std::string subject,bool State1);
	QuestionTF();
	void setState(bool newstate);

	bool getState();

	void toString();
	/*friend std::istream &operator>>(std::istream input, QuestionTF &quest);*/
};

