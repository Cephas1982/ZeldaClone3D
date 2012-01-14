#include "stdafx.h"
#ifndef INPUT_H
#define INPUT_H
#include "Ogre.h"

#define MOVE_SPEED 200
#define LEFT 0
#define RIGHT 1

class C_Input{

	public:
			C_Input();
			~C_Input();

			void Translate(Ogre::SceneManager* _sceneManager_, const Ogre::FrameEvent& _event);//moves player based on keys pressed


			bool up, down, left, right, space, key_1, key_2, key_grave, key_a;//TODO: Public because I'm lazy tonight, change later.
			bool lMouseDown, rMouseDown, middleMouseDown, mouseWheelUp, mouseWheelDown;

			float m_angleFacing;
			bool m_directionFacing, m_keepTurning;

			Ogre::AnimationState* a_ninjaStealth;
			Ogre::AnimationState* a_ninjaWalk;
			Ogre::AnimationState* a_ninjaIdle1;
			Ogre::AnimationState* a_ninjaAttack1;
			Ogre::AnimationState* a_ninjaAttack2;
			Ogre::AnimationState* a_ninjaAttack3;
		

	private:
			
			bool m_initDone;
			float m_xVel, m_xMagnitude;
			
			

};

#endif