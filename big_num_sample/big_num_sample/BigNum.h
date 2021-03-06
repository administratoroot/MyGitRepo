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
	int a[MAXLEN];    //可以控制大数的位数 
	int len;       //大数长度
public: 
	BigNum(); //构造函数
	BigNum(int);       //将一个int类型的变量转化为大数
	BigNum(const char *);     //将一个字符串类型的变量转化为大数
	BigNum(const BigNum &);  //拷贝构造函数
	~BigNum(void);//析构函数
	BigNum &operator=(const BigNum &);   //重载赋值运算符，大数之间进行赋值运算

	friend istream& operator>>(istream&,  BigNum&);   //重载输入运算符
	friend ostream& operator<<(ostream&,  BigNum&);   //重载输出运算符

	BigNum operator+(const BigNum &) const;   //重载加法运算符，两个大数之间的相加运算 
	BigNum operator-(const BigNum &) const;   //重载减法运算符，两个大数之间的相减运算 
	BigNum operator*(const BigNum &) const;   //重载乘法运算符，两个大数之间的相乘运算 
	BigNum operator/(int  b) const;    //重载除法运算符，大数对一个整数进行相除运算
	
	BigNum operator^( int  n) const;    //大数的n次方运算
	int    operator%(int  b) const;    //大数对一个int类型的变量进行取模运算    
	bool   operator>(const BigNum & T)const;   //大数和另一个大数的大小比较
	bool   operator>(const int & t)const;      //大数和一个int类型的变量的大小比较
	bool bPositive() const;
	BigNum &Negative();
	BigNum &Positive();
	void print();       //输出大数
}; 

