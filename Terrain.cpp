#include "stdafx.h"
#ifndef TERRAIN_CPP
#define TERRAIN_CPP
#include "Terrain.h"

C_Terrain::C_Terrain()
{

}

C_Terrain::~C_Terrain()
{

}

void C_Terrain::Load_plane(Ogre::SceneManager* sceneMgr)
{
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

	Ogre::MeshManager::getSingleton().createPlane("ground",
												Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
												plane, 1500, 1500, 20, 20, true, 1, 5, 5,
												Ogre::Vector3::UNIT_Z);

	Ogre::Entity* entGround = sceneMgr->createEntity("GroundEntity", "ground");
	sceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entGround);

	entGround->setMaterialName("Examples/rough1-2");
	entGround->setCastShadows(false);
}
#endif