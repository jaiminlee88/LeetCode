//Given an unsorted integer array, find the smallest missing positive integer.

#include <cstdio>
#include <vector>
using namespace std;

int cnt = 0;

void swapNum(int& a, int& b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}
int firstMissingPositive(vector<int>& nums) 
{
	//把数字放到对的位置，然后再遍历一次看第一个不在位置的数，遍历两次，O(N)
	if (nums.size() <= 0) return 1;
	for (int i = 0; i < nums.size();i++)
	{
		while (nums[i] > 0 && nums[i] < nums.size() && nums[i] != i + 1)
		{
			if (nums[i] != nums[nums[i] - 1])
				swapNum(nums[i], nums[nums[i] - 1]);
			else
				break;
		}
	}
	for (int i = 0; i < nums.size();i++)
	{
		if (nums[i] != i + 1)
			return i + 1;
	}
	return nums.size()+1;
}

int removeElement(vector<int>& nums, int val) {
	if (nums.size() <= 0) return 0;
	int pre = 0;
	for (unsigned short int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == val) continue;
		else
			nums[pre++] = nums[i];
	}
	return pre;
}
void test(int* Array, int len, int tarVal)
{
	vector<int> newVector;
	for (int i = 0; i < len; i++)
	{
		newVector.push_back(Array[i]);
		printf("%d,", Array[i]);
	}
	printf("\n");
	printf("tarVal: %d\n", tarVal);
	if (firstMissingPositive(newVector) == tarVal)
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
	int Array[] = { 1, 2, 0 };
	test(Array, sizeof(Array) / sizeof(int), 3);
}

void test2()
{
	printf("test2 begin:");
	int Array[] = { 3, 4, -1, 1 };
	test(Array, sizeof(Array) / sizeof(int), 2);
}

void test3()
{
	printf("test3 begin:");
	int Array[] = { 7, 8, 9, 11, 12 };
	test(Array, sizeof(Array) / sizeof(int), 1);
}

void test4()
{
	printf("test4 begin:");
	int Array[] = { 2 };
	test(Array, sizeof(Array) / sizeof(int), 1);
}

void test5()
{
	printf("test5 begin:");
	int Array[] = { -2 };
	test(Array, sizeof(Array) / sizeof(int), 1);
}

void test6()
{
	printf("test6 begin:");
	int Array[] = { 1,1 };
	test(Array, sizeof(Array) / sizeof(int), 2);
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