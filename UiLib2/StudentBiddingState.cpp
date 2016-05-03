#include "StudentBiddingState.h"
#include "EntryDisplayState.h"
#include "UiLibraryState.h"
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include <exception>

StudentBiddingState::StudentBiddingState(UiLibraryContext* context, seasonConfig season1, Student student1) : season(season1), student(student1), cur_sel(0)
{
	this->context = context;
	flag = 0;
	Lexer lexer;
	string formula;
	int completetd = student.completed.count();
	formula = season.formula.get();
	/*check if the formula is empty*/
	if (formula == ""){
		throw exception("No points -> Come back Later");
		exit(0);
	}
	lexer.setExpr(formula);
	lexer.tokenize();
	points = lexer.getExpr(completetd);
	cur_points = points;


};

void StudentBiddingState::display(){
	system("CLS");
	/*check is a local var that holds 1 if the course shold add to bid course of student otherwise 0*/
	int check = 0;
	/*flag is responsibe that this block will happen only once*/
	if (flag == 0)
	{

		for (int i = 0; i < season.courseList.count(); i++){//course i
			Course course = season.courseList.get(i);
			course.points.set(0);
			/*cout << "Course idobj : " << season.courseList.get(i).get_id() << endl;*/
			/*check if course i has no pre courses , we add this course to the bid courses of student*/
			if (course.pre.count() == 0){
				check = 1;
			}
			else
			{
				for (int j = 0; j < course.pre.count(); j++){// move on the pre courses of course i 
					check = 0;
					for (int x = 0; x < student.completed.count(); x++)/*check if course j is appear in the list of completed courses of student*/
					{
						/*local var for tests*/
						/*int t = course.pre.get(j).get_id();
						int z = student.completed.get(x).get_id();*/
						if (course.pre.get(j).id.get() == student.completed.get(x).id.get())
						{
							check = 1;
						}

					}
					/*if 1 course from the pre courses doesn't appear in the comleted course it stop checking the rest*/
					if (check == 0)
						break;
				}

			}
			/*add course to the bid courses*/
			if (check)
			{
				/*cout << "season = " <<season.courseList.get(i).name.get() << endl;*/
				Course course = season.courseList.get(i);
				/*Reset points*/
				student.BidCourses.add(course);
				/*cout << "student = " << student.BidCourses.get(i).name.get() << endl;*/
			}

		}
	}
	cout << "POINTS: ";
	cout << points << endl;
	cout << "CURRENT POINTS: ";
	cout << cur_points << endl;
	for (int i = 0; i < student.BidCourses.count(); i++)
	{
		if (i == cur_sel)
			cout << "*" << i << "->" << student.BidCourses.get(i).name.get() << endl;
		else
			cout << i << "->" << student.BidCourses.get(i).name.get() << endl;

	}
	cout << "Options:" << endl;
	cout << "1- Enter points to course" << endl;
	cout << "q- Exit" << endl;
	flag = 1;

};


bool StudentBiddingState::handleInput(int c){
	switch (c)
	{
	case '1':
	{
		try{
			bidPoints(cur_sel);
		}
		catch (exception e)
		{
			system("CLS");
			cout << e.what() << endl;
		}
		break;
	}
	case 72:
		cur_sel--;
		if (cur_sel < 0)
			cur_sel = 0;
		break;
	case 80:
		cur_sel++;
		if (cur_sel > student.BidCourses.count())
			cur_sel = 0;
		break;
	case 'q':
	case 'Q':
		return false;
	default:
		break;
	};
	return true;

};


void StudentBiddingState::bidPoints(int cur_sel) {
	cout << "Enter points: " << endl;
	int input;
	cin >> input;
	int curr = 0;
	/*check if we have enough points*/
	if (input <= cur_points)
	{
		int y = cur_sel;

		student.BidCourses.get(cur_sel).points.set(input);


		for (int i = 0; i < student.BidCourses.count(); i++)
		{
			int x = student.BidCourses.get(i).points.get();

			curr = curr + student.BidCourses.get(i).points.get();
		}

		cout << "Current POINTS : " << points - curr << endl;

		cur_points = points - curr;
	}

	else{
		throw exception("***NOT ENOUGH POINTS TO BID -> REBID***");
	}

}