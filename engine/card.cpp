#include "card.h"
#include <iostream>
#include <string.h>

Card::Card(std::string value) { this->value = value; }
Card::Card(std::initializer_list<std::string> list) {

  int i = 0;
  for (auto a : list) {

    if (i == 0) {
      this->value = a;
    }
    if (i == 1) {
      this->familia = a;
    }
    if (i == 2) {
      this->valor = std::stoi(a);
    }

    i++;
  }
}

void Card::setValue(std::string value) { this->value = value; }
void Card::setFamily(std::string value) { this->familia = value; }
std::string Card::getValue() const { return this->value; }
std::string Card::getFamily() const { return this->familia; }

Card::~Card() {}
