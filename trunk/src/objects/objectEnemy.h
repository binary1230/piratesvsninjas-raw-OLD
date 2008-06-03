#ifndef ENEMY_OBJECT_H
#define ENEMY_OBJECT_H

#include "stdafx.h"
#include "object.h"

class ObjectFactory;
class PlayerObject;

//! An enemy object that interacts with the player
class EnemyObject : public Object {
	protected:
		void MoveTowardsPlayer();
		PlayerObject* m_pkTargetPlayer;

		bool bCollidedLastFrame;
		Vector2D m_kCollisionDirection;
		int iTimeToWaitBeforeCollisionsAllowedAgain;
				
	public:
		bool Init();
		void Shutdown();
		
		void Update();

		EnemyObject();
		virtual ~EnemyObject();

		void Collide(Object* obj);

		virtual void ApplyForces();

		static int iSpawnedObjectCount;

		friend class ObjectFactory;
};

#endif // EnemyObject_H   
