#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Experssion\Lexer.h"
#include "..\Experssion\Parser.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(LexerTest)
{
public:
	TEST_METHOD(isInputOkTest)
	{
		Lexer lex;
		std::string se1 = "1",
			se2 = "@",
			se3 = "(-3)";
		Assert::AreEqual(lex.isInputOk(se1), true);
		Assert::AreEqual(lex.isInputOk(se2), true);
		Assert::AreEqual(lex.isInputOk(se3), true);
	}
	/*
	TEST_METHOD(getExprTest)
	{
		class ExprMock : public Expr {
			int evaluate() {
				return 0;
			}
		};
	

		class ParserMock : public Parser {
			Expr* getExpr(int at) {
				return new ExprMock();
			}
		};
		
		Lexer lex;
		lex.setParser(ParserMock());
		int x = lex.getExpr(0);
		Assert::IsTrue(lex.getExpr(0) == 0);
	}
	*/
	/*
	TEST_METHOD(tokenizeTest)
	{
		Lexer lex;
		lex.setExpr("1");
		lex.tokenize();
		vector<string> expected;
		expected.push_back("1");
		Assert::AreEqual(lex.getStokenvec(), expected);
	}*/
};