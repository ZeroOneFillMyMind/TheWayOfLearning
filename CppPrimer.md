# CppPrimer
## 1 迭代器

## 1.1 输入迭代器
只读不写，单遍扫描，只能递增

支持：
1、比较(!=, ==)
2、递增(++)
3、解引用运算符(*)
4、箭头运算符(->)

eg. find / accumulate

## 1.2 输出迭代器
只写不读，单遍扫描，只能递增

支持：
1、递增(++)
2、解引用(*)

eg. copy的三参

## 1.3 前向迭代器
可读写，多遍扫描，只能递增

支持：
1、输入迭代器和输出迭代器的操作
2、多次读写同一元素

eg. replace

## 1.4 双向迭代器
可读写，多遍扫描，可递增递减

支持：
1、前向迭代器操作
2、递减(--)

eg. reverse

## 1.5 随机访问迭代器
可读写，多遍扫描，支持全部迭代器运算

支持：
1、双向迭代器操作
2、比较(<, <=, >, >=)
3、迭代器和一个整数值的加减运算(+, +=, -, -=)
4、迭代器间减法(-)
5、下标运算(iter[n])

eg. sort, array/deque/string/vector的迭代器，内置数组

# 2 算法命名

传递谓词
_if
_copy

# 3 关联容器

## 3.1 common
key_type 容器的关键字
mapped_type 关联字关联的类型，仅适用于map
value_type 对于set, value_type == key_type; 对于map, value_type == pair<const key_type, mapped_type>

erase操作
c.erase(k);
c.erase(it);
c.erase(b, e);

## 3.2 map
添加新元素
```
m.insert({word, 1});
m.insert(make_pair(word, 1)); // <utility>
m.insert(pair<string, size_t>(word, 1));
m.insert(map<string, size_t>::value_type(word, 1));
```

访问
```
c[k]
c.at(k)
```

通常情况下，解引用一个迭代器所返回的类型与下标运算符返回的类型一致，但是，对于map来说，执行下标操作，会获得一个mapped_type对象，而解引用一个map迭代器时，得到value_type对象。
map下标运算返回左值


## 3.3 查找
```
lower_bound / upper_bound 不适用于无序容器
下标 / at 适用于非const的map和unordered_map
c.find(k)
c.count(k)
c.lower_bound(k)
c.upper_bound(k)
c.equal_range(k)
```

multimap的find操作：
在multimap中，同一个键关联的元素必然相邻存放
所以可以通过count/find操作, 以及++iter操作一次访问

lower_bound如果查找的关键字不存在，则返回尾后迭代器
upper_bound如果查找的关键字是最大的，则返回尾后迭代器

```
for (auto beg = authors.lower_bound(search_item), end = authors.upper_bound(search_item); beg != end; ++beg) {
    cout << beg->second << endl;
}
```

## 3.4 注意事项
通常不对关联容器使用泛型算法；

## 3.n question
1、emplace和emplace_hint的区别?

# 4 智能指针

## 4.1 分类
shared_ptr 允许多个指针指向同一对象
unique_ptr 独占所指向对象
weak_ptr 弱引用，指向shared_ptr所管理的对象

```cpp
// 共有操作
shared_ptr<T> sp;
unique_ptr<T> up;

p
*p
p->mem
p.get()

swap(p, q);
p.swap(q);

// shared_ptr独有操作
make_shared<T>(args); // <memory>

shared_ptr<T>p(q);

p = q;
p.unique();
p.use_count();

// unique_ptr
make_unique<T> p; // C++14

```

## 4.2 shared_ptr

当进行拷贝或者赋值操作时，每个shared_ptr会记录有多少shared_ptr指向同一对象。（引用计数器，变为0时释放对象）
引用计数器减少(析构)：被赋新值或者shared_ptr被销毁

程序使用动态内存的原因：
1、程序不知道自己需要使用多少对象;
2、程序不知道所需对象的准确类型;
3、程序需要在多个对象中共享数据;


