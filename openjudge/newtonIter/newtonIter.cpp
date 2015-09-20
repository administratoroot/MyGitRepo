/************************************************************************/
/*
��ţ�ٵ�������ⷽ��
*/
/************************************************************************/
#include<iostream>
using namespace std;

/*
������ double CubeRoot(double)
���ܣ� ���һ������������
�㷨�� ţ�ٷ�
ʹ�ã� ����һ��ʵ�����������ʵ����������
*/
double newtonCubeRoot(const double stuff)
{
    const double  precision = 0.00001; /* ���� */
    double nextX, currentX;
    double squareX;     /* ��ǰֵ ��ƽ�� */
    double cubeX;       /* �¸��� ������ */
    bool flag;

    currentX = stuff;  /* ��ʼ����ǰ��ֵΪX */

    if (stuff == 0)
    {
        return stuff;
    }
    else
    {
        do
        {
            squareX = currentX * currentX;
            nextX = (2 * currentX + stuff / squareX) / 3;       /* ţ�ٵ�����ʽ */
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
// Method:    ţ�ٵ�������ƽ����
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