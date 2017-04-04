#pragma once
#include "CMOGO.h"
#include"softBody.h"
class Node : public CMOGO
{
public:
	Node(bool _lock,string _fileName, ID3D11Device* _GD, IEffectFactory* _EF);
	virtual ~Node() {};
	virtual void Tick(GameData* _GD);
	
protected:
	bool Lock;
	float Force = 0;
	int gravity = 1;

};