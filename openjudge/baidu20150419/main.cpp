/************************************************************************/
/* 
�ȶ��ܵ�����֮��������ֻ��˵���������һ��Ӣ����ĸ��ɣ�'a'~'z',�Լ���'A'~'Z'����
���裺
һ����ĸ'a'�����ֵΪ1����value��a��==1����'b'Ϊ2...,'z'Ϊ26��
����һ����д��ĸ�൱�����Ӧ������Сд��ĸ����bBb��bbbb�ȼۡ�
�������������������ͬ�ַ�����aaaaa.....������k��a��������k��a����Ȩֵ����k*k*value��a�������磬bBb��bbbb��
���Ƕ�Ӧ����Ȩֵ��4*4*2=32��
Input��
��������ݵ�һ���Ǹ�������T��T<=1000������ʾ��T���������ݡ�
������T��ÿ�ж��Ƕȶ��ܵİ�������ɴ�Сд��ĸ���ɵ��ַ������������10000.
Output��
����ÿ����������Ȩֵ��
ÿ�����ռһ�С�                                                                    
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
