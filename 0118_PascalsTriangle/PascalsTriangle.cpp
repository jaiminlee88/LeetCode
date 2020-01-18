/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

*/

#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> outVector;
	if (numRows>0)
	{
		vector<int> tempVector;
		tempVector.push_back(1);
		outVector.push_back(tempVector);
		tempVector.clear();
		for (int currRow = 1; currRow < numRows;currRow++)
		{
			for (int j = 0; j <= currRow;j++)
			{
				if (j - 1 < 0)
					tempVector.push_back(outVector[currRow - 1][j]);
				else if (j >= outVector[currRow - 1].size())
					tempVector.push_back(outVector[currRow - 1][j - 1]);
				else
					tempVector.push_back(outVector[currRow - 1][j - 1] + outVector[currRow - 1][j]);
			}
			outVector.push_back(tempVector);
			tempVector.clear();
		}
	}
	return outVector;
}

void test(int* Array, int len,int num)
{
	vector<vector<int>> inVector;
	vector<vector<int>> outVector;
	int posNum =1;
	for (int i = 0; i < len; i++)
	{
		if (posNum>num) break;
		vector<int> tempVec;
		for (int j = 0; j < posNum;j++)
			tempVec.push_back(Array[i++]);
		inVector.push_back(tempVec);
		posNum ++;
		i--;
	}
	outVector = generate(num);
	if (inVector.size()!=outVector.size())
	{
		printf("Failed.");
	}
	for (int i = 0; i < inVector.size();i++)
	{
		bool failed = false;
		for (vector<int>::iterator ite1 = inVector[i].begin(), ite2 = outVector[i].begin();
			ite1 != inVector[i].end(), ite2 != outVector[i].end();
			ite1++, ite2++
			)
		{
			if (*ite1 != *ite2){
				failed = true;
				break;
			}
		}
		if (failed)
			break;
	}
	printf("Passed.\n");
}

void test1()
{
	printf("test1 begin:");
	int num = 3;
	int Array[] = { 1, 1, 1, 1, 2, 1 };
	test(Array, sizeof(Array) / sizeof(int),num);
}

void test2()
{
	printf("test2 begin:");
	int num = 5;
	int Array[] = { 1, 1, 1, 1,2,1,1,3,3,1,1,4,6,4,1 };
	test(Array, sizeof(Array) / sizeof(int), num);
}

void test3()
{
	printf("test3 begin:");
	int num = 1;
	int Array[] = {1 };
	test(Array, sizeof(Array) / sizeof(int), num);
}

void test4()
{
	printf("test4 begin:");
	int num = 2;
	int Array[] = { 1, 1, 1};
	test(Array, sizeof(Array) / sizeof(int), num);
}
void main()
{
	test1();
	test2();
	test3();
	test4();
}