#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include "stdafx.h"

/******************************************************/
// TitleScreen is a class with that will store all	  //
// the necessary objects to display the title screen  //
// on the window.									  //
/*****************************************************/
class TitleScreen
{
	public:
		TitleScreen()
		{
			assert( _image.LoadFromFile( "images/titlescreen.png" ) );
			_sprite.SetImage( _image );
		}

		~TitleScreen() { }

		void displayScreen( sf::RenderWindow & window )
		{
			window.Draw( _sprite );
		}

	private:
		sf::Image _image;
		sf::Sprite _sprite;
};

#endif // TITLESCREEN_H