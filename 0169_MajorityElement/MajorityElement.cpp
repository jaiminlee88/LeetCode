/*
Given an array of size n, find the majority element. The majority element
is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element 
always exist in the array.

要么排序，直接找中间
要么直接找中间数，长度N为偶数或者奇数时，N/2位数是出现一半的数
*/
#include <cstdio>
#include <vector>
using namespace std;

void swapNum(int&a, int& b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}
int majorityElement(vector<int>& nums) 
{
	if (nums.size() <= 0) return -1;
	int currNum = nums[0];
	int cnt = 1;
	for (int i = 1; i < nums.size();i++)
	{
		if (currNum == nums[i])
			cnt++;
		else if (cnt>0)
			cnt--;
		else
		{
			currNum = nums[i];
			cnt++;
		}
	}
	return currNum;
}

int majorityElement1(vector<int>& nums) {
	if (nums.size() <= 0) return -1;
	if (nums.size() == 1) return nums[0];
	int midPos = nums.size() >> 1;
	int currPos = 0;
	int left = 0;
	int right = nums.size() - 1;
	while (true)
	{
		currPos = left;
		int l=left+1;
		int h = right;
		while (l<h)
		{
			while (h>l && nums[h] > nums[currPos]) h--;
			while (l < h && nums[l] <= nums[currPos]) l++;
			if (l < h)
				swapNum(nums[l], nums[h]);
		}
		if (l>=h && nums[currPos]>nums[h])
			swapNum(nums[currPos], nums[h]);
		if (h == midPos)
			return nums[h];
		else if (midPos >= h)
			left = h;
		else
			right = h - 1;
	}
	return -1;
}

void test(int* Array, int len, int tarVal)
{
	vector<int> newVector;
	for (int i = 0; i < len; i++)
		newVector.push_back(Array[i]);
	printf("tarVal: %d\n", tarVal);
	if (majorityElement(newVector) == tarVal)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}
void test1()
{
	printf("test1 begin:");
	int Array[] = { 4, 5, 4};
	test(Array, sizeof(Array) / sizeof(int), 4);
}

void test2()
{
	printf("test2 begin:");
	int Array[] = { 2, 2, 1, 1, 1, 2, 2 };
	test(Array, sizeof(Array) / sizeof(int), 2);
}

void test3()
{
	printf("test3 begin:");
	int Array[] = { 1 };
	test(Array, sizeof(Array) / sizeof(int), 1);
}

void test4()
{
	printf("test4 begin:");
	int Array[] = { 2,2 };
	test(Array, sizeof(Array) / sizeof(int), 2);
}

void test5()
{
	printf("test5 begin:");
	int Array[] = { 1,9,9,6,8,9,9 };
	test(Array, sizeof(Array) / sizeof(int), 9);
}

void test6()
{
	printf("test6 begin:");
	int Array[] = {5,1,1,-2,1,1 };
	test(Array, sizeof(Array) / sizeof(int), 1);
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