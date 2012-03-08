#include "stdafx.h"
#include "VisibleObjectManager.h"
#include "VisibleObject.h"
#include "Game.h"

// inserts a VisibleObject with corresponding std::string key
// into the object map
void VisibleObjectManager::addObject( std::string key, VisibleObject * object )
{
	_objects.insert( std::pair<std::string, VisibleObject *>( key, object ) );
}

// searches for the object of specified key
// PARAM key - the string name of the value
//			   desired
// TODO: implement a better error handling system - returning a VisibleObject is a rather 
//		 crappy solution
VisibleObject * VisibleObjectManager::getObject( std::string key )
{
	std::map<std::string, VisibleObject *>::iterator it = _objects.find( key );

	if( it != _objects.end() )
		return it->second;
	else
		return new VisibleObject(); // terrible way to handle this situation, buut I'm lazy right now
}

void VisibleObjectManager::updateObjects()
{
	std::map<std::string, VisibleObject *>::iterator it;
	float elapsedTime = Game::getWindow().GetFrameTime();

	// iterate through all the pairs in the map and update the second
	// item (i.e. the VisibleObject) of each pair
	for( it = _objects.begin(); it != _objects.end(); it++ )
	{
		it->second->update( elapsedTime );
	}
}

void VisibleObjectManager::displayObjects( sf::RenderWindow & window )
{
	std::map<std::string, VisibleObject *>::iterator it;

	// same as in updateObjects(), but this time draw the
	// objects' sprites to the screen
	for( it = _objects.begin(); it != _objects.end(); it++ )
	{
		it->second->display( window );
	}
}

std::map<std::string, VisibleObject *> VisibleObjectManager::_objects;