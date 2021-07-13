Chapter3 Using Functions and Classes
===

Functions Declaring
---

```cpp
/*
  function name
       |
long func (int, double);
  |         |      |_______argument type
  |         |________argument type
  |
  function type(type of return value)
*/
```

上面的定义为编译器提供了以下信息:

* func 是该函数的名称
* 该函数被调用时接收两个参数: 第一个是int类型, 第二个是double类型
* 该函数的返回值类型是long

Mathematical standard functions(cmath)

```cpp
double sin (double); // Sine
double cos (double); // Cosine
double tan (double); // Tangent
double atan (double); // Arc tangent
double cosh (double); // Hyperbolic Cosine
double sqrt (double); // Square Root
double pow (double, double); // Power
double exp (double); // Exponential Function
double log (double); // Natural Logarithm
double log10 (double); // Base-ten Logarithm
```

Declaring Functions Details
---

函数有名字和类型, 和变量差不多. 函数的类型即是其返回值的类型(该函数返回给本程序的值)  
函数所需要的参数的类型也是至关重要的. 当一个函数被声明后, 必须给编译器提供以下信息:

* 函数名称和其类型
* 每个参数的类型

* eg:

  ```cpp
  int toLower(int); // @1
  double pow(double, double); // @2
  ```

  上面的函数定义@1告诉编译器函数toLower()的类型是int, 也就是说其返回值类型是int  
  函数定义@2表示pow()类型为double, 当调用其时必须传入两个double类型的参数,  
  参数类型后也可以跟参数名称, **但是这些参数名称仅仅被视为注释**.

* eg:

  ```cpp
  int toLower(int ch); // @1
  double pow(double base, double exponent); // @2
  ```

Function Calls Details
----

* eg: function calls

  ```cpp
    //  Calculating powers with
    //  the standard function pow()
    #include <iostream> // Declaration of cout
    #include <cmath> // Prototype of pow(), thus:
                     // double pow( double, double);
    using namespace std;

    int main() {
      double x = 2.5, y;

    // By means of a prototype, the compiler generates
    // the correct call or an error message!

    // Computes x raised to the power 3:
    y = pow("x", 3.0); // Error! String is not a number
    y = pow(x + 3.0);  // Error! Just one argument
    y = pow(x, 3.0);   // ok!
    y = pow(x, 3);     // ok! The compiler converts the
                     // int value 3 to double.

    cout << "2.5 raised to 3 yields:       "
         << y << endl;

    // Calculating with pow() is possible:
    cout << "2 + (5 raised to the power 2.5) yields: "
         <<  2.0 + pow(5.0, x) << endl;
    return 0; }
  ```

TYPE void FOR FUNCTIONS
---

函数不必有返回值, void 类型的函数就是用于不必有返回值的函数, 在其它的某些编程语言中也叫过程

eg:

```cpp
void srand(usigned int seed);
void printDummyChar(string cs);
```

函数也可以没有参数, 定义没有参数的函数时函数名后的括号保持空状态或者填充一个void关键字( void )

eg:

```cpp
int rand( void );
double offerDouble( void );
```

Head files
---

```cpp
Header file                 Header file
   iostream                   myheader.h
// Declaration of cin, cout   // Declaration of self-defined functions and classes
// ...                       // long myFunc(int);
    |                               |
    |                               |
    |    Source file : app.cpp      | 
    | copy           |              |
    |                |          copy|
    |---->#include <iostream>       | 
          #include "myheader.h" <---|

          int maint() {
            int nu;
            ...
            cin >> nu;
            cout <<  myfunc(nu);
            ...
            return 0;
          }


```

使用头文件

* 头文件是包含声明和宏(macro)的纯文本文件，通过`#include`指令就可以将头文件  
  包含到任何cpp的源文件或者头文件中，使用头文件需要注意一下几点:
  * 头文件需要在源文件的最开头引入
  * 一个头文件一个`#include`指令
  * 头文件名必须使用< ... >尖括号或者双引号包住 " ... "

编译器搜索头文件的规则

* 与编译器一起的头文件一般都放置于`include`文件加下, 在源码中使用 `#include <...>` 引入头文件, 加速文件搜索的速度；  
  另外, 用户自己编写的头文件一般放置于本项目的某目录, 在源码中使用 `#include " ... "` 来引入头文件

  ```cpp
  #include "customizedHead.h"
  #include "project.h"
  ```

标准类(内置类)的定义

* 除了内置的函数定义, 头文件中也包含了标准类定义. 当一个头文件被源文件引入时,  
  其中定义的任何类及其声明的其它对象都可以被但前源文件访问

  ```cpp
  #include <iostream>
  using namespace std;
  ```

  有上面两句指令后, istream和ostream这两个类就可以配合cin和cout流使用了, cin是istream类的一个对象  
  cout是ostream类的一个对象

Standard Header Files
---

Header Files of the C++ standard library

|            |          |         |           |
| ---------- | -------- | ------- | --------- |
| algorithm  | ios      | map     | stack     |
| bitset     | iosfwd   | memory  | stdexcept |
| complex    | iostream | new     | streambuf |
| dequeue    | istream  | numeric | string    |
| exception  | iterator | ostream | typeinfo  |
| fstream    | limits   | queue   | utility   |
| functional | list     | set     | valarray  |
| iomanip    | locale   | sstream | vector    |

Header Files of the C standard library

|          |          |          |          |
| -------- | -------- | -------- | -------- |
| assert.h | limits.h | stdarg.h | time.h   |
| ctype.h  | locale.h | stddef.h | wchar.h  |
| errno.h  | math.h   | stdio.h  | wctype.h |
| float.h  | setjmp.h | stdlib.h |
| iso646.h | signal.h | string.h |

在C++中, 头文件是由'.h'扩展名称所标识, 头文件中包含了所有的声明和定义并存在其自己的命名空间中.  
虽然引入了某个头文件, 但是由于对于源文件来说, 头文件中的命名空间中的标识符是无法直接引用的:  

```cpp
#include <iostream>
```

上面虽然引用了iostream头文件, 但是编译器仍然无法知道cin和cout流. 为了能全局使用std命名空间中  
的标识符, 必须使用一个`using`指令  

```cpp
#include <iostream>
#include <string>
using namespace std;
```

如此, 才能直接使用cin和cout而不必使用(std::cin, std::cout), 上面还引入了string头文件, 这  
使得`string`这个类可以被该源文件使用.  

**注意**: C的标准头文件被C++完全采纳, 所以C的标准库的所有功能在C++中都可以使用

```cpp
#include <math.h>
```

引入math.h后, 数学相关的功能即可使用, 但是在C头文件中声明的标识符是全局可见的, 这在一些大型项目  
中可能会导致名称冲突. 因此, 在C++中对于每个C的头文件都会有一个兄弟, 比如math.h, C++中会有一个  
叫cmath的头文件, 其在std名称空间中声明和name.h一样的标识符, 所以上面的引入等同于:

```cpp
#include <cmath>
using namespace std;
```

string.h或者cstring必须被引入以使用里面的标准函数来操作字符串. 这两个头文件使得引入其的程序可以  
访问C的字符串库, 但是它们和C++的string头文件是不同的, string头文件中定义了string类.  

Using Standard Classes
---

```cpp
#include <iostream> // Declaration of cin, cout
#include <string>   // Declaration of class string
using namespace std;

int main() {
    string tip("Tell me your name: "),
    name,
    line(50, '*'),  // string with 50 *
    greet = "Hey, ";

    cout << tip;
    getline(cin, name);  // get a sring in one line

    greet = greet + name;

    cout << line << endl
         << greet << endl;
    cout << "Good name, your name is " << name.length() << " characters long!" << endl;

    cout << line << endl;

    return 0;
}
```