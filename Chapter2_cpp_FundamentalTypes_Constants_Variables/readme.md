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

- 1 --> true
- 0 --> false

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

- 16bit computers --> int is equivalent to short
- 32bit computers --> int will be equivalent to long
- c++ treat char and wchar_t like normal integers, so char and wchar_t can perform calculate
- wchart_t is normally defined as unsigned short
- int type is normally interpreted as signed, also char type
- "unsigned int" cant be abbreviated as keyword "unsigned"
- type size: char <= short <= int <= long

- Examples for integral constants

| Decimal    | Octal        | Hexdecimal | Type                       |
| ---------- | ------------ | ---------- | -------------------------- |
| 16         | 020          | 0x10       | int                        |
| 255        | 0377         | 0xff       | int                        |
| 32767      | 077777       | 0x7FFFF    | int                        |
| 32768U     | 0100000U     | 0x8000U    | unsigned int               |
| 100000     | 0303240      | 0x186A0    | int(32bit)/long(16bit-CPU) |
| 10L        | 012L         | 0xAL       | long                       |
| 27UL       | 033UL        | 1bUL       | unsigned long              |
| 2147483648 | 020000000000 | 0x80000000 | unsigned long              |



Types Floating-point
---

| Type        | Size    | Range of values | Lowest Positive value | Accuracy(decimal) |
| ----------- | ------- | --------------- | --------------------- | ----------------- |
| float       | 4bytes  | -3.4e+38        | 1.2e-38               | 6digits           |
| double      | 8bytes  | -1.7e+308       | 2.3e-308              | 15digits          |
| long double | 10bytes | -1.1E+4932      | 3.4e-4932             | 19digits          |