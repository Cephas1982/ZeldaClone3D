#include "stdafx.h"
#include "Ogre.h"
#ifndef BASEENTITY_CPP
#define BASEENTITY_CPP
#include "BaseEntity.h"

C_BaseEntity::C_BaseEntity()
{
	m_degreeFacing = 0;
}

C_BaseEntity::~C_BaseEntity()
{

}

void C_BaseEntity::LoadPlayer(Ogre::SceneManager* sceneMgr)
{
/*	
	Ogre::Entity* player2 = sceneMgr->createEntity("Player_2", "sinbad.mesh");//load mesh
	p_playerNode = sceneMgr->getRootSceneNode()->createChildSceneNode("Player_2", Ogre::Vector3(10,0,0));//create node and hold the pointer for later use
	p_playerNode->attachObject(player2);//attach player entity to the new scene manager node
	p_playerNode->scale(2,2,2);
*/

	
	Ogre::Entity* player = sceneMgr->createEntity("Player_1", "sinbad.mesh");//load mesh
	p_playerNode = sceneMgr->getRootSceneNode()->createChildSceneNode("Player_1", Ogre::Vector3(0,40,0));//create node and hold the pointer for later use
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
		m_velocity.z -= 4;

	if(input.down)
		m_velocity.z += 4;

	if(input.left)
		m_velocity.x -= 4;

	if(input.right)
		m_velocity.x += 4;

}
void C_BaseEntity::Move(OgreBites::SdkTrayManager* trayMgr)
{


	if(m_velocity.z > MAX_PLAYER_VELOCITY)
		m_velocity.z = MAX_PLAYER_VELOCITY;

	if(m_velocity.z < -MAX_PLAYER_VELOCITY)
		m_velocity.z = -MAX_PLAYER_VELOCITY;

	if(m_velocity.x > MAX_PLAYER_VELOCITY)
		m_velocity.x = MAX_PLAYER_VELOCITY;

	if(m_velocity.x < -MAX_PLAYER_VELOCITY)
		m_velocity.x = -MAX_PLAYER_VELOCITY;

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
	//UP-LEFT
	if(m_velocity.z < 0 && m_velocity.x < 0 && m_degreeFacing !=225){
		if(m_degreeFacing <= 225 && m_degreeFacing > 45){
			m_degreeFacing += 5;
			p_playerNode->yaw(Ogre::Degree(5), Ogre::Node::TS_PARENT);
		}
		if(m_degreeFacing > 225 || m_degreeFacing < 45){
			m_degreeFacing -= 5;
			p_playerNode->yaw(Ogre::Degree(-5), Ogre::Node::TS_PARENT);
		}
	}
	//UP-RIGHT
	if(m_velocity.z < 0 && m_velocity.x > 0 && m_degreeFacing !=135){
		if(m_degreeFacing <= 315 && (m_degreeFacing > 135 )){
			m_degreeFacing -= 5;
			p_playerNode->yaw(Ogre::Degree(-5), Ogre::Node::TS_PARENT);
		}
		if(m_degreeFacing > 315 || m_degreeFacing < 135){
			m_degreeFacing += 5;
			p_playerNode->yaw(Ogre::Degree(5), Ogre::Node::TS_PARENT);
		}
	}
	//DOWN-RIGHT
	if(m_velocity.z > 0 && m_velocity.x > 0 && m_degreeFacing !=45){
		if(m_degreeFacing <= 225 && m_degreeFacing > 45 ){
			m_degreeFacing -= 5;
			p_playerNode->yaw(Ogre::Degree(-5), Ogre::Node::TS_PARENT);
		}
		if(m_degreeFacing > 225 || m_degreeFacing < 45){
			m_degreeFacing += 5;
			p_playerNode->yaw(Ogre::Degree(5), Ogre::Node::TS_PARENT);
		}
	}
	//DOWN-LEFT
	if(m_velocity.z > 0 && m_velocity.x < 0 && m_degreeFacing !=315){
		if(m_degreeFacing <= 315 && m_degreeFacing > 135 ){
			m_degreeFacing += 5;
			p_playerNode->yaw(Ogre::Degree(5), Ogre::Node::TS_PARENT);
		}
		if(m_degreeFacing > 315 || m_degreeFacing < 135){
			m_degreeFacing -= 5;
			p_playerNode->yaw(Ogre::Degree(-5), Ogre::Node::TS_PARENT);
		}
	}


	if(m_degreeFacing == 360)
		m_degreeFacing = 0;
	if(m_degreeFacing < 0)
		m_degreeFacing = 355;

	
	//make sure player isn't moving off the plane
	Ogre::Vector3 tempPos = p_playerNode->getPosition();
	if(tempPos.z > PLANE_HEIGHT/2)
		tempPos.z = PLANE_HEIGHT/2;

	if(tempPos.z < -PLANE_HEIGHT/2)
		tempPos.z = -PLANE_HEIGHT/2;

	if(tempPos.x < -PLANE_WIDTH/2)
		tempPos.x = -PLANE_WIDTH/2;

	if(tempPos.x > PLANE_WIDTH/2)
		tempPos.x = PLANE_WIDTH/2;

	p_playerNode->setPosition(tempPos);


	//Offset stuff
	m_velocity.y = -m_position.y; //this offsets the player position so he doesn't float into space
	Ogre::Vector3 newPosition = m_velocity + m_position;
	p_playerNode->translate(newPosition);





}
void C_BaseEntity::Animation(Ogre::SceneManager* sceneMgr, const Ogre::FrameEvent& evt)
{
	//RunBase, RunTop, Dance
	Ogre::Entity* player = sceneMgr->getEntity("Player_1");
	p_runTopState = player->getAnimationState("RunTop");
	p_runBaseState = player->getAnimationState("RunBase");
	
	//Dance animation
	if(m_velocity.x == 0 && m_velocity.z == 0){
		p_danceState = player->getAnimationState("Dance");
		p_danceState->setLoop(true);
		p_danceState->setEnabled(true);
		p_danceState->addTime(evt.timeSinceLastFrame);
	}
	else{
		p_danceState->setEnabled(false);
	}

	//Running animation
	if(m_velocity.x != 0 || m_velocity.z != 0){
		p_runTopState->setLoop(true);
		p_runTopState->setEnabled(true);
		p_runTopState->addTime(evt.timeSinceLastFrame);


		p_runBaseState->setLoop(true);
		p_runBaseState->setEnabled(true);
		p_runBaseState->addTime(evt.timeSinceLastFrame);
	}
	else{
		p_runTopState->setEnabled(false);
		p_runBaseState->setEnabled(false);
	}

}
#endif