#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\DataStorage\IStorage.h"
#include "..\DataStorage\IdObj.h"
#include <CppUnitTestException.h>
#include "..\DataStorage\IdObjectFactory.h"
#include "..\DataStorage\FileStroage.h"
#include "..\DataStorage\Student.h"
#include "assert.h"
#include <typeinfo>       // operator typeid


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IdObjectFactoryTest
{
	TEST_CLASS(IdObjectFactoryTest)
	{
	public:

		TEST_METHOD(getStorageTest)
		{
			struct StorageMock : public IStorage {
				virtual string get(string id) { return ""; }
				virtual void set(string id, string value) {}
				virtual int getLastId(){ return 0; }
			}storageMock;

			IdObjectFactory factory(storageMock);
			Assert::IsTrue(&storageMock == factory.getStorage());

		}

		TEST_METHOD(allocateTest)
		{
			struct StorageMock : public IStorage {
				virtual string get(string id) { return ""; }
				virtual void set(string id, string value) {}
				virtual int getLastId(){ return 0; }
			}storageMock;
			struct IdObjMock : public IdObj {
				IdObjMock(int id, IdObjectFactory &factory) : IdObj(id, factory), fact(factory) {
					Assert::AreEqual(id, 1);
				}
				IdObjectFactory &fact;
			};

			IdObjectFactory factory(storageMock);
			Assert::IsTrue(&factory == &factory.allocate<IdObjMock>().fact);
		};
		TEST_METHOD(constructTest)
		{
			struct StorageMock : public IStorage {
				virtual string get(string id) { return ""; }
				virtual void set(string id, string value) {}
				virtual int getLastId(){ return 0; }
			}storageMock;

			struct IdObjMock : public IdObj {
				IdObjMock(int id, IdObjectFactory &factory) : IdObj(id, factory), fact(factory) {
					Assert::AreEqual(id, 50);
				}
				IdObjectFactory &fact;
			};

			IdObjectFactory factory(storageMock);
			Assert::IsTrue(&factory == &factory.construct<IdObjMock>(50).fact);
		}

	};
}