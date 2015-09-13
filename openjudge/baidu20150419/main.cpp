/************************************************************************/
/* 
度度熊的神秘之处在于他只会说暗语，暗语由一串英语字母组成（'a'~'z',以及由'A'~'Z'）。
假设：
一、字母'a'代表的值为1（即value（a）==1），'b'为2...,'z'为26。
二、一个大写字母相当于其对应的两个小写字母，如bBb和bbbb等价。
三、如果出现连续的相同字符，如aaaaa.....（连续k个a），则这k个a的总权值会变成k*k*value（a）；比如，bBb与bbbb，
他们对应的总权值是4*4*2=32。
Input：
输入的数据第一行是个正整数T（T<=1000），表示有T个测试数据。
接下来T行每行都是度度熊的暗语，，即由大小写字母构成的字符串，长度最多10000.
Output：
对于每条暗语，输出其权值。
每组输出占一行。                                                                    
 */
/************************************************************************/
#include <iostream>
using namespace std;
char arr[1000][10001];
int value(char letter)
{
	if (letter >= 'a'&&letter <= 'z')
	{
		return letter - 'a' + 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int result[1000];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		result[i] = 0;
		char *p = arr[i];
		char pre = 0;
		int times = 0;
		while (*p != '\0')
		{
			if (pre == 0 || pre == *p || pre == *p + 32)
			{
				if (*p >= 'A'&&*p <= 'Z'){
					pre = *p + 32;
					times += 2;
				}
				else
				{
					pre = *p;
					times++;
				}
				p++;
			}
			else
			{
				result[i] += value(pre)*times*times;
				pre = 0;
				times = 0;
			}
		}
		result[i] += value(pre)*times*times;
	}
	for (int i = 0; i < N; i++)
	{
		cout << result[i] << endl;
	}
	system("pause");
	return 0;
}
