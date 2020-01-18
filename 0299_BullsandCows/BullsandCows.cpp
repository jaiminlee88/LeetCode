/*
You are playing the following Bulls and Cows game with your friend: 
You write down a number and ask your friend to guess what the number 
is.Each time your friend makes a guess, you provide a hint that indicates
how many digits in said guess match your secret number exactly in both
digit and position(called "bulls") and how many digits match the secret
number but locate in the wrong position(called "cows").Your friend will 
use successive guesses and hints to eventually derive the secret number.
Write a function to return a hint according to the secret number and
friend's guess, use A to indicate the bulls and B to indicate the cows. 
Please note that both secret number and friend's guess may contain duplicate 
digits.
Note: You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
*/
#include <cstdio>
#include <map>
#include <stdio.h>
#include <sstream>
using namespace std;

string getHint(string secret, string guess) 
{
	if (secret.size() != guess.size() || secret.size()==0 || guess.size()==0) return "0A0B";

	int A = 0;
	int B = 0;
	int SecArray[10] = { 0 };
	int GueArray[10] = { 0 };
	std::map<int, int> mmap;
	for (int i = 0; i < secret.size();i++)
	{
		if (secret[i] == guess[i])
			A++;
		else
		{
			SecArray[secret[i]-'0']++;
			GueArray[guess[i]-'0']++;
		}
	}
	for (int i = 0; i < 10;i++)
	{
		if (SecArray[i] == 0 || GueArray[i] == 0) continue;
		else if (SecArray[i] >= GueArray[i])
			B += GueArray[i];
		else
			B += SecArray[i];
	}
	string ret;
	stringstream ss;   
	ss << A;                      
	ss << 'A';
	ss << B;
	ss << 'B';
	ss >> ret;
	return ret;
}

void test(string secret, string guess,string expected)
{
	if (getHint(secret, guess) == expected)
		printf("Passed.");
	else
		printf("Failed.");
}

void test1()
{
	printf("test1 begin:");
	string a = "1234";
	string b = "2226";
	test(a, b, "1A0B");
}

void test2()
{
	printf("test2 begin:");
	string a = "1234";
	string b = "2356";
	test(a, b, "0A2B");
}

void test3()
{
	printf("test3 begin:");
	string a = "1234";
	string b = "2356";
	test(a, b, "0A2B");
}

void test4()
{
	printf("test4 begin:");
	string a = "1234";
	string b = "2356";
	test(a, b, "0A2B");
}

void test5()
{
	printf("test5 begin:");
	string a = "1234";
	string b = "2356";
	test(a, b, "0A2B");
}

void test6()
{
	printf("test6 begin:");
	string a = "1234";
	string b = "2356";
	test(a, b, "0A2B");
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