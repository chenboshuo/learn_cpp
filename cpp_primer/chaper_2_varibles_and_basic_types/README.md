## 2.1 Primitive Build-in Types
C++ defines a set of primitive types that include the **arithmetic types** and a special type nemed **void**.The arithmetic types represent characters, integers, boolean values, and floating-point numbers. The void types has no assoicated values and can be used in only a few circustances, most commonly as the return type for functions that do not return a value.

### 2.1.1 arithmetic types
The arithmetic types are devided into two categories: **integral types**(which include chacter and boolean types) and floating-point types.

The size of--that is, the number of bits in--the arthmetic types varies across machines.The standard guarantees minimum sizes as listed in Table.However,compilers are allowed to use larger sizes for these typse.

| type        | mieaning                          | Miniumn Size          |
|:----------- |:--------------------------------- |:--------------------- |
| bool        | boolean                           | NA                    |
| char        | character                         | 8 bits                |
| wchar_t     | wide character                    | 16 bits               |
| char16_t    | unicode character                 | 16 bits               |
| car32_t     | unicode character                 | 32bits                |
| short       | short integer                     | 16bits                |
| int         | integer                           | 16bits                |
| long        | long integer                      | 32bits                |
| long long   | long integer                      | 64bits                |
| float       | single-precision floating-point   | 6 significant digits  |
| double      | double-precision floating-point   | 10 significant digits |
| long double | extended-precision floating-point | 10 significant digits |

The bool type represent the truth values true and false.

There are several character types,most of which exists to support international-
ization.The basic character type is char. A char is guaranteed to be big enough
to hold numetic values corresponding to the characters in the machine's basic
character set.That is, a char is the same size as a single machine byte.

#### signed  and unsigned types.

A signed type represents negative or positive numbers(including zero);an unsigned type represents only values greater than or equal to zero.

Unlike the other integer types,there are three distinct basic character types:
char,singed char,and unsigned char.In particular,char is not the same as signed char.The (plain) char types uses one of these representations.Which of the other two character representations is equivalent to char depends on the compiler.

In an unsigned type,all the bits represent the value. For example, an 8-bit unsigned char can hold the values from 0 through 255 inclusive.

### 2.1.2 Type convensions
```cpp
bool b = 42; // b is true
int i = b; // i has value 1
i = 3.14; // i has value 3
double pi = 1; // pi has value 3.0
unsigned char c = -1; // assuming 8-bit cahrs, c has value 255
signed char c2 = 256; // assuming 8-bit cahrs,the value of c2 si undefined
```
- if we assigned an out-of-range value to an object of signed type, the result is **undifined**.The program might appear to work, it might crash, or it might produce garbage values.

#### Expressions Involving Unsigned Types
```cpp
unsigned u = 10;
int i = -42;
std::cout << i + i << '\n'; // prints -84
std::cout << u + i << '\n'; // if 32-bits ints, prints 4294967264
```
```python
>>> 2 ** 32
4294967296
>>> _ + 10 - 42
4294967264
```
- Don't mix signed and unsigned types

```cpp
unsigned u1 =  42, u2 = 10;
std::cout << u1 - u2 << '\n'; // ok:result is 32
std::cout << u2 - u1 << '\n'; // ok:but the result will wrap around
```

### 2.1.3 literals
A value, such as 42, is known as a **literal** because its a value self-evident. Every literal has a type. The form and values of a literal determine its type.

#### Integer and Floating-point Literals
Integer literals that begin with 0 are interpreted as octal.

Those that begin with `0x` or `0X` are interpreted as hexadecimal.
` 20 /* deciaml */ 024 /* octal */   0x14 /* hexadecimal */ `

Although integer literals may be stored in signed types,technically speaking, the value of a decimal literal is never a negative number.If we write what apperas to a negative decimal lieteral, the minus sign is *not* part of the literal.The minus sign is an operator that negats the value of its (literal) operand.

Using scientific notation, the expoent is indiciated by either `e` or `E`:
```
3.14   3.14E0  0. 0e0
```
#### Character and charater string literals
```cpp
'a' // character literal
"hello world" // string literal
```
The type of a string literal is **array** of constant chars.

#### Escape Sequences
