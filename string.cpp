#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::endl;
using std::string;
using std::list;

/*迭代器: 访问容器元素的一种方式, 可以通过迭代器遍历容器中的元素, 
		可以把迭代器看做指针, 使用方法和指针类似: 可以进行访问位置的移动; 比如++,--,可以进行类似指针的解引用: *, ->






正向迭代器, 反向迭代器: iterator, reverse_iterator 都为可读可写的迭代器
正向的const迭代器
*/

/*
default (1)
string();
copy (2)
string (const string& str);
substring (3)
string (const string& str, size_t pos, size_t len = npos);
from c-string (4)
string (const char* s);
from sequence (5)
string (const char* s, size_t n);
fill (6)
string (size_t n, char c);
range (7)
template <class InputIterator>
string  (InputIterator first, InputIterator last);
*/

void test4()
{
	string str;  //""
	string cpy(str);  //""
	string str2("1234"); // "1234"
	string str22 = "1234";  //单参构造隐式类型转换
	string str3(str2, 2);  // "34"
	string str4(str2, 2, 1); // "3"
	string str5("123456", 3); // "123"
	string str6(20, 'a');// "aaaaaaaaaaaaaaaaaaaa"
	string str7(str2.begin(), str2.end());
	cout << str << endl;
	cout << cpy << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
	cout << str5 << endl;
	cout << str6 << endl;
	cout << str7 << endl;

}

void test5()
{
	string str2 = "1234";  //单参构造隐式类型转换
	string::iterator it = str2.begin(); // 返回第一个元素的位置
	string::iterator eit = str2.end();
	//遍历元素
	while (it != eit)
	{
		//解引用,获取内容
		cout << *it << " ";
		//移动迭代器:移动到下一个元素的位置
		++it;
		//it++;
	}
	cout << endl;

	list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	cout << "list:" << endl;
	list<int>::iterator lit = lst.begin();
	while (lit != lst.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;

}

void test6()
{
	string str2 = "1234";  //单参构造隐式类型转换
	string::iterator it = str2.begin(); // 返回第一个元素的位置
	string::iterator eit = str2.end();
	//遍历元素
	while (it != eit)
	{
		//解引用,获取内容
		cout << *it << " ";
		//移动迭代器:移动到下一个元素的位置
		*it *= 2;
		++it;
		//it++;
	}
	cout << endl;
	cout << "reverse_iterator: " << endl;
	//反向迭代器
	string::reverse_iterator rit = str2.rbegin();
	while (rit != str2.rend())
	{
		cout << *rit << " ";
		*rit /= 2;
		++rit;  //反向迭代器， 向前移动
	}
	cout << endl;

	it = str2.begin();
	//遍历元素
	while (it != eit)
	{
		//解引用,获取内容
		cout << *it << " ";
		//移动迭代器:移动到下一个元素的位置
		++it;
		//it++;
	}

	string::const_iterator cit = str2.begin();
	while (cit != str2.end())
	{
		cout << *cit << " ";
		//const迭代器不支持修改容器内容，只读迭代器
		//*cit *= 2;
		++cit;
	}
	cout << endl;

	string::const_reverse_iterator crit = str2.rbegin();
	while (crit != str2.rend())
	{
		cout << *crit << " ";
		++crit;
	}
	cout << endl;
}
int main(){


	system("pause");
	return 0;
}