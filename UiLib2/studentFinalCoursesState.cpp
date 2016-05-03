#include "studentFinalCoursesState.h"
#include <iostream>
#include <string>
using namespace std;
studentFinalCoursesState::studentFinalCoursesState(UiLibraryContext* context, Student student1) : student(student1){
	this->context = context;
}

void studentFinalCoursesState::display(){
	for (int i = 0; i < student.FinalCourses.count(); i++)
	{
			string name = student.FinalCourses.get(i).name.get();
			string id = to_string(student.FinalCourses.get(i).id.get());
			cout << i<<"-> "<<id << "," << name << endl;

	}
	cout << "click q for Exit " << endl;
}



bool studentFinalCoursesState::handleInput(int c){
	switch (c)
	{
	case 'q':
	case 'Q':
		return false;
	default:
		break;
	};
	return true;
};
