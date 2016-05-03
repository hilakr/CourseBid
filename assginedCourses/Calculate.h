/*#ifndef Calculate_H
#define Calculate_H
#include <lemon/glpk.h>
#include <lemon/lp.h>
#include "FileStroage.h"
#include "IdObjectFactory.h"
#include <iostream>
#include "seasonConfig.h"
using namespace lemon;
using namespace std;
class calculate{

public:
	FileStorage storage;
	IdObjectFactory factory;
	calculate(FileStorage storage, IdObjectFactory factory);
	void assignedCoursestoStudents();

};

#endif*/