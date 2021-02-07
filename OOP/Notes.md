# OOP

## Basic paradigm

In programming an object is nothing more than a piece of memory that can be used to store values.

**Variables are objects with a name.**

In traditional programming we use variables and functions, variables to store values with accessible names, that can be used for referencing their respective memory slots, and functions that work on the data we store in variables. That is, programs are lists of instructions to the computer that define data and then work with that data. In programs functions and variables are combined together to produce the desired results. Because of this separation between variables and functions, traditional programming often doesn't provide a very intuitive representation of reality. Programmers need to come up with an okay representation of reality and connect properties (variables) to the behaviors (functions).



**In object-oriented programming** objects represent real objects with properties and behaviours assigned to them. Objects have two major components to them:

- list of relevant properties, e.g. weight, color, size, etc.
- and some numbers of behaviors that they can exhibit, or do, e.g. being opened, making something else hot, etc.

**In OOP these properties and behaviours are inseparable, they belong to the object.**

OOP provides us with the ability to create objects that tie together both properties and behaviours into reusable package, but also these objects provide a more intuitive way to work with our data by allowing us to define how we interact with the objects, and how they interact with other objects.



## Classes

In object-oriented programming, we often want our types to not only hold data, such as structs do in C or C++, but provide functions that work with the data that we store. In C++ these are called classes. Class definitions are like a blueprint, they describe what the resulting object will look like, but they do not actually create the object, or an instance of the object.



### Member variables

Variables declared inside the class definition.



### Member functions

Classes can hold functions that work with the data. Functions defined inside classes are called member functions or methods in languages other than C++.



### Member types

In addition to member variables and member functions, classes can have member types or nested types, including type aliases. That is, we can "nickname" types, so when we need to change it, we only need to change it in one place. Basically, it reduces typing.



## Access specifiers

There are public and private members of classes. 

**Public members** of a class can be accessed from outside of the class, whilst **private members** can only be accessed from inside the class, by other members.

Generally, member variables are usually made private, and member functions are usually made public. We want to create instances of objects, that hold our data, but we cannot handle the data from outside the definition, just via its declared behaviours.

The group of public members of a class are often referred to as a public interface.



## Encapsulation

In object-oriented programming encapsulation, also called information hiding, is the process of keeping the details about how an object is implemented hidden away from the users of the object. Users of the object access the object only through a public interface. That means, we have a public interface with public methods, or member functions, and all the unnecessary member variables are hidden away from the users. They don't need to know how the object is implemented, how it's stores its information, how the methods are implemented, to make use of the object.

Benefits:

- encapsulated classes are easier to use, you only need to know its methods, what arguments they take, and what they return and reduce the complexity of your programs;
- encapsulated classes help protect your data and prevent misuse;
- encapsulated classes are easier to change, the implementation is independent, we can change the implementation completely, and the users would still be able to run the same application without changing a single line of code, assuming we haven't changed the function names.

<u>Access functions</u>

An access function is a short public function whose job is to retrieve or to change the value of a private member variable.

These are getters or setters, which get or set the value of such a variable.

<u>Constructors</u>

Are special functions that are called when creating or instantiating a new object.

<u>Destructors</u>

Are special functions that are called when destroying an object.



<u>RAII</u>

**Resource Acquisition is Initialization** is a programming technique whereby resource use is tied to the lifetime of objects with automatic duration. In C++, RAII is implemented via classes with constructors and destructors.

That is, we get hold of a resource when creating our object, or when calling its constructor. We can use this resource, such as a piece of memory, a file or a database while the object is alive. But, the resource is released when the destructor is called.

So, we use the resource only while the object is alive.



<u>This pointer</u>

The **this pointer** is a hidden const pointer that holds the address of the object the member function was called on.

If we return a *this pointer from a member function it allows us to chain member functions together. This simply means, that the member functions returns the address of the object on which it executed its instructions.



<u>Static member variables</u>

Static member variables are shared by all objects of a class and they are not associated with class objects. That is, we can access static member variables before an object is instantiated, and using the class name.

Also, they act like global variables, they are created when the program starts, and destroyed when the program ends.

<u>Static member functions</u>

Are functions that aren't tied to a particular object, thus they can be called before instantiating an object.



<u>Friend functions and classes</u>

In C++ a friend function is a function that can access the private members of a class as though it were a member of that class.



## Object relationships

### Composition

Complex objects built from simpler ones, when we build classes with data members, we're essentially constructing a complex object from simpler parts, which is composition.

To qualify as a composition, an object and a part must have the following relationship:

- the part is part of the object;
- the part can only belong to one object at a time;
- the part has its existence managed by the object;
- the part does not know about the existence of the object;

### Aggregation

To qualify as an aggregation, a whole object and its parts must have the following relationship:

- the part is part of the object;
- the part can belong to more than one object at a time;
- the part does not have its existence managed by the object;
- the part does not know about the existence of the object;

### Association

To qualify as an association, an object and another object must have the following relationship:

- the associated object is otherwise unrelated to the object;
- the associated object can belong to more than one object at a time;
- the associated object does not have its existence managed by the object;
- the associated object may or may not know about the existence of the boject;

### Dependency

A dependency occurs when one object invokes another object's functionality in order to accomplish some specific task.



## Basic principles of OOP

### Encapsulation

### Abstraction

### Inheritance

### Polymorphism