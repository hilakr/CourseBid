#ifndef StudentBiddingState_H
#define StudentBiddingState_H
#include "UiLibraryState.h"
#include "seasonConfig.h"
#include "Student.h"
#include  "Lexer.h"
#include <string>
#include <iostream>
using namespace std;

class StudentBiddingState : public UiLibraryState{
public:
	seasonConfig season;
	Student student;
	int cur_sel;
	int points;
	int cur_points;
	Lexer lexer;
	int flag; 
	StudentBiddingState(UiLibraryContext* context, seasonConfig season1, Student student1);

	void display();


	bool handleInput(int c);


	void bidPoints(int cur_sel);

};
#endif