#include "stdafx.h"
#include "BackgroundObjectManager.h"
#include "VisibleObject.h"
#include "Game.h"

void BackgroundObjectManager::addObject( std::string key, std::vector<VisibleObject *> * objectSet )
{
	_objects.insert( std::pair<std::string, std::vector<VisibleObject *> *>( key, objectSet ) );
}

// TODO: better error stuffs in return here!!
std::vector<VisibleObject *> * BackgroundObjectManager::getObject( std::string key )
{
	std::map<std::string, std::vector<VisibleObject *> *>::iterator it = _objects.find( key );

	if( it != _objects.end() )
		return it->second;
	else
	{
		std::vector<VisibleObject *> * tempVect = new std::vector<VisibleObject *>();
		return tempVect;
	}
}

void BackgroundObjectManager::updateObjects()
{
	float elapsedTime = Game::getWindow().GetFrameTime();
	std::vector<VisibleObject *> * vect;						// create a pointer for the appropriate vector
	std::vector<VisibleObject *>::iterator vectItr;				// create an iterator of the appropriate type for the vector
	std::map<std::string, std::vector<VisibleObject *> *>::iterator mapItr;	// create an iterator for the map

	// iterate through all the map items
	for( mapItr = _objects.begin(); mapItr != _objects.end(); mapItr++ )
	{
		// assign the current map iterator's second value to the vector pointer
		vect = mapItr->second;
		// iterate through that vector
		for( vectItr = vect->begin(); vectItr < vect->end(); vectItr++ )
		{
			// update the objects in the vector
			(*vectItr)->update( elapsedTime );
		}
	}
}

void BackgroundObjectManager::displayObjects( sf::RenderWindow & window )
{
	std::vector<VisibleObject *> * vect;
	std::vector<VisibleObject *>::iterator vectItr;
	std::map<std::string, std::vector<VisibleObject *> *>::iterator mapItr;

	for( mapItr = _objects.begin(); mapItr != _objects.end(); mapItr++ )
	{
		vect = mapItr->second;
		for( vectItr = vect->begin(); vectItr < vect->end(); vectItr++ )
		{
			(*vectItr)->display( window );
		}
	}
}

std::map<std::string, std::vector<VisibleObject *> *> BackgroundObjectManager::_objects;