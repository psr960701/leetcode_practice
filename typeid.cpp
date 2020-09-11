#include<iostream>
#include<typeinfo>
using namespace std;
class A{
    public:
private:
    int a;
};

class B :public A{
public:
    virtual void f(){ cout << "HelloWorld\n"; }
private:
    int b;
};

class C :public B{
public:
    virtual void f(){ cout << "HelloWorld++\n"; }
private:
    int c;
};

class D :public A{
public:
    virtual void f(){ cout << "HelloWorld--\n"; }
private:
    int d;
};
int main()
{
    int a = 2;
    cout << typeid(a).name() << endl;
    A objA;
    //打印出class A  
    cout << typeid(objA).name() << endl;
    B objB;
    //打印出class B  
    cout << typeid(objB).name() << endl;
    C objC;
    //打印出class C  
    cout << typeid(objC).name() << endl;
    
    //以下是多态在VC 6.0编译器不支持，但是在GCC以及微软更高版本的编译器却都是
    //支持的，且是在运行时候来确定类型的，而不是在编译器,会打印出class c
    B *ptrB=new C();
    cout<<typeid(*ptrB).name()<<endl;
    
    A *ptrA=new C();
    //打印出class A而不是class D  因为A没有类方法f啊啊啊
    cout << typeid(*ptrA).name() << endl;
    ptrB->f();
    getchar();
    return 0;
}