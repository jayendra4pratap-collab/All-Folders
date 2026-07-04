#include <iostream>
using namespace std;

// -------- Base Class --------
class Animal
{
public:
    virtual void makeSound()
    {
        cout << "Animal makes a sound" << endl;
    }

    virtual ~Animal() {} // good practice
};

// -------- Derived Class: Dog --------
class Dog : public Animal
{
public:
    void makeSound() override
    {
        cout << "Dog barks" << endl;
    }
};

// -------- Derived Class: Cat --------
class Cat : public Animal
{
public:
    void makeSound() override
    {
        cout << "Cat meows" << endl;
    }
};

// -------- Main Function --------
int main()
{
    // Array of base class pointers
    Animal* animals[2];

    // Assign derived class objects
    animals[0] = new Dog();
    animals[1] = new Cat();

    // Calling overridden functions
    for (int i = 0; i < 2; i++)
    {
        animals[i]->makeSound();  // runtime polymorphism
    }

    // Free memory
    for (int i = 0; i < 2; i++)
    {
        delete animals[i];
    }

    return 0;
}
