#ifndef GAME_H //If game has not been included..
#define GAME_H //Include the game.

#include "stdafx.h" //"Use pre-compiled headers.  Only compiles the headers once -> speeds up build time.
// ^ These are files that are always the same.  They are not re-compiled with each build which sames time.

/*********************************************************************/
// Game is the static class which handles all of the initializition, //
// looping, and destruction of the game.							 //
/*********************************************************************/

class Game
{
	public: //All of the public fields/methods are listed below:
		static void init();  //A public method in Game.cpp
		//The following "sf" methods are from the SFML library:

		//Analysis of this line:
		//This is the name of the fuction in the corresponding source file.
		//The return type - sf::Input - sf is the SFML namespace/library and Input is the SFML class
		//& - returns a reference instead of a copy - which means this method can modify the original object
		//getInput() the name of the method - which is detailed in the .cpp file.
		const static sf::Input & getInput();  // static Input getInput() { return input; }
		  
		const static sf::RenderWindow & getWindow(); //getWindow returns a type RenderWindow which is in the sf library.
		const static int SCREEN_WIDTH = 1024;  //Width of the game screen.
		const static int SCREEN_HEIGHT = 768;  //Height of the game screen.
		
		//Analysis of this line:
		//GameState is the variable name of the enum (obviously).
		//The contents of the enum can be refered to by 0,1,...8 (unless other values are given)
		//Each of these represents the possible game states. Any game states not included are not valid.
		//i.e. GameState state = UNINITIALIZED   or   GameState state = 0
		enum GameState { UNINITIALIZED, 
						 TITLE_SCREEN,
						 MAIN_MENU,
						 PAUSE_MENU,
						 WORLD_MAP,
						 BATTLE_SCREEN,
						 LOADING,
						 EXITING
					   };
	private: //All of the private fields/methods are listed below:
		const static int NUM_PATCHES = 25;
		const static int NUM_WALLS = 11;
		static sf::RenderWindow _window;  //The variable for RenderWindow (from the SFML library)
		static GameState _gameState;  //The variable for the GameState num
		
		//All are private methods:
		static void loop(); 
		static void showBattle();
		static void showTitle();
};

#endif // GAME_H
//Ends the #ifndef preprocssor statement.  This means that nothing after this point is included.