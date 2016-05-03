#include <exception>
using namespace std;

#pragma once

class InvalidExpressionException : public exception {
public:
	virtual const char* what() const {
		return "Invalid Expression";
	}
};
