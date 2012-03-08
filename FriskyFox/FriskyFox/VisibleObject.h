#ifndef VISIBLEOBJECT_H
#define VISIBLEOBJECT_H

#include "stdafx.h"

/*********************************************/
// VisibleObject is the base class to all the
// objects that will be drawn to the game
// screen while playing.
/*********************************************/

class VisibleObject
{
	public:
		VisibleObject();
		virtual ~VisibleObject();
		virtual void update( float elapsedTime );
		virtual void display( sf::RenderWindow & window ); // as of now, the only function to actually have an implementation

	protected:
		sf::Sprite _sprite;
};

#endif // VISIBLEOBJECT_H