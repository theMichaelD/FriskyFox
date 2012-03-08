#ifndef WALL_H
#define WALL_H

#include "stdafx.h"
#include "VisibleObject.h"

/***********************************************************************/
// Wall is currently just for testing some collision implementation,   //
// but could be used as a "template" for other upcoming objects which  //
// cannot be passed through.							
/***********************************************************************/

class Wall : public VisibleObject
{
	public:
		Wall();
		~Wall();
		void update( float elapsedTime );

	private:

};

#endif // WALL_H