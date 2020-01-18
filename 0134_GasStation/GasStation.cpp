/*
There are N gas stations along a circular route, where the amount 
of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] 
of gas to travel from station i to its next station (i+1). 
You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around
the circuit once in the clockwise direction, otherwise return -1.

Note:

If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.
可以转换成求最大连续和做，但是有更简单的方法。基于一个数学定理：

如果一个数组的总和非负，那么一定可以找到一个起始位置，从他开始绕数组一圈，累加和一直都是非负的
关键在于j位置的时候累计和为负，说明从i-j中间任何一个节点开始到j都会为负，不符合累加一直为非负的要求
*/
#include <cstdio>
#include <vector>
using namespace std;

int cnt = 0;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	if (gas.size() <= 0 || gas.size() != cost.size()) return -1;
	
	for (int i = 0; i < gas.size();i++)
	{
		int total = gas[i] - cost[i];
		if (total<0) continue;
		int j = i+1;
		while (true)
		{	
			if (j == i) return i;
			else if (j >= gas.size())
			{
				j = 0;
				continue;
			}
			else if (total + gas[j] - cost[j] >= 0)
				total += gas[j] - cost[j];
			else
			{
				if (j + 1 == i) return -1;
				else if (i > j)
					return -1;
				else
					i = j;
				break;
			}
			j++;
		}
	}
	return -1;
}

int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
	if (gas.size() <= 0 || gas.size() != cost.size()) return -1;
	int g = 0;
	int c = 0;
	for (int i = 0; i < gas.size();i++)
	{
		if (gas[i]<cost[i]) continue;
		else
		{
			int j = i+1;
			g = gas[i];
			c = cost[i];
			while (true)
			{
				if (j == i) return i;
				else if (j >= gas.size())
				{
					j = 0;
					continue;
				}

				if (g + gas[j] >= c + cost[j])
				{
					g += gas[j];
					c += cost[j];
					j++;
				}
				else
				{
					g = 0;
					c = 0;
					break;
				}
			}
		}
	}
	return -1;
}

void test(int* gas,int* cost, int len, int tarVal)
{
	vector<int> gasVector;
	vector<int> costVector;
	for (int i = 0; i < len; i++)
		gasVector.push_back(gas[i]);
	for (int i = 0; i < len; i++)
		costVector.push_back(cost[i]);
	
	if (canCompleteCircuit(gasVector,costVector) == tarVal)
	{
		printf("Passed. Time=%d\n", cnt);
		cnt = 0;
	}
	else
		printf("Failed.\n");
}
void test1()
{
	printf("test1 begin:");
	int gas[] = { 1, 2, 3, 4, 5 };
	int cost[] = { 3, 4, 5, 1, 2 };
	test(gas, cost, sizeof(gas) / sizeof(int), 3);
}

void test2()
{
	printf("test2 begin:");
	int gas[] = {  2, 3, 4 };
	int cost[] = { 3, 4, 3 };
	test(gas, cost, sizeof(gas) / sizeof(int), -1);
}

void test3()
{
	printf("test3 begin:");
	int gas[] = { 3,1,1 };
	int cost[] = { 1,2,2 };
	test(gas, cost, sizeof(gas) / sizeof(int), 0);
}

void test4()
{
	printf("test4 begin:");
	int gas[] = { 1, 2, 3, 4, 3, 2, 4, 1, 5, 3, 2, 4 };
	int cost[] = { 1, 1, 1, 3, 2, 4, 3, 6, 7, 4, 3, 1 };
	test(gas, cost, sizeof(gas) / sizeof(int), -1);
}

void test5()
{
	printf("test5 begin:");
	int gas[] = { 2, 3, 4 };
	int cost[] = { 3, 4, 3 };
	test(gas, cost, sizeof(gas) / sizeof(int), -1);
}

void test6()
{
	printf("test6 begin:");
	int gas[] = { 2, 3, 4 };
	int cost[] = { 3, 4, 3 };
	test(gas, cost, sizeof(gas) / sizeof(int), -1);
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