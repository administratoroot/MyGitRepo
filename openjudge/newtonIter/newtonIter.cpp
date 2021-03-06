/************************************************************************/
/*
用牛顿迭代法求解方程
*/
/************************************************************************/
#include<iostream>
using namespace std;

/*
函数： double CubeRoot(double)
功能： 求解一个数的立方根
算法： 牛顿法
使用： 输入一个实数，输出输入实数的立方根
*/
double newtonCubeRoot(const double stuff)
{
    const double  precision = 0.00001; /* 精度 */
    double nextX, currentX;
    double squareX;     /* 当前值 的平方 */
    double cubeX;       /* 下个解 的立方 */
    bool flag;

    currentX = stuff;  /* 初始化当前的值为X */

    if (stuff == 0)
    {
        return stuff;
    }
    else
    {
        do
        {
            squareX = currentX * currentX;
            nextX = (2 * currentX + stuff / squareX) / 3;       /* 牛顿迭代公式 */
            cubeX = nextX*nextX*nextX;
            if ((cubeX - stuff < precision) && (cubeX - stuff > -precision))
            {
                flag = true;
            }
            else
            {
                flag = false;
                currentX = nextX;
            }
        } while (flag == false);
    }

    return nextX;
}

//************************************
// Method:    牛顿迭代法求平方根
// FullName:  newtonSqrt
// Access:    public 
// Returns:   double
// Qualifier:
// Parameter: const double x
//************************************
double newtonSqrt(const double x)
{
    if (x < 0)
    {
        return -1;
    }
    if (x == 0)
    {
        return 0;
    }

    double _avg = x;
    double last_avg = DBL_MAX;
    double precision = 1e-6;

    while (abs(_avg - last_avg) > precision)
    {
        last_avg = _avg;
        _avg = (_avg + x / _avg) / 2;
    }
    return _avg;
}

int main()
{
    cout << newtonCubeRoot(7) << endl;
    cout << newtonSqrt(2) << endl;
    system("pause");
    return 0;
}