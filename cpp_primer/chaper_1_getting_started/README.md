## 1.1 Wrinting a Simple Program
- Every C++ program contains one or more functions, one of which must be named `main`.The operating system runs a C++ program by calling `main`.

```cpp
main() {
  return 0;
}
```

- A function defination has four elements:a `return type`, a `function name`, a(posibily empty)`parameter list` enclosed in parenthness(圆括号),and a `funstion body`
- the int type is a **build-in type**,shich means that it is one of the types the langues defines.

## 1.2 Afirst Look at Input/Output

- The C++ lanuage does not definr any statements to do input or output(IO).Instead, C++ includes an extensive **standard library** that provides IO(and many other facilities)
- Fundamental to the `iostream` are two types name `istream` and `ostream`,which respresent input and output streams, respectively.
- A **stream** is a sequence of characters read from or written to an IO device.The term `stream` is intended to suggest that the characters and generated,or consumed, sequentially over time.

**standard Input and Output Objects**

- To handle input,we use an object of type istream named **cin**(pronounced see-in).This object is also referred to as the **standard input**
- For output,we use an *ostream* object named **cout**.This object is also known as the **standard output**.
- The library also defines two other *ostream* objects,named **cerr** and **clog**(pronounced see-err and see-log,respectively). We typically use `cerr` referred to as the **standard error**,for warning and eooro messages and `clog` for general information about the execution of the problem.

**A problem That uses the IO Library**

-[sum.cpp](https://github.com/chenboshuo/cpp_learning/blob/master/cpp_primer/chaper_1_getting_started/sum.cpp)

The first line of our Program

```cpp
##include <isostream>
```

tells the complier that we want to use the `iostream` library.THe name inside angle brackets(`isostream` in this case) refers to a header. Every program that use a library faility must include its associated header.The`#include` directive must be written on a single line--the name of the header and the `#include` must appear on the same line.

**Writing to a Stream**
