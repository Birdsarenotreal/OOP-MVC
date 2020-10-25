#pragma once
#include "Question.h"

struct Multiple {

	std::string Optiontext;
	bool studentPick;
	bool correctPick;

};

class QuestionMultiple :public Question
{

private:
	Multiple op1;
	Multiple op2;
	Multiple op3;
public:
	QuestionMultiple(int id, Type type, std::string text, std::string subject, Multiple op1, Multiple op2, Multiple op3);
	QuestionMultiple();
	void setPickTextOp1(std::string s);
	void setStudentPickOp1(bool pick);
	void setcorrectPickOp1(bool pick);

	void setPickTextOp2(std::string s);
	void setStudentPickOp2(bool pick);
	void setcorrectPickOp2(bool pick);
	
	void setPickTextOp3(std::string s);
	void setStudentPickOp3(bool pick);
	void setcorrectPickOp3(bool pick);


	std::string getTextOp1();
	bool getStudentPickOp1();
	bool getCorrectPickOp1();

	std::string getTextOp2();
	bool getStudentPickOp2();
	bool getCorrectPickOp2();

	std::string getTextOp3();
	bool getStudentPickOp3();
	bool getCorrectPickOp3();

	void toString();

};

