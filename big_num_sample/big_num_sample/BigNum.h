#pragma once
#include <assert.h>
#include<iostream> 
#include<string> 
#include<iomanip> 
#include<algorithm> 
using namespace std; 

#define MAXLEN 1000
#define MAXN 9999
#define MAXSIZE 10
#define DLEN 4

class BigNum
{ 
private: 
	int a[MAXLEN];    //���Կ��ƴ�����λ�� 
	int len;       //��������
public: 
	BigNum(); //���캯��
	BigNum(int);       //��һ��int���͵ı���ת��Ϊ����
	BigNum(const char *);     //��һ���ַ������͵ı���ת��Ϊ����
	BigNum(const BigNum &);  //�������캯��
	~BigNum(void);//��������
	BigNum &operator=(const BigNum &);   //���ظ�ֵ�����������֮����и�ֵ����

	friend istream& operator>>(istream&,  BigNum&);   //�������������
	friend ostream& operator<<(ostream&,  BigNum&);   //������������

	BigNum operator+(const BigNum &) const;   //���ؼӷ����������������֮���������� 
	BigNum operator-(const BigNum &) const;   //���ؼ������������������֮���������� 
	BigNum operator*(const BigNum &) const;   //���س˷����������������֮���������� 
	BigNum operator/(int  b) const;    //���س����������������һ�����������������
	
	BigNum operator^( int  n) const;    //������n�η�����
	int    operator%(int  b) const;    //������һ��int���͵ı�������ȡģ����    
	bool   operator>(const BigNum & T)const;   //��������һ�������Ĵ�С�Ƚ�
	bool   operator>(const int & t)const;      //������һ��int���͵ı����Ĵ�С�Ƚ�
	bool bPositive() const;
	BigNum &Negative();
	BigNum &Positive();
	void print();       //�������
}; 

