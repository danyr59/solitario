#ifndef CARD
#define CARD
/**
 * @class Card
 *
 **/

#include <initializer_list>
#include <string>
class Card {
private:
  std::string value;
  std::string familia;

public:
  Card() {}
  Card(std::initializer_list<std::string>);
  Card(std::string);
  void setValue(std::string);
  void setFamily(std::string);
  std::string getValue() const;
  std::string getFamily() const;
  ~Card();
};
#endif // !CARD
