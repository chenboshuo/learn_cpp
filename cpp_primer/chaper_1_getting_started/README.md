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

### standard Input and Output Objects

  - To handle input,we use an object of type istream named **cin**(pronounced see-in).This object is also referred to as the **standard input**
  - For output,we use an *ostream* object named **cout**.This object is also known as the **standard output**.
  - The library also defines two other *ostream* objects,named **cerr** and **clog**(pronounced see-err and see-log,respectively). We typically use `cerr` referred to as the **standard error**,for warning and eooro messages and `clog` for general information about the execution of the problem.

### A problem That uses the IO Library

  -[sum.cpp](https://github.com/chenboshuo/cpp_learning/blob/master/cpp_primer/chaper_1_getting_started/sum.cpp)

  The first line of our Program

  ```cpp
  ##include <isostream>
  ```

  tells the complier that we want to use the `iostream` library.THe name inside angle brackets(`isostream` in this case) refers to a header. Every program that use a library faility must include its associated header.The`#include` directive must be written on a single line--the name of the header and the `#include` must appear on the same line.

### Writing to a Stream
  The first statement in the body of `main` executess an  **expression**.In c++ an expression yeilds a result and is composed of one or more operands(操作数) and (usually) an operator.The expression in this statement use the output operator(the **<< operator**) to print a message on the standard output:
  ```cpp
  std::cout << "enter two numbers" << std::endl;
  ```
  The `<< operator` takes two operands: The left-hand operand must be an `ostream` object; the right-hand ooperand is a value to print. The operator writes the given value on the given `ostream`.The result of the output is its left-hand operand.That is, the result is th `ostream` on which we wrote the given value.

  Our output statement uses the `<<` twice. Because the operator is its left-hand operand,the result of the first operator becomes the left-hand operators and of the second.As a result,we can chain together output requests.Thus our expression is equivalent to
  ```cpp
  (std::cout << "enter two numbers") << std::endl;
  ```

  Each operator in the chain has the same object as its left-hand operand.

  The output operator prints a message to user.That message is a **string literal**, which a sequence of characters enclosed in double quoation marks.
  ```cpp
  std::cout << std::endl
  ```
  The operator prints `endl`, which is a specialvalue called a **manipulator**(操纵器).Writing `endl` has the effect of ending a current line and flushing the **buffer**(缓冲区) associated with that device.flushing the buffer ensures that all the output the program has generated so far is actually written to output stream,rather than sitting in memory waiting to be written.

  Programmers often add print statements during debugging.Such statements should always flush the stream.Otherwise, if the program crashes,output may be in the buffer,leading to incorrect inferences about where the program crashed.

### Using Names from the Standard library
  the prefix `std::` indictes that the names `cout` and`endl` are difined inside the **namespace** named **std**.Nameplaces allow us to avoid inadervertent collisions between the names we defined and the uses of those names inside the library.All the name defined by the standard library are in the std namespace.

  the scope operator(`the :: operator`) is to say that we want to use the name `cout` that is defined in the nameplace `std`

### Reading from a Stream
  The input operator(the **>>operator**) behaves analogously(类似地) to the output operator.It takes an `istream` as its left-hand operand and an objects as right-hand operator.

## 1.3 Word about comments

## 1.4 Flow of control

### 1.4.1 The `while` statement
  -[sum_of_1_to_10.cpp](./sum_of_1_to_10.cpp)
  A **while statement** repeatedly executes a section of code as a given condition is true.A while has the form
  ```
  while (/* condition */) {
    /* statement */
  }
  ```

  A **condition** is an expression that yeilds a result that is either true or false.

  the less-than-or-equal operantor :**<= operator**

  The compound assignment operator(the **+= operator**) adds its right-hand operand to its left-hand operand and stores the result in the left-hand operand.

  The `increment operator` (the ** ++ operator**) add 1 to its operand.

### 1.4.2 The `for` statement
  
