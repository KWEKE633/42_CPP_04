#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int N = 4;
    Animal* animals[N];

    for (int i = 0; i < N / 2; ++i)
        animals[i] = new Dog();
    for (int i = N / 2; i < N; ++i)
        animals[i] = new Cat();

    std::cout << "\n--- Setting ideas ---" << std::endl;
    Dog* dog = dynamic_cast<Dog*>(animals[0]);
    Cat* cat = dynamic_cast<Cat*>(animals[N - 1]);

    if (dog) dog->setIdea(0, "I want a bone.");
    if (cat) cat->setIdea(0, "I want to nap.");

    std::cout << "\nDog idea: " << dog->getIdea(0) << std::endl;
    std::cout << "Cat idea: " << cat->getIdea(0) << std::endl;

    std::cout << "\n--- Deleting animals ---" << std::endl;
    for (int i = 0; i < N; ++i)
        delete animals[i];

    std::cout << "\n--- Deep copy test ---" << std::endl;
    Dog original;
    original.setIdea(0, "Catch the ball!");
    Dog copy = original;
    original.setIdea(0, "Sleep...");

    std::cout << "Original Dog idea: " << original.getIdea(0) << std::endl;
    std::cout << "Copied Dog idea:   " << copy.getIdea(0) << std::endl;

    return 0;
}
