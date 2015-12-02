#ifndef ContactListener_H
#define ContactListener_H

#include "Debug.h"
#include "Box2D/Box2D.h"
#include "GameObject.h"
#include <vector>

//Responsible for handling Box2D Contacts.
//It implements b2ContactListener.
namespace GAME {
	class ContactListener : public b2ContactListener  {
	public:
		explicit ContactListener(std::vector<GameObject*>* sceneGameObjects);
		virtual ~ContactListener();

		/// Get rid of these
		ContactListener(const ContactListener&) = delete; 
		ContactListener(ContactListener &&) = delete;
		ContactListener& operator=(const ContactListener &) = delete;
		ContactListener& operator=(ContactListener &&) = delete;

		// TODO: Adam --> Coupling to Scene
		// Retrieves the GameObject with the respective bodyRef
		virtual GameObject* GetGameObjectWithBody(const b2Body& bodyRef) const;

		// b2ContactListener functions
		virtual void BeginContact(b2Contact* contact);
		virtual void EndContact(b2Contact* contact);
		virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
		virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);

	protected:
		std::vector<GameObject*>* gameObjects;

	};
}
#endif