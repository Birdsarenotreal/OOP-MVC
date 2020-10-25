#pragma once
#include <iostream>
#include <string>
enum Type {
	TRUEF, MULTC, MATCC
};


class Question {

protected://protected ca sa avem acces la fieldurile private cu clasele derivate
	int id;
	Type type;
	std::string text;
	std::string subject;

public:

	//functii simple, getteri si setteri
	Question();

	Question(int id, Type type, std::string text, std::string subject);

	int getId();

	void setId(int id);

	void setType(Type type);

	Type getType();

	std::string getText();

	void setText(std::string string);

	std::string getSubj();

	void setSubj(std::string sub);

	virtual void toString();
	
	/*virtual friend std::istream &operator>>(std::istream input, Question &quest);*/
	

};




