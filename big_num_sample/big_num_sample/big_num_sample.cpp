// big_num_sample.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BigNum.h"

BigNum fab1(int n) //递归实现，n>50左右堆栈会溢出
{
	assert(n >= 0);
	if (n == 1)
		return BigNum(1);
	if (n == 2)
		return BigNum(2);
	return fab1(n - 1) + fab1(n - 2);
}

BigNum fab2(int n)//非递归实现
{
	assert(n >= 0);
	BigNum bn(0);
	BigNum bn1(1);
	BigNum bn2(2);
	if (n == 1)
		return bn1;
	if (n == 2)
		return bn2;
	n -= 2;
	while (n-- > 0)
	{
		bn = bn1 + bn2;
		bn1  = bn2;
		bn2 = bn;
	}
	return bn;
}

int _tmain(int argc, _TCHAR* argv[])
{
	BigNum bn;
	BigNum bn1(-23325);
	BigNum bn2("-11111111");
	bn = bn2^2;
	bn = bn +  bn1;
	bn.print();
	bn = fab2(2500);
	bn.print();
	getchar();
	return 0;
}

