#pragma once
#include <iPhysicsWorld.h>
#include <vector>
#include "cRigidBody.h"
#include "shapes.h"

#include <btBulletDynamicsCommon.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp> // <- This includes vec3 and mat4

namespace nPhysics
{
	class cPhysicsWorld : public iPhysicsWorld
	{
	public:
		virtual ~cPhysicsWorld();

		virtual void TimeStep(float deltaTime);

		virtual void AddRigidBody(iRigidBody* rigidBody);
		virtual void RemoveRigidBody(iRigidBody* rigidBody);

		void buildBulletWorld();

	private:
		btBroadphaseInterface * broadphase;
		btDefaultCollisionConfiguration* collisionConfiguration;
		btCollisionDispatcher* dispatcher;
		btSequentialImpulseConstraintSolver* solver;
		btDiscreteDynamicsWorld* dynamicsWorld;		
	};
}