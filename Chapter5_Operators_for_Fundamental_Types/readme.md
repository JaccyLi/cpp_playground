Chapter5 Operators for Fundamental Types
===

二元运算符与操作数(Binary operator and operands)
---

```cpp
                   | -----> Operator |
                   | u-------------- |
                 a + b
                 |     |
                 | u-- |
Left operand <---|   |---> Right operand
```

二元运算符列表:

| Operator | Significance   |
| -------- | -------------- |
| +        | Addition       |
| -        | Subtraction    |
| *        | Multiplication |
| /        | Division       |
| %        | Remainder      |

除法操作符的操作数为整数时结果也为整数, 如果两个操作数任意一个为浮点型则结果为浮点类型  
另外, 取余操作符仅对整数可用:

eg:

```cpp
7 / 2 = 3;

7.0 / 2 = 3.5;
```

表达式
---

表达式由操作符和操作数组成, 表达式亦可作为操作符的操作数; 只要不是void类型的表达式都会  
返回一个值; 在算术表达式中操作数决定了表达式的类型:

```cpp
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a = 1.23;
    int b = 3;

    cout << b * 2.5 << endl; // Type double

    cout << a * 3 << endl; // Type double

    cout << b + sin(2) << endl; // Type double

    cout << b / 2 << endl; // Type int

    return 0;
}
```

算术运算符遵循数学上的优先级, `* / %` 等运算符比 `+ -` 运算符优先级高:

```cpp
1 + 2 * 3  // result is 1 add 6, that's 7
```

也可以使用括弧来改变优先级:

```cpp
(1 + 2) * 3  // result is 3 multiply 3 , that's 9
```

一元运算符
---

| Operator |     | Significance         |
| -------- | --- | -------------------- |
| +        | -   | Unary sign operators |
| ++       |     | Increment operator   |
| --       |     | Decrement operator   |

数学运算符的优先级:

| Precedence | Operator         | Grouping      |
| ---------- | ---------------- | ------------- |
| High       | ++  -- (postfix) | left to right |
| \          | ++  -- (prefix)  | right to left |
| \          | +  - (sign)      | right to left |
| \          | + / %            | left to right |
| \          | + (addition)     | left to right |
| low        | - (subtraction)  | left to right |

`++` 自增运算符会在将操作数加1, 所以其不能用于常量; `++` 运算符作用于操作数前还是后  
是不同的(`++i`, `i++`):

* `++i` : `i` 的值就地加1, 将该表达式赋值给另一个变量时, 该变量会得到的值为 `i + 1`
* `i++` : `i` 的值也被加1, 但是此时将该表达式赋值给一个变量时, 该变量的值为 `i` , 待  
  下一个变量使用i时, 得到的值才为 `i + 1`

`--` 运算符同上

eg:

```cpp
float val(5.0);
cout << val++ – 7.0/2.0;
```

由于运算符优先级: `++` > `/` > `-`, 所以上面的cout相当于`cout << (val++) - (7.0/2.0)`  
由于`val`的值会在使用了val之后才会被加1, 所以结果是 `5.0 - 3.5 = 1.5`

赋值(Assignments)
---

**简单赋值:**  
简单赋值时使用赋值符号`=`, 在简单的赋值表达式中, 变量置于赋值操作符的左侧, 赋予的值置于赋值操作符  
右侧, eg:

```cpp
double x, y, z;
x = 2.3;
y = x;
z = 3.4 + 2.3 * x - y;
```

在上面例子最后一行, 由于 `=` 的优先级比较低, 所以右侧的部分会被计算出结果， 然后赋给`z`

```cpp
cos(z = 2.3);
```

在上面的例子中, 2.3 被赋值给z, 然后z作为函数`cos()`的参数传给其

```cpp
z = y = x = 1;
```

多重赋值也是可行的, 如上面例子， 1 首先被赋给x, 然后赋值给y, 最后1被赋值给z

**复合赋值:**
复合赋值操作是将一个算术操作(`+ - * / %`)和赋值操作合并起来的一种操作, eg:

```cpp
i += 1;       // i = i + 1
i *= j + 1;   // i = i * (j + 1)
```

上面例子中第二个由于 `*=` 的优先级比 `+` 低, 所以会先将右边的部分计算出结果再乘以`i`, 再将  
得到的值赋给 `i`; 算术复合赋值可以是`+= -= *= /= %=`等

关系运算符
---

关系运算符

| Operator | Significance             |
| -------- | ------------------------ |
| <        | less than                |
| <=       | less than or equal to    |
| >        | greater than             |
| >=       | greater than or equal to |
| ==       | equal                    |
| !=       | unequal                  |

关系运算符和数学运算符优先级

| Precedence | Operator                         |
| ---------- | -------------------------------- |
| High       | Arithmetic Operators (+ - * / %) |
| -          | `<`, `<=`, `>`, `>=`             |
| -          | `==`, `!=`                       |
| Low        | Assignment Operators (=)         |

eg:

```cpp
// true, 65 < 97
'A' < 'a';

// 3 < (3 - 1) --> false, flag = false;
int index = 3, max = 3
bool flag = index < max - 1;  

// (1 + 2) == 3 --> true, res = 1;
int res;
int len = 1, limit = 3;
res = len + 2 == limit;

// res == 1 + 1 == 2, 2 != 3 --> false, rres = 0
int res, rres;
int len = 1, limit = 3;
rres = (res = len + 1) == limit;
```

对于一个数值来说, 如果其值为0则被解析为'false', 其它非0值均被解析为'true'

逻辑运算符(&& || !)
---

逻辑运算符和可和关系运算符组合成为条件来执行特定的代码片段, 逻辑运算符的操作数为bool类型.
但是任何可以转化为bool类型的操作数都可以被使用在逻辑运算中: 

```cpp
// @1
(len < .2) || (len > .9)

// @2
(index < 20) && (cin >> number)
```

`||` 或操作符返回true的条件是其左右两边的条件结果至少有一个的值是true, 所以在@1中,  
如果len小于0.2或者大于0.9整个表达式的值都为true
`&&` 与操作符放回true的条件只能是其两边的条件结果都是true， 并且只有左边的为true后  
才会继续处理右边的条件, 在@2中, 只有index小于20, 才会去接受输入, 而且成功输入一个  
数值后, 整个表达式的值才为true; 对于`||`也是一样, 只要左边为真, 右边就不再被处理,  
只有左边为假时才会处理右边.

`&&` 的优先级比 `||` 高, `&&` 和 `||` 的优先级都比赋值运算符的优先级高, 另外运算
符 `!` 的优先级比前面二者都高, 因为其是一元运算符.

