#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Experssion\Lexer.h"
#include "..\Experssion\Parser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(LexerTest)
{
public:
	TEST_METHOD(isInputOkTest)
	{
		Lexer lex;
		std::string se1 = "1",
			se2 = "(2)",
			se3 = "(-3)",
			se4 = "@",
			se5 = "5*5+5/5-5",
			se6 = "((6))";
		Assert::AreEqual(lex.isInputOk(se1), true);
		Assert::AreEqual(lex.isInputOk(se2), true);
		Assert::AreEqual(lex.isInputOk(se3), true);
		Assert::AreEqual(lex.isInputOk(se4), true);
		Assert::AreEqual(lex.isInputOk(se5), true);
		Assert::AreNotEqual(lex.isInputOk(se6), true);
	}

	TEST_METHOD(getExprTest)
	{
		class ExprMock : public Expr {
			virtual int evaluate() {
				return 0;
			}
		};

		class ParserMock : public Parser {
			virtual Expr* getExpr(int at) {
				return new ExprMock();
			}
		};

		Lexer lex;
		lex.setParser(ParserMock());
		Assert::AreEqual(lex.getExpr, 0);
	}

	TEST_METHOD(tokenizeTest)
	{
		Lexer lex;
		lex.setExpr("1");
		lex.tokenize();
		vector<string> expected;
		expected.push_back("1");
		Assert::AreEqual(lex.getStokenvec(), expected);
	}
};