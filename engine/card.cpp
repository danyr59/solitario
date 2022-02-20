#include "card.h"
#include <iostream>
#include <string.h>

Card::Card(std::string value) { this->value = value; }
void Card::setValue(std::string value) { this->value = value; }
void Card::setFamily(std::string value) { this->familia = value; }
std::string Card::getValue() const { return this->value; }
std::string Card::getFamily() const { return this->familia; }

Card::~Card() {}
