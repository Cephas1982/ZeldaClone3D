#include "stdafx.h"
#ifndef GUI_H
#define GUI_H
#include <SdkTrays.h>

class C_GUI{
	
	public:
			C_GUI();
			~C_GUI();

			void Debug(OgreBites::SdkTrayManager* trayMgr, Ogre::SceneManager* ogre_scene_mgr);
	private:

			OgreBites::Label* p_output;	
			OgreBites::ParamsPanel* p_paramPanel;
			bool initDone;
};


#endif