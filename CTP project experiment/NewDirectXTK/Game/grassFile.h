#pragma once
#ifndef _GRASSFILE_H_
#define _GRASSFILE_H_
#include "fileVBGO.h"
#include "vertex.h"


class VBGrassFile : public FileVBGO
{
public:
	VBGrassFile(int _size, std::string _fileName, ID3D11Device* _GD, GameObject* player);
	virtual ~VBGrassFile() {};

	//initialise the Veretx and Index buffers for the grass

	virtual void Tick(GameData* _GD);

	void Spawn(Vector3 _pos, GameData* _GD);


	bool m_alive;

	void CollisionWind(GameData* _GD,Vector3 windmin,Vector3 windmax);
	void Collisioncalc();
	int numVerts;

	virtual void Draw(DrawData* _DD);


protected:
	int m_size;
	myVertex* m_vertices;

	Vector3 grassmin = Vector3(m_pos.x-100, m_pos.y - 100, m_pos.z);
	Vector3 grassmax = Vector3(m_pos.x + 100, m_pos.y + 100, m_pos.z);
	Vector3 Windmin;
	Vector3 Windmax;

	Vector3 Grassrest = m_pos;
	

	Vector3 ppos;
	GameObject * PP;
	

	bool frwd=true;
	bool back=false;
	bool Windisblown=false ;
	int windForce = 0;

};

#endif