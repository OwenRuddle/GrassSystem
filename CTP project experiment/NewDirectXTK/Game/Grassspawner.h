#pragma once
#include "grassFile.h"
#include <list>
#include <string>

using namespace std;
using namespace DirectX;

class GrassSpawner : public VBGO
{
public:
	list<VBGrassFile*> Blades;

	GrassSpawner(int _numBlades,int size,Vector3 _startpos, ID3D11Device* _pd3dDevice,GameObject* pPlayer);
	~GrassSpawner();
	virtual void Tick(GameData* _GD);

	virtual void Draw(DrawData* _DD);
	
	Vector3 Bpos;

	int i;
	int q = 0;
};