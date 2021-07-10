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

