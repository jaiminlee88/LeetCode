/*

Now you want to find out who the celebrity is or verify that
there is not one.The only thing you are allowed to do is to
ask questions like : "Hi, A. Do you know B?" to get information
of whether A knows B.You need to find out the celebrity(or verify
there is not one) by asking as few questions as possible(in the asymptotic sense).

You are given a helper function bool knows(a, b) which tells
you whether A knows B.Implement a function int findCelebrity(n),
your function should minimize the number of calls to knows.

Note : There will be exactly one celebrity if he / she is in
the party.Return the celebrity's label if there is a celebrity 
in the party. If there is no celebrity, return -1.
*/

#include <cstdio>
#include <math.h>
#include <queue>
using namespace std;

int cnt = 0;
bool knows(int** Matrix, int a, int b);
int findCelebrity(int n, int** Matrix)
{
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < n;j++)
		{
			if (!knows(Matrix,j,i))
				break;
			if (j == n - 1)
				return i;
		}
	}
	return -1;
}

int findCelebrity1(int n, int** Matrix)
{
	queue<int> mqueue;
	int len = 0;
	for (int i = 0; i < n;i++)
	{
		if (!knows(Matrix, i, 0))
			mqueue.push(i);
	}
	len = mqueue.size();
	if (len == 0)
		return 0;
	int currPerson = 0;
	while (true)
	{
		currPerson = mqueue.front();
		mqueue.pop();
		len--;
		int newLen = 0;
		while (len>0)
		{
			if (!knows(Matrix,mqueue.front(),currPerson))
			{
				mqueue.push(mqueue.front());
				mqueue.pop();
				newLen++;
			}
			len--;
		}
		if (newLen == 0)
			break;
		else
			len = newLen;
	}
	for (int i = 0; i < n;i++)
	{
		if (!knows(Matrix, i, currPerson))
			break;
		else if (i == n - 1)
			return currPerson;
	}
	return -1;
}

bool knows(int** Matrix, int a, int b)
{
	cnt++;
	if (a < 0 || b < 0)
		return false;
	return Matrix[a][b];
}

void test(int* Array, int len, int celebrity)
{
	double rows=sqrt((double)len);
	if (rows - (int)rows != 0)
	{
		printf("Wrong Input!");
		return;
	}

	int** Matrix = new int*[(int)rows];
	int currRow = -1;
	for (int i = 0; i <len;i++)
	{
		currRow++;
		Matrix[currRow] = new int[(int)rows];
		for (int j = 0; j < ((int)rows);j++)
			Matrix[currRow][j] = Array[i++];
		i--;
	}
	
	//method1
	printf("method1:");
	if (findCelebrity((int)rows, Matrix) == celebrity)
	{
		printf("Passed. Time=%d\n",cnt);
		cnt = 0;
	}
	else
		printf("Failed.\n");

	//method2
	printf("method2:");
	if (findCelebrity1((int)rows, Matrix) == celebrity)
	{
		printf("Passed. Time=%d\n", cnt);
		cnt = 0;
	}
	else
		printf("Failed.\n");
	
	for (int i = 0; i <= currRow; i++)
		delete[] Matrix[i];
	delete[] Matrix;
}

void test1()
{
	printf("test1 begin\n");
	int Array[] = { 1, 1, 1, 1, 1,
					0, 1, 1, 1, 1,
					1, 1, 1, 1, 0,
					0, 0, 0, 1, 0,
					0, 0, 1, 1, 1 };
	test(Array,sizeof(Array)/sizeof(int),3);
}
void test2()
{
	printf("test2 begin\n");
	int Array[] = { 1, 1, 1, 1, 1,
		0, 1, 1, 1, 1,
		1, 1, 1, 1, 0,
		0, 0, 0, 1, 0,
		0, 0, 1, 0, 1 };
	test(Array, sizeof(Array) / sizeof(int), -1);
}

void test3()
{
	printf("test3 begin\n");
	int Array[] = { 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1,
		1, 1, 1, 1, 1,
		1, 1, 1, 1, 1,
		0, 0, 0, 0, 1 };
	test(Array, sizeof(Array) / sizeof(int), 4);
}

void main()
{
	test1();
	test2();
	test3();
}