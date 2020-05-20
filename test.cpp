#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

/*
�ڴ�й©: �ռ��㲻�� ����Ҳ�ò���(���鲻�� --> ͼ��ݿ���) ���ػᵼ�·�����/���Կ���,����
	·��������(�ڴ�й©, ������һ��������Ϣ�ĳ���, )
1. ���ڴ�й©
2. ϵͳ�ڴ�й©(���ļ�/�򿪹ܵ�/�������������ǹر�) linux���ļ�������512��(���Ը�)
��α���
1. ����淶
2. ����ָ��
3. ��˾ʹ���Լ����ڴ�����
4. �ڴ�й©��⹤��

*/

// ���һ���ڶ�������4G(8��f)���ڴ�
//void test(){
//	int* pa = (int*)malloc(0xffffffff);//����������Ѱַ�ռ���4G(�����ں˿ռ�), ���԰ѵ�ǰ�ĳ���ĳ�64λ�ĳ��� 2^64�ռ�
//}

/* 
ģ����: ��д����������޹ص�ͨ�ô���
	��߳���Ա���Ҹ���, ���ٳ���Ա�ظ��Ĺ�����, �����Զ����ɴ���, ��߹���Ч��
	�����������ʵ�ʵĴ�����, ֻ�Ǵ����ɻ����Զ�����
����:
����ģ��: 
		template <class/typename ģ�����1, class/typename ģ�����2, ...>
		����ֵ ������ (�����б�: ������ģ�����){}
	����ģ�岻��һ������ִ�еĺ���, ֻ�о���ʵ���������������͵ĺ�������ſ���ִ��
	����ģ��ʵ����:
		1. ��ʽʵ����: ���������ݾ�����������Զ��Ƶ�, Ȼ������Ƶ����ľ�������������ɿ�ִ�д���
		2. ��ʽʵ����: ��ʽָ����Ҫ���ɵĲ�������, ������<����ĺ�������>(��������)
	ƥ�����:
		1. ����ȫƥ�����ͨ��������ʵ����, 
		2. ���ʵ�������Բ�������ƥ��ĺ���, ����ʵ����
		3. �����ʽָ��ʵ����, ����ʵ����

��ģ��:
		template <class/typename ģ�����1, class/typename ģ�����2, ...>
		class ����(��������/��Ա���������Ϳ���Ϊģ�����)
	��ģ�������ʽʵ����
	����ģ��ʵ������ľ�����, �������ͺ�����������, ����: ����<��������, �����ж��>
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
	//����ģ�����ʽʵ����
	Swap(&a, &b);  //Swap(int, int)
	Swap(&c, &d);  //Swap(char, char)
	Swap(&e, &f);  //Swap(double, double)

	Node n1(10, 20);
	Node n2(30, 40);
	Swap(&n1, &n2);  //Swap(Node, Node)

	Swap(&a, (int*)&f);
	//��ʾʵ����: ������ + <��������> ()
	//Swap<int>(&a, &f);
	Add<int>(a, f);
}

void test2(){
	int a = 1, b = 2;
	char c = 'a', d = 'b';
	double e = 2.0, f = 1.0;
	//��ģ�庯����ģ�庯�����棬���ȵ��÷�ģ�庯���������к���ģ���ʵ����
	//���ֳɵķ���ֱ�ӳ�
	Swap(&a, &b);  //Swap(int, int)
	Swap(&c, &d);  //Swap(char, char)
	Swap(&e, &f);  //Swap(double, double)

	Node n1(10, 20);
	Node n2(30, 40);
	Swap(&n1, &n2);  //Swap(Node, Node)

	//��ģ�庯����ģ�庯�����棬��ģ�庯���������Ͳ�����ȫƥ��ʵ�ʵĲ������ͣ�
	//ģ�����ʵ����һ����ȫƥ��ĺ���������к���ģ���ʵ����
	//���ֳɵķ������ǲ���θ�ڣ�������
	Swap(&a, &f);

	//��ģ�庯����ģ�庯�����棬����ָ������Ҫʵ������
	//�����۷�ģ�庯���Ƿ�ƥ�䣬������к���ģ���ʵ����
	//���ֳɵķ����������Լ����� ������
	Swap<int>(&a, &b);
}

//��ģ��
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
	//��ģ�����ʽʵ������ֻ�ܽ�����ʽʵ����
	Node2<char> node;
	Node2<int> node2;
	Node2<Node> node3;
	//��ģ��ʵ�����ľ����ࣺ ���������Ͳ�ͬ
	//���ͣ� ����<��������>

	//Node2����һ���������ͣ����ܼ����С�� Node2ֻ��һ������
	//cout << sizeof(Node2) << endl;
	cout << sizeof(Node2<int>) << endl;

	Node3<int, double, char, float> node4;
}
int main(){
	//test();

	system("pause");
	return 0;
}
