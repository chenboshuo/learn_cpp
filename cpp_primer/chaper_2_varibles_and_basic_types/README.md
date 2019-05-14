# Chapter 2 Variables and Basics types
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
-   if we assigned an out-of-range value to an object of signed type, the result is **undifined**.The program might appear to work, it might crash, or it might produce garbage values.

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
-   Don't mix signed and unsigned types

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

**Identifiers** in C++ can be composed of letters,digits,and the underscore character.

#### Conventions of variable Names
-   An identifier should give some indication of its meaning.
-   Variable names normally are lowercase.
-   Class we difine usually begin with an uppercase letter.

### Scope of Name
A **scpoe** is a part of the program in which a name has a particular meaning. Most of C++ are delimited by curly braces.

The dame name can refer to diffierent entities(实体) in different scopes.

```cpp
int main(int argc, char const *argv[]) {
  int sum = 0, var = 1;
  // keeping executing the while as long as val is less than or equal to 10
  for (int val = 1; val <= 10; val++) {
    sum += val;
  }
  std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
  return 0;
}
```
The name `main` defined outside any curly braces. The name `main` -- like most names difines outside a function--has **global scope**.Once declared, names at the global scope are accessible throughout the problem.The variable `sum` has **block scope**.The naem `val` is difined in the scope of the `for` statement. It can be used in that statement but not elsewhere in main.

#### Nested Scopes
scopes can contain other scopes. The contain(or nested) scope is reffered to as an **inner scope**,the containing scope is the outer scope.

Once a name has been declared in a scope,that name can be used by scopes nested inside that scope. Names declared in the outer scope can also be redefined in an inner scope:

[区分全局变量与局部变量](./nested_scope.cpp)

It is almost a;ways a bad idea to defined a local variable with the same name as a global variable that the function uses or might use.

## 2.3 Compound Types

**A compound type** is a type that is defined in terms of another type. C++ has several compound types, two of which--reference and pointers--we'll cover in this chapter.

A declaration is a *base type* followed by a list of **declarators**.Each declarator names a variable and gives the variable a type that is ralated to the base type.

### 2.3.1 References

A **reference** defines an alternative name for an object. A referenc type "refers to" another type. We define a type by writing a declartor of the form `&d` where `d` is the name being declared:
```cpp
int ival = 1024;
int &refVal = ival; // refval refers to(is another name for) ival
int &refVal2; // error: a reference must be initialized
```
Ordinarily when we initialize a variable, the value of the initalizer is copied into the object we are creating. When we define a reference, instead of copying the initializer's value,we **bind** the reference to its initializer. Once initialized, a reference remains bound to its initial object.Because there is no way to rebind a reference,references must be initialized.

#### A reference is an Alias

-   A reference is not an object.Instead a reference is *just another name for an already existing object.*

After a reference has been defined, all operations on that reference are actually operations on the objects to which the reference is bound:
```cpp
refVal = 2; // assigns 2 to the object which refval refers,i.e.,to ival
int ii = refVal; // same as ii = ival
```
reference is not objects,we may not define a reference to a deference.
```cpp
int &refVal3 = refval;// ok:refVal3 is bound to the object to which refVal is bound,i.e,to ival
int i = refVal; // ok:initializes i to the same value as ival
```

#### Reference Definitions
We can define mutiple reference in a single definition.Each identifier that is a reference must be preceded by the `&` symbol.

```cpp
int &refVal = 10; // error: initializer must be an objects
double dval = 3.14;
int &refVal5 = dval; //error: initializer must be an int object
```

### 2.3.2 Pointers
A **pointer** is a compound type that "point to" another type. Like reference,pointers are used for indirect access to others objects. Unlike a reference, a pointer is an onject in its own right. Pointers can be assigned and copied; a single pointer can point to several different objects over its lifetime.

#### Taking the Adress of an Object
A pointer holds the adress of another object. We get the adress of an object by using the address-of operator(the **& operator**)

The type must match because the type of the pointer is used to infer the type of the object to which the pointer points. If a pointer adressed an object of another type, operations performed on the underlying(基本的) object would fail.

#### Pointer Value
The value(i.e., the adress) stored in a pointer can be in one of four states:
1. It can point to an object.
2. It can point to the location just immediatelly past the end of an object.
3. It can be a null pointer, incicatiing that it is not bound to any object.
4. It can be invailed; values other than the preceding three are invalid.

Although pointers int case 2 and 3 are valid ,there are limits on what we can do with such pointers. Because these pointers do not to any object, we may not use them to access the (supposed) object to which the pointer points.If we do attempt to access an object through such pointers, the behavior is undifined.

#### Using a Pointer to Access Object
When a pointer pointers to an object, we can use the dereference operator(the **`*` operator**) to access that object.

Dereferencing a pointer yields the object to which the pointer points. We assign to that object by assigning to the dereference.

#### Null Pointers
A **null pointer** does not point to any object. Code can check whether a pointer is null before attempting to use it. There are several ways to obtain a null pointer:
```cpp
int *p1 = nullptr; // equivalent to int *p1 = 0
int *p2 = 0;// directly initialize p2 from the literal constant 0
// must #include <ctdlib>
int *p3 = NULL;
```

The most direct approach is to initialize the pointer usng the literal **nullptr**, which was introduced to any other pointer type. Alternatively, we can initalize a pointer to the literal 0.

Other programs sometimes use a **preprocessor variable** named `NULL`,which the `cstdio` header defines as 0.

#### void* Pointers
The type `void*` is a special type that can hold the adress of any object.Like other pointer, a void* pointer holds an adress, but type of the object at that adress unknown:
```cpp
double obj = 3.14, *pd = &obj;
void *pv = &obj;// ok:obj can be an object of any type
pv = pd;// pv can hold a pointer to any type.
```
We cannot use a void* to operate on the object it adress--we don't know that object's type, and type determines what operations we can perform on the object.

### 2.3.3 Understanding Compound Type Declarations
#### Pointers to points
In general, there are no limits to how many type midifiers can be applied to a declarator. When there is more than modifier, they combine that are logical but not always obvious.

[code](https://github.com/chenboshuo/cpp_learning/blob/619a3d9ada9b1321305c752d08577b028db30553/cpp_primer/chaper_2_varibles_and_basic_types/pointers-to-pointers.cpp)

```cpp
  int ival = 1024;
  int *pi = &ival;
  int **ppi = &pi;
```
ppi -> pi -> ival

#### Reference to Pointers
A reference is not an object. Hence, we may not have a pointer to a reference.However, because a pointer is an object, we can define a reference to a pointer:
```cpp
int i = 42;
int *p; // p is a pointer to int
int *&r = p; // r is a reference to the pointer p

r = &i;// r refers to a pointer; assigning &i to r makes p point to i
*r = 0;// dereference r yields i, the object tp which p points; change i to 0
```
The easiest way to understand the type of r is to read the definition right to left. The symbol closest to the name of the variable(in this case the & in &r) is the one that has the most immediate effect on the variable's type. Thus, we know that r is a reference. The rest of declarator determines the type to is a pointer type. Finally, the base type of the declaration says that r is a reference to a pointer to an `int`.

## 2.4 `const` Qualifier
We can make a variable unchangeable by defining the variable's type as **const**:
```cpp
const int bufSize = 512;
```
Any attempt ro assign to bufSize is an error. Because we can't change the value of a const object after we create it, it must be initialized.  As uaual, the initializer may be an srbitrarily complicated expression:
```cpp
const int i = get_size();// ok: initialized at run time
const int j = 42; // ok: initialized at compile time
const int l; // errror: l is uninitialize const
```

#### by default, const objects are local to file
When a `const` object is initialize from a compile-time constant, the compiler will usually replace uses of the variable with its corredponding value.

To substitute the value for the variable, the complier has to see the valable's initializer. When we split a program into mutiple files, every file that uses the const must have access to its initializer. In order to see the initializer, the variable must be defined in every file that wants to use the variable's value. To support this usage, yet avoid multiple definitions of the same variable, const variables are difined as local to the file. When we define a const in a const with the same name in mutiple files, it is as if we had written definition for separate variables in each file.

Sometimes we have a const variable that we want to share across mutiple files but whose initializer is not a constant expression. In that case, we don't want the compiler to generate a separate variable in each file. Instead, we want the compiler to have behave like other object. We want to define the const in one file, and declare it in the other files that use that objects.

To define a single instance of a const object, we use the keyword `extern` on both definition and declarations:
```cpp
// file_1.cc defines and initializes a const that is accessible to other file
extern const int bufSize = fcn();

// file_1.h
extern const int bufSize; // same bufSize as defined in file_c.cc
```

To share a const object among mutiple files, you must define the variables as extern.

### 2.4.1 References to `const`

As with any other object, we can bind a reference to an object of a const type. To do so we use a **reference to const**, which is a reference that refers to a const type. Unlike an ordinary reference, a reference to const cannot be used to change the object to which the reference is bound:
```cpp
const int ci = 1024;
const int &r1 = ci; // ok: both reference and underlying object are const
r1 = 42; // error: r1 is a reference to constant
int &r2 = ci;//error: nonconst reference to a const object  
```

Because we cannot assign dirctly to ci, we also should not be able to use a reference to change ci. Therefore, the Initialization r2 is an error.

TERMINOLOGY(术语): CONST REFERENCE IS REFERENCE TO CONST

C++ programmers tend to abbreviate the phase "reference to const" as "const reference." This abbreviation makes sense-- if you remember that it is an abbreviation.

Technically speaking, there are no const. Indeed, because there is no way to make a reference refer to a different objection.

#### Initialization and reference to const
In `2.3.1` we noted that there are two expections to the rule that the type of a reference must match the type of the objects which it refers. The first exception is that we can initialize a reference to const from any expression that can converted to the type of the reference. In particular, we can bind a reference to const to a nonconst object, a literal, or a more general expression:
```cpp
int i = 42;
const int &r1 = i; // we can bind a const int& to a plain int object
const int &r2 = 42; // ok: r1 is a reference to const
const int &r3 = r1 * 2; // ok: r3 is a reference to const
int &r4 = r * 2; // error: r4 is a plain, nonconst reference
```

The easiest way to understand this difference in initialization rules is to consider what happens when we bind a feference to an object of a different type:

```cpp
double dval = 3.14;
const int &ri = dval;
```

Here `ri` referes to an int. Operations on `ri` will be integer operations, but `dval` is a float-point number, not an integer. To ensure that the object to which `ri` is bound is an `int`, the compiler transforms this code into something like
```cpp
const int temp = dval; // create a temporary const int from the double
const int &ri = temp; // bind ri to that temporary
```
In this case, `ri` is bound to a **temporary** object. A temporary object is an unnamed object created by the compiler when it needs a place to store a result from evaluatong an expression. C++ programmers often use the word temporary as an abbreviation for temporary object.

Now consider what could happen if this initialization were allowed but was not a const. If `ri` weren't const, we could assign to `ri`. Doing so would change the object to which `ri` is bound. That object is a temporary, not `dival`. The programmer who made `ri` to `dval` would probably expcect that assigning to `ri` would change `dval`. After all, why assign to `ri` unless the intent is to change the object to whcih `ri` is bound? Because binding a reference to a temporary is almost surely not what the programmer intended, the language makes it illegal.

#### A Reference to `const` May Refer to an Object That Is Not `const`

It is imprortant to realize that a reference to const retricts only what we can through that reference. Binding a reference const to an object says nothing about whether the underlying object itself is const. Because the underlying object might be nonconst, it might be changed by means:
```cpp
int i = 42;
int &r1 = i; // r1 bound to i
const int &r2 = i; // r2 also bound to i; but cannot be used to change i
r1 = 0; // r1 is not const; i is now 0
r2 = 0; // error : r2 is a reference to const
```

Binding r2 to the (nonconst) int i is legal. However, we cannot use r2 to change i. Even so, the value in i still might change. We can change i by assigning to it directly, or by assigning to another reference bound to i, such as r1.

### 2.4.2 Pointers and const

As with reference, we can define pointers that point to either const or nonconst types. Like a reference to const, a **pointer to const** may not be used to const:
```cpp
const double pi = 3.14;
double *ptr = &pi; // error: ptr is a plain pointer
const double *cptr = &pi;
*cptr = 42;
```

In we noted that there are two expections to the rule that the types of a pointer and the object to which it points must match. The first expection is that we can use a pointer to `const` to point to nonconst object:
```cpp
double dval = 3.14;  // dval is a double; its value can be changed
cptr = &dval;  // ok: but can't change dval through cptr
```

Like a reference to const, a pointer to `const` says nothing about whether the object to which the pointer points is `const`. Defining a pointer as a pointer as a pointer to const affects only what we can do with the pointer. It is important to remember that there there is no guarantee that an object pointed to by a pointer to const won't change.

#### const Pointers

Unlike a reference, pointers are objects. Hence, as with any other type, we can have a pointer that is itself const. Like any other const, a **const pointer** must be initialized, and once initialized, and once initialized, its value.
```cpp
int errNumb = 0;
int *const curErr = &errNumb;  // curErr will always point to errNumb
const double pi = 3.1415926;
const double *const pip = &pi;  // pip is a const pointer to a const object.
```

The fact that a pointer is itself const says nothing about whether we can use the pointer to change the underlying object. Whether we can change that object depends entirely on the type to which the pointer points. For example. `pip` is a const pointer to const. Neither the value of the object adressed by `pip` nor the adress stored in `pip` can be changed. On the other hand, `curErr` adresses a plain nonconst int. We can use `curErr` to change the value of `errNumb`

### Top-Level const

As we've seen, a pointer is an object that can point to a different object. As a result, we can talk independently about whether a pointer is const and whether the objects to which it can point are `const`. We use the term **top-level const** to indicate that pointer itself is a `const` as **low-level const**
```cpp
int i = 0;
int *const p1 = &i;      // we can't change the value of p1; const is top-level
const int ci = 42;       // we can't change ci; const is top-level
const int *p2 = &ci;     // we can change p2; const is low-level
const int *const p3 = p2;// right-most const is top-level, left-most is not.
const int &r = ci;       // const in reference types is always low-level
```

The distination between top-level and low-level matters when we copy an object. When we copy an object from or copied into is const.

```cpp
i = ci;  // ok:copying the of ci; top-level const in ci is ignored
p2 = p3; // ok:pointed-to type matvhes; top-level const in p3 is ignored
```

On the other hand, low-level const is never ignored. When we copy an object, both objects must have the same low-level const qualification or there must be a conversion between the types of two objects. In general, we can convert a nonconst to const but not the other way round:
```cpp
int *p = p3;
