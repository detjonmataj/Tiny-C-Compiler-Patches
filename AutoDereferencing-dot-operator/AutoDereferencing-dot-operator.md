# Auto Dereferencing Dot (.) Operator in C

## Introduction

During my experiences with C, I have come across many situations and I faced many problems. Here i'm going to share some details about the problems I faced using structures, unions, and pointers.

I'm going to describe the problems with the following:

- Accessing members of struct
- Accessing members of pointer to a struct

To acess members of the structures we use dot (.) operator members of structs and to access them through pointer a.k.a arrow (->)operator. The arrow operator was introduced in 1975 and back then it's purpose was different. Previously, it was first dereferenced using \* operator and it was accessed using dot (.) operator (*ptr).member (According to the Original C Reference Manual). We are going to discuss more about this in the following sections

It was very difficult for me to understand how to access the members of the struct. Also pointers were confusing to me at that time. I always forgot how to use them and access the members of the struct they are pointing to.

I wasn't the only one who faced these problems. It was a problem for many other students. When i was mentoring First Year Students, I came across the question "Why can't I access struct members only using dot (.) operator?". I also read some posts and comments on the internet that mentioned the same thing which gave me an idea.

More about this will be discussed below in this section.

Below i described how the access is made in practice.

**Let's consider the following struct example:**

```c
typedef struct {
    int id;
    char name[20];
    int age;
} Student;
```

Here we declared a struct named Student. The struct contains three members (fields), id, name and age. The id is an integer and name is a string (to be more precise it's a array of chars with length 20 including the string terminator character '\0') and age is an integer.

**So how do we access the members of the struct?**

```c
// Declaring a identifier with the type of the struct Student
Student student;
// Updating the members of the struct
student.id = 1;
student.name = "Detjon";
student.age = 20;
```

In the above example I have declared a struct named student and then updated values of the struct members, but how did i acces them?
To access them in this case I've used the dot operator (.) and than assigned a value to the members of the struct.

**So let's take a look for the case when we have a pointer to the struct.**

***First Method:***

```c
// Declaring and initializing a pointer to the struct Student
Student *student = (Student *)malloc(sizeof(Student));
// Updating the members of the struct
(*student).id = 1;
(*student).name = "Detjon";
(*student).age = 20;
```

In the above example, I have declared a pointer to the struct named student and then updated the members of the struct. To access the members of the struct, I have used the dot operator (.), but first i dereferenced the pointer to the struct and put it inside the parentheses because of operator precedence. The precedence of the dot operator is higher than the precedence of the \* (Indirection, dereference) operator.

***Second Method:***

```c
// Declaring and initializing a pointer to the struct Student
Student *student = (Student *)malloc(sizeof(Student));
// Updating the members of the struct
student->id = 1;
student->name = "Detjon";
student->age = 20;
```

In the above example, I have declared a pointer to the struct named student and then updated the members of the struct. To access the members of the struct, I have used the arrow operator (->) which is used when we access members of the structures through pointers.

**Is there another way of accessing members of pointers to structures?**

In the above examples we saw different ways to access the members of the struct for different cases in different ways. All the methods in the above examples are valid and the only difference is the way we access the members so you can use whichever method you want.

Let's consider the following example:

```c
// Declaring identifier stud with the type of the struct Student
Student stud;
// Declaring and initializing a pointer to the struct Student
Student *student = (Student *)malloc(sizeof(Student));

// Updating the members of the struct stud using the dot operator
stud.id = 1;
stud.name = "Detjon";
stud.age = 20;

// Updating the members of the struct student using Auto Dereferencing Dot Operator
student.id = 1;
student.name = "Detjon";
student.age = 20;
```

We see that they both use dot (.) operator to access the members of the struct. The only difference is that in the first example, we used the dot operator to access the members of the struct stud and in the second example, we used it to access the members of the struct student which is a pointer to a struct.

**The question is is that valid? If it is how it is possible?**

Actually the answer is no, it's not valid (for the most legacy compilers it will be considered as an error), but would it be cool if that was possible? If yes, how would we do it and why?

I used to forget using arrow operator (->) for accesing member of pointers to structs and insted used dot operator (.). The compiler always yelled at me which helped me to understand the problem. They are both smart and precise most of the time since they showed me the exact problem and the solution to that problem.

![Compilation error when trying to access members of a struct to a pointer with the dot operator.](./assets/images/dot_operator_on_pointer_error.jpg)

In the above picture it's obvious that the compiler is complaining about the error and I decided to patch the compiler which will not consider it as an error. I will reference to this feature as "Auto Dereferencing Dot Operator".

**Why C don't have The "Auto Dereferencing Dot Operator"?**

The question is why the C commite didn't implement it. Is there any problem? If so what are the reasons? Is a solution possible?
In the next section, I will discuss how to we can make it possible and the pros and cons of doing so.
