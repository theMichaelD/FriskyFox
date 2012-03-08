#ifndef BATTLESCREEN_H
#define BATTLESCREEN_H

#include "stdafx.h"

/**********************************************/
// A trivial class meant only to provide	  //
// modularity to the game's battle screen	  //
// backgrounds. This will allow for the		  //
// game to easily switch backgrounds based	  //
// on the world's surrounding terrain.		  //
/*********************************************/
class BattleScreen
{
	public:
		static void setScreen( const sf::Image * image );
		static void displayScreen( sf::RenderWindow & window );

	private:
		static sf::Sprite _background;
};

#endif // BATTLESCREEN_H