#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "\n--- Correct Polymorphism ---\n" << std::endl;

    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << " makes sound: ";
    dog->makeSound();
    std::cout << cat->getType() << " makes sound: ";
    cat->makeSound();
    std::cout << animal->getType() << " makes sound: ";
    animal->makeSound();

    delete animal;
    delete dog;
    delete cat;

    std::cout << "\n--- Wrong Polymorphism ---\n" << std::endl;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " makes sound: ";
    wrongCat->makeSound(); // ❌ WrongCat::makeSound is not virtual, so WrongAnimal::makeSound is called!
    std::cout << wrongAnimal->getType() << " makes sound: ";
    wrongAnimal->makeSound();

    delete wrongAnimal;
    delete wrongCat;

    return 0;
}
