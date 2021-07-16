Chapter4 Input and Output with Streams
===

流(Streams)
---

用于输入和输出的流类, ios是其它所有流类的基本类, 其包含了所有流类的共同的属性和能力(方法)

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

C++使用了基于类的标准输入输出系统, 即处理I/O流的类, 均位于iostream库中, 其中基本类ios:  

* 管理通往物理数据流的连接, 其将应用程序的数据写入到某个文件或者输出到屏幕
* 包括了数据格式化的基本函数. (定义了很多flags来决定输入的数据被如何解析来辅助数据格式化)

istream和ostream都源自ios类, 其构建了一个对用户友好的流处理接口. istream用于读取流数据  
ostream用于写数据到流中, 操作符`>>`在istream中定义, 而`<<`在ostream中定义.

iostream 源自对istream和ostream的多重继承, 所以iostream提供了istream和ostream的功能,  
更高级的流类, 比如用于管理文件的类, 其源自以上的类, 但其也包括一些诸如打开和关闭文件的方法  
后面会说到.

标准流
---

cin和cout流分别是istream和ostream的实例, 当一个程序被运行时这些对象会自动被创建  
去读取标准输入或者写数据到标准输出. 标准输入一般是键盘, 标准输出一般是屏幕. 但是,  
标准输入和标准输出也可以被重定向至文件中, 此时数据就不是从键盘而是文件读取, 或者  
数据不是显示在屏幕而是写入至文件.
cerr和clog这两个标准流被用于在程序发生错误是显示错误. 即使标准输出被重定向至文件  
错误信息还是显示在屏幕.

格式化和操纵符(Formatting and Manipulators)
---

例如: 调用一个操纵符

```cpp
Here the manipulator showpos is called.
           ↓
cout << showpos << 123;   // Output:  +123
// The above statement is equivalent to
cout.setf( ios::showpos);
cout << 123;
// The other positive numbers are printed with their sign as well:
cout << 22;               // Output:  +22
// The output of a positive sign can be canceled by the manipulator noshowpos:
cout << noshowpos << 123;  // Output:  123
// The last statement is equivalent to
cout.unsetf( ios::showpos);
cout << 123;
```

tips:

* `>>` 和 `<<` 操作符会根据基础类ios中设置的flags来格式化输入和输出
* showpos 操纵符实际上是一个调用cout.setf(ios::showpos)的函数
* 使用操纵符比直接访问ios中的flags更加简便

格式化(Formatting), 标志(flags)和操纵符(manipulators)
---

当从键盘读取数据时, 必须使用正确的输入格式来解析输入数据. 同样, 输出数据到屏幕  
也遵循相似的规则, 比如如何将浮点数正确的输出到屏幕. istream和ostream类提供了  
多种处理这些问题的选择. iostream类的能力包括:

* `>>` 和 `<<` 操作符用来格式化输入和输出, 二者都是为基本数据类型而定义的(字符, 布尔, 数值和字符串)
* 操纵符(manipulator), 可以插入到输入或者输出流中. 其可以用于为子输入输出流生成格式. 比如  
  经常使用的endl 操纵符, 其可以在行结尾产生一个换行.
* 另外, 格式化标志位定义于父类ios中, 用于决定字符如何输入或者输出, 标志位(flags)由一个特殊整型变量中  
  的每一位表示. 例如: 其中某个位是否为1决定一个正整数输出是是否带'+'号. 可以单独的修改每一个标准位.  
  setf()和unsetf()就是用于此目的. 然而更方便的做法是使用操纵符号(manipulators), 所有重要的标志位  
  都有对应的操纵符号, 操纵符号可以插入到输入或输出流中从而被调用.

整型数的格式化输出
---

格式化输出整型数的操纵符号(manipulators)

| Manipulator | Effects                                      |
| :---------- | :------------------------------------------- |
| oct         | 以八进制输出(Octal base)                     |
| hex         | 以十六进制输出(Hexadecimal base)             |
| dec         | 以十进制输出(Decimal base), 默认以十进制输出 |
|             |
| showpos     | 在非负的整数前加个'+'号再输出(0 --> +0)      |
| noshowpos   | 非负数前不加'+'号, 默认                      |
| uppercase   | 在十六进制输出时使用大写字母                 |
| nouppercase | 在十六进制输出时使用小写, 默认               |

eg:

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int b = -2;
    cout << showpos << a << endl;
    cout << noshowpos;

    int aNumber;
    cout << "Please input an integer: ";
    cin >> aNumber;

    cout << "Octal\tDecimal\tHexadecimal\tHexadecimal upper\n"
    << oct << aNumber << "\t"
    << dec << aNumber << "\t"
    << hex << aNumber << "\t\t"
    << uppercase << hex<< aNumber << "\t\n";

    cout << dec << b << "   " << hex << b << endl;
    return 0;
}
```

浮点型数的格式化输出
---

格式化输出浮点型数的操纵符号(manipulators)

| Manipulator          | Effects                                                                     |
| :------------------- | :-------------------------------------------------------------------------- |
| showpoint            | 浮点数输出时使用小数点分隔, 输出的数字位数和使用的精确度相对应              |
| noshowpoint          | 小数点后面部分的尾部的0将不会被输出, 如果小数点后没有数则小数点不输出(默认) |
|                      |                                                                             |
| fixed                | 使用定点计数法输出浮点数(小数点后的数字位数和精度对应)                      |
| scientific           | 使用科学计数法输出浮点数                                                    |
|                      |                                                                             |
| setprecision (int n) | 设置输出的精度为n位                                                         |

修改输出精度的方法

|                        |                            |
| :--------------------- | :------------------------- |
| int precision(int n);  | Sets the precision to n.   |
| int precision() const; | Return the used precision. |

* tip: `int precision() const;`, 这里的const表示precision()只执行读操作

以域的方式输出(Output in Fields)
---

以域输出的函数

| Method             | Effects                              |
| :----------------- | :----------------------------------- |
| int width() const; | Returns the minimum field width used |
| int width(int n);  | Sets the minimum field width to n    |
| int fill() const;  | Returns the fill character used      |
| int fill(int ch);  | Sets the fill character to ch        |

以域输出的操纵符

| Method          | Effects                                                                   |
| :-------------- | :------------------------------------------------------------------------ |
| setw(int n)     | Sets the minimum field width to n                                         |
| setfill(int ch) | Sets  the fill character to ch                                            |
|                 |                                                                           |
| left            | Left-aligns output in fields                                              |
| right           | Right-aligns output in fields                                             |
| internal        | Left-aligns output of the sign andright-aligns output of the numericvalue |

**注意**: 这些操纵符号`setw(int n)`和方法`int width(int n)`是暂时性的, 只对下一次输出有效;

eg:

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "current default field width: " << cout.width() << endl;
    cout << "aaa" << endl;
    cout.width(8);
    int w = cout.width();
    cout << "AAA" << endl;
    cout << "current field width w: " << w << endl;
    int w2 = cout.width();
    cout << "current field width w2: " << w2 << endl;
    cout.width(2);
    int nw = cout.width();
    cout << "current default field width again?: " << nw << endl;
    cout << "current default field width: " << "5 space ahead of me?" << endl;

    for (int i=0;i<10;i++)
    {
        if (i%2 == 0)
        {
            cout << '|' << setw(10);
        }
        else if (i%2 == 1)
        {
            cout << 'A' << '|';
            cout << endl;
        }
    }

    cout << setfill('*') << setw(30) << '\0' << endl;
    cout << '|' << setfill(' ') << setw(29) << '|' << endl;
    cout.fill('=');
    cout << setw(30) << '\0' << endl;

    cout.width(8); cout.fill('0');
    cout << internal << -123 << endl;
    cout << left << cout.width(8) << 'H' << endl;

}

/*
Output: 
current default field width: 0
aaa
     AAA
current field width w: 8
current field width w2: 0
current default field width again?: 2
current default field width: 5 space ahead of me?
|         A|
|         A|
|         A|
|         A|
|         A|
*****************************
|                            |
=============================
-0000123
00000000H
*/
```

字符, 字符串和布尔值的输出
---

eg:

```cpp

```

page 89