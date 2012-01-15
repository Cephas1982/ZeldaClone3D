#include "stdafx.h"
#ifndef CAMERA_CPP
#define CAMERA_CPP

#include "Camera.h"


C_Camera::C_Camera()
{
}

C_Camera::~C_Camera()
{
}

void C_Camera::Update(Ogre::SceneManager* SceneMgr, Ogre::Camera* Camera, int planeSelected)
{
	//track player_1
	Ogre::Vector3 player_position = SceneMgr->getSceneNode("Player_1")->getPosition();
	Ogre::Vector3 cameraPos = Camera->getPosition();
	
	//set camera angle
	player_position.y +=15;
	cameraPos.x = player_position.x;
	cameraPos.y = 220;
	cameraPos.z = player_position.z + 600;


	//lock camera
	if(cameraPos.z > 1100)
		cameraPos.z = 1100;
	if(cameraPos.z < 100)
		cameraPos.z = 100;
	if(cameraPos.x < -500)
		cameraPos.x = -500;
	if(cameraPos.x > 500)
		cameraPos.x = 500;

	//Set camera
	Camera->setPosition(cameraPos);//track player
	Camera->lookAt(player_position);
}

#endif