#ifndef PLAYERMOVES_H
#define PLAYERMOVES_H

#include "stdafx.h"
/********************************************************/
// Experimental set of structs which will provide a     //
// template for movesthat the player can know.		    //
/*******************************************************/
typedef struct
{
	int min;	// minimum damage
	int max;	// maximum damage
	float crit;	// multiplier for critical hit
} DamageRange;

typedef struct
{
	int cost;	// the amount by which the Special Meter is drained
} Move;

#endif // PLAYERMOVES_H