Chapter4 Input and Output with Streams
===

```cpp
      ios   // base class of all other stream classe
      /  \
     /    \
    /      \
istream  ostream
    \      /
     \    /
      \  /
    iostream
```

there are four standard streams

* cin : istream 类的实例对象, 用于控制标准输入
* cout : ostream 类的实例对象, 用于控制标准输出
* cerr : ostream 类的实例对象, 用于控制无缓冲的错误输出(unbuffered error)
* clog : ostream 类的实例对象, 用于控制有缓冲的错误输出(buffered error)

I/O Stream Classes
---

Page 80