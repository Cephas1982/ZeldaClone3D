#include "stdafx.h"
#ifndef INPUT_CPP
#define INPUT_CPP
#include "Input.h"

C_Input::C_Input()
{
	//Keyboard
	up = false;
	down = false;
	left = false;
	right = false;
	space = false;

	key_1 = false;
	key_2 = false;


	key_grave = false;

	key_a = false;

	//MOUSE
	lMouseDown = false;
	rMouseDown = false;
	middleMouseDown = false;

	mouseWheelUp = false;
	mouseWheelDown = false;


	m_keepTurning = false;

	m_angleFacing = 0;//TODO put this somewhere better... Gary.
	m_directionFacing = RIGHT;

	m_xVel = 10;
	m_xMagnitude = 0;
}

C_Input::~C_Input()
{
}

void C_Input::Translate(Ogre::SceneManager *sceneMgr, const Ogre::FrameEvent& evt)
{
	/*

	Ogre::Vector3 transVector = Ogre::Vector3::ZERO;//vector to hold transition to translate to

	//Prep animations
	//Stealth walk
	a_ninjaStealth = sceneMgr->getEntity("Ninja")->getAnimationState("Stealth");
	a_ninjaStealth->setLoop(true);
	a_ninjaStealth->setEnabled(false);
	//Walk ---todo: add this
	a_ninjaWalk = sceneMgr->getEntity("Ninja")->getAnimationState("Walk");
	a_ninjaWalk->setLoop(true);
	a_ninjaWalk->setEnabled(false);
	//Idle1
	a_ninjaIdle1 = sceneMgr->getEntity("Ninja")->getAnimationState("Idle1");
	a_ninjaIdle1->setLoop(true);
	a_ninjaIdle1->setEnabled(false);
	//Attack1
	a_ninjaAttack1 = sceneMgr->getEntity("Ninja")->getAnimationState("Attack1");
	a_ninjaAttack1->setLoop(true);
	a_ninjaAttack1->setEnabled(false);

	if(left){
		m_xMagnitude += m_xVel;
		if(m_xMagnitude > MOVE_SPEED)
			m_xMagnitude = MOVE_SPEED;
		
		m_directionFacing = LEFT;
		m_keepTurning = true;

		//Stealth
		//if(!a_ninjaStealth->getEnabled()){//if not already walking
		if(m_xMagnitude < MOVE_SPEED){
			a_ninjaStealth->setEnabled(true);//walk
			a_ninjaStealth->addTime(evt.timeSinceLastFrame);
		}
		else{
			a_ninjaStealth->setEnabled(false);
			a_ninjaWalk->setEnabled(true);
			a_ninjaWalk->addTime(evt.timeSinceLastFrame);
			m_xMagnitude = 350;
		}
		transVector.x -= m_xMagnitude;
	}

	if(right){
		transVector.x += MOVE_SPEED;
		m_directionFacing = RIGHT;
		m_keepTurning = true;

		//Stealth	
		if(!a_ninjaStealth->getEnabled()){//if not already walking
			a_ninjaStealth->setEnabled(true);//walk
			a_ninjaStealth->addTime(evt.timeSinceLastFrame);

			//TODO scribble here
			m_xMagnitude = 0;
		}
	}
	/*
	if(up)
		transVector.y += MOVE_SPEED;

	if(down)
		transVector.y -= MOVE_SPEED;
	*/


/*
	//IF NOT LEFT OR RIGHT IDLE OR TURNING
	if(!left && !right){
		a_ninjaStealth->setEnabled(false);
		a_ninjaWalk->setEnabled(false);
		a_ninjaIdle1->setEnabled(true);
		
		a_ninjaIdle1->addTime(evt.timeSinceLastFrame);
		
	}
	else
		a_ninjaIdle1->setEnabled(false);
	



	//const Ogre::FrameEvent evt; TODO: how to setup timer???
	//TODO: DONT LEAVE TRANSLATION UPDATE HERE!!
	sceneMgr->getSceneNode("Ninja1")->translate(transVector * evt.timeSinceLastFrame, Ogre::Node::TS_WORLD);
	
	
	//sceneMgr->getSceneNode("Ninja1")->yaw(Ogre::Degree(m_degreeFacing));
	if(m_directionFacing == RIGHT && m_angleFacing < 90  && m_keepTurning == true){
		float turnSpeed = 240 * evt.timeSinceLastFrame;
		sceneMgr->getSceneNode("Ninja1")->yaw(Ogre::Degree(turnSpeed));
		m_angleFacing += turnSpeed;
		if(m_angleFacing > 90)
			m_keepTurning = false;
	}

	if(m_directionFacing == LEFT && m_angleFacing > -90 && m_keepTurning == true){
		float turnSpeed = -240 * evt.timeSinceLastFrame;
		sceneMgr->getSceneNode("Ninja1")->yaw(Ogre::Degree(turnSpeed));
		m_angleFacing += turnSpeed;
		if(m_angleFacing < -90)
			m_keepTurning = false;
	}

	if(space){
		//make a function that sets everything to false
		a_ninjaWalk->setEnabled(false);
		a_ninjaStealth->setEnabled(false);
		a_ninjaIdle1->setEnabled(false);
		a_ninjaAttack1->setEnabled(true);
		a_ninjaAttack1->addTime(evt.timeSinceLastFrame);
	}
	
	
	//This will test collision for a falling ninja
	if(key_a)
		sceneMgr->getSceneNode("Ninja1")->setPosition(0, 300,-100);

	


	

	//REAL INPUTS HERE todo: clean up above but save for reference
	//GUI STUFF
#if(GUI_ON)
	if(key_grave)
		CEGUI::System::getSingleton().getGUISheet()->show();//shows GUI. User must click close to exit
#endif


	*/

	float speed = 30;
	Ogre::Vector3 movement = Ogre::Vector3::ZERO;

	if(up)
		movement.z = -speed;

	if(down)
		movement.z = speed;

	if(left)
		movement.x = -speed;

	if(right)
		movement.x = speed;

	if(mouseWheelUp)
		movement.y = speed;

	if(mouseWheelDown)
		movement.y = -speed;

	

	Ogre::Camera* cam = sceneMgr->getCamera("PlayerCam");
	cam->setPosition(cam->getPosition() + movement);



	//reset mouse wheel movement (CEGUI IS lame about it)
	mouseWheelDown = false;
	mouseWheelUp = false;
}

#endif