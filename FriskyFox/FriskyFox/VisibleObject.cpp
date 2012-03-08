#include "stdafx.h"
#include "VisibleObject.h"

VisibleObject::VisibleObject()
{ }

VisibleObject::~VisibleObject()
{ }

void VisibleObject::update( float elapsedTime )
{ }

// display draws the sprite to the screen
// PARAM window - the window onto which the
//				  sprite will be rendered
void VisibleObject::display( sf::RenderWindow & window )
{
	window.Draw( _sprite );
}