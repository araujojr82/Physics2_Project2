#include "cPhysicsWorld.h"
#include <algorithm>

#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>

const glm::vec3 GRAVITY = glm::vec3( 0.0f, 0.0f, -9.82f );

namespace nPhysics
{
	void cPhysicsWorld::buildBulletWorld()
	{
		this->broadphase = new btDbvtBroadphase();
		this->collisionConfiguration = new btDefaultCollisionConfiguration();
		this->dispatcher = new btCollisionDispatcher( collisionConfiguration );
		this->solver = new btSequentialImpulseConstraintSolver;
		this->dynamicsWorld = new btDiscreteDynamicsWorld( dispatcher, broadphase, solver, collisionConfiguration );
		dynamicsWorld->setGravity( btVector3( 0, 0, -9.82 ) );

		return;
	}	

	cPhysicsWorld::~cPhysicsWorld()
	{
		return;
	}

	void cPhysicsWorld::TimeStep( float deltaTime )
	{			
		btScalar btdeltaTime = deltaTime;
		dynamicsWorld->stepSimulation( btdeltaTime );
		return;
	}

	void cPhysicsWorld::AddRigidBody( nPhysics::iRigidBody* rigidBody )
	{
		cRigidBody* rb = dynamic_cast< cRigidBody* >( rigidBody );
		
		this->dynamicsWorld->addRigidBody( rb->myBulletBody );

		return;
	}

	void cPhysicsWorld::RemoveRigidBody( nPhysics::iRigidBody* rigidBody )
	{
		cRigidBody* rb = dynamic_cast< cRigidBody* >( rigidBody );
		this->dynamicsWorld->removeRigidBody( rb->myBulletBody );
		return;
	}

}