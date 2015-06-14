#include <iostream>
#include"Plane.h"
#include "bullet.h"
using std::cout;
using std::endl;
void Plane::fire(int i)
{
    this->gun.fire(i);
}
