#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

/*
内存泄漏: 空间你不用 别人也用不了(借书不还 --> 图书馆空了) 严重会导致服务器/电脑卡顿,崩掉
	路由器重启(内存泄漏, 里面是一个不会休息的程序, )
1. 堆内存泄漏
2. 系统内存泄漏(打开文件/打开管道/打开网络链接忘记关闭) linux打开文件上限是512个(可以改)
如何避免
1. 代码规范
2. 智能指针
3. 公司使用自己的内存管理库
4. 内存泄漏检测工具

*/

// 如何一次在堆上申请4G(8个f)的内存
//void test(){
//	int* pa = (int*)malloc(0xffffffff);//现在这个最大寻址空间是4G(包括内核空间), 可以把当前的程序改成64位的程序 2^64空间
//}

/* 
模板编程: 编写与具体类型无关的通用代码
	提高程序员的幸福感, 减少程序员重复的工作量, 机器自动生成代码, 提高工作效率
	本身并不会减少实际的代码量, 只是代码由机器自动生成
分类:
函数模板: 
		template <class/typename 模板参数1, class/typename 模板参数2, ...>
		返回值 函数名 (参数列表: 可以有模板参数){}
	函数模板不是一个可以执行的函数, 只有经过实例化产生具体类型的函数代码才可以执行
	函数模板实例化:
		1. 隐式实例化: 编译器根据具体参数进行自动推导, 然后根据推导出的具体参数类型生成可执行代码
		2. 显式实例化: 显式指定需要生成的参数类型, 函数名<具体的函数类型>(参数类型)
	匹配规则:
		1. 有完全匹配的普通函数则不走实例化, 
		2. 如果实例化可以产生更加匹配的函数, 则走实例化
		3. 如果显式指定实例化, 则走实例化

类模板:
		template <class/typename 模板参数1, class/typename 模板参数2, ...>
		class 类名(函数参数/成员变量的类型可以为模板参数)
	类模板必须显式实例化
	用类模板实例化后的具体类, 它的类型和类名有区别, 类型: 类名<具体类型, 可以有多个>
*/
void Swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Swap(char * a, char * b){
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void Swap(double * a, double * b){
	double tmp = *a;
	*a = *b;
	*b = tmp;
}


template <typename T>
void Swap(T* a, T* b){
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

template <class T1, class T2>
void Swap(T1* a, T2* b){
	T1 tmp = *a;
	*a = *b;
	*b = tmp;
}

template <class T>
T Add(T a, T b){
	return a + b;
}

struct Node{
	int _a;
	int _b;
	Node()
	{}
	Node(int a, int b)
		:_a(a)
		, _b(b)
	{}
};
void test1(){
	int a = 1, b = 2;
	char c = 'a', d = 'b';
	double e = 2.0, f = 1.0;
	//函数模板的隐式实例化
	Swap(&a, &b);  //Swap(int, int)
	Swap(&c, &d);  //Swap(char, char)
	Swap(&e, &f);  //Swap(double, double)

	Node n1(10, 20);
	Node n2(30, 40);
	Swap(&n1, &n2);  //Swap(Node, Node)

	Swap(&a, (int*)&f);
	//显示实例化: 函数名 + <具体类型> ()
	//Swap<int>(&a, &f);
	Add<int>(a, f);
}

void test2(){
	int a = 1, b = 2;
	char c = 'a', d = 'b';
	double e = 2.0, f = 1.0;
	//非模板函数与模板函数共存，优先调用非模板函数，不进行函数模板的实例化
	//有现成的饭，直接吃
	Swap(&a, &b);  //Swap(int, int)
	Swap(&c, &d);  //Swap(char, char)
	Swap(&e, &f);  //Swap(double, double)

	Node n1(10, 20);
	Node n2(30, 40);
	Swap(&n1, &n2);  //Swap(Node, Node)

	//非模板函数与模板函数共存，非模板函数参数类型不能完全匹配实际的参数类型，
	//模板可以实例化一个完全匹配的函数，则进行函数模板的实例化
	//有现成的饭，但是不和胃口，重新做
	Swap(&a, &f);

	//非模板函数与模板函数共存，但是指定了需要实例化，
	//则无论非模板函数是否匹配，都会进行函数模板的实例化
	//有现成的饭，但是想自己做， 重新做
	Swap<int>(&a, &b);
}

//类模板
template <class T>
struct Node2{
	T _a;
	T _b;
	Node2(){}
	Node2(T a, T b)
		:_a(a)
		, _b(b){}
};

template <class T, class T2, class T3, class T4>
struct Node3{
	T _a;
	T _b;
	Node3(){}
	Node3(T a, T b)
		:_a(a)
		, _b(b){}
};
/*
struct Node2_char
{
	char _a;
	char _b;
	Node2_char(){}
	Node2_char(char a, char b)
		:_a(a)
		, _b(b){}
};
*/

void test3(){
	//类模板的显式实例化，只能进行显式实例化
	Node2<char> node;
	Node2<int> node2;
	Node2<Node> node3;
	//类模板实例化的具体类： 类名和类型不同
	//类型： 类名<具体类型>

	//Node2不是一个具体类型，不能计算大小， Node2只是一个类名
	//cout << sizeof(Node2) << endl;
	cout << sizeof(Node2<int>) << endl;

	Node3<int, double, char, float> node4;
}
int main(){
	//test();

	system("pause");
	return 0;
}
