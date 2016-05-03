#ifndef loginSec_H
#define loginSec_H
#include "UiLibraryState.h"
#include "seasonConfig.h"
#include <iostream>
using namespace std;

class loginSec : public UiLibraryState{

public:
	seasonConfig season;

	loginSec(UiLibraryContext* context, seasonConfig season1);

	void display();

	bool handleInput(int c);


};


#endif