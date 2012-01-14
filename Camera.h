#include "stdafx.h"
#ifndef CAMERA_H
#define CAMERA_H

class C_Camera{

	public:
			C_Camera();
			~C_Camera();

			void Update(Ogre::SceneManager* _sceneManager_, Ogre::Camera* _ogreCamera_, int planeSelected);

			//set state function here

	private:

			//enum m_cameraState {CS_TRACK_PLAYERS};//TODO: add other camera states

			int x, y, z; //position of camera in space
			float xLook, yLook, zLook; //direction camera faces
			float m_distance;//distance between 2 objects
			int m_xMax, m_xMin, m_yMax, m_yMin, m_zMax, m_zMin; //max and min value for camera zoom/pan

};


#endif