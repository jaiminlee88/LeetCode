// Given an array nums and a value val, remove all instances of that value in - place and return the new length.
// 
// Do not allocate extra space for another array, you must do this by modifying the input array in - place with O(1) extra memory.
// 
// The order of elements can be changed.It doesn't matter what you leave beyond the new length.
#include <cstdio>
#include <vector>
using namespace std;

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
void test(int* Array, int len,int deleVal)
{
	vector<int> newVector;
	printf("Input Array:");
	for (int i = 0; i < len; i++)
	{
		newVector.push_back(Array[i]);
		printf("%d,", Array[i]);
	}
	printf("\n");
	printf("deleVal: %d\n",deleVal);
	int newlen=removeElement(newVector, deleVal);
	printf("Output Array:");
	for (int i = 0; i < newlen; i++)
		printf("%d,", newVector[i]);
	printf("\n");
}
void test1()
{
	printf("test1 begin\n");
	int Array[] = { 1, 2, 2, 2, 3, 3 };
	test(Array, sizeof(Array) / sizeof(int),2);
}

void test2()
{
	printf("test2 begin\n");
	int Array[] = { 1 };
	test(Array, sizeof(Array) / sizeof(int), 1);
}

void test3()
{
	printf("test3 begin\n");
	int Array[] = { 1, 2,3, 3 };
	test(Array, sizeof(Array) / sizeof(int), 3);
}

void main()
{
	test1();
	test2();
	test3();

}