/************************************************************************/
/* 
0到999个数中，每隔2个数删除掉。删除到最后一个然后循环到开头。
最后剩余的数是什么？
思路:将删掉的数作特殊的标记
*/
/************************************************************************/
#include <iostream>
#define ARRLENGTH 100
#define STEP 3
using namespace std;
bool isRemainLastNum(int* arr,const int length)
{
    int nNum = 0;//剩余的数字个数
    for (int i = 0; i < length; ++i)
    {
        if (arr[i] != -1)
        {
            nNum++;
        }
        if (nNum > 1)
        {
            return false;
        }
    }
    return true;
}
void printLastNum(int* arr, const int length)
{
    for (int i = 0; i < length; ++i)
    {
        if (arr[i] != -1)
        {
            cout << "last num is " << arr[i] << endl;
            return;
        }
    }
}
int main()
{
    int arr[ARRLENGTH];
    for (int i = 0; i < ARRLENGTH; ++i)
    {
        arr[i] = i;
    }
    int k = 0;
    while (!isRemainLastNum(arr, ARRLENGTH))
    {
        for (int i = 0; i < ARRLENGTH; ++i)
        {
            if (arr[i] != -1)
            {
                k++;
            }
            if (k == STEP)
            {
                arr[i] = -1;
                k = 0;
            }
        }
    }
    printLastNum(arr, ARRLENGTH);
    system("pause");
    return 0;
}