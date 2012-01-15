#include "stdafx.h"
#ifndef LIGHTING_H
#define LIGHTING_H
#include "Ogre.h"

class C_Lighting{

	public:
			C_Lighting();
			~C_Lighting();

			void Init(Ogre::SceneManager* ogre_scene_mgr);

	private:
			Ogre::Light* directionalLight;
};
#endif