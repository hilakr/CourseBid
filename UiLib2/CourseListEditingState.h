#ifndef CourseListEditingState_H
#define CourseListEditingState_H
#include "ListDisplayState.h"
#include "seasonConfig.h"
#include <string.h>
#include <iostream>
using namespace std;

class CourseListEditingState : public ListDisplayState {

public:

	seasonConfig season;

	CourseListEditingState(UiLibraryContext* context, seasonConfig season1);

	string get(int index);;

	void  select(int index);;

	void myDelete(int index);

	void add(int index);

	int countList();

	void returnState();

	void Shibetz_final_studetnts();
};


#endif