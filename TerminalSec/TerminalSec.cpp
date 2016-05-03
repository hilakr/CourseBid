// CourseBid.cpp : Defines the entry point for the console application.
#include <vector>
#include <string.h>
#include "FileStroage.h"
#include "IdObjectFactory.h"
#include "Terminal.h"
#include "seasonConfig.h"
#include "loginSec.h"
#include "SystemLogin.h"
#include <iostream>
using namespace std;

int main()

{	cout << "hello" << endl;
	
	FileStorage storage("db.txt");
	IdObjectFactory factory(storage);
	seasonConfig season(0, factory);
	Terminal terminal = season.getFactory().allocate<Terminal>();
	UiLibraryContext* context = new UiLibraryContext();
	loginSec* state = new loginSec(context, season);
	context->setState(state);
	context->run();
	return 1;
};