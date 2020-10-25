#pragma once
#include "Question.h"
//un struct unde retin valorile corecte a intrebarii 
struct correctMatches {
	int op1=1, op2=2, op3=3, op4=0, op5=0, op6=0;
};

class QuestionMatching :public Question
{
private:
	std::string option1;
	std::string option2;
	std::string option3;

	std::string option4;
	std::string option5;
	std::string option6;

	correctMatches matches;
public:

	QuestionMatching(int id,Type type,std::string text,std::string subject,std::string op1, std::string op2, std::string op3, std::string op4, std::string op5, std::string op6, int cop1,int cop2,int cop3 );
	QuestionMatching();
	void setOption1(std::string op);
	std::string getOption1();

	void setOption2(std::string);
	std::string getOption2();

	void setOption3(std::string op);
	std::string getOption3();

	void setOption4(std::string op);
	std::string getOption4();

	void setOption5(std::string op);
	std::string getOption5();

	void setOption6(std::string op);
	std::string getOption6();
	
	void setCorrectOptions(int op1,int op2,int op3);
	int getCorrectOption1();
	int getCorrectOption2();
	int getCorrectOption3();

	void toString();
	/*friend std::istream &operator>>(std::istream input, QuestionMatching &quest);*/
};

