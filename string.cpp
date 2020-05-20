#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::endl;
using std::string;
using std::list;

/*������: ��������Ԫ�ص�һ�ַ�ʽ, ����ͨ�����������������е�Ԫ��, 
		���԰ѵ���������ָ��, ʹ�÷�����ָ������: ���Խ��з���λ�õ��ƶ�; ����++,--,���Խ�������ָ��Ľ�����: *, ->






���������, ���������: iterator, reverse_iterator ��Ϊ�ɶ���д�ĵ�����
�����const������
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
	string str22 = "1234";  //���ι�����ʽ����ת��
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
	string str2 = "1234";  //���ι�����ʽ����ת��
	string::iterator it = str2.begin(); // ���ص�һ��Ԫ�ص�λ��
	string::iterator eit = str2.end();
	//����Ԫ��
	while (it != eit)
	{
		//������,��ȡ����
		cout << *it << " ";
		//�ƶ�������:�ƶ�����һ��Ԫ�ص�λ��
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
	string str2 = "1234";  //���ι�����ʽ����ת��
	string::iterator it = str2.begin(); // ���ص�һ��Ԫ�ص�λ��
	string::iterator eit = str2.end();
	//����Ԫ��
	while (it != eit)
	{
		//������,��ȡ����
		cout << *it << " ";
		//�ƶ�������:�ƶ�����һ��Ԫ�ص�λ��
		*it *= 2;
		++it;
		//it++;
	}
	cout << endl;
	cout << "reverse_iterator: " << endl;
	//���������
	string::reverse_iterator rit = str2.rbegin();
	while (rit != str2.rend())
	{
		cout << *rit << " ";
		*rit /= 2;
		++rit;  //����������� ��ǰ�ƶ�
	}
	cout << endl;

	it = str2.begin();
	//����Ԫ��
	while (it != eit)
	{
		//������,��ȡ����
		cout << *it << " ";
		//�ƶ�������:�ƶ�����һ��Ԫ�ص�λ��
		++it;
		//it++;
	}

	string::const_iterator cit = str2.begin();
	while (cit != str2.end())
	{
		cout << *cit << " ";
		//const��������֧���޸��������ݣ�ֻ��������
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