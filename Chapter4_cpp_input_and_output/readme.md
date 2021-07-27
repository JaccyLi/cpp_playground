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

可以将字符存储在char或者int类型中, 使用cout输出时输出字符或者对应的ascii值  
操纵符号来使其输出为字母(true/false)而不是1和0. 需要注意的是对于ascii码和  
int来说, 定义的类型决定输出时是显示char还是int.

eg:

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // output char
    int char1 = '0';  // 输出时显示int值
    char char2 = 'A'; // 输出时显示char本身
    char char3 = 97;  // 输出时显示a

    cout <<"the ascii value: " << char1 << " is char '0'" << endl;
    cout << "char2 is: " << char2 << endl;
    cout << "char3 is: " << char3 << endl;

    // output boolean
    bool isShe = true;
    bool imJack = true;
    bool doorOpen = 0;
    cout << "Is she? " << isShe  << endl;
    cout << "I'm Jack? " << boolalpha << imJack  << endl;
    cout << "Door is Open? " << doorOpen << endl;

    // output string
    string s("Summer is Over ");
    cout << left
         << setfill('?')
         << setw(30) << s << endl;
    cout << right 
         << setfill('?')
         << setw(30) << s << endl;
}
```

格式化输入
---

使用cin.sync()来清除某次输入后的输入缓冲, 使用cin.clear()函数可以重置  
任何在输入中置位的错误标志位, 即使下面例子中输入的字符数量超过16, 程序也会  
等待接下来的输入.

eg:

```cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <ios>
#include <limits>

using namespace std;

// FileName:          cpp_input_formatting.cpp
// Date:              2021-07-19
// 

int main()
{
    float x, y = 3.14;
    string title; 

    cout << "input a title: ";
    cin.width(16);
    cin >> title;
    cin.sync();
    cin.clear();

    cout << "input a float: ";
    cin >> x;
    cout <<"title: " << title << endl;
    cout << fixed << setprecision(2) << x << endl;

    return 0;
}
```

如上面的例子中`cin.width(16)`在输入字符串时可以指定宽度, 即可以输入的最大字符数  

使用`>>`操作符时也可以指定输入的数以十进制、八进制或者十六进制来解析输入的数字  

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
  int a;
  cout << "input a(hex): ";
  cin >> hex >> a;
  cout << "a is: " <<  a <<endl;
  
  cin.sync();
  cin.clear();
  
  int b;
  cout << "input b(oct): ";
  cin >> oct >> b;
  cout << "b is: " <<  b << endl;
}

/* Input one:
input a(hex): 0xF1
a is: 241
input b(oct): 021
b is: 17
*/

/* Input two:
input a(hex): f1
a is: 241
input b(oct): 23
b is: 19
*/

/* Input three:
input a(hex): 0xg
a is: 0
input b(oct): 9
b is: 0
*/
```

输入域(输入时cin认为空格或者tab隔开的内容是不同的域)
---

在使用cin和`>>`操作符接受输入流时, 该操作符会默认读取下一个域(上个输入后的tab,space,return会被忽略),  
并且会尝试将输入转化为所提供的变量的类型, 再将接受到的数据写入到变量. 输入域会被第一个空格或者第一个无法  
处理的字符所终结, 此时读取的就是一个输入域. 当遇到无法处理的字符时, 当前的域读取结束了, 接下来的cin会读取  
后面的域(后面的域仍然留在输入缓冲区中等待读取).

eg: 输入字符

```cpp
char a,b,c;
cin >> a;
cout << a << endl;

cin.sync();
cin.clear();

cin >> b;
cout << b << endl;

cin.sync();
cin.clear();

cin >> c;
cout << c << endl;
/* input 1:
    j
j
  a
a
c
c
*/

/* input 2:
jack
j
a
c
*/

/* input 3:
j
j
a
a
c
c
*/

/* input 4:
j     a       ck
j
a
c
*/
```

eg: 输入数值

```cpp
int i;
cin >> i;
cout << i << endl;

cin.sync();

string remain;
cin >> remain;
cout << remain << endl;

/*input 1:
123jack
123
jack
*/

/*input 2:
   123	jack
123
jack
*/

/*input 3: 正确输入
123
123
jack
jack
*/
```

eg: 输入字符串

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

// FileName:          Chapter4_cpp_input_and_output/cpp_input_strings.cpp
// Date:              2021-07-22
// 

int main()
{
    string s;
    cout << "input a str: ";
    cin >> s;
    cout << "str is: " << s << endl;
}

/*input 1:
input a str: jack is jack
str is: jack
*/

/*input 2:
input a str: jackisajack
str is: jackisajack
*/
```

eg: 如果一个cin接受数据遇到空格,tab或者return等无法处理的字符时视为本次接受的域结束,  
    后一个cin会读取接下来留在输入缓冲区的数据

```cpp
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
using namespace std;

int main()
{
  int age;
  cout << "What is your age? ";
  cin >> setw(8) >> age;
  std::cout << "Hello, you are " << age << " years old!\n";
  
  cin.sync();
  cin.clear();
  
  string remain;
  cout << "input remain: ";
  cin >> remain;
  cout << "remain is: " << remain << endl;
}
/* input 1:
What is your age? 18
Hello, you are 18 years old!
input remain: jack
remain is: jack
*/

/* input 2:
What is your age? 18jack
Hello, you are 18 years old!
input remain: remain is: jack    // don't let input remain
*/

/* input 3:
What is your age?    18   jack      // blanks are ignored
Hello, you are 18 years old!
input remain: remain is: jack
*/
```

输入整型数
---

可以使用hex, oct and dec来指定输入的字符串按照hexadecimal, octal or decimal来处理

eg: 下面输入21(被认为是8进制), 会被解析为十进制的17

```cpp
int n;
cin >> oct >> n;
cout << n;
```

eg: 下面输入21(被认为是16进制), 会被解析为十进制的33

```cpp
int n;
cin >> hex >> n;
cout << n;
```

输入浮点数
---

当存储输入的变量是浮点型时(floaat, double, long double), `>>` 操作符会将任何输入解析为浮点类型  
浮点数可以使用定点表示法或者指数计数法输入

eg: 此时输入如123, 0.23, -2.33或者2e3都是合法的  

```cpp
double x;
cin >> x;
```

Unformatted input
---

eg:

```cpp
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// FileName:          Chapter4_cpp_input_and_output/cpp_unformatted_input.cpp
// Date:              2021-07-22
// 

string header("--- Demo for Unformatted Input ---");

int main()
{
    string prefix, remain;

    cout << header
         << "\n\nPress <return> to continue\n"; 

    cin.get();

    cout << "\nPlease enter a sentence with several words!"
         << "\nEnd with <!> and <return>."
         << endl;

    cin >> prefix;                // Read the first word
    getline( cin, remain, '!');   // and the remaining text
                                  // up to the character !

    cout << "\nThe first word:   " << prefix 
         << "\nRemaining text: " << remain << endl;

    return 0;
}
```

在上面的例子中, 使用了两个函数1: `cin.get()`和2: `getline()`, 1在不传入参数时表示  
读取标准输入的一个字符但是不保存, 当其指定一个char类型的变量作为其参数时, 表示从标准输  
入流中读取下一个字符, 并存在char类型的变量中. 另外, 还有个函数`cout.put()`表示输出单  
个字符, eg:

```cpp
char ch1;
cin.get(ch1);

char ch2 = 'A';
cout.put(ch2);  // cout << ch2;
```

而`getline()`则是用来读取一行数据, eg:

```cpp
string line;
getline(std::cin, line);
```

其会从标准输入读取一整行数据(知道回车键按下), 存储在string类型的line变量中, 也可以指定非  
回车键为接收结束的标志, 给getline()指定第三个char类型的参数即可. eg:

```cpp
string line;
getline(std::cin, line, '.');
```

上面的例子中, '.' 不会被存储在line中, '.'后面的内存都会被存在输入缓冲区中, 如果后续有  
读取操作, cin 将会接收到'.'后面的内容:

```cpp
    string line, remain;
    getline(cin, line, '.');
    cin >> remain;

    cout << "line: " << line << endl;
    cout << "remain: " << remain << endl;

//Input:
// jack is a good man. and this is the remain

// Output:
/*
line: jack is a good man
remain: and
*/
```
