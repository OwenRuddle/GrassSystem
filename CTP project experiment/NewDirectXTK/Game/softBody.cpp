#include "softBody.h"
#include "game.h"
#include <dinput.h>
#include "GameData.h"
#include <vector>

SoftBody::SoftBody(string _fileName, GameObject* _Node1,
					GameObject* _Node2, ID3D11Device* _GD, IEffectFactory* _EF)
	               : CMOGO(_fileName, _GD, _EF)
{
	//any special set up for Player goes here
	m_fudge = Matrix::CreateRotationY(XM_PI);
	node1 = _Node1;
	node2 = _Node2;
	// Set up parents so that nodes link 
	nodeloc1 = m_pos;
	nodeloc2 = m_pos;
	reset = m_pos;
	
}


void SoftBody::Tick(GameData* _GD)
{
	GameData GameData;
	//get distance between nodes
		 spring = node1->GetPos() - node2->GetPos();
		 Length = spring.Length();
		 ////hookes law (f=-kx)
		 restorf += (-(spring/Length)*(Length-GameData.NaturalLength)*GameData.K);
		 //apply force to node depending on distance 
		 if (spring.Length() > GameData.NaturalLength)
		 {
			 nodeloc2 = -restorf;
			 nodeloc1 = restorf;
		 }
		 else if (spring.Length() <GameData.NaturalLength)
		 {
			 nodeloc2 = restorf;
			 nodeloc1 = -restorf;
		 }
		  //set pos with force.
		 node2->SetPos(nodeloc2);

	 

	CMOGO::Tick(_GD);
	
	

	


}