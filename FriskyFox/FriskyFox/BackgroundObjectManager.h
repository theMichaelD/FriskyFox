#ifndef BACKGROUNDOBJECTMANAGER_H
#define BACKGROUNDOBJECTMANAGER_H

#include "stdafx.h"

/**********************************************************/
// BackgroundObjectManager handles the objects to be	  //
// drawn in the background. This will be called to update //
// before the foreground objects, so that the background  //
// objects are not drawn on top of them.				  //
/**********************************************************/

class VisibleObject;

class BackgroundObjectManager
{
	public:
		static void addObject( std::string key, std::vector<VisibleObject *> * objectSet );
		static std::vector<VisibleObject *> * getObject( std::string key );
		static void updateObjects();
		static void displayObjects( sf::RenderWindow & window );

	private:
		static std::map<std::string, std::vector<VisibleObject *> *> _objects;
};

#endif // BACKGROUNDOBJECTMANAGER_H