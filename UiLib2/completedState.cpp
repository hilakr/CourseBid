#include "completetdState.h"
#include "Course.h"
#include "Student.h"
#include "StudentEditingState.h"
#include <string>
#include <iostream>
using namespace std;
combState::combState(UiLibraryContext* context1, seasonConfig season1, int idobj1) : season(season1), idobj(idobj1), cur_sel(0){
	context = context1;
}

bool combState::handleInput(int c){
	try{

		switch (c)
		{
		case '1':
			add(cur_sel, idobj);
			break;
		case '2':
			remove(cur_sel, idobj);
			break;
		case 'r':
			returnStudentEnrty();
			break;
		case 72:
			cur_sel--;
			if (cur_sel < 0)
				cur_sel = 0;
			break;
		case 80:
			cur_sel++;
			if (cur_sel >  season.courseList.count())
				cur_sel = 0;
			break;
		case 'q':
		case 'Q':
			return false;
		default:
			break;

		};
	}
	catch (exception &e){
		cout << e.what() << endl;
	}
	return true;
};

void combState::display(){

	for (int i = 0; i < season.courseList.count(); i++)
	{
		if (i == cur_sel)
			cout << "*" << i << "-> " << season.courseList.get(i).id.get() << endl;

		else
			cout << i << "-> " << season.courseList.get(i).id.get() << endl;

	}
	cout << "Opitions: " << endl;
	cout << "1 -> add" << endl;
	cout << "2 -> remove" << endl;
	cout << "r -> return" << endl;
	cout << "q -> exit" << endl;
}

void combState::add(int index, int idobj){
	if (season.courseList.count() == 0)
		throw exception("No courses to add");
	Course temp = season.courseList.get(index);
	Student student = season.getFactory().construct<Student>(idobj);
	for (int i = 0; i < season.studentList.get(i).completed.count(); i++)
		if (temp.id.get() == season.studentList.get(i).completed.get(i).id.get())
			cout << "Already in the list " << endl;
		else
			student.completed.add(temp);
	cout << "Added successfully" << endl;

}
void combState::remove(int index, int idobj){
	int idcourse = season.courseList.get(index).id.get();
	Student student = season.getFactory().construct<Student>(idobj);
	/*cout << "BEFORE - num of courses " << student.completed.count() << endl;*/
	for (int i = 0; i < student.completed.count(); i++)
	{
		if (student.completed.get(i).id.get() == idcourse)
			student.completed.remove(i);

	}
	/*	cout << "Test" << endl;
	cout << "print the courses" << endl;*/
	for (int i = 0; i < student.completed.count(); i++)
	{
		cout << student.completed.get(i).id.get() << ",";

	}
	cout << "Deleted successfully" << endl;

}

void combState::returnStudentEnrty(){
	StudentEditingState* state = new StudentEditingState(context, season, season.getFactory().construct<Student>(idobj));
	context->setState(state);
}