#ifndef VISIBLEOBJECTMANAGER_H
#define VISIBLEOBJECTMANAGER_H

#include "VisibleObject.h"

/********************************************************/
// VisibleObjectManager will store most of the drawn    //
// updatable objects. The objects can be retrieved,     //
// updated, and displayed by VisibleObjectManager.      //
/********************************************************/

class VisibleObjectManager
{
	public:
		static void addObject( std::string key, VisibleObject * object );
		static VisibleObject * getObject( std::string key );
		static void updateObjects();
		static void displayObjects( sf::RenderWindow & window );

	private:
		static std::map<std::string, VisibleObject *> _objects;
};

#endif // VISIBLEOBJECTMANAGER_H