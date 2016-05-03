#include "Shibetz_Students.h"

finalStudents::finalStudents(UiLibraryContext* context, seasonConfig season1): season(season1){

	this->context = context;

}

void finalStudents::display(){
	system("CLS");
	int index, count = 0;
	for (int i = 0; i < season.studentList.count(); i++)
	{
		cout << i << "-> "<< season.studentList.get(i).name.get() << endl;
	}
	cout << "Choose student by index" << endl;
	cin >> index;
	for (int i = 0; i < season.studentList.get(index).FinalCourses.count(); i++)
	{
		cout << season.studentList.get(index).FinalCourses.get(i).name.get() << endl;
		count++;
	}
	cout << "Total num of courses ->" << count << endl;
	cout << "q-exit" << endl;
}


bool finalStudents::handleInput(int c){
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

