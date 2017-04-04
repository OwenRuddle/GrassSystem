#include "Grassspawner.h"

GrassSpawner::GrassSpawner(int _numBlades,int size, Vector3 _startpos, ID3D11Device * _pd3dDevice, GameObject * pPlayer)
{
	Bpos = _startpos;
	for (int i = 0; i < _numBlades; i++)
	{
		Blades.push_back(new VBGrassFile(size, "grass.jpg",_pd3dDevice, pPlayer));
	}

	i = _numBlades;

	int z = 0;
	int x = 0;

		for(list<VBGrassFile *>::iterator it = Blades.begin(); it != Blades.end(); it++)
		{


			(*it)->SetPos(Vector3(x, -20,   z));
			z -= 0.3 - (rand() % 1 + (-2.5));//3;
			if (z == -60)
			{
				x -=0.1+(rand() % 1+(2));//1.5;
				z = 0;
			}
			//adds randomness to the grass Yaw at start but looks off 
			(*it)->SetYaw(-(rand() % 2 + (-0.5)));
	}

		

}

GrassSpawner::~GrassSpawner()
{
}

void GrassSpawner::Tick(GameData * _GD)
{
	
	
	
	for (list<VBGrassFile *>::iterator it = Blades.begin(); it != Blades.end(); it++)
	{
		(*it)->Spawn(Bpos, _GD);
	}
	for (list<VBGrassFile *>::iterator it = Blades.begin(); it != Blades.end(); it++)
	{
		(*it)->SetScale(1.0f);
	}
	for (list<VBGrassFile *>::iterator it = Blades.begin(); it != Blades.end(); it++)
	{
			(*it)->Tick( _GD);
		}
	}
	


void GrassSpawner::Draw(DrawData * _DD)
{

	for (list<VBGrassFile *>::iterator it = Blades.begin(); it != Blades.end(); it++)
	{
		(*it)->Draw(_DD);
	}
}


