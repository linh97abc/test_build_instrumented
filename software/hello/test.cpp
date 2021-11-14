#include <stdio.h>

class test
{
private:
	int x;

	int inc(int y)
	{
		this->x = this->x + y;
		return this->x;
	}
public:
	test(){ x = 0; }
	test(int x)
	{
		this->x = x;
	}

	int func(int y)
	{
		static int i = 0;
		printf("func: %d\n", i++);

		this->x = y+this->x;
		return this->x;
	}
	bool operator == (const test other){
		return this->x == other.x;
	}
	bool operator != (const test other){
		return !(*this == other);
	}

	void testRef(test& x1)
	{
		x1.x = x1.func(this->x);
	}
};

static test _test;

void testRef(test& classX, int y)
{
	classX.func(y);
}

test testEqClass(test& classX)
{
	test newclass = classX;
	return newclass;
}

int func(int x)
{
//	test xx = _test.testRef(_test);
//	int x = 0;
//	testRef(x);

	return x;
}
