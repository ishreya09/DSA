/*
In C++, an auto keyword is used to specify that the variable’s
 data type will automatically be deducted from its initializer. 
 In the case of functions, the auto keyword before the function name or 
 the auto return type signifies that the return type of that function will 
 be evaluated from the return type expressions at runtime. From C++ 11, this 
 keyword was introduced; before that, the programmer needed to assign each variable’s 
 data type explicitly at compile time. The automatic deduction of the datatype from the expression is 
 called Type Inference in C++. This feature reduces the overhead 
 and saves a lot of time for the programmer to declare the things which the compiler is already aware of.

Syntax:

There is no specific syntax for using the auto keyword in a program. 
Instead, we need to simply write the ‘auto’ keyword before the variable name or the function return type.


How does the auto keyword work in C++?
The Keyword auto is used normally like other keywords in C++. It is used before the name of the variable or 
the function to infer the return type of both of them. When the auto keyword is used, it is evaluated at the 
compilation time. Since the compiler has to do this, it increases the compilation time to a few seconds, 
which is almost negligible.

One of the advantages of using the auto keyword is that it reduces the extra 
overhead on the programmer to define the data type so that he/she can focus on other 
important tasks as well. In the case of functions, using the auto keyword helps to 
create generic functions, i.e., we can pass different parameters to the function 
with their datatype as being auto. So the issue of creating separate functions for 
different data types can be easily solved by creating only one single function.

Although the auto keyword can be used in the function return type, it is usually not 
used by the programmers in the case of simple functions, as it sometimes creates 
problems as the return type of function is very useful and returned to the caller, 
which then performs specific tasks according to the program requirements. 
The caller may misinterpret what is returned from the function, which can lead to unexpected results.

Some important points to be kept in mind while working with auto keyword:

The keyword auto can be used along with the modifiers like const, pointer (*), reference (&), etc.

When the auto return type is used in functions, all the return statements of that 
function must need to return the same data type; otherwise, it will throw an error in the program.

The keyword auto can also be used to iterate the values of the complex data structures 
like vectors, sets, etc., in C++. Programmers don’t have to worry about the long and complex 
iterator declaration. It can be defined as ‘auto’ simply.

Multiple declarations of variables are not possible in the case of defining their auto. 
For example, auto a =10, b= 344.5;

Function parameters can also be declared as auto. For example, auto func(auto a, auto b).

Declaring a variable as ‘auto,’ which stores the return value of a function, must be avoided 
as it creates confusion at times.  For example, auto-answer = funct().
*/

auto sum(int var1, int var2)
{
return (var1+var2);
}
auto sub(double var1, double var2)
{
return (var1-var2);
}

int main()
{
auto var1 = 3.767;
auto var2 = 34;

}

