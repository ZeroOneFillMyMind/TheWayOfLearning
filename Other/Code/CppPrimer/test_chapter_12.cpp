#include <memory>
#include <vector>
#include <string>

using namespace std;

template<typename Foo, typename T>
shared_ptr<Foo> factory(T arg)
{
    // 恰当的处理arg
    // shared_ptr负责释放内存
    return make_shared<Foo>(arg);
}

template<typename Foo, typename T>
void use_factory(T arg)
{
    shared_ptr<Foo> p = factory(arg);

    // 使用p
} // p离开作用域，其指向的内存会被自动释放

template<typename Foo, typename T>
shared_ptr<Foo> use_factory(T arg)
{
    shared_ptr<Foo> p = factory(arg);
    return p; // 返回p时，引用计数递增
} // p离开作用域，但是指向的内存不会被释放

// 上述函数向调用者返回一个p的拷贝

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(std::initializer_list<std::string> il) : data(make_shared<vector<string>>(il)) {}
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}
    void push_back(const std::string &t) {data->push_back(t);}
    void pop_back()
    {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    std::string &front()
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    std::string &back()
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

