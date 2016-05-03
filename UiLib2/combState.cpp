#include "completetdState.h"
#include "Course.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <string.h>
#include <iostream>
using namespace std;

combState::combState(UiLibraryContext* context1, seasonConfig season1, int idobj1) : season(season1), idobj(idobj1), cur_sel(0){
	context = context1;
}

bool combState::handleInput(int c){
	switch (c)
	{
	case '1':
		add(cur_sel, idobj);
		break;
	case '2':
		remove(cur_sel, idobj);
		break;
	case 72:
		cur_sel--;
		if (cur_sel < 0)
			cur_sel = 0;
		break;
	case 80:
		cur_sel++;
		if (cur_sel > 5)
			cur_sel = 0;
		break;
	case 'q':
	case 'Q':
		return false;
	default:
		break;

	};
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

}

void combState::add(int index, int idobj){

	Course temp = season.courseList.get(index);
	Student student = season.getFactory().construct<Student>(idobj);
	student.completed.add(temp);
	cout << endl;


}
void combState::remove(int index, int idobj){
	int idcourse = season.courseList.get(index).id.get();
	Student student = season.getFactory().construct<Student>(idobj);
	cout << "BEFORE - num of courses " << student.completed.count() << endl;
	for (int i = 0; i < student.completed.count(); i++)
	{
		if (student.completed.get(i).id.get() == idcourse)
			student.completed.remove(i);

	}
	cout << "Test" << endl;
	cout << "print the courses" << endl;
	for (int i = 0; i < student.completed.count(); i++)
	{
		cout << student.completed.get(i).id.get() << ",";

	}
	cout << endl;

}