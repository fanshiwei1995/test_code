#include<stdio.h>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<string.h>
#include<iostream>
#include<exception>  //Ϊ�쳣���û��࣬��ͨ��exception & eȷ���������ͣ���ͨ��e.what()��ʾ
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