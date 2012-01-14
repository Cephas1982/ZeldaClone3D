#include "stdafx.h"
#include "Ogre.h"
#ifndef BASEENTITY_CPP
#define BASEENTITY_CPP
#include "BaseEntity.h"

C_BaseEntity::C_BaseEntity()
{
	m_degreeFacing = 0;
	initDone = false;
}

C_BaseEntity::~C_BaseEntity()
{

}

void C_BaseEntity::LoadPlayer(Ogre::SceneManager* sceneMgr)
{
	Ogre::Entity* player2 = sceneMgr->createEntity("Player_2", "sinbad.mesh");//load mesh
	p_playerNode = sceneMgr->getRootSceneNode()->createChildSceneNode("Player_2", Ogre::Vector3(10,0,0));//create node and hold the pointer for later use
	p_playerNode->attachObject(player2);//attach player entity to the new scene manager node
	p_playerNode->scale(2,2,2);
	

	
	Ogre::Entity* player = sceneMgr->createEntity("Player_1", "sinbad.mesh");//load mesh
	p_playerNode = sceneMgr->getRootSceneNode()->createChildSceneNode("Player_1", Ogre::Vector3(0,55,0));//create node and hold the pointer for later use
	p_playerNode->attachObject(player);//attach player entity to the new scene manager node
	p_playerNode->scale(8,8,8);

	m_position = p_playerNode->getPosition();
}
void C_BaseEntity::Controls(C_Input& input)
{

	m_velocity.x = 0;
	m_velocity.y = 0;
	m_velocity.z = 0;
	//up down left right
	if(input.up)
		m_velocity.z -= 2;

	if(input.down)
		m_velocity.z += 2;

	if(input.left)
		m_velocity.x -= 2;

	if(input.right)
		m_velocity.x += 2;

}
void C_BaseEntity::Move(OgreBites::SdkTrayManager* trayMgr)
{
	if(m_velocity.z > 40)
		m_velocity.z = 40;

	if(m_velocity.z < -40)
		m_velocity.z = -40;

	if(m_velocity.x > 40)
		m_velocity.x = 40;

	if(m_velocity.x < -40)
		m_velocity.x = -40;

	//face the correct direction
	if(m_velocity.z < 0 && m_degreeFacing != 180){//face up
		if(m_degreeFacing < 180){
			m_degreeFacing += 5;
			p_playerNode->yaw(Ogre::Degree(5), Ogre::Node::TS_PARENT);
		}
		if(m_degreeFacing > 180){
			m_degreeFacing -= 5;
			p_playerNode->yaw(Ogre::Degree(-5), Ogre::Node::TS_PARENT);
		}
	}
	if(m_velocity.z > 0 && m_degreeFacing != 0){//face down
		if(m_degreeFacing <= 180){
			m_degreeFacing -= 5;
			p_playerNode->yaw(Ogre::Degree(-5), Ogre::Node::TS_PARENT);
		}
		if(m_degreeFacing > 180){
			m_degreeFacing += 5;
			p_playerNode->yaw(Ogre::Degree(5), Ogre::Node::TS_PARENT);
		}
	}

	if(m_velocity.x < 0 && m_degreeFacing != 270){//face left
		if(m_degreeFacing >= 90  && !(m_degreeFacing > 270)){
			m_degreeFacing += 5;
			p_playerNode->yaw(Ogre::Degree(5), Ogre::Node::TS_PARENT);
		}
		if(m_degreeFacing < 90  || m_degreeFacing > 270){
			m_degreeFacing -= 5;
			p_playerNode->yaw(Ogre::Degree(-5), Ogre::Node::TS_PARENT);
		}
	}
	if(m_velocity.x > 0 && m_degreeFacing != 90){//face right
		if(m_degreeFacing <= 270 && !(m_degreeFacing < 90)){
			m_degreeFacing -= 5;
			p_playerNode->yaw(Ogre::Degree(-5), Ogre::Node::TS_PARENT);
		}
		if(m_degreeFacing > 270 || m_degreeFacing < 90){
			m_degreeFacing += 5;
			p_playerNode->yaw(Ogre::Degree(5), Ogre::Node::TS_PARENT);
		}
	}


	if(m_degreeFacing == 360)
		m_degreeFacing = 0;
	if(m_degreeFacing < 0)
		m_degreeFacing = 355;


	m_velocity.y = -m_position.y; //this offsets the player position so he doesn't float into space
	Ogre::Vector3 newPosition = m_velocity + m_position;
	p_playerNode->translate(newPosition);



	//OUTPUT
	if(!initDone){
		p_output = trayMgr->createLabel(OgreBites::TL_TOP, "TrayInfo", "", 500);
		initDone = true;
	}
	std::stringstream output;
	output << "angle facing: " << m_degreeFacing;
	
	trayMgr->moveWidgetToTray(p_output, OgreBites::TL_TOP, 0);
	p_output->show();
	p_output->setCaption(output.str());

}
#endif