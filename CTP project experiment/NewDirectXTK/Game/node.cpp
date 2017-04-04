#include "node.h"
#include "game.h"
#include <dinput.h>
#include "GameData.h"


Node::Node(bool _lock, string _fileName, ID3D11Device* _GD, IEffectFactory* _EF) : CMOGO(_fileName, _GD, _EF)
{
	//any special set up for Player goes here
	m_fudge = Matrix::CreateRotationY(XM_PI);
	Lock = _lock;
	m_pos.y = 10.0f;
	
}



void Node::Tick(GameData* _GD)//SoftBody &s
{
	/////sets gravity force doesnt work right yet needs delta time but cant find it
	if (_GD->m_keyboardState[DIK_Q] & 0x80)
	{
		 
	}
		
	if (Lock == false)
	{
	
	}
	else if (Lock)
	{
		switch (_GD->m_GS)
		{
		case GS_PLAY_MAIN_CAM:
		{
			{
				//		MOUSE CONTROL SCHEME HERE
				float speed = 0.1f;
				m_pos.x += speed * _GD->m_mouseState->lX;
				m_pos.z += speed * _GD->m_mouseState->lY;
			}
			break;
		}
		case GS_PLAY_TPS_CAM:
			//TURN AND FORWARD CONTROL HERE
			Vector3 forwardMove = 20.0f * _GD->m_dt * Vector3::Forward;
			Matrix rotMove = Matrix::CreateRotationY(m_yaw);
			forwardMove = Vector3::Transform(forwardMove, rotMove);
			

			if (_GD->m_keyboardState[DIK_S] & 0x80)
			{
				m_pos.z += _GD->m_dt * 10.0f;
			}
			if (_GD->m_keyboardState[DIK_W] & 0x80)
			{
				m_pos.z -= _GD->m_dt * 10.0f;
			}

			float rotSpeed = 2.0f * _GD->m_dt;
			if (_GD->m_keyboardState[DIK_A] & 0x80)
			{
				m_pos.x-= _GD->m_dt * 10.0f;
			}
			if (_GD->m_keyboardState[DIK_D] & 0x80)
			{
				m_pos.x += _GD->m_dt * 10.0f;
			}
			break;
		}

		if (_GD->m_keyboardState[DIK_R] & 0x80)
		{
			m_pos.y += _GD->m_dt * 10.0f;
		}

		if (_GD->m_keyboardState[DIK_F] & 0x80)
		{
			m_pos.y -= _GD->m_dt * 10.0f;
		}
		//Reset Button///////
		  if (_GD->m_keyboardState[DIK_Q] & 0x80)
		{
			m_pos = Vector3(0.0f, 0.0f, 0.0f);
		}
		  //attempted hud interaction doesnt work
		  if (_GD->m_keyboardState[DIK_O] & 0x80) 
		  {
			  _GD->K- 1;

		  }
		  if (_GD->m_keyboardState[DIK_P] & 0x80) 
			  _GD->K+ 1;

		  }
		float length = m_pos.Length();
		float maxLength = 500.0f;
		if (length > maxLength)
		{
			m_pos *= maxLength / length;
		}
	

		//apply my base behaviour
		CMOGO::Tick(_GD);
}








