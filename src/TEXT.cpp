#include"TEXT.h"
TEXT::TEXT()
{
    this->word.loadFromFile("resources/STHeiti Light.ttc");
    setFont(word);
    setCharacterSize(2);
}
