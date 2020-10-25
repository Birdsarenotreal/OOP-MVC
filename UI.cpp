#include "Controller.h"
#include <fstream>

//Aici initializez fieldurile campurilor de la intrebari pentru a construii intrebari noi
void constructTF(int& id, Type& type, std::string& text, std::string& subject, bool& State1) {
	
	
	std::cout << "Choose question id \n";
	std::cin >> id;
	std::cin.ignore();


	std::cout << "Choose question text\n";
	std::getline(std::cin, text);
	
	std::cout << "Choose question subject\n";
	std::cin >> subject;
	
	std::cout << "Choose question validity(1 for true 0 for false) \n";
	std::cin >> State1;
	

}
void constructMatch(int& id, Type& type, std::string& text, std::string& subject,std::string &op1, std::string &op2, std::string &op3, std::string &op4, std::string &op5, std::string &op6,correctMatches &matches) {



	std::cout << "Choose question id \n";
	std::cin >> id;
	
	
	std::cin.ignore();

	std::cout << "Choose question text \n";
	std::getline(std::cin, text);
	

	std::cout << "Choose question subject\n";
	std::getline(std::cin, subject);
	
	

	std::cout << "Choose option 1 : \n";
	std::getline(std::cin, op1);
	


	std::cout << "Choose option 2: \n";
	std::getline(std::cin, op2);
	


	std::cout << "Choose option 3 : \n";
	std::getline(std::cin, op3);



	std::cout << "Choose option 4 : \n";
	std::getline(std::cin, op4);



	std::cout << "Choose option 5 : \n";
	std::getline(std::cin, op5);
	


	std::cout << "Choose option 6 : \n";
	std::getline(std::cin, op6);




	std::cout << "Choose correct match for option 1(from 4 to 6): \n";
	std::cin >> matches.op4;

	std::cout << "Choose correct match for option 2(from 4 to 6) : \n";
	std::cin >> matches.op5;

	std::cout << "Choose correct match for option 3(from 4 to 6) : \n";
	std::cin >> matches.op6;

}

void constructMultiple(int& id, Type& type, std::string& text, std::string& subject,Multiple &temp1,Multiple &temp2,Multiple &temp3) {


	
	std::cout << "Choose question id \n";
	std::cin >> id;
	std::cin.ignore();


	std::cout << "Choose question text \n";
	std::getline(std::cin, text);
	

	std::cout << "Choose question subject\n";
	std::cin >> subject;
	std::cin.ignore();


	std::cout << "Choose the text for the first option :\n";
	std::getline(std::cin, temp1.Optiontext);
	


	std::cout << "Choose the text for the second option :\n";
	std::getline(std::cin, temp2.Optiontext);
	


	std::cout << "Choose the text for the third option :\n";
	std::getline(std::cin, temp3.Optiontext);
	


	std::cout << "Choose the validity of option 1(1 for true, 0 for false):\n";
	std::cin >> temp1.correctPick;
	


	std::cout << "Choose the validity of option 2(1 for true, 0 for false):\n";
	std::cin >> temp2.correctPick;
	


	std::cout << "Choose the validity of option 3(1 for true, 0 for false):\n";
	std::cin >> temp3.correctPick;
	
}

//popularea database-ului pentru testare
void populateRepo(Controller &ctrl) {

		std::fstream f, g, h;
		f.open("Questions.txt");
		g.open("QuestionsMulti.txt");
		h.open("QuestionsMatching.txt");

		//citesc fieldurile pentru fiecare tip de intrebare 
		//am 3 fisiere diferite pentru fiecare tip de intrebare

		int id;
		Type type1 = TRUEF;
		std::string text;
		std::string subject;
		std::string line;


		bool state;
		while (!f.eof()) {
			f >> id;
			f.ignore();
			std::getline(f, text);
			std::getline(f, subject);
			f >> state;
			if (!f.eof()) {
				ctrl.addTF(id, type1, text, subject, state);
			}
		}
		
		Type type3=MULTC;
		Multiple m1, m2, m3;
		while (!g.eof()) {
			g >> id;
			g.ignore();
			std::getline(g, text);
			std::getline(g, subject);
			std::getline(g, m1.Optiontext);
			std::getline(g, m2.Optiontext);
			std::getline(g, m3.Optiontext);
			g >> m1.correctPick;
			g >> m2.correctPick;
			g >> m3.correctPick;
			if (!g.eof()) {
				ctrl.addMult(id, type3, text, subject, m1, m2, m3);
			}
		}

		Type type2=MATCC;
		std::string op1; std::string op2; std::string op3; std::string op4; std::string op5; std::string op6;
		correctMatches cMatches;
		while (!h.eof()) {
			h >> id;
			h.ignore();
			std::getline(h, text);
			std::getline(h, subject);
			std::getline(h,op1); std::getline(h, op2); std::getline(h, op3); std::getline(h, op4); std::getline(h, op5); std::getline(h, op6);
			h >> cMatches.op4;
			h >> cMatches.op5;
			h >> cMatches.op6;
			if (!h.eof()) {
				ctrl.addMatch(id, type2, text, subject, op1, op2, op3, op4, op5, op6, cMatches);
			}
		}
		
		
		f.close();
		g.close();
		h.close();
		
}


void validateTF(bool &studentPick) {
	

	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Error: Enter only 0 or 1" << std::endl;
		std::cout << "Enter in a new value." << std::endl;
		std::cin >> studentPick;
	}
	
}

void validateMULTC(bool &userInput) {
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Error: Enter only 0 or 1" << std::endl;
		std::cout << "Enter in a new value." << std::endl;
		std::cin >> userInput;
	}
}

void validateMATCC(int &userInput) {
	while (std::cin.fail() || (userInput <4 || userInput > 6))
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Error: Enter a numerical value between 4 and 6." << std::endl;
		std::cout << "Enter in a new value." << std::endl;
		std::cin >> userInput;
	}
}

//initializarea Database-ului si a controllerelor 
QuestionRepo repo;
QuestionRepo review;
Controller ctrl(repo);
Controller ctrlStudent(review);


void TeacherMode(Controller &ctrl) {

	int input = -1;
	std::cout << "To add a question to the exam press 1.\n";
	std::cout << "To remove a question from the exam press 2.\n";
	std::cout << "To update a question press 3.\n";
	std::cout << "To see all of the questions press 4.\n";
	std::cout << "To see all of the options again press 5.\n";
	std::cout << "To exit the application press 0.\n";

	while (input != 0) {
		std::cin >> input;

		if (input == 1) {
			int type1=-1;
			std::cout << "Choose a type, 0 for T/F, 1 for Multiple Choice, 2 for Matching Content.\n";
			std::cin >> type1;
			if (type1 == 0) {
				int id;
				Type type=TRUEF;
				std::string text;
				std::string subject;
				bool state;
				constructTF(id, type, text, subject, state);
				ctrl.addTF(id, type, text, subject, state);
			}
			if (type1 == 1) {
				int id;
				Type type=MULTC;
				std::string text;
				std::string subject;
				bool state;
				Multiple m1, m2, m3;
				constructMultiple(id, type, text, subject, m1, m2, m3);
				ctrl.addMult(id, type, text, subject, m1, m2, m3);
			}
			if (type1 == 2) {
				int id;
				Type type=MATCC;
				std::string text;
				std::string subject;
				std::string op1; std::string op2; std::string op3; std::string op4; std::string op5; std::string op6;
				correctMatches cMatches;
				constructMatch(id, type, text, subject, op1, op2, op3, op4, op5, op6, cMatches);
				ctrl.addMatch(id, type, text, subject, op1, op2, op3, op4, op5, op6, cMatches);
			}
		}
		if (input == 2) {
			std::cout << "Choose the id of the question you wish to remove.\n";
			int id;
			std::cin >> id;
			ctrl.removeElem(id);
		}
		if (input == 3) {
			int id1;
			std::cout << "Choose+ the id of the question you wish to update.\n";
			std::cin >> id1;
			std::cout << "Choose the type of question(0 for T/F,1 for Matching,2 for Multiple):\n";
			int type;
			std::cin >> type;
			if (type == 0) {
				int id;
				Type type;
				std::string text;
				std::string subject;
				bool state;
				constructTF(id, type, text, subject, state);
				ctrl.editTF(id, type, text, subject, state, id1);
			}
			if (type == 1) {
				int id;
				Type type;
				std::string text;
				std::string subject;
				bool state;
				Multiple m1, m2, m3;
				constructMultiple(id, type, text, subject, m1, m2, m3);
				ctrl.editMultiple(id, type, text, subject, m1, m2, m3,id1);
			}
			if (type == 2) {
				int id;
				Type type;
				std::string text;
				std::string subject;
				std::string op1; std::string op2; std::string op3; std::string op4; std::string op5; std::string op6;
				correctMatches cMatches;
				constructMatch(id, type, text, subject, op1, op2, op3, op4, op5, op6, cMatches);
				ctrl.editMatch(id, type, text, subject, op1, op2, op3, op4, op5, op6, cMatches,id1);
			}
			
		}
		if (input == 4) {
			ctrl.displayAll();
		}
		if (input == 5) {
			std::cout << "To add a question to the exam press 1.\n";
			std::cout << "To remove a question from the exam press 2.\n";
			std::cout << "To update a question press 3.\n";
			std::cout << "To see all of the questions press 4.\n";
			std::cout << "To see all of the options again press 5.\n";
			std::cout << "To exit the application press 0.\n";
		}
	}


}
void StudentMode(Controller& ctrl1, Controller& ctrl2) {

	int iterator = 0;
	int score = 1;
	int temp = ctrl1.getSize();
	bool running = true;
	std::cout << "If you wish to see your review list, press 1 after finishing with a question.\n";
	std::cout << "If you wish to remove a question from your review list you can do so after finishing with your current question by pressing 2.\n";
	std::cout << "If you wish to see all the questions with a subject of your choice press 3.\n";
	std::cout << "If you wish to see the options again press 4.\n";
	std::cout << "\n";
	while (running) {
		int poz4sub=0;
		if (iterator < temp) {

			if (ctrl1.getByPos(iterator)->getType() == TRUEF) {
				bool userInput;
				QuestionTF* A = dynamic_cast<QuestionTF*>(ctrl1.getByPos(iterator));
				A->toString();
				std::cout << " Choose 1 for true, 0 for false.\n";
				std::cin >> userInput;

				validateTF(userInput);
					
				if (A->getState() == userInput) {
					score++;
					iterator++;
					std::cout << "Correct answer! Do you want to add the question to the review list? Yes/No.\n";
					std::string rev;
					std::cin >> rev;
					if (rev == "Yes") {
						ctrlStudent.addStudentQ(A);
					}
				}
				else {
					std::cout << "Wrong answer! Add the question to the review list? Yes/No.\n";
					std::string rev;
					std::cin >> rev;
					if (rev == "Yes") {
						ctrlStudent.addStudentQ(A);
					}
					iterator++;
				}
					
				
				
			}
			
			if (ctrl1.getByPos(iterator)->getType() == MATCC) {
				int op1, op2, op3;
				QuestionMatching* A = (QuestionMatching*)ctrl1.getByPos(iterator);
				A->toString();
				std::cout << "Choose the correct match for the first option on the left(a number from 4 to 6).\n";
				std::cin >> op1;
				validateMATCC(op1);
				std::cout << "Choose the correct match for the second option on the left(a number from 4 to 6).\n";
				std::cin >> op2;
				validateMATCC(op2);
				std::cout << "Choose the correct match for the third option on the left(a number from 4 to 6).\n";
				std::cin >> op3;
				validateMATCC(op3);
				if (A->getCorrectOption1() == op1 and A->getCorrectOption2() == op2 and A->getCorrectOption3() == op3) {
					score++;
					iterator++;
					std::cout << "Correct answer! Do you want to add the question to the review list? Yes/No .\n";
					std::string rev;
					std::cin >> rev;
					if (rev == "Yes") {
						ctrlStudent.addStudentQ(A);
					}
				}
				else {
					std::cout << "Wrong answer! Add the question to the review list? Yes/No .\n";
					std::string rev;
					std::cin >> rev;
					if (rev == "Yes") {
						ctrlStudent.addStudentQ(A);
					}
					iterator++;
				}
			}
			
			
			if ((ctrl1.getByPos(iterator)->getType() == MULTC)) {
				bool userInput1, userInput2, userInput3;
				QuestionMultiple* A = (QuestionMultiple*)ctrl1.getByPos(iterator);
				A->toString();
				std::cout << "If the first option is correct choose 1, 0 for false.\n";
				std::cin >> userInput1;
				validateMULTC(userInput1);
				std::cout << "If the second option is correct choose 1, 0 for false.\n";
				std::cin >> userInput2;
				validateMULTC(userInput2);
				std::cout << "If the third option is correct choose 1, 0 for false.\n";
				std::cin >> userInput3;
				validateMULTC(userInput3);
				if (iterator != temp) {
					if ((A->getCorrectPickOp1() == userInput1) and (A->getCorrectPickOp2() == userInput2) and (A->getCorrectPickOp3() == userInput3)) {
						score++;
						iterator++;
						std::cout << "Correct answer! Do you want to add the question to the review list? Yes/No .\n";
						std::string rev;
						std::cin >> rev;
						if (rev == "Yes") {
							ctrlStudent.addStudentQ(A);
						}
					}
					else {
						std::cout << "Wrong answer! Add the question to the review list? Yes/No .\n";
						std::string rev;
						std::cin >> rev;
						if (rev == "Yes") {
							ctrlStudent.addStudentQ(A);
						}
						iterator++;
					}
				}
			}
		

			

			bool extra;
			std::cout << "Do you wish to do any extra actions? 1/0 ;\n";
			std::cin >> extra;
			validateTF(extra);

			if (extra) {
				std::cout << "1. If you wish to see your review list, press 1 after finishing with a question.\n";
				std::cout << "2. If you wish to remove a question from your review list you can do so after finishin with your current question by pressing 2.\n";
				std::cout << "3. If you wish to see all the questions with a subject of your choice press 3.\n";
				std::cout << "4. If you wish to see the options again press 4.\n";
				std::cout << "\n";
				std::cout << "Choose your option:\n";
				int input;
				std::cin >> input;
				if (input == 1) {
					if (ctrlStudent.getSize() == 0) {
						std::cout << "You have no questions in your review list!\n";
					}
					ctrlStudent.displayAll();
				}
				if (input == 2) {
					int tempid;
					std::cout << "Choose the id of the question you with to remove from the review list.\n";
					std::cin >> tempid;
					ctrlStudent.removeElem(tempid);
				}
				if (input == 3) {
					std::string subject;
					std::cout << "Choose the subject of the questions you wish to see.\n";
					std::cin.ignore();
					std::cout << "Subject:";
					std::cin >> subject;

					ctrl.displayBySubj(subject, poz4sub);
					iterator = poz4sub;
				}
				if (input == 4) {
					std::cout << "If you wish to see your review list, press 1 after finishing with a question.\n";
					std::cout << "If you wish to remove a question from your review list you can do so after finishin with your current question by pressing 2.\n";
					std::cout << "If you wish to see all the questions with a subject of your choice press 3.\n";
					std::cout << "If you wish to see the options again press 4.\n";
					std::cout << "\n";
				}
			}
				
		}
		if (iterator == temp) {
			std::cout << "End of exam reached! Do you wish to restart from question 1? Yes/No.\n";
			std::string answer;
			std::cin >> answer;
			if (answer == "Yes") {
				iterator = 0;
			}
			else {
				std::cout << "Your score is : " << score << "\n";
				running = false;
			}
		}
	}
}



int main() {
	
	
	populateRepo(ctrl);
	bool runMode = 1;
	std::cout << "Press 1 for teacher mode or 0 for student mode.\n";
	std::cin >> runMode;
	if (runMode) {
		TeacherMode(ctrl);
	}
	else {
		StudentMode(ctrl, ctrlStudent);
	}
	
	ctrl.clearMemory();
	ctrlStudent.clearMemory();
	return 0;
}
