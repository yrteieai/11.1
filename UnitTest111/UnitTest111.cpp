#include "pch.h"
#include "CppUnitTest.h"
#include "../11.1/11.1.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest111
{
	TEST_CLASS(UnitTest111)
	{
	public:

		TEST_METHOD(TestFindThirdDotInLine)
		{
			string line = "Hello...world!";
			int dotPosition = -1;

			bool result = FindThirdDotInLine(line, dotPosition);

			Assert::IsTrue(result, L"Третя крапка має бути знайдена.");
			Assert::AreEqual(7, dotPosition, L"Позиція третьої крапки має дорівнювати 7.");
		}
	};
}
