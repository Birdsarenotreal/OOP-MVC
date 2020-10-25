#pragma once
#include "QuestionRepo.h"
class Controller
{
private:
	QuestionRepo Repo;
public:
	Controller(QuestionRepo &Repo); //constructor cu parametrii si unul default pt testare
	Controller();
	//editarea se face creeand un obiect nou cu valoare fieldurilor si inlocuind obiectul vechi
	void editTF(int id, Type type, std::string text, std::string subject, bool State,int newid);
	void editMatch(int id, Type type, std::string text, std::string subject, std::string op1, std::string op2, std::string op3, std::string op4, std::string op5, std::string op6,correctMatches matches,int newid);
	void editMultiple(int id, Type type, std::string text, std::string& subject, Multiple temp1, Multiple temp2, Multiple temp3,int newid);
	void removeElem(int id);
	
	int getSize();
	void displayAll();
	void displayBySubj(std::string subj,int &poz);//afisarea intrebarilor cu un subiect dat,retinerea pozitiei in <<poz>> a ultimei intrebari gasite  cu subiectul ales

	void addTF(int &id, Type &type, std::string &text, std::string &subject, bool &State1);
	void addMult(int &id, Type &type, std::string &text, std::string &subject, Multiple &op1, Multiple &op2, Multiple &op3);
	void addMatch(int& id, Type& type, std::string& text, std::string& subject, std::string& op1, std::string& op2, std::string& op3, std::string& op4, std::string& op5, std::string& op6, correctMatches& matches);
	void clearMemory(); //dealocarea memoriei la sfarsitul rularii
	Question* getById(int id);
	Question* getByPos(int pos);

	
	void addStudentQ(Question* quest);//adaugarea intrebarilor in lista de review
};

