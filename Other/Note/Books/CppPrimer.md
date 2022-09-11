[toc]

# CppPrimer

## 1 理论

调用函数
return作用：1.返回值；2.将控制权从被调函数转会主调函数。

空形参列表：隐式、显式

lifetime
*名字的作用域是程序文本的一部分，名字在其中可见；
*对象的生命周期是程序执行过程中该对象存在的一段时间。

自动对象：只存于块执行期间的对象。eg.形参

local static object
在程序的执行路径第一次经过对象定义语句时初始化，直至程序终止才被销毁。

函数声明（函数原型function prototype）
函数三要素：返回类型+函数名+形参类型

声明放在头文件是为了保持一致性。

.o的含义是该文件包含对象代码

形参与实参的交互：1、引用传递；2、值传递
指针：拷贝指针的值

顶层const作用于对象本身。
使用实参初始化形参时，会忽略顶层const。即当形参有顶层const时，传给它常量对象或者非常量对象都可以。注意函数签名影响。

可以使用非常量初始化一个底层const对象，反之不行。

C++允许使用字面值初始化常量。

数组
不允许拷贝数组；
使用数组时会将其转换成指针

可将形参携程数组形式。

```
三者等价
void print(const int*);
void print(const int[]);
void print(const int[10]);
```

管理指针形参三种方法：
1、使用标记指定数组长度（类似结束字符'\0'）
2、使用标准库规范，eg. beg != end
3、显式传递数组长度

c++允许将变量定义为数组的引用，因此，形参也可以是数组的引用

```
void print(int (&arr)[10]) // 注意不要写成int &arr[10]
{
    for (auto elem : arr) {
        cout << elem << endl;
    }
}
```

```
int &arr[10]
int (&arr)[10]

int *matrix[10]
int (*matrix)[10]
```

initializer_list 元素全为常量值

为处理不同数量实参的函数，方法：
1、如果所有实参类型相同，传递一个名为initializer_list的标准库类型；
2、如果类型不同，使用可变参数模板。

```
initializer_list<T> lst;
initializer_list<T> lst{a,b,c,...}
lst2(lst);
lst2 = lst;
lst.size()
lst.begin() // 含begin()/end()，所以可以使用for-range循环
lst.end()
```

省略符形参

```
void foo(para_list, ...);
void foo(...);
```

返回一个值的方式和初始化一个变量/形参一样：返回的值用于初始化调用点的一个临时量，该临时量就是函数调用的结果。
如果返回值类型是传值，则函数返回return值的副本或者一个未命名的临时对象。
返回值类型是引用，则是其对象的一个别名。
注意：不要返回局部对象。

列表初始化返回值

函数可以返回花括号包围的值的列表。
列表用于对函数返回的临时量进行初始化。如果列表为空，临时量执行值初始化，反则，返回值由函数的返回类型决定。

cstdlib中两个预处理变量：EXIT_SUCCESS/EXIT_FAILURE

递归：直接或间接调用自身

如果返回值，则创建一个未命名临时对象；如果返回引用，则引用是其别名，不会真正拷贝对象。

使用类型别名：
```
typedef int arrT[10];
using arrT = int[10];
arrT* func(int i);
```

```
int arr[10]; // arr是一个含有10个int变量的数组
int *p[10]; // p是一个含有10个int指针的数组
int (*p2)[10]; // p2是一个指针，指向含有10个int变量的数组
```
如果想要定义一个返回数组指针的函数，则数组的维度必须跟在函数名后。
返回数组指针的函数形式
```
Type (*function(parameter_list))[dimension]
```

尾置返回类型
```
auto func(int i) -> int(*)[10]
```

decltype

iostream file mode
```
in // ifstream/fstream
out // ofstream/fstream
app
ate
trunc // after out mode
binary
```

```
sstream strm;
sstream strm(s);
strm.str(); // return the copy of string
strm.str(s); // input s to strm
```

## 2 实战

### 2.1 建议

* 除非必须，否则不用递增递减运算符的后置版本。也不是绝对，书中还提倡简洁。

### 2.2 交换指针

```
值传递，什么都没做
void swap1(int *p, int *q)
{
    int *tmp = p;
    p = q;
    q = tmp;
}

值传递，解引用，交换指针指向内容
void swap2(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

引用传递
void swap3(int *&p, int *&q)
{
    int *temp = p;
    p = q;
    q = temp;
}
```

### 2.3 返回值+运算符

```
auto sz = shorterString(s1, s2).size();
```

### 2.4 引用返回左值

```
// 该调用是个左值
char &get_val(string &str, string::size_type ix)
{
    return str[ix];
}

int main()
{
    string s("a value");
    cout << s << endl;
    get_val(s, 0) = 'A';
    cout << s << endl;
    
    return 0;
}
```

### 2.3 返回包含n个string对象的数组

```
string (&func())[n]

typedef string arr[10];
arr &func();

auto func() -> string(&)[10]

string str[10];
decltype(str) &func();
```

## 3 课后题

### 6-6

形参、局部变量、局部静态变量的区别：
个人答案：形参和局部变量类似，执行某个函数时创建，函数结束后销毁。局部静态变量在第一次执行时创建，程序终止时销毁。
官方答案：出题思路是需要我们理解局部变量的含义，理解自动对象的创建和销毁机制，弄清楚我们为什么需要局部静态变量，应该如何使用局部静态变量。
形参和定义在函数体内部的变量统称为局部变量，仅在函数作用域内可见。
函数内部局部变量又分为普通局部变量和静态局部变量，其生命周期不同。
形参是一种自动对象，函数开始时为其申请内存空间，使用实参对其初始化。
普通局部变量，生于定义，死于块结束。
局部静态变量，lifetime始于定义，终于程序结束。


### 6-14

与值传递相比，引用传递的优势主要体现在三个方面：
一是可以直接操作引用形参所引的对象；
二是使用引用形参可以避免拷贝大的类类型对象或容器类型对象；
三是使用引用形参可以返回多个值
（总结：直接操作/减少开销/返回多值）


