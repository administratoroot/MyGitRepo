// big_num_sample.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "BigNum.h"

BigNum fab1(int n) //�ݹ�ʵ�֣�n>50���Ҷ�ջ�����
{
	assert(n >= 0);
	if (n == 1)
		return BigNum(1);
	if (n == 2)
		return BigNum(2);
	return fab1(n - 1) + fab1(n - 2);
}

BigNum fab2(int n)//�ǵݹ�ʵ��
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

