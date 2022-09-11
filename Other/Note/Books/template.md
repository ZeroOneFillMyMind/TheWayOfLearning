# 模板元编程

## 1 type_traits

traits是模板编程中使用的一种技术。
主要功能：将功能相同而参数不同的函数抽象出来，通过traits将不同参数的相同属性提取出来，在函数中利用这些traits提取的属性，是的函数对不同的参数表象一致。

traits是一种特性萃取技术,它在Generic Programming中被广泛运用,常常被用于使不同的类型可以用于相同的操作,或者针对不同类型提供不同的实现.traits在实现过程中往往需要用到以下三种C++的基本特性: 
enum、typedef、template (partial) specialization 
enum用于将在不同类型间变化的标示统一成一个,它在C++中常常被用于在类中替代define,你可以称enum为类中的define; 
typedef则用于定义你的模板类支持特性的形式,你的模板类必须以某种形式支持某一特性,否则类型萃取器traits将无法正常工作 
template (partial) specialization被用于提供针对特定类型的正确的或更合适的版本.