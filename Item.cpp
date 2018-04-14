#include <iomanip>

#include "Item.h"

/**
 *
 */
Item::Item()
    :name("Air")
{
    this->id   = 0;
}

/**
 *
 */
Item::Item(int id)
    :name()
{
    this->id = id;
}

/**
 *
 */
Item::Item(int id, std::string name)
    :name(name)
{
    this->id   = id;
}

/**
 *
 */
void Item::display(std::ostream &outs) const
{
    outs << std::right << std::setw(3) << id << " " << name;  
}