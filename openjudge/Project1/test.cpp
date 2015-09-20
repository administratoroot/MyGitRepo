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
double CubeRoot(const double stuff)
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
int main()
{
    cout << CubeRoot(8) << endl;
    system("pause");
    return 0;
}