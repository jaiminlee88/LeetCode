/*
Given a non-negative index k where k ¡Ü 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.
Could you optimize your algorithm to use only O(k) extra space?
*/

#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) 
{
	vector<int> pVector[2];
	unsigned short int currVector = 0;
	pVector[currVector].push_back(1);
	for (int i = 1; i <= rowIndex;i++)
	{
		currVector = 1-currVector;
		pVector[currVector].clear();
		for (int j = 0; j <= i; j++)
		{
			if (j - 1 < 0)
				pVector[currVector].push_back(pVector[1 - currVector][j]);
			else if (j >= pVector[1 - currVector].size())
				pVector[currVector].push_back(pVector[1 - currVector][j - 1]);
			else
				pVector[currVector].push_back(pVector[1 - currVector][j - 1] + pVector[1 - currVector][j]);
		}
	}
	return  pVector[currVector];
}

void test(int* Array, int len, int num)
{
	vector<int> outVector;
	int posNum = 1;
	outVector = getRow(num);
	if (len != outVector.size())
	{
		printf("Failed.\n");
		return;
	}
	for (int i = 0; i < len; i++)
	{
		if (Array[i]!=outVector[i])
		{
			printf("Failed.\n");
			return;
		}
	}
	printf("Passed.\n");
}

void test1()
{
	printf("test1 begin:");
	int num = 2;
	int Array[] = {1, 2, 1 };
	test(Array, sizeof(Array) / sizeof(int), num);
}

void test2()
{
	printf("test2 begin:");
	int num = 4;
	int Array[] = { 1, 4, 6, 4, 1 };
	test(Array, sizeof(Array) / sizeof(int), num);
}

void test3()
{
	printf("test3 begin:");
	int num = 0;
	int Array[] = { 1 };
	test(Array, sizeof(Array) / sizeof(int), num);
}

void test4()
{
	printf("test4 begin:");
	int num = 1;
	int Array[] = { 1, 1 };
	test(Array, sizeof(Array) / sizeof(int), num);
}

void test5()
{
	printf("test5 begin:");
	int num = 5;
	int Array[] = { 1, 5,10,10,5,1 };
	test(Array, sizeof(Array) / sizeof(int), num);
}

void test6()
{
	printf("test6 begin:");
	int num = 6;
	int Array[] = { 1,6,15,20,15,6,1 };
	test(Array, sizeof(Array) / sizeof(int), num);
}

void main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
}