#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Dog copied" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    Animal::operator=(other);
    std::cout << "Dog assigned" << std::endl;
    if (this != &other) {
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructed" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! 🐶" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return brain->getIdea(index);
}
