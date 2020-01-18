/* Given a sorted array nums, remove the duplicates in - place 
	such that duplicates appeared at most twice and return the new length.
 Do not allocate extra space for another array, you must 
 do this by modifying the input array in - place with O(1) extra memory.
*/
#include <cstdio>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
	if (nums.size() <= 2) return nums.size();
	int pre = 0,cnt=0;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[pre]==nums[i])
		{
			cnt++;
			if (i==nums.size()-1)
				nums[++pre] = nums[i];
			continue;
		}
		else if (cnt==0)
			nums[++pre] = nums[i];
		else
		{
			nums[pre + 1] = nums[pre];
			pre += 2;
			cnt = 0;
			nums[pre] = nums[i];
		}
	}
	return pre + 1;
}

void test(int* Array, int len)
{
	vector<int> newVector;
	printf("Input Array:");
	for (int i = 0; i < len; i++)
	{
		newVector.push_back(Array[i]);
		printf("%d,", Array[i]);
	}
	printf("\n");
	int newlen = removeDuplicates(newVector);
	printf("Output Array:");
	for (int i = 0; i < newlen; i++)
		printf("%d,", newVector[i]);
	printf("\n");
}

void test1()
{
	printf("test1 begin\n");
	int Array[] = { 1, 1, 2 };
	test(Array, sizeof(Array) / sizeof(int));
}

void test2()
{
	printf("test2 begin\n");
	int Array[] = { 1, 1, 1, 2, 2, 3 };
	test(Array, sizeof(Array) / sizeof(int));
}

void test3()
{
	printf("test3 begin\n");
	int Array[] = { 0, 0, 1, 1, 1, 1, 2, 3, 3 };
	test(Array, sizeof(Array) / sizeof(int));
}

void test4()
{
	printf("test4 begin\n");
	int Array[] = { 0, 0, 1, 1, 1, 1, 2, 3 };
	test(Array, sizeof(Array) / sizeof(int));
}
void main()
{
	test1();
	test2();
	test3();
	test4();
}