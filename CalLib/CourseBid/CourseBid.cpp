/*// CourseBid.cpp : Defines the entry point for the console application.
#include <vector>
#include <string.h>
#include "RefListField.h"
#include "IStorage.h"
#include "FileStroage.h"
#include"IdObjectFactory.h"
#include "IdObj.h"
#include"NonRefField.h"
#include "Student.h"
#include <iostream>
#include "FileStroage.h"
#include "expTest.h"
#include "loginSec.h"
#include "Login.h"
#include "Terminal.h"
#include "seasonConfig.h"
#include "EditFormulaDisplayState.h"
#include <vector>
using namespace std;
#include <conio.h>
#include <cstdlib>

int main()
{
	cout << "hello" << endl;
	FileStorage storage("db.txt");
	IdObjectFactory factory(storage);
	seasonConfig season(0, factory);
	UiLibraryContext* context = new UiLibraryContext();
	loginSec* state = new loginSec(context, season);
	context->setState(state);
	context->run();
	
	return 1;
	
};*/