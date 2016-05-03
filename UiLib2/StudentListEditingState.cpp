#include "StudentListEditingState.h"
#include "StudentEditingState.h"
#include "CourseListEditingState.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include <conio.h>
#include <cstdlib>
#include "loginSec.h"


StudentListEditingState::StudentListEditingState(UiLibraryContext* context, seasonConfig season1) : season(season1) {
	this->context = context;
}

string StudentListEditingState::get(int index)
{

	return season.studentList.get(index).id.get() + "," + season.studentList.get(index).name.get();
};

void StudentListEditingState::select(int index) {
	string input;
	StudentEditingState* state = new StudentEditingState(context, season, season.studentList.get(index));
	context->setState(state);
};

void StudentListEditingState::myDelete(int index) {
	int input;
	cout << "Are you sure you want to delete ?" << endl;
	cout << "if yes enter '1' otherwise enter '0'" << endl;
	cin >> input;
	if (input)
		season.studentList.remove(index);
	else
		cout << "Not deleted" << endl;
};

void StudentListEditingState::add(int index) {
	string input, val;
	cout << "Please insert the following deatils" << endl;
	Student newStudnet = season.studentList.allocateAndAdd();
	season.studentList.add(newStudnet);
	StudentEditingState* state = new StudentEditingState(context, season, newStudnet);
	context->setState(state);

};

int StudentListEditingState::countList() {
	return season.studentList.count();

}

void StudentListEditingState::returnState(){
	loginSec* state = new loginSec(context, season);
	context->setState(state);

}
	