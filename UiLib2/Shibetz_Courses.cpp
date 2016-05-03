#include "Shibetz_Courses.h"
#include <exception>
finalCourses::finalCourses(UiLibraryContext* context, seasonConfig season1) : season(season1){

	this->context = context;

}

void finalCourses::display(){
	system("CLS");
	int index, count = 0;
	for (int i = 0; i < season.courseList.count(); i++)
	{
		cout << i << "-> " << season.courseList.get(i).name.get() << endl;
	}
	cout << "Choose course by index" << endl;
	cin >> index;
	if (index > season.courseList.count())
		throw exception("Not correct index");
	int idCourse = season.courseList.get(index).get_id();
	for (int i = 0; i < season.studentList.count(); i++)
	{
		for (int j = 0; j < season.studentList.get(i).FinalCourses.count(); j++){
			int y = season.studentList.get(i).FinalCourses.count();
			int x = season.studentList.get(i).FinalCourses.get(j).get_id();
			string name = season.studentList.get(i).name.get();
			if (idCourse == season.studentList.get(i).FinalCourses.get(j).get_id())
			{
				cout << season.studentList.get(i).name.get() << endl;
				count++;
			}
		}
	}
	cout << "Total num of students ->" << count << endl;
}


bool finalCourses::handleInput(int c){
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

