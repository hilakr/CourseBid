#ifndef StudentListEditingState_H
#define StudentListEditingState_H
#include "ListDisplayState.h"
#include "seasonConfig.h"
#include <string.h>
#include <iostream>
using namespace std;

class StudentListEditingState : public ListDisplayState{
public:
	seasonConfig season;
	StudentListEditingState(UiLibraryContext* context, seasonConfig season1);
	string get(int index);

	void  select(int index);

	void myDelete(int index);

	void add(int index);

	int countList();
	
	void returnState();

	void Shibetz_final_courses();

};

#endif