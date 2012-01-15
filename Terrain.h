#include "stdafx.h"
#ifndef TERRAIN_H
#define TERRAIN_H
#include "Ogre.h"
#include "Definitions.h"

class C_Terrain{
	
	public:
			C_Terrain();
			~C_Terrain();

			void Load_plane(Ogre::SceneManager* ogre_scene_mgr);

	private:
			Ogre::SceneNode* p_terrainNode;

};

#endif