#include <stdio.h>

typedef struct
{
    int f1, f2;
} Foo;

void sum(Foo *foo)
{

    ///! Assigning a value to struct fields
    foo->f1 = 69;
    foo->f2 = 911;

    ///! Print the sum of foo fields
    printf("%d\n", foo->f1 + foo->f2);
}

void _sum(Foo *foo)
{

    ///! Assigning a value to struct fields
    foo.f1 = 69;
    foo.f2 = 911;

    ///! Print the sum of foo fields
    printf("%d\n", foo.f1 + foo.f2);
}

int main(void)
{

    ///! Defined struct foo with Type Foo
    Foo foo;

    ///! Calling the function sum with the address of foo as argument
    ///! This function will add the values of f1 and f2 and print the sum
    ///! It will access struct fields with member access operator '->' in the regular way (not Auto Dereferencing with dot operator)
    sum(&foo);

    ///! Calling the function _sum with the address of foo as argument
    ///! This function will add the values of f1 and f2 and print the sum
    ///! It will access struct fields with member access operator '.' using Auto Dereferencing with dot operator Patch
    ///! This feature is available only for the Tiny C Compiler with my patch
    ///! The compiler patch it's backward compatible with the legacy code, but the codes that uses 'Auto Dereferencing' with dot operator can't be compiled with the legacy compilers
    _sum(&foo);

    return 0;
}