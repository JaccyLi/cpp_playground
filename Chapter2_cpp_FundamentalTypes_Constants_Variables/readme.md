Fundamental types
===

| comments       | type        |
| :------------- | :---------- |
| Boolean values | bool        |
| Characters     | char        |
| Characters     | wchar_t     |
| Integers       | short       |
| Integers       | int         |
| Integers       | long        |
| Floating-point | float       |
| Floating-point | double      |
| Floating-point | long double |

Type bool
---

* 1 --> true
* 0 --> false

Type char and wchar_t
---

| type    | data       | size                                                    |
| :------ | :--------- | :------------------------------------------------------ |
| char    | ASCII code | 8 bits, control chars(0-31) and printable chars(32-127) |
| wchar_t | Unicode    | at least 2bytes(16bits), approximately 35000 chars      |

Types Integral
---

| Type           | Size        | Range of values            |
| :------------- | :---------- | :------------------------- |
| char           | 1byte       | -128 -- +127 or 0 -- 255   |
| unsigned char  | 1byte       | 0 -- 255                   |
| signed char    | 1byte       | -128 -- +127               |
| int            | 2byte resp. | -32768 -- +32767           |
| int            | 4byte       | -2147483648 -- +2147483647 |
| unsigned int   | 2byte resp. | 0 -- 65535                 |
| unsigned int   | 4byte       | 0 -- 4294967295            |
| short          | 2byte       | -32768 -- +32767           |
| unsigned short | 2byte       | 0 -- 65535                 |
| long           | 4byte       | -2147483648 -- +2147483648 |
| unsigned long  | 4byte       | 0 -- 4294967295            |

* 16bit computers --> int is equivalent to short
* 32bit computers --> int will be equivalent to long
* c++ treat char and wchar_t like normal integers, so char and wchar_t can perform calculate
* wchart_t is normally defined as unsigned short
* int type is normally interpreted as signed, also char type
* "unsigned int" cant be abbreviated as keyword "unsigned"
* type size: char <= short <= int <= long

Types Floating-point
---

| Type        | Size    | Range of values | Lowest Positive value | Accuracy(decimal) |
| ----------- | ------- | --------------- | --------------------- | ----------------- |
| float       | 4bytes  | -3.4e+38        | 1.2e-38               | 6digits           |
| double      | 8bytes  | -1.7e+308       | 2.3e-308              | 15digits          |
| long double | 10bytes | -1.1E+4932      | 3.4e-4932             | 19digits          |

The sizeof Operator
---

* sizeof: give the amount of memory needed to store an object(bytes)
* usage: sizeof(name)
* eg:

```cpp
  sizeof(int); // will be 2 or 4 depending on the machine
  sizeof(float); // will alwalys equal 4
  int a; 
  sizeof(a) // will be 2 or 4 depending on the machine
  ```

Types classification
---

* fundamental types in cpp are:
  * integer types(arithmetic types)
  * floating-point types(arithmetic types)
  * and the void type(expressions that do not represent a value, eg: a function call)

Constants
---

* 字符串和其他的基本数据类型都可以使用cout输出, int类型默认以十进制输出

* Boolean Constants
  boolean expression can have two values that are identified by the keywords true and
  false. Both constants are of the bool type. They can be used, for example, to set flags
  representing just two states

* Integral Constants
  * decimal constant(0 is not included)
  * octal constant(with a leading 0, eg: 075, 032123)
  * hexadecimal constant(with a 0x or 0X, eg:0xabc123, 0XEEAB123)
  * integral constants are usually type int, we can specify the constant's type by adding
    letter L or l(long), U or u(unsigned), eg:

```cpp
    12L, 12l // type long
    12U, 12u // type unsigned int
    12UL, 12ul // type unsigned long
```

* Examples for integral constants
  | Decimal    | Octal        | Hexdecimal | Type                           |
  | ---------- | ------------ | ---------- | ------------------------------ |
  | 16         | 020          | 0x10       | int                            |
  | 255        | 0377         | 0xff       | int                            |
  | 32767      | 077777       | 0x7FFFF    | int                            |
  | 100000     | 0303240      | 0x186A0    | int(32bit-CPU)/long(16bit-CPU) |
  | 10L        | 012L         | 0xAL       | long                           |
  | 32768U     | 0100000U     | 0x8000U    | unsigned int                   |
  | 27UL       | 033UL        | 1bUL       | unsigned long                  |
  | 2147483648 | 020000000000 | 0x80000000 | unsigned long                  |

* Floating-Point Constants
  * 必须使用小数点或者E(e)来将浮点数和整型数区分开

  | 1         | 2      | 3      | 4       |
  | --------- | ------ | ------ | ------- |
  | 5.19      | 12.    | 0.75   | 0.00004 |
  | 0.519E1   | 12.0   | .75    | 0.4e-4  |
  | 0.0519e2  | .12E+2 | 7.5e-1 | .4E-4   |
  | 519. OE-2 | 12e0   | 75E-2  | 4E-5    |

* Character Constants
  * 字符常量由单引号和一个字符组成

  | Constant | Character                  | Constant Value |
  | -------- | -------------------------- | -------------- |
  | 'A'      | Capital A                  | 65             |
  | 'a'      | Lowercase a                | 97             |
  | ' '      | Blank                      | 32             |
  | '.'      | Dot                        | 46             |
  | '0'      | Digit 0                    | 48             |
  | '\0'     | Terminating null character | 0              |

* String Constants
  * 字符串常量由多个字符组成，被双引号包围
  * 字符串保存时不包括双引号，但是由一个null字符('\0')标志着字符串的结束，'\0'所在的字节所有bit都置为0(也即数值为0)
  * 字符串存储时内存中由于多了null字符，所以会多占用1字节内存空间
  * String literal: "Hello!"
  * stored bytes sequence: 'H' 'e' 'l' 'l' 'o' '!' '\0'

Escape Sequences
---

| Single Char | Meaning                        | ASCII code      |
| ----------- | ------------------------------ | --------------- |
| \a          | alert(BEL)                     | 7               |
| \b          | backspzce(BS)                  | 8               |
| \t          | horizontal tab(HT)             | 9               |
| \n          | line feed(LF)                  | 10              |
| \v          | vertical tab(VT)               | 11              |
| \f          | form feed(FF)                  | 12              |
| \r          | carriage return(CR)            | 13              |
| \\"         | "(double quote)                | 34              |
| \\'         | '(single quote)                | 39              |
| \\?         | ?(question mark)               | 63              |
| \\\         | \ (backslash)                  | 92              |
| \0          | string terminating character   | 0               |
| \ooo        | numerical value of a character | ooo(octal!)     |
| \xhh        | numerical value of a character | hh(hexadecimal) |

Keywords in c++
---

|           |          |                  |             |              |
| --------- | -------- | ---------------- | ----------- | ------------ |
| asm       | do       | inline           | short       | typeid       |
| do        | auto     | double           | bool        | dynamic_cast |
| break     | case     | else             | catch       | enum         |
| char      | explicit | class            | extern      | while        |
| const     | false    | const_cast       | float       | continue     |
| for       | default  | friend           | delete      | goto         |
| if        | inline   | int              | long        | mutable      |
| namespace | new      | operator         | private     | protected    |
| public    | register | reinterpret_cast | return      | short        |
| signed    | sizeof   | static           | static_cast | struct       |
| switch    | template | this             | throw       | true         |
| try       | typedef  | typeid           | typename    | union        |
| unsigned  | using    | virtual          | void        | volatile     |
| wchar_t   |          |

标识符
---

* 标识符示例
  Valid：
  a, CHINA, china, VOID, _var, GetNumber, C919, top_of_mountain, a_short_variable_with_number222333222
  Invalid:
  goto, 8086_cpu, dashed-var, CHINA￥

* 标识符规则
  * 标识符可以包含字母, 数字或者下划线(_), 大小写敏感
  * 第一个字符必须是字母或者下划线
  * 标识符没有长度限制
  * c++关键字保留, 不允许作为标识符

* 标识符应当和其作用相关, 并清晰易懂
  * c, ch --> 字符
  * i, j, k, l, m, n --> 整形数
  * x, y, z --> 浮点型数

Define a Variables in C++
---

变量在使用前必须被定义, 当定义一个变量时需要指定type, 一定数量的内存  
会根据type被预留给该变量, 内存的地址通过引用该变量名得到.  

* Syntax:

  ```cpp
  type name1 [, name2, ...];

  eg:
  char c;
  int i, j, k, counter;
  float x, y, area;
  string helloStr;
  ```

Initialize a Variable in C++
---

变量可以在定义时初始化, 即在定义时给其赋值, 通过一个'='或者()给一个变量赋值  

* 一个'=' 后紧接着该变量的值
* 在变量名后紧跟(), 将值写在()中

  ```cpp
  char c = 'A';
  char a('C');
  float y = 3.14159;
  float y(3.14159);
  ```

* Any global variables not explicitly initialized default to zero.  
  In contrast, the initial value for any local variables that you  fail to initialize will have an undefined initial value.

The Keywords const And volatile
---

* Constant Objects
  const 关键字用于创建"只读"的对象. 只读的对象没法被再次更改并且在定义时必须被初始化  
  如:

  ```cpp
  const double pi = 3.1415926;
  ```

* Volatile Objects
  volatile 关键字很少被使用到, 其创建一个变量不仅仅可以被本程序更改, 还可以被  
  其它程序或者外部时间更改(如硬件时钟的中断事件), 如:

  ```cpp
  volatile unsigned long clock_ticks;
  ```

  即使程序自身并没有更改volatile关键字定义的变量, 编译器还是会认为它在上次被访问后已经改变,  
  因此, 编译器会创建机器码去读取该变量无论该变量何时被访问, 而不是使用一个在某段时间读取的值,  

* 也可以将const和volatile用在一起

  如:

  ```C
  volatile const unsigned time_to_live;
  ```

  这种情况则说明time_to_live这个变量不能被本程序更改, 但是可以被外部事件更改
