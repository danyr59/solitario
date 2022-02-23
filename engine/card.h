#ifndef CARD
#define CARD
/**
 * @class Card
 *
 **/

#include <initializer_list>
#include <iostream>
#include <string>
class Card {
private:
  std::string value;
  std::string familia;

public:
  Card() {}
  Card(std::initializer_list<std::string>);
  Card(std::string);
  void operator=(const Card &p1) {
    this->setValue(p1.getValue());
    this->setFamily(p1.getFamily());
    this->valor = p1.valor;
  }
  friend std::ostream &operator<<(std::ostream &o, const Card &card) {
    o << "{" << card.getValue() << "," << card.getFamily() << "," << card.valor
      << "}" << std::endl;
    return o;
  }
  void setValue(std::string);
  void setFamily(std::string);
  int valor;
  std::string getValue() const;
  std::string getFamily() const;
  ~Card();
};

#endif // !CARD
