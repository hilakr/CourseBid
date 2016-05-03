#include "ListDisplayState.h"
#include "seasonConfig.h"
#include <iostream>
#include <string>
using namespace std;
#include <conio.h>
#include <cstdlib>
#include "loginSec.h"

ListDisplayState::ListDisplayState() : cur_sel(0){
}

bool ListDisplayState::handleInput(int c){
	try{

		switch (c)
		{
		case '1':
			this->select(cur_sel);
			break;
		case '2':
			this->myDelete(cur_sel);
			cout << "Deleted successfully" << endl;
			break;
		case '3':
			this->add(cur_sel);
			cout << "Added successfully" << endl;
			break;
		case 'r':
			this->returnState();
			break;
		case 72:
			cur_sel--;
			if (cur_sel < 0)
				cur_sel = 0;
			break;
		case 80:
			cur_sel++;
			if (cur_sel > this->countList())
				cur_sel = 0;
			break;
		case 'q':
		case 'Q':
			return false;
		default:
			break;

		};

	}
	catch (exception &e){
		cout << "*** " << e.what() << " ***" << endl;
	}
	return true;
};

void ListDisplayState::display()  {

	cout << "******" << endl;
	cout << "Opitions: " << endl;
	cout << "1 -> Choose element to edit or to show details" << endl;
	cout << "2 -> Choose element to delete" << endl;
	cout << "3 -> Add element " << endl;
	cout << "r -> Return " << endl;
	cout << "Print list" << endl;
	for (int i = 0; i < countList(); i++)
	{
		if (i == cur_sel)
			cout << "*" << i << "->" << this->get(i) << endl;
		else
			cout << i << "->" << this->get(i) << endl;
	}
	cout << "Total -> " << this->countList() << endl;


}


