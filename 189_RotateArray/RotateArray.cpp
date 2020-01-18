//Given an array, rotate the array to the right by k steps, where k is non-negative.
#include <cstdio>
#include <vector>
using namespace std;

void rotate(vector<int>& nums, int start, int end)
{
	if (start >= end) return;
	while (start<end)
	{
		nums[start] = nums[start] ^ nums[end];
		nums[end] = nums[start] ^ nums[end];
		nums[start] = nums[start] ^ nums[end];
		start++;
		end--;
	}
}
void rotate(vector<int>& nums, int k) 
{
	if (nums.size()<=1 || k<=0 || k==nums.size()) return;
	if (k > nums.size())
		k %= nums.size();
	rotate(nums, 0, nums.size() - 1);
	rotate(nums, 0, k - 1);
	rotate(nums, k, nums.size() - 1);
	return;
}

void test(int* Array, int len, int k)
{
	vector<int> newVector;
	printf("rotate pos: %d\n", k);
	printf("Input Array:");
	for (int i = 0; i < len; i++)
	{
		newVector.push_back(Array[i]);
		printf("%d,", Array[i]);
	}
	printf("\n");
	rotate(newVector,k);
	printf("Output Array:");
	for (int i = 0; i < len; i++)
		printf("%d,", newVector[i]);
	printf("\n");
}

void test1()
{
	printf("test1 begin\n");
	int Array[] = { 1, 1, 2 };
	test(Array, sizeof(Array) / sizeof(int),2);
}

void test2()
{
	printf("test2 begin\n");
	int Array[] = { 1, 1, 1, 2, 2, 3 };
	test(Array, sizeof(Array) / sizeof(int),3);
}

void test3()
{
	printf("test3 begin\n");
	int Array[] = { 1, 2, 3, 4, 5, 6, 7 };
	test(Array, sizeof(Array) / sizeof(int),3);
}

void test4()
{
	printf("test4 begin\n");
	int Array[] = { -1, -100, 3, 99 };
	test(Array, sizeof(Array) / sizeof(int),2);
}

void test5()
{
	printf("test5 begin\n");
	int Array[] = { 1,2 };
	test(Array, sizeof(Array) / sizeof(int),3);
}

void main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
}