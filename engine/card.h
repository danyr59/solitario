#ifndef CARD
#define CARD
/**
 * @class Card
 *
 **/

#include <string>
class Card {
private:
  std::string value;
  std::string familia;

public:
  Card() {}
  Card(std::string);
  void setValue(std::string);
  void setFamily(std::string);
  std::string getValue() const;
  std::string getFamily() const;
  ~Card();
};
#endif // !CARD
