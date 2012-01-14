#include "stdafx.h"
#ifndef BASEENTITY_H
#define BASEENTITY_H
#include "Ogre.h"
#include <sstream>
#include <SdkTrays.h>

#include "Input.h"
class C_BaseEntity{

	public:
			C_BaseEntity();
			~C_BaseEntity();

			void LoadPlayer(Ogre::SceneManager* ogre_scene_manager);
			void Controls(C_Input &user_inputs);
			void Move(OgreBites::SdkTrayManager* trayMgr);
			//void Render();//Done automatically

	private:
			Ogre::Vector3 m_position, m_velocity;
			Ogre::SceneNode* p_playerNode;
			int m_degreeFacing;
			OgreBites::Label* p_output;		

			bool initDone;
};
#endif