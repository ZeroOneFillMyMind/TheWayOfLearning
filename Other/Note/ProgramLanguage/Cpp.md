# CPP

## 0 前言

计算机适合记忆工作和固定流程工作。

## 1 运算符

sizeof 关键字，编译时运算符

## 2 template

多实例化点
compiler为template生成特例化版本的场景：

* 任何实例化点
* 任何编译单元的末尾
* 为生成特例化而特别创建的编译单元中

尽量限制template中的上下文依赖

compiler完成依赖性名字的绑定：
模板定义点所处作用域中的名字；
依赖性调用的一个实参的名字空间中的名字

实参依赖查找 Argument-Dependent Lookup
如果一个头文件包含类型定义，则避免再在其中放置完全通用（不受限）的函数模板

明确依赖关系

* 用依赖性类型限定名字
* 声明一个名字指向此类的一个对象
* 用using声明将名字引入作用域

模板定义应尽可能自包含

this限定

## 3 继承/多态/封装

多态和继承用于消除重复代码，创建通用性更强的构件

## 4 type

隐式类型转换中，涉及窄化类型转换和值保护（提升 promotion）

使用{}能防止窄化计算的发生。

```cpp
narrow_cast<T>()
```

```cpp
// <limits>
FLT_MAX
DBL_MAX
```

任何指向对象类型的指针都能隐式转化成void*
指向派生类的指针（或引用）能隐式转换成指向其可访问且明确无二义的积累指针（或引用）
指向函数的指针或指向成员的指针不能隐式转换成void*
求值结果为0的常量表达式能隐式转换成任意指针类型的空指针，最好使用nullptr
T*可以隐式转换为const T\*
T&可以隐式转换为const T&
指针、整数、浮点数可以隐式转换为bool

常量 constexpr/const, 为值提供符号化的名字，避免magic number
const也可用于非常量表达式初始化，但是此时该const不能用作床两表达式？？？？
优先使用constexpr

枚举值也可替代const

含有constexpr的构造函数（须足够简单）的类称为字面值常量类型。
c++编译时求值被严格限定为只能使用整数值

全局变量等静态分配的对象的地址是一个常量（linker进行赋值）

{}列表作用

* 初始化命名变量
* 限定为某种类型，T{...}
* 未限定的{...}，其类型根据上下文确定

{}列表不可修改，只能拷贝而不能移动

无法通过推断未限定列表的类型使其作为普通模板的实参
当容器的元素类型是模板时，无法推断

using T{} rather than T()

类型转换

```cpp
const_cast // 仅在const修饰符和volatile修饰符上有所区别
static_cast // 关联类型之间的转换
reinterpret_cast // 非关联类型之间
dynamic_cast // 指针或引用向类层次体系的类型转换，并执行运行时检查
```

```cpp
template<class target, class source>
target narrow_cast(source v)
{
    auto r = static_cast<target>(v);
    if (static_cast<source>(r) != v) {
        throw runtime_error("failed");
    }

    return r;
}
```

字面值、常量以及需要执行类型转换的参数可以被传递给const T&参数，但是不能传给普通的非const T&参数。
引用传递：左值引用传递，函数不能接受一个右值引用作为它的参数

右值引用模板参数：“完美转发”

使用未限定类型参数时，应优先考虑使用重载函数，带默认参数的函数

匹配顺序
【1】精确匹配
【2】提升后匹配
【3】标准类型转换后匹配
【4】用户自定义类型转换后匹配
【5】函数声明中的省略号匹配

## 5 memory

拷贝一个以'\0'结尾的字符串的最有效方式：使用标准的c风格字符串拷贝函数

```cpp
char *strcpy(char *, const char *);
```

一般的拷贝任务：标准库copy算法

自由存储（堆/动态内存）
命名对象的生命周期由作用域决定
若期望函数返回后仍能使用创建的对象，使用new/delete

若某一类型含默认构造函数，则可省略初始化器

```cpp
auto pc = new complex<double>;
auto pi = new int;
```

对nullptr执行delete无实际效果

自由存储问题

* 对象泄露 可能会导致资源耗尽
* 提前释放 已删对象不再有效，可能已存放其他对象
* 重复释放 资源管理器童虫无法追踪资源所有者，导致未定义行为

针对上述问题，建议：有限使用作用域内变量，而非自由存储对象；在自由存储上构建对象时，把指针放在一个管理器对象中，此类对象通常含有析构函数。

vector的元素位于自由存储上，资源分配/释放都限定在内部进行

智能指针
unique_ptr/shared_ptr

尽量确保没有裸new

vector本身就是一个对象，可通过new/delete管理vector

切忌不要用new创建局部对象，风险大且低效

分配/释放函数负责处理五类型且未初始化的内存，而非类型明确的对象

new发现无内存空间分配时，会报bad_alloc异常

```cpp
void* operator new(size_t, void *p) {return p;}
void *buf = reinterpret_cast<void *>(0xF00F);
X* p2 = new(buf) X;

// nothrow版本 new/delete 异常情况下返回nullptr
int *p = new(nothrow) int[n];
operator delete(nothrow, p);
```

## 6 lambda

匿名函数

由lambda生成的类型的对象：closure object

替代：局部类

命名lambda

foreach + lambda

```cpp
template<class C>
void print_module(const C &v, ostream &os, int m)
{
    bfs(begin(v), end(v), [&os, m](int x){if (x % m == 0) os << x << '\n';});
}
```

lambda的生命周期可能超过调用者（eg. 将lambda传递给另一个线程或者被调用者把lambda存在别处以供后续使用）
当需要将lambda传递给其他线程时，使用值捕获更合适。

最简形式：[]{}

闭包类型：函数对象的类型
lambda：局部类类型，含有一个构造函数以及一个const成员函数operator()()
除了能作为参数，还能用于初始化一个声明为auto或者std::function<R(AL)>的变量

## 7 function

若调用函数代价较高，考虑采用inline

声明

* 函数名
* 参数列表
* 返回类型
* inline
* constexpr
* noexcept
* 链接说明，eg. static
* [[noreturn]]

成员函数限定

* virtual
* override
* final
* static
* const

返回类型：前置/后置

inline
One-Definition Rule

[[noreturn]]
[[...]]：属性，描述位于它前面的语法实体的性质（依赖于实现），也可置于语句开始的位置

C++标准属性：[[no return]] / [[carries_dependency]]

不能递归含静态变量初始化的函数

```cpp
void f(int(&r)[4]); // 形参为4元素数组，一般在模板中使用，数组引用

template<class T, class N>
void f(T(&r)[N]);
```

**重载解析过程中不考虑函数的返回类型，否则，依赖上下文而无法独立进行。**

匹配需要关注作用域。

要么匹配，要么二义性报错。

函数指针
解引用函数指针时，可以用*，也可以不用。
获取函数地址时，可用&，也可不。

函数指针必须反映出函数的链接信息
链接说明和noexcept都不能出现在类型别名中。

## 8 特殊参数

```cpp
## 拼接
#参数 变量字符串化
#@参数 转换为单字符

宏的参数列表可以为空
```

## 9 exception

处理异常的时候不要抛出异常。
不抛出无法处理的异常。

terminate()
std::set_terminate()

## 10 class

引用类的一个成员,在类名后接::

```cpp
int (S::*) pmf() {&S::f};
```

static成员，是类的一部分，但不是某个类对象的一部分。只有共同的一个副本。

## 10 XXX
