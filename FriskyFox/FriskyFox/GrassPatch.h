#ifndef GRASSPATCH_H
#define GRASSPATCH_H

#include "stdafx.h"
#include "VisibleObject.h" //Acts like a java import. Must be included even if files are in same package.

/***********************************************/
// silly little animated patch of grass on the //
// screen. Will soon be stored in			   //
// BackgroundObjectManager once it is		   //
// implemented.								   //
/***********************************************/

class GrassPatch : public VisibleObject
{
public:
	GrassPatch();
	~GrassPatch();
	void update( float elapsedTime );

private:
	float _accumulatedTime; // accumulates time until a certain point; helps time the animation
	const static float MAX_TIME;
	bool _flipped;
};

#endif // GRASSPATCH_H