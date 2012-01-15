#include "stdafx.h"
#ifndef LIGHTING_CPP
#define LIGHTING_CPP
#include "Lighting.h"

C_Lighting::C_Lighting()
{
}
C_Lighting::~C_Lighting()
{
}
void C_Lighting::Init(Ogre::SceneManager* sceneMgr)
{
	sceneMgr->setAmbientLight(Ogre::ColourValue(.9, .9, .6));
    sceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

	directionalLight = sceneMgr->createLight("directionalLight");
    directionalLight->setType(Ogre::Light::LT_DIRECTIONAL);
    directionalLight->setDiffuseColour(Ogre::ColourValue(1, 1, 1));
    directionalLight->setSpecularColour(Ogre::ColourValue(.5, .5, .5));

	directionalLight->setDirection(Ogre::Vector3( -1, -.8, 1 ));
}
#endif