#ifndef preState_H
#define preState_H
#include "UiLibraryState.h"
#include "seasonConfig.h"
#include "Course.h"
#include "Student.h"
class preState : public UiLibraryState{
public:
	seasonConfig season;
	int idobj;
	int cur_sel;
	preState(UiLibraryContext* context1, seasonConfig season1, int idobj1);

	bool handleInput(int c);

	void display();

	void add(int index, int idobj);

	void remove(int index, int idobj);
	void returnStateCourseEntry();

};

#endif