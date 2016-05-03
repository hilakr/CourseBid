#include "UiLibraryContext.h"
#include "UiLibraryState.h"
#include <string>
#include <iostream>
using namespace std;
#include <conio.h>
#include <cstdlib>
#include <exception>
void UiLibraryContext::setState(UiLibraryState* state1){
	state = state1;
}


void UiLibraryContext::run(){
	try{

		do
		{
			state->display();
		} while (state->handleInput(_getch()));

	}
	catch (exception e){
		cout << e.what() << endl;
	}

};

