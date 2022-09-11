# Boost

## 1 常见问题

在校生：
* vector or map 的内部实现、各种操作的复杂度，以及迭代器失效的可能场景。

有经验的程序员：
* shared_ptr的线程安全性、循环引用的后果及如何避免、weak_ptr的作用。
* 线程安全的引用计数，如果定制删除动作等

## 2 相关库

绝对无害的库
* noncopyable/scoped_ptr/static_assert

自己实现
* date_time/circular_buffer等

## 3 经验

进行消息传递和资源管理可以考虑采用更加现代的方式，比如某些情况下使用function/bind代替虚函数作为库的回调接口、借助shared_ptr实现线程安全的对象回调。

immutable数据和mutable数据，前者可以安全的跨线程共享，后者不行。

大佬名言：
如果程序员的工作就是摆弄参数去调用现成的库，而程序员不知道这些库是如何实现的，那么这份职业就没有任何乐趣可言。 From Donald Knuth

## 4 相关术语

### 4.1 泛型编程

concept
model
refinement

## 5 导读

STL是c++标准库中一个很大的子集

文件名后缀hpp = .h + .cpp

