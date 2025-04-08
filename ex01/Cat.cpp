#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Cat copied" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    Animal::operator=(other);
    std::cout << "Cat assigned" << std::endl;
    if (this != &other) {
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructed" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow! 🐱" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea) {
    brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return brain->getIdea(index);
}
