#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "ImageManager.h"
#include "GrassPatch.h"
#include "Wall.h"
#include "Player.h"
#include "VisibleObject.h"
#include "VisibleObjectManager.h"
#include "BackgroundObjectManager.h"
#include "BattleScreen.h"
#include "HealthBar.h"
#include "CombatStats.h"
#include "TitleScreen.h"

// init() initializes all objects that will be in the game
// and starts the game loop
void Game::init()
{
	_window.Create( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, 32 ), "FriskyFox ver. 0.001" );

	/***********************************************************/
	// add images to the manager
	// add player image
	sf::Image * img = new sf::Image();  //Java equivalent: Image img = new Image();
	assert( img->LoadFromFile( "images/player.png" ) );  //assertTrue( img
	ImageManager::addImage( "player", img );

	// add grass patch image
	img = new sf::Image();
	assert( img->LoadFromFile( "images/grasspatch.png" ) );
	ImageManager::addImage( "grass patch", img );

	// add wall image
	img = new sf::Image();  
	assert( img->LoadFromFile( "images/wall.png" ) );
	ImageManager::addImage( "wall", img );

	// add battlescreen background
	img = new sf::Image();
	assert( img->LoadFromFile( "images/battlebkgd.png" ) );
	ImageManager::addImage( "battle screen", img );
	/***********************************************************/

	/*************************************************************/
	// Initialize and store game objects
	// Create a set of grass patches
	std::vector<VisibleObject *> * grass = new std::vector<VisibleObject *>();
	GrassPatch * patch;
	for( int i = 0; i < NUM_PATCHES; i++ )
	{
		patch = new GrassPatch();
		grass->push_back( patch );
	}
	BackgroundObjectManager::addObject( "grass", grass );

	// Create a set of walls
	std::vector<VisibleObject *> * walls = new std::vector<VisibleObject *>();
	Wall * wall;
	for( int i = 0; i < NUM_WALLS; i++ )
	{
		wall = new Wall();
		walls->push_back( wall );
	}
	BackgroundObjectManager::addObject( "walls", walls );

	// Create player
	Player * player = new Player();
	VisibleObjectManager::addObject( "player", player );
	/*************************************************************/

	_gameState = TITLE_SCREEN;

	while( _gameState != EXITING )
	{
		loop();
	}
	
	_window.Close();
}

void Game::loop()
{
	sf::Event ourEvent;
	_window.GetEvent( ourEvent );

	switch( _gameState )
	{
		// TODO: Implement LOADING, PAUSE_MENU, LEVELING(?), DEATH(?) cases
		case TITLE_SCREEN:
		{
			showTitle();
			_gameState = WORLD_MAP;
			break;
		}

		case MAIN_MENU:
		{
			break;
		}

		case WORLD_MAP:
		{
			// background color is the grass color for now
			_window.Clear( sf::Color( 31, 186, 67 ) );

			if( ourEvent.Type == sf::Event::Closed )
				_gameState = EXITING;

			if( ourEvent.Type == sf::Event::KeyPressed )
			{
				if( ourEvent.Key.Code == sf::Key::Escape )
					_gameState = EXITING;

				if( ourEvent.Key.Code == sf::Key::B )
					_gameState = BATTLE_SCREEN;
			}

			BackgroundObjectManager::updateObjects();
			// update the foreground objects after, or else the background sprites will be drawn on top of the foreground stuffs (e.g. player sprite )
			VisibleObjectManager::updateObjects();

			BackgroundObjectManager::displayObjects( _window );
			VisibleObjectManager::displayObjects( _window );

			_window.Display();

			break;
		}

		case BATTLE_SCREEN:
		{
			showBattle();
			_gameState = WORLD_MAP; // should be LEVELING or DEATH based on outcome of battle later on
			break;
		}
	}
}

void Game::showBattle()
{
	// Display battle background.......................CHECK
	// display battle menu
	// IF player turn:
	// get input
	// ELSE IF enemy turn:
	// resolve actions/effects + animations
	// check for player death or enemy death
	bool battling  = true;

	// there has to be a more efficient way for this...
	Player * pl = (Player*)VisibleObjectManager::getObject( "player" );
	CombatStats * plStats = pl->getCombatStats();
	HealthBar playerHealth( plStats->getHealth(), plStats->getMaxHealth() );
	
	sf::Event battleEvents;
	BattleScreen::setScreen( ImageManager::getImage( "battle screen" ) );

	while( battling )
	{
		_window.GetEvent( battleEvents );

		_window.Clear( sf::Color( 31, 186, 67 ) );
		BattleScreen::displayScreen( _window );
		// BattleMenu::displayMenu( _window );

		if( battleEvents.Type == sf::Event::KeyPressed )
		{
			if( battleEvents.Key.Code == sf::Key::A )
				plStats->useAttack();
			if( battleEvents.Key.Code == sf::Key::S )
				battling = false;
		}

		playerHealth.displayHealth( plStats->getHealth(), _window );
		_window.Display();
	}
}

void Game::showTitle()
{
	TitleScreen title;
	bool running = true;
	sf::Event myEvent;
	
	while( running )
	{
		_window.GetEvent( myEvent );
		_window.Clear( sf::Color( 0, 0, 0 ) );

		if( myEvent.Type == sf::Event::KeyPressed )
			running = false;

		title.displayScreen( _window );
		_window.Display();
	}
}

const sf::Input & Game::getInput()
{
	return _window.GetInput();
}

const sf::RenderWindow & Game::getWindow()
{
	return _window;
}

sf::RenderWindow Game::_window;
Game::GameState Game::_gameState = UNINITIALIZED;