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
Some characters, such as backspace or control character,have no visible image.Such characters are **nonprintable**.We use an **escape sequence** to represent such characters.

| name         |       | name            |       |
|:------------ |:----- | --------------- | ----- |
| newline      | `\n`  | horizontial tab | `\t ` |
| vertical tab | `\v`  | alert(bell)     | `\a`  |
| backspace    | `\b ` | double quote    | `\"`  |
| blackslash   | `\\`  | question mark   | `\?`  |
| single quote | `\'`  | carriage return | `\r`  |
| formfeed     | `\f`  |                 |       |

We can also write a generalized escape sequence,which is \x followed by one or more hexadecimal digits or a \ followed by one,two,or three octal digits.
```
\7 bell \12 newline  \40 blank
\0 null \115 'M' \x4d 'M'
```

Note that if a \ is followed by more than three octal digits,only the first three sociated with the \.
```cpp
\1234
```
represents two characters: the character represented by the octal value `123` and the character `4`. In contrast, `\x` uses up all the hex digits following it.
```cpp
\x1234
```
reprents a single, 16-bit character composed from the bits corresponding to these for hexadecimal digits.

#### Specifying the type of a Literal
```cpp
L'a' // wide character literal,type is wchar_t
u8"hi!"// utf-8 string literal
42ULL // unsigned integer literal, type is unsigned long long
1E - 3F //single-percision floating-point literal,type is float
3.14159L // extended-persion floating-point literal,type is long double
```

Character and character String Literals

| prefix | meaning                    | type     |
|:------ |:-------------------------- | -------- |
| u      | unicode 16 character       | char16_t |
| U      | unicode 32 character       | char32_t |
| L      | wide character             | wchar_t  |
| u8     | utf-8(string liters only ) | char     |

Integer Literals

| Suffix   | Minium Type |
|:-------- |:----------- |
| u or U   | unsigned    |
| l or L   | long        |
| ll or LL | long long   |

Floating- point Literals

| suffix | type        |
|:------ |:----------- |
| f or F | float       |
| l or L | long double |

#### boolean and Pointer Liters
the word `true` and `False` are literals of type *bool*

The world `nullptr` is a pointer literal.

## 2.2 Variables
A *variable* provides us with named storage that our program can manipulate.

### 2.2.1 Variable Definitions

A simple variable definition consists of a **type specifier**, followed by a list of one or more variable names separated by commas,and ends with semicolon.
```cpp
int sum = 0 , value;
std::string book("0-201-78345-x")// book initalized from string literal
```

#### Initalizers
An object that is **initalized** gets the specified value at the moment it is created.

#### List Initialization

We can use any of the following ways to define an int variable named units_sold and ititalize it to 0:
```cpp
int units_sold = 0;
int units_sold = {0};
int units_sold{0};
int units_sold(0);
```
The gengeralized use of curly brace for Initialization was introduced as part of the new standard.

When used with variables of built-in type, this form of Initialization has one important property: The compiler will not let us initialize variables of  build-in type if the initializer might lead to the loss of information:
```cpp
long double ld = 3.1415926536;
int a{ld}, b = {ld}; //error narrowing conversion required
int c(ld), d = ld; // ok: but value will be truncated
```
#### Default Initialization
When we defined a variable without an initializer, the variable is **default initalized**.Such variables are given the "default" value.What that default value is depends on the type of the variable and may also depend on where the value is depends.

The value of an object of build-in type that is not explicitly initialized depends on where it is defined,Variables defined outside any function body are initalized to zero.

Most classes let us define objects without explicitly initializers. Such class supply an appropriate default value for us.For example, as we've seen,the library string class says that if we do not supply an initializer,then the resulting string is the empty string:
```cpp
std::string empty;// empty implicitly initialized to the empty string
Sales_item item; // default-initialized Sales_item object
```

Some classes require that every object be explicitly initialized. The compiler will complain if we try to create an object of such a class with no initializer.

### 2.2.2 Variable Declarations and Definitions

To allow programs to be written in logical parts,C++ supports what is commonly known as **sparate compilation**.Separate compilation lets us split our programs into several files, each of which can be compiled independently.

A **declaration** makes a name known to the program.A file that wants to use a name defined elsewhere includes a declaration for that time. A **definition** creats the assoicated entity.

To obtain a declaration is not also a definition, we add `extern` key-word and may not provide an explicit initalizer:
```cpp
extern int i; // declares but does not define i
int j; // declares and defines j
```
Any declaration that includes an exp;ict initialzer is a definition. We can provide an ititializer on a variable defined as `extern`, but doing so overrides the `extern`. An extern that has an initalizer is a definition:
```cpp
extern double pi = 3.1416; // definition (ERROR:extern double pi = 3.1416;)

```
It is an error to provide an initialzer on an `extern` inside a function

*Variables must be defined exactly once but can be declared many times*
To use a variable in more than one file requires declarations that are separate from the variable's definition.To use the same variable in multiple files,we must define that variable in one——and only one——file.Other files that use the variable must declare--but not define--that variable.

### 2.2.3 Identifiers
