#pragma once
#ifndef _GRASS_H_
#define _GRASS_H_
#include "VBGO.h"
#include "vertex.h"

//=================================================================
//procedurally generate a VBGO Cube
//each side be divided in to _size * _size squares (2 triangles per square)
//=================================================================

class VBGrass : public VBGO
{
public:
	VBGrass() {};
	virtual ~VBGrass() {};

	//initialise the Veretx and Index buffers for the cube
	void init(int _size, ID3D11Device* _GD);
	virtual void Tick(GameData* _GD);
	float xmov = 0.5f;


	int numVerts;
	virtual void Transform()
	{
		Vector3 newPos = m_vertices[2].Pos += Vector3(1, 0, 0);

		m_vertices[2].Pos = newPos;

		 newPos = m_vertices[2].Pos += Vector3(1, 0, 0);
	/*	for (int i = 0; i<m_numPrims * 3; i++)
		{
			m_vertices[i].Color *= ((i / 3) % 2) ? 1.0f : 0.5f;
			m_vertices[i].Color.w = 1.0f;

			Vector3 vertPos = m_vertices[i].Pos;
			Vector3 spherePos = m_vertices[i].Pos;

			spherePos.Normalize();

			Vector3 newPos = 1.5f * (vertPos + (m_size - 1) * spherePos);

			m_vertices[2].Pos = newPos;

			
		}*/
	}

protected:
	//this is to allow custom versions of this which create the basic cube and then distort it
	//see VBSpiral, VBSpiked and VBPillow
	

	int m_size;
	myVertex* m_vertices;

	Vector3 A1 = Vector3(1.0f, 30, 0.5f * 5);
};

#endif