/************************************************************************/
/* 
输入一个整数的数组
将这里面的整数排列，组成最大的数
输出次最大的数
*/
/************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//************************************
// Method:    将数字循环延长 比如：45 延长 3位，结果：45454
// FullName:  extentNum
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: char * s
// Parameter: int addLength
//************************************
void extentNum(char* s,int addLength)
{
    if (addLength == 0)
    {
        return;
    }
    int nLength = strlen(s);
    char *p = s;
    char *q = s + nLength;
    int nStep = 0;
    while (nStep < addLength)
    {
        *q = *p;
        ++p;
        ++q;
        ++nStep;
        if (nStep%nLength == 0)
        {
            p = s;
        }
    }
    *q = '\0';
}
//************************************
// Method:    特殊的比较函数
// FullName:  specialGreater
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: const int & a
// Parameter: const int & b
//************************************
bool specialGreater(const int &a, const int &b)
{
    char s_a[100];
    char s_b[100];
    _itoa_s(a, s_a, 100, 10);
    _itoa_s(b, s_b, 100, 10);
    int n_aLength = strlen(s_a);
    int n_bLength = strlen(s_b);
    int n_maxLength = max(n_aLength, n_bLength);
    //补全
    extentNum(s_a, n_maxLength - n_aLength);
    extentNum(s_b, n_maxLength - n_bLength);
    if (strcmp(s_a, s_b)>=0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
int main()
{
    vector<int> arr;
    arr.push_back(45);
    arr.push_back(45456);
    arr.push_back(6);
    arr.push_back(9);
    arr.push_back(72);
    arr.push_back(38);
    arr.push_back(528);
    arr.push_back(2);
    arr.push_back(1);


    sort(arr.begin(), arr.end(), specialGreater);
    for each(int i in arr)
    {
        cout << i<< " ";
    }
    system("pause");
    return 0;
}