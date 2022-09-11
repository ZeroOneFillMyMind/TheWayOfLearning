# 1 常量表达式

原代码：

```cpp
//...

struct Point {
    int x;
    int y;
    int z;

    constexpr Point up(int d) {
        return {x, y, z + d};
    }

    constexpr Point move(int dx, int dy){
        return {x + dx, y + dy, z};
    }
};


constexpr Point origo {0, 0, 0};
constexpr int z = origo.x;
constexpr Point n = origo.move(1,2);

constexpr Point a[] = {origo, Point{1, 1, 1}, Point{2, 2, 2}, origo.move(3, 3)};
// ...
```

编译报错：

```shell
error: passing ‘const Point’ as ‘this’ argument discards qualifiers [-fpermissive]
   22 | constexpr Point a[] = {origo, Point{1, 1, 1}, Point{2, 2, 2}, origo.move(3, 3)};
      |                                                                              ^
test_const.cpp:12:21: note:   in call to ‘constexpr Point Point::move(int, int)’
   12 |     constexpr Point move(int dx, int dy) {
      |                     ^~~~
```

原因：

```
编译器认为成员函数可能会修改被const限定的变量
```

修改方案：

```cpp
// move方法后增加const修饰
constexpr Point move(int dx, int dy) const {
	return {x + dx, y + dy, z};
}
```

在bjarne的《C++程序设计语言》中虽然提到了：

`对成员函数来说，constexpr隐含了const的意思，所以添加const修饰没有必要`，但是实际应用中，编译器可能会报错。



