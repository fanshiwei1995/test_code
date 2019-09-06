#include<stdio.h>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<string.h>
#include<iostream>
#include<exception>  //为异常调用基类，可通过exception & e确定错误类型，并通过e.what()显示
#include"LinkList.h"

using namespace std;

class A
{
public:
	void f()
	{
		printf("A\n");
	}
};

class B : public A
{
public:
	virtual void f()
	{
		printf("B\n");
	}
};

int main()
{
	A *a = new B;
	a->f();
	delete a;
	return 0;
}