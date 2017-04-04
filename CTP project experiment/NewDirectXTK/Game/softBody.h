#pragma once
#include "CMOGO.h"


class SoftBody : public CMOGO
{
public:
	SoftBody(string _fileName, GameObject* _Node1, GameObject* _Node2, ID3D11Device* _GD, IEffectFactory* _EF);// , GameObject* _parent, GameObject* _parent1);
	virtual ~SoftBody() {};
	virtual void Tick(GameData* _GD);


	
	
	
protected:
	GameObject* node1;
	GameObject* node2;
	float Length;
	float friction = 10.0f;


	Vector3 spring;
	Vector3 restorf;
	Vector3 reset;
	Vector3 nodeloc1;
	Vector3 nodeloc2;

};
