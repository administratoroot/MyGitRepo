//////////////////////////////////////////////////////////////////////////
//��̰���㷨������ǰ������ֵ��ʱ�临�Ӷ�O(n)
//��TestCase1��
//���룺
//7
//1 7 3 5 9 4 8
//�����
//8
//
//��TestCase2��
//���룺
//2
//3 1
//�����
//0
//
//��TestCase3��
//���룺
//7
//8 4 9 5 3 7 1
//�����
//0
//
//��TestCase4��
//���룺
//1
//0
//�����
//0
//
//��TestCase5��
//���룺
//3
//1 1 1
//�����
//0
//
//////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int Array[1000];
int getMaxDiff(int* a,int length)
{
	int minNum = a[0];
	int Sub_MaxDiff = 0;
	for (int i = 1; i < length; i++)
	{
		minNum = (a[i] < minNum) ? a[i] : minNum;
		Sub_MaxDiff = ((a[i] - minNum)>Sub_MaxDiff)? (a[i] - minNum) : Sub_MaxDiff;
	}
	return Sub_MaxDiff;
}
int main()
{

	int N=0;//�������еĳ���
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Array[i]; 
	}
	cout << getMaxDiff(Array, N) << endl;
	system("pause");
	return 0;
}