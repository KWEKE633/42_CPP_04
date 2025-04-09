#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    return 0;
}

// void printLine(std::string title) {
//     std::cout << "\n=== " << title << " ===\n" << std::endl;
// }

// int main() {
//     printLine("Create MateriaSource and Learn Materia");
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     // これ以上learnできない
//     src->learnMateria(new Ice());

//     printLine("Create Character and Equip Materia");
//     ICharacter* me = new Character("me");

//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);

//     // 装備できない (満杯)
//     tmp = src->createMateria("ice");
//     me->equip(tmp);

//     printLine("Use Materia on another character");
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob); // ice
//     me->use(1, *bob); // cure
//     me->use(2, *bob); // ice
//     me->use(3, *bob); // cure

//     // 存在しないスロット
//     me->use(4, *bob);

//     printLine("Unequip Materia");
//     me->unequip(2); // 2番目のiceを外す（消さない）
//     me->use(2, *bob); // もう使えない

//     printLine("Character Deep Copy Check");
//     Character* original = new Character("original");
//     tmp = src->createMateria("cure");
//     original->equip(tmp);

//     Character* copied = new Character(*original); // deep copy
//     delete original;

//     copied->use(0, *bob); // 元の "original" が消えても使える = deep copy成功

//     printLine("MateriaSource Deep Copy Check");
//     MateriaSource* src1 = new MateriaSource();
//     src1->learnMateria(new Ice());

//     MateriaSource* src2 = new MateriaSource(*src1); // deep copy

//     AMateria* m1 = src1->createMateria("ice");
//     AMateria* m2 = src2->createMateria("ice");

//     std::cout << "src1 materia type: " << m1->getType() << std::endl;
//     std::cout << "src2 materia type: " << m2->getType() << std::endl;

//     delete m1;
//     delete m2;

//     printLine("Try to create unknown materia");
//     AMateria* unknown = src->createMateria("fire");
//     if (!unknown)
//         std::cout << "Unknown materia type: fire (nullptr returned)" << std::endl;

//     printLine("Cleanup");
//     delete bob;
//     delete me;
//     delete copied;
//     delete src;
//     delete src1;
//     delete src2;

//     return 0;
// }
