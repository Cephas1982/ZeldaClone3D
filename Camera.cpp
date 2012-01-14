#include "stdafx.h"
#ifndef CAMERA_CPP
#define CAMERA_CPP

#include "Camera.h"


C_Camera::C_Camera()
{
	m_zMax = 1500; //maximum zoom
	m_zMin = 300;
}

C_Camera::~C_Camera()
{
}

void C_Camera::Update(Ogre::SceneManager* SceneMgr, Ogre::Camera* Camera, int planeSelected)
{
	//track player_1
	Ogre::Vector3 player_position = SceneMgr->getSceneNode("Player_1")->getPosition();

	Ogre::Vector3 cameraPos = Camera->getPosition();

	cameraPos.x = player_position.x;
	cameraPos.y = 600;
	cameraPos.z = player_position.z + 50;
	Camera->setPosition(cameraPos);//track player
	Camera->lookAt(player_position);
}

#endif