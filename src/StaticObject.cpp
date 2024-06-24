#include "StaticObject.h"

StaticObject::StaticObject(b2World& world, const GameTextures texture, const sf::Vector2f location)
    :GameObject(texture, location), m_type(texture)

{

}

StaticObject::~StaticObject()
{
}
