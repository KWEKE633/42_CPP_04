#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "--- BASIC TEST ---" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " makes sound: ";
    j->makeSound();

    std::cout << i->getType() << " makes sound: ";
    i->makeSound();

    delete j;
    delete i;

    std::cout << "\n--- ARRAY TEST ---" << std::endl;
    const int SIZE = 4;
    Animal* animals[SIZE];

    for (int i = 0; i < SIZE / 2; ++i)
        animals[i] = new Dog();
    for (int i = SIZE / 2; i < SIZE; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < SIZE; ++i)
        animals[i]->makeSound();

    for (int i = 0; i < SIZE; ++i)
        delete animals[i];

    std::cout << "\n--- DEEP COPY TEST ---" << std::endl;
    Dog original;
    original.setIdea(0, "Play fetch!");
    Dog copy = original;
    original.setIdea(0, "Chase tail!");
    std::cout << "original idea[0]: " << original.getIdea(0) << std::endl;
    std::cout << "copy idea[0]: " << copy.getIdea(0) << std::endl;
    std::cout << "\n--- END ---" << std::endl;
    return 0;
}
