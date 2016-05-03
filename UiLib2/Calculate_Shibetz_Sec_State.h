#ifndef Calculate_Shibetz_Sec_State_H
#define Calculate_Shibetz_Sec_State_H
#include "UiLibraryState.h"
#include "seasonConfig.h"
#include <iostream>
using namespace std;


class Shibetz : public UiLibraryState{

public:
	seasonConfig season;

	Shibetz(UiLibraryContext* context, seasonConfig season);

	void display();

	bool handleInput(int c);

};


#endif 