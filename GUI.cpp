#include "stdafx.h"
#ifndef GUI_CPP
#define GUI_CPP
#include "GUI.h"
C_GUI::C_GUI()
{
	initDone = false;
}
C_GUI::~C_GUI()
{
}
void C_GUI::Debug(OgreBites::SdkTrayManager* trayMgr, Ogre::SceneManager* sceneMgr)
{
		//OUTPUT
	if(!initDone){
	//	p_output = trayMgr->createLabel(OgreBites::TL_TOPRIGHT, "TrayInfo", "", 200);
		initDone = true;

		//Make string vector
		Ogre::StringVector items;
		items.push_back("cam.pX");
		items.push_back("cam.pY");
		items.push_back("cam.pZ");
		items.push_back("");		
		items.push_back("Filtering");
		items.push_back("Poly Mode");
		items.push_back("");
		items.push_back("Player1.x");
		items.push_back("Player1.z");

		//Create panel to hold string vector then assign data to read
		p_paramPanel = trayMgr->createParamsPanel(OgreBites::TL_TOPRIGHT, "DetailsPanel", 200, items);
	}

	//Get camera pointer
	Ogre::Camera* cameraPtr = sceneMgr->getCamera("PlayerCam");
	//Get player pointer
	Ogre::SceneNode* player1 = sceneMgr->getSceneNode("Player_1");




	//Get coordinates
	p_paramPanel->setParamValue(0, Ogre::StringConverter::toString(cameraPtr->getDerivedPosition().x));
    p_paramPanel->setParamValue(1, Ogre::StringConverter::toString(cameraPtr->getDerivedPosition().y));
    p_paramPanel->setParamValue(2, Ogre::StringConverter::toString(cameraPtr->getDerivedPosition().z));
    p_paramPanel->setParamValue(4, "Bilinear");
    p_paramPanel->setParamValue(5, "Solid");
	p_paramPanel->setParamValue(7, Ogre::StringConverter::toString(player1->getPosition().x));
	p_paramPanel->setParamValue(8, Ogre::StringConverter::toString(player1->getPosition().z));

	p_paramPanel->show();

/*
	trayMgr->moveWidgetToTray(p_output, OgreBites::TL_TOP, 0);
	p_output->show();
	p_output->setCaption(output.str());
	*/
}
#endif