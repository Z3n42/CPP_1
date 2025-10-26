<div align="center">

# 🔷 C++ Piscine - Modules 00 to 04

### Introduction to Object-Oriented Programming in C++98

<p>
  <img src="https://img.shields.io/badge/Module_00-99%2F100-success?style=for-the-badge&logo=42" alt="CPP00 Score"/>
  <img src="https://img.shields.io/badge/Module_01-100%2F100-success?style=for-the-badge&logo=42" alt="CPP01 Score"/>
  <img src="https://img.shields.io/badge/Module_02-100%2F100-success?style=for-the-badge&logo=42" alt="CPP02 Score"/>
  <img src="https://img.shields.io/badge/Module_03-100%2F100-success?style=for-the-badge&logo=42" alt="CPP03 Score"/>
  <img src="https://img.shields.io/badge/Module_04-100%2F100-success?style=for-the-badge&logo=42" alt="CPP04 Score"/>
</p>

<p>
  <img src="https://img.shields.io/badge/Language-C++98-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++98"/>
  <img src="https://img.shields.io/badge/Compiler-c++-00599C?style=for-the-badge" alt="Compiler"/>
  <img src="https://img.shields.io/badge/Standard-C++98-blue?style=for-the-badge" alt="Standard"/>
  <img src="https://img.shields.io/badge/42-Urduliz-000000?style=for-the-badge&logo=42&logoColor=white" alt="42 Urduliz"/>
</p>

*A comprehensive journey through Object-Oriented Programming fundamentals, from basic C++ syntax to advanced polymorphism and design patterns.*

[Overview](#-overview) • [Modules](#-modules-breakdown) • [Concepts](#-key-concepts) • [Compilation](#-compilation)

</div>

---

## 📋 Table of Contents

- [Overview](#-overview)
- [Modules Breakdown](#-modules-breakdown)
- [Key C++ Concepts](#-key-c-concepts)
- [Project Structure](#-project-structure)
- [Compilation](#-compilation)
- [What I Learned](#-what-i-learned)
- [Resources](#-resources)

---

## 🎯 Overview

The **C++ Piscine** is a series of modules designed to introduce fundamental concepts of Object-Oriented Programming using **C++98 standard**. Each module builds upon the previous one, progressively introducing more advanced OOP concepts from basic class syntax to polymorphism and abstract interfaces.

### Summary Statistics

<table>
<tr>
<th>Module</th>
<th>Score</th>
<th>Exercises</th>
<th>Focus Area</th>
</tr>
<tr>
<td><b>CPP Module 00</b></td>
<td>99/100</td>
<td>3</td>
<td>C++ Basics, I/O, Classes</td>
</tr>
<tr>
<td><b>CPP Module 01</b></td>
<td>100/100</td>
<td>7</td>
<td>Memory, Pointers, References</td>
</tr>
<tr>
<td><b>CPP Module 02</b></td>
<td>100/100</td>
<td>4</td>
<td>Orthodox Canonical Form, Operators</td>
</tr>
<tr>
<td><b>CPP Module 03</b></td>
<td>100/100</td>
<td>4</td>
<td>Inheritance, Virtual Functions</td>
</tr>
<tr>
<td><b>CPP Module 04</b></td>
<td>100/100</td>
<td>4</td>
<td>Polymorphism, Abstract Classes, Interfaces</td>
</tr>
</table>

**Total**: 22 exercises covering the complete OOP spectrum

### Core Learning Areas

<table>
<tr>
<td width="50%" valign="top">

### 📚 OOP Fundamentals
- **Classes and objects** definition
- Member functions and attributes
- Access specifiers (public/private/protected)
- Constructors and destructors
- Static members and methods

</td>
<td width="50%" valign="top">

### 🧠 Memory Management
- **Stack vs Heap** allocation
- Pointers and references
- Deep copy vs shallow copy
- Memory leak prevention
- Resource management (RAII)

</td>
</tr>
<tr>
<td width="50%" valign="top">

### 🔄 Polymorphism
- **Function overloading**
- Operator overloading
- Inheritance hierarchies
- Virtual functions and vtables
- Abstract classes and interfaces

</td>
<td width="50%" valign="top">

### 🏗️ Design Patterns
- **Orthodox Canonical Form**
- Rule of Three
- Fixed-point arithmetic
- Multiple inheritance (Diamond Problem)
- Factory pattern basics

</td>
</tr>
</table>

---

## 📦 Modules Breakdown

### CPP Module 00 - Namespaces, Classes, I/O Streams (Score: 99/100)

**Topics**: Basic C++ syntax, namespaces, classes, member functions, stdio streams, initialization lists

<table>
<tr>
<th>Exercise</th>
<th>Files</th>
<th>Concept</th>
</tr>
<tr>
<td><b>ex00: Megaphone</b></td>
<td>megaphone.cpp</td>
<td>Basic I/O, string manipulation, toupper</td>
</tr>
<tr>
<td><b>ex01: My Awesome PhoneBook</b></td>
<td>Contact.hpp/cpp, Phonebook.hpp/cpp, blacklist.cpp</td>
<td>Classes, arrays of objects, interactive program</td>
</tr>
<tr>
<td><b>ex02: The Job Of Your Dreams</b></td>
<td>Account.hpp/cpp, tests.cpp</td>
<td>Static members, timestamps, log formatting</td>
</tr>
</table>

**Key Implementation**: PhoneBook stores 8 contacts with first name, last name, nickname, phone number, and darkest secret. Implements ADD, SEARCH, and EXIT commands with formatted table output.

---

### CPP Module 01 - Memory Allocation, Pointers, References (Score: 100/100)

**Topics**: Memory allocation, pointers to members, references, switch statement

<table>
<tr>
<th>Exercise</th>
<th>Files</th>
<th>Concept</th>
</tr>
<tr>
<td><b>ex00: BraiiiiiiinnnzzzZ</b></td>
<td>Zombie.hpp/cpp, main.cpp, randomChump.cpp, newZombie.cpp</td>
<td>Stack vs Heap allocation</td>
</tr>
<tr>
<td><b>ex01: Moar brainz!</b></td>
<td>Zombie.hpp/cpp, ZombieHorde.cpp, main.cpp</td>
<td>Array of objects, heap allocation</td>
</tr>
<tr>
<td><b>ex02: HI THIS IS BRAIN</b></td>
<td>main.cpp</td>
<td>Pointers vs references comparison</td>
</tr>
<tr>
<td><b>ex03: Unnecessary violence</b></td>
<td>Weapon.hpp/cpp, HumanA.hpp/cpp, HumanB.hpp/cpp, main.cpp</td>
<td>References vs pointers in practice</td>
</tr>
<tr>
<td><b>ex04: Sed is for losers</b></td>
<td>main.cpp</td>
<td>File I/O, string replacement</td>
</tr>
<tr>
<td><b>ex05: Harl 2.0</b></td>
<td>Karen.hpp/cpp, main.cpp</td>
<td>Pointers to member functions</td>
</tr>
<tr>
<td><b>ex06: Harl filter</b></td>
<td>Karen.hpp/cpp, main.cpp</td>
<td>Switch statement, log filtering</td>
</tr>
</table>

**Key Insight**: HumanA always has a Weapon (reference), HumanB may not have one (pointer). Demonstrates when to use references vs pointers.

---

### CPP Module 02 - Ad-hoc Polymorphism, Operator Overloading (Score: 100/100)

**Topics**: Orthodox Canonical Form, operator overloading, fixed-point numbers

<table>
<tr>
<th>Exercise</th>
<th>Files</th>
<th>Concept</th>
</tr>
<tr>
<td><b>ex00: My First Orthodox Class</b></td>
<td>Fixed.hpp/cpp, main.cpp</td>
<td>Orthodox Canonical Form basics</td>
</tr>
<tr>
<td><b>ex01: Towards a more useful fixed-point number class</b></td>
<td>Fixed.hpp/cpp, main.cpp</td>
<td>Type conversions (int/float to Fixed)</td>
</tr>
<tr>
<td><b>ex02: Now we're talking</b></td>
<td>Fixed.hpp/cpp, main.cpp</td>
<td>Arithmetic and comparison operators</td>
</tr>
<tr>
<td><b>ex03: BSP</b></td>
<td>Fixed.hpp/cpp, Point.hpp/cpp, main.cpp</td>
<td>Binary Space Partitioning, geometric algorithms</td>
</tr>
</table>

**Orthodox Canonical Form** (implemented in all exercises):
- Default constructor
- Copy constructor  
- Copy assignment operator
- Destructor

**Fixed-point class**: Represents fixed-point numbers with 8 fractional bits (256 divisions per integer).

<details>
<summary><b>Fixed-Point Arithmetic Implementation</b></summary>

class Fixed {
private:
int _fixedPointValue;
static const int _fractionalBits = 8;

public:
Fixed();
Fixed(const int n);
Fixed(const float f);
Fixed(const Fixed &copy);
Fixed &operator=(const Fixed &rhs);
~Fixed();

int     getRawBits(void) const;
void    setRawBits(int const raw);
float   toFloat(void) const;
int     toInt(void) const;

// Comparison operators
bool    operator>(const Fixed &rhs) const;
bool    operator<(const Fixed &rhs) const;
bool    operator>=(const Fixed &rhs) const;
bool    operator<=(const Fixed &rhs) const;
bool    operator==(const Fixed &rhs) const;
bool    operator!=(const Fixed &rhs) const;

// Arithmetic operators
Fixed   operator+(const Fixed &rhs) const;
Fixed   operator-(const Fixed &rhs) const;
Fixed   operator*(const Fixed &rhs) const;
Fixed   operator/(const Fixed &rhs) const;

// Increment/Decrement
Fixed   &operator++();      // Pre-increment
Fixed   operator++(int);    // Post-increment
Fixed   &operator--();      // Pre-decrement
Fixed   operator--(int);    // Post-decrement

// Min/Max static functions
static Fixed &min(Fixed &a, Fixed &b);
static const Fixed &min(const Fixed &a, const Fixed &b);
static Fixed &max(Fixed &a, Fixed &b);
static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

</details>

---

### CPP Module 03 - Inheritance (Score: 100/100)

**Topics**: Inheritance, derived classes, virtual functions, multiple inheritance

<table>
<tr>
<th>Exercise</th>
<th>Files</th>
<th>Concept</th>
</tr>
<tr>
<td><b>ex00: Aaaaand... OPEN!</b></td>
<td>ClapTrap.hpp/cpp, main.cpp</td>
<td>Base class with attributes and methods</td>
</tr>
<tr>
<td><b>ex01: Serena, my love!</b></td>
<td>ScavTrap.hpp/cpp, ClapTrap files, main.cpp</td>
<td>Simple inheritance from ClapTrap</td>
</tr>
<tr>
<td><b>ex02: Repetitive work</b></td>
<td>FragTrap.hpp/cpp, ScavTrap files, main.cpp</td>
<td>Multiple derived classes</td>
</tr>
<tr>
<td><b>ex03: Now it's weird!</b></td>
<td>DiamondTrap.hpp/cpp, FragTrap, ScavTrap, ClapTrap files</td>
<td>Multiple inheritance, Diamond Problem, virtual inheritance</td>
</tr>
</table>

**Inheritance Hierarchy**:

ClapTrap (base)
├── ScavTrap (inherits ClapTrap)
├── FragTrap (inherits ClapTrap)
└── DiamondTrap (inherits BOTH ScavTrap AND FragTrap)

**ClapTrap attributes**: Name, Hit points (10), Energy points (10), Attack damage (0)
**ScavTrap**: HP 100, EP 50, AD 20 + special `guardGate()`
**FragTrap**: HP 100, EP 100, AD 30 + special `highFivesGuys()`
**DiamondTrap**: Multiple inheritance with virtual inheritance to solve diamond problem

<details>
<summary><b>Diamond Problem Solution</b></summary>

// Virtual inheritance prevents duplicate ClapTrap base
class ScavTrap : virtual public ClapTrap { /* ... / };
class FragTrap : virtual public ClapTrap { / ... */ };

class DiamondTrap : public ScavTrap, public FragTrap {
private:
std::string _name; // DiamondTrap's own name

public:
DiamondTrap(std::string name);
DiamondTrap(const DiamondTrap &copy);
DiamondTrap &operator=(const DiamondTrap &rhs);
~DiamondTrap();

void    whoAmI();  // Displays both names

// Inherits attack() from ScavTrap (must specify)
using ScavTrap::attack;
};

The Diamond Problem occurs when a class inherits from two classes that share a common base. **Virtual inheritance** ensures only one instance of ClapTrap exists in DiamondTrap.

</details>

---

### CPP Module 04 - Subtype Polymorphism, Abstract Classes (Score: 100/100)

**Topics**: Polymorphism, abstract classes, interfaces, deep copy

<table>
<tr>
<th>Exercise</th>
<th>Files</th>
<th>Concept</th>
</tr>
<tr>
<td><b>ex00: Polymorphism</b></td>
<td>Animal.hpp/cpp, Dog.hpp/cpp, Cat.hpp/cpp, main.cpp</td>
<td>Virtual functions, polymorphic behavior</td>
</tr>
<tr>
<td><b>ex01: I don't want to set the world on fire</b></td>
<td>Brain.hpp/cpp, Dog.cpp, Cat.cpp, main.cpp</td>
<td>Deep copy, memory management in inheritance</td>
</tr>
<tr>
<td><b>ex02: Abstract class</b></td>
<td>Animal.hpp (abstract), WrongAnimal.hpp/cpp, WrongCat.hpp/cpp</td>
<td>Pure virtual functions, abstract base classes</td>
</tr>
<tr>
<td><b>ex03: Interface & recap</b></td>
<td>AMateria, Ice, Cure, Character, MateriaSource (2 versions)</td>
<td>Interface design, factory pattern, inventory system</td>
</tr>
</table>

**Polymorphism in Action**:

Animal* animal = new Dog(); // Polymorphism
animal->makeSound(); // Calls Dog's makeSound() (virtual)
delete animal; // Calls Dog's destructor (virtual)

**Abstract Class**: Animal with pure virtual function `makeSound() = 0` cannot be instantiated.

**Brain Class**: Each Dog and Cat has a `Brain*` member with 100 ideas. Requires deep copy implementation to avoid shallow copy issues.

<details>
<summary><b>Deep Copy Implementation</b></summary>

class Brain {
private:
std::string ideas;

public:
Brain();
Brain(const Brain &copy); // Deep copy constructor
Brain &operator=(const Brain &rhs); // Deep copy assignment
~Brain();
};

class Dog : public Animal {
private:
Brain* brain;

public:
Dog();
Dog(const Dog &copy) : Animal(copy) {
this->brain = new Brain(*copy.brain); // Deep copy
}
Dog &operator=(const Dog &rhs) {
if (this != &rhs) {
Animal::operator=(rhs);
delete this->brain;
this->brain = new Brain(*rhs.brain); // Deep copy
}
return *this;
}
~Dog() { delete brain; }

void makeSound() const;  // Override
};

**Why Deep Copy?**: Prevents two objects from pointing to the same Brain memory, which would cause double-free errors.

</details>

**Materia System** (ex03): Implements RPG-style inventory with abstract `AMateria` interface, concrete `Ice` and `Cure` classes, `Character` with 4-slot inventory, and `MateriaSource` as a factory pattern for creating materias.

---

## 🔑 Key C++ Concepts

### Orthodox Canonical Form

The **Orthodox Canonical Form** is a C++98 requirement for robust classes that manage resources. It consists of four essential components:

1. **Default Constructor**: Initializes object with default values
2. **Copy Constructor**: Creates new object as copy of existing one
3. **Copy Assignment Operator**: Assigns one existing object to another
4. **Destructor**: Cleans up resources when object is destroyed

class MyClass {
public:
MyClass(); // Default constructor
MyClass(const MyClass &copy); // Copy constructor
MyClass &operator=(const MyClass &rhs); // Copy assignment operator
~MyClass(); // Destructor
};

### Rule of Three

If a class needs **any one** of these three, it probably needs **all three**:
- Destructor
- Copy constructor
- Copy assignment operator

This applies to classes that manage dynamic resources (heap memory, file handles, etc.).

### Virtual Functions and Polymorphism

**Virtual functions** enable runtime polymorphism:

class Base {
public:
virtual void func() { std::cout << "Base"; }
virtual ~Base() {} // Virtual destructor is essential!
};

class Derived : public Base {
public:
void func() { std::cout << "Derived"; } // Override
};

Base* ptr = new Derived();
ptr->func(); // Prints "Derived" (polymorphism)
delete ptr; // Calls Derived destructor then Base destructor

**Pure Virtual Function**: `virtual void func() = 0;` makes class abstract (cannot be instantiated).

### Memory Management Patterns

**Stack Allocation** (automatic):
MyClass obj; // Destructor called automatically when out of scope

**Heap Allocation** (manual):
MyClass* ptr = new MyClass(); // Must manually delete
delete ptr; // Calls destructor

**RAII Pattern**: Resource Acquisition Is Initialization - resources are acquired in constructor and released in destructor.

---

## 📁 Project Structure
```
cpp_module_00-04/
│
├── cpp00_pass/ # Module 00 (Score: 99/100)
│ ├── ex00/ # Megaphone
│ │ └── megaphone.cpp
│ ├── ex01/ # Phonebook
│ │ ├── Contact.hpp
│ │ ├── Phonebook.hpp
│ │ ├── contact.cpp
│ │ ├── phonebook.cpp
│ │ ├── blacklist.cpp
│ │ └── Makefile
│ └── ex02/ # Account
│ ├── Account.hpp
│ ├── Account.cpp
│ ├── tests.cpp
│ └── Makefile
│
├── cpp01_pass/ # Module 01 (Score: 100/100)
│ ├── ex00/ # BraiiiiiiinnnzzzZ
│ ├── ex01/ # Moar brainz!
│ ├── ex02/ # HI THIS IS BRAIN
│ ├── ex03/ # Unnecessary violence
│ ├── ex04/ # Sed is for losers
│ ├── ex05/ # Karen
│ └── ex06/ # Karen filter
│
├── cpp02_pass/ # Module 02 (Score: 100/100)
│ ├── ex00/ # Orthodox Canonical Form
│ ├── ex01/ # Fixed-point conversions
│ ├── ex02/ # Operators overload
│ └── ex03/ # BSP (Point in triangle)
│
├── cpp03_pass/ # Module 03 (Score: 100/100)
│ ├── ex00/ # ClapTrap
│ ├── ex01/ # ScavTrap (inheritance)
│ ├── ex02/ # FragTrap
│ └── ex03/ # DiamondTrap (multiple inheritance)
│
└── cpp04_pass/ # Module 04 (Score: 100/100)
├── ex00/ # Animal polymorphism
├── ex01/ # Brain deep copy
├── ex02/ # Abstract classes
└── ex03/ # Materia interface system
```

**Total**: 5 modules, 22 exercises, ~80+ source files

---

## ⚙️ Compilation

All exercises use a standard Makefile with C++98 compilation flags:

NAME = exercise_name

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp ClassName.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
rm -f $(OBJS)

fclean: clean
rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

**Compilation Flags**:
- `-Wall -Wextra -Werror`: All warnings as errors
- `-std=c++98`: Enforce C++98 standard (no C++11 features)

**Forbidden**: STL containers (vector, list, map, etc.) except in Module 08+

---

## 💡 What I Learned

Through these five modules, comprehensive understanding was gained in:

**C++ Fundamentals**:
- ✅ Differences between C and C++ (namespaces, references, function overloading)
- ✅ Class design and encapsulation principles
- ✅ Access specifiers and member visibility
- ✅ Static members vs instance members

**Memory Management**:
- ✅ Stack vs heap allocation strategies
- ✅ When to use pointers vs references
- ✅ Deep copy vs shallow copy implications
- ✅ RAII pattern for resource management
- ✅ Memory leak detection and prevention

**Object-Oriented Programming**:
- ✅ Four pillars: Encapsulation, Abstraction, Inheritance, Polymorphism
- ✅ Constructor/destructor call order in inheritance
- ✅ Virtual functions and dynamic dispatch
- ✅ Abstract classes and pure virtual functions
- ✅ Multiple inheritance and the Diamond Problem

**Operator Overloading**:
- ✅ Arithmetic operators (+, -, *, /)
- ✅ Comparison operators (<, >, ==, !=, <=, >=)
- ✅ Increment/decrement operators (++, --)
- ✅ Stream insertion operator (<<)
- ✅ Assignment operator (=)

**Design Patterns**:
- ✅ Orthodox Canonical Form (Rule of Three)
- ✅ Factory pattern (MateriaSource)
- ✅ Interface design (AMateria abstract class)
- ✅ Composition vs Inheritance trade-offs

**Best Practices**:
- ✅ Always make destructors virtual in base classes
- ✅ Use const correctness for read-only methods
- ✅ Initialize all member variables in constructors
- ✅ Implement deep copy when managing dynamic resources
- ✅ Follow naming conventions (Hungarian notation for members)

---

## 📚 Resources

**Official Documentation**:
- [cppreference.com](https://en.cppreference.com/) - C++ language reference
- [C++ FAQ](https://isocpp.org/faq) - ISO C++ FAQ

**Key Topics**:
- **Orthodox Canonical Form**: [LearnCpp.com](https://www.learncpp.com/)
- **Virtual Functions**: Understanding vtables and dynamic dispatch
- **Diamond Problem**: Virtual inheritance solution
- **Operator Overloading**: Syntax and best practices
- **Fixed-Point Arithmetic**: Binary representation with fractional bits

**C++98 Standard Restrictions**:
- No `nullptr` (use `NULL` or `0`)
- No `auto` keyword
- No range-based for loops
- No lambda functions
- No `std::array` (use C-style arrays)

---

## 🔗 Related Projects

These modules prepare for:
- **CPP Modules 05-09**: Advanced topics (exceptions, templates, STL, iterators)
- **webserv**: HTTP server in C++98
- **ft_irc**: IRC server implementation

Skills learned apply to:
- Any C++ software development
- Object-oriented system design
- Memory management in systems programming
- Game engine architecture

---

<div align="center">

**Made with ☕ by [Iñigo Gonzalez](https://github.com/Z3n42)**

*42 Urduliz | C++ Piscine | Circle 3*

[![42 Profile](https://img.shields.io/badge/42_Intra-ingonzal-000000?style=flat&logo=42&logoColor=white)](https://profile.intra.42.fr/users/ingonzal)

</div>
