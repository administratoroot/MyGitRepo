/************************************************************************/
/* 
用贪心算法求后面减前面最大差值，时间复杂度O(n)
【TestCase1】
输入：
7
1 7 3 5 9 4 8
输出：
8

【TestCase2】
输入：
2
3 1
输出：
-2

【TestCase3】
输入：
7
8 4 9 5 3 7 1
输出：
5

【TestCase4】
输入：
1
0
输出：
input error

【TestCase5】
输入：
3
1 1 1
输出：
0
*/
/************************************************************************/
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

int Array[1000];
int getMaxDiff(int* a,int length)
{
    assert(length > 1);
    int minNum = min(a[0], a[1]);
    int Sub_MaxDiff = a[1] - a[0];
	for (int i = 2; i < length; i++)
	{
		minNum = (a[i] < minNum) ? a[i] : minNum;
		Sub_MaxDiff = ((a[i] - minNum)>Sub_MaxDiff)? (a[i] - minNum) : Sub_MaxDiff;
	}
	return Sub_MaxDiff;
}
int main()
{
    int N = 0;//输入序列的长度
	cin >> N;
    if (N < 2)
    {
        cout << "input error";
        return -1;
    }
	for (int i = 0; i < N; i++)
	{
		cin >> Array[i]; 
	}
	cout << getMaxDiff(Array, N) << endl;
	system("pause");
	return 0;
}