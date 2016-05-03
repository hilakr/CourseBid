#ifndef ListDisplayState_H
#define ListDisplayState_H
#include "UiLibraryState.h"
#include <string>
#include <iostream>
using namespace std;

class ListDisplayState : public UiLibraryState {

public:
	int cur_sel;
	ListDisplayState();
	bool handleInput(int c);
	void display();
	virtual string get(int index) = 0;
	virtual void select(int index) = 0;
	virtual void myDelete(int index) = 0;
	virtual void add(int index) = 0;
	virtual int countList() = 0;
	virtual void returnState() =0 ;


};


#endif



