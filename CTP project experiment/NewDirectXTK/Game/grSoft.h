#pragma once
#include "VBGO.h"
#include "vertex.h"

class GSoftBody : public VBGO
{
public:
	GSoftBody( GameObject* _Node1, GameObject* _Node2, ID3D11Device* _GD, IEffectFactory* _EF);// , GameObject* _parent, GameObject* _parent1);
	virtual ~GSoftBody() {};
	virtual void Tick(GameData* _GD, ID3D11Device * GD);

	Vector3 V1;
	Vector3 V2;
	Vector3 V3;
	Vector3 V4;
	//myVertex* m_vertices;

	//int numVerts = 8;

	void init(int _size, ID3D11Device* _GD);
int m_size;
	myVertex* m_vertices;


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

