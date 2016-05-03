#include <iostream>
#include "FileStroage.h"
#include "IdObjectFactory.h"
#include "myCalLib.h"
#include "SystemState.h"
#include "UiLibraryContext.h"
#include <fstream>
using namespace std;

void main(){
	cout << "hiel";
	string input,token1,token2,temp_str;
	FileStorage storage("db_input.txt");
	IdObjectFactory factory(storage);

	UiLibraryContext* context = new UiLibraryContext();
	SystemState* state = new SystemState(storage, factory);
	context->setState(state);
	context->run();
	

	
	
}