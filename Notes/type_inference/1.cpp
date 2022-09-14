/*
Type Inference in C++ (auto and decltype)

Type Inference refers to automatic deduction of the data type of an expression in 
a programming language. Before C++ 11, each data type needed to be explicitly 
declared at compile-time, limiting the values of an expression at runtime but 
after the new version of C++, many keywords are included which allows a programmer 
to leave the type deduction to the compiler itself.

With type inference capabilities, we can spend less time having to write out things 
the compiler already knows. As all the types are deduced in the compiler phase only, 
the time for compilation increases slightly but it does not affect the run time of the program.

1) auto keyword: The auto keyword specifies that the type of the variable that is being declared 
will be automatically deducted from its initializer. In the case of functions, if their return type 
is auto then that will be evaluated by return type expression at runtime. 
Good use of auto is to avoid long initializations when creating iterators for containers.

Note: The variable declared with auto keyword should be initialized at the time of its 
declaration only or else there will be a compile-time error.



*/