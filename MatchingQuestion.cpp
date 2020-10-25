#include "Question.cpp"
class QuestionMA : public Question {

private:
	bool State;
public:

	bool getState() {
		return State;
	}
	void setState(bool newState) {
		this->State = newState;
	}
};

int defnotmar() {

	Type a = TRUEF;

	QuestionMA b;
	b.setState(false);
	b.setText("fuck");

	if (b.getState() == false) {
		std::cout << "ass we can";
	}

	return 0;
}