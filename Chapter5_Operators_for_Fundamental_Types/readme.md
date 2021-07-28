Chapter5 Operators for Fundamental Types
===

二元运算符与操作数(Binary operator and operands)
---

```cpp
                   |-----> Operator
                   |
                 a + b
                 |   |
                 |   |
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

一元运算符的优先级:

| Precedence | Operator         | Grouping      |
| ---------- | ---------------- | ------------- |
| High       | ++  -- (postfix) | left to right |
| \          | ++  -- (prefix)  | right to left |
| \          | +  - (sign)      | right to left |
| \          | + / %            | left to right |
| \          | + (addition)     | left to right |
| low        | - (subtraction)  | left to right |
