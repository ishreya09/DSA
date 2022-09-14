/*

decltype vs typeid

Decltype gives the type information at compile time while typeid gives at runtime.
So, if we have a base class reference (or pointer) referring to (or pointing to) a derived class object, 
the decltype would give type as base class reference (or pointer, but typeid would give the derived 
type reference (or pointer).

*/