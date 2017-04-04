#include "grassFile.h"
#include "game.h"
#include <dinput.h>
#include "GameData.h"

//void VBGrassFile::init(int _size, ID3D11Device* GD)
//{


VBGrassFile::VBGrassFile(int _size, std::string _fileName, ID3D11Device * _GD, GameObject* player) :FileVBGO(_fileName, _GD)
{
	PP = player;
	Windmin = Vector3(PP->GetPos().x - 10, PP->GetPos().y - 10, PP->GetPos().z - 10);
	Windmax = Vector3(PP->GetPos().x + 10, PP->GetPos().y + 10, PP->GetPos().z + 10);
	m_size = _size;


	// base box stuff
	//calculate number of vertices and primatives
	int numVerts = 6 * 6 * (m_size - 1) * (m_size - 1);
	m_numPrims = numVerts / 3;
	m_vertices = new myVertex[numVerts];
	WORD* indices = new WORD[numVerts];

	//as using the standard VB shader set the tex-coords somewhere safe
	for (int i = 0; i < numVerts; i++)
	{
		indices[i] = i;
		m_vertices[i].texCoord = Vector2::One;
	}

	if (m_alive)
	{

		//in each loop create the two traingles for the matching sub-square on each of the six faces
		int vert = 0;
		for (int i = -(m_size - 1) / 2; i < (m_size - 1) / 2; i++)
		{



			for (int j = -(m_size - 1) / 2; j < (m_size - 1) / 2; j++)
			{
				//for textured grass///////
			//	////back
			//	m_vertices[vert].Color = Color(0.0f, 1.0f, 0.0f, 1.0f);
			//	m_vertices[vert++].Pos = Vector3((float)i, (float)j, 0.5f * (float)(m_size - 1));
			//	m_vertices[vert].Color = Color(0.0f, 1.0f, 0.0f, 1.0f);
			//	m_vertices[vert++].Pos = Vector3((float)(i + 1), (float)j, 0.5f * (float)(m_size - 1));
			//	m_vertices[vert].Color = Color(0.0f, 1.0f, 0.0f, 1.0f);
			//	m_vertices[vert++].Pos = Vector3((float)i, (float)(j + 1), 0.5f * (float)(m_size - 1));

			//	m_vertices[vert].Color = Color(0.0f, 1.0f, 0.0f, 1.0f);
			//	m_vertices[vert++].Pos = Vector3((float)(i + 1), (float)j, 0.5f * (float)(m_size - 1));
			//	m_vertices[vert].Color = Color(0.0f, 1.0f, 0.0f, 1.0f);
			//	m_vertices[vert++].Pos = Vector3((float)(i + 1), (float)(j + 1), 0.5f * (float)(m_size - 1));
			//	m_vertices[vert].Color = Color(0.0f, 1.0f, 0.0f, 1.0f);
			//	m_vertices[vert++].Pos = Vector3((float)i, (float)(j + 1), 0.5f * (float)(m_size - 1));

			//	//front
			////	m_vertices[vert].Color = Color(0.0f, 1.0f, 1.0f, 1.0f);
			//	m_vertices[vert++].Pos = Vector3((float)j, (float)i, 0.5f * (float)(m_size - 1));
			////	m_vertices[vert].Color = Color(0.0f, 1.0f, 1.0f, 1.0f);
			//	m_vertices[vert++].Pos = Vector3((float)j, (float)(i + 1), 0.5f * (float)(m_size - 1));
			////	m_vertices[vert].Color = Color(0.0f, 1.0f, 1.0f, 1.0f);
			//	m_vertices[vert++].Pos = Vector3((float)(j + 1), (float)i, 0.5f * (float)(m_size - 1));

			////	m_vertices[vert].Color = Color(0.0f, 1.0f, 1.0f, 1.0f);
			//	m_vertices[vert++].Pos = Vector3((float)j, (float)(i + 1), 0.5f * (float)(m_size - 1));
			////	m_vertices[vert].Color = Color(0.0f, 1.0f, 1.0f, 1.0f);
			//	m_vertices[vert++].Pos = Vector3((float)(j + 1), (float)(i + 1), 0.5f * (float)(m_size - 1));
			////	m_vertices[vert].Color = Color(0.0f, 1.0f, 1.0f, 1.0f);
			//	m_vertices[vert++].Pos = Vector3((float)(j + 1), (float)i, 0.5f * (float)(m_size - 1));



			/////for single point of grass
				for (int i = 0; i < (m_size); i++)
				{
					m_vertices[0].Color = Color(0.0f, 1.0f, 0.0f, 1.0f);
					//bottom left
					m_vertices[0].Pos = Vector3((float)i, 0, 0.5f * (float)(m_size - 1));// (float)j, 0.5f * (float)(m_size - 1));
					//Boittom right
					m_vertices[1].Color = Color(0.0f, 1.0f, 0.0f, 1.0f);
					m_vertices[1].Pos = Vector3((float)(i + 1), 0, 0.5f * (float)(m_size - 1));//Vector3((float)(i + 1), (float)j, 0.5f * (float)(m_size - 1));
					//top
					m_vertices[2].Color = Color(0.0f, 1.0f, 0.0f, 1.0f);
					m_vertices[2].Pos = Vector3((float)(i + 1), (float)(j + 10), 0.5f * (float)(m_size - 1));

					m_vertices[3].Color = Color(0.0f, 1.0f, 0.0f, 1.0f);
					m_vertices[3].Pos = Vector3((float)(i + 0), 60, 0.5f * (float)(m_size - 1));// Vector3((float)(i + 1), (float)j, 0.5f * (float)(m_size - 1));
					m_vertices[4].Color = Color(0.0f, 1.0f, 0.0f, 1.0f);
					m_vertices[4].Pos = Vector3((float)(i + 1), 0, 0.5f * (float)(m_size - 1)); //Vector3((float)(i + 1), (float)(j + 1), 0.5f * (float)(m_size - 1));
					m_vertices[5].Color = Color(0.0f, 1.0f, 0.0f, 1.0f);
					m_vertices[5].Pos = Vector3((float)i, 0, 0.5f * (float)(m_size - 1));// Vector3((float)i, (float)(j + 1), 0.5f * (float)(m_size - 1));
				}



			}

		}
		

		//calculate the normals for the basic lighting in the base shader
		for (int i = 0; i < m_numPrims; i++)
		{
			WORD V1 = 3 * i;
			WORD V2 = 3 * i + 1;
			WORD V3 = 3 * i + 2;

			//build normals
			Vector3 norm;
			Vector3 vec1 = m_vertices[V1].Pos - m_vertices[V2].Pos;
			Vector3 vec2 = m_vertices[V3].Pos - m_vertices[V2].Pos;
			norm = vec1.Cross(vec2);
			norm.Normalize();

			m_vertices[V1].Norm = norm;
			m_vertices[V2].Norm = norm;
			m_vertices[V3].Norm = norm;
		}


		//build the Box collider

		grassmin.x = m_vertices[0].Pos.x;
		grassmin.y = m_vertices[0].Pos.y;
		grassmin.z = m_vertices[0].Pos.z;
		grassmax.x = m_vertices[1].Pos.x;
		grassmin.y = m_vertices[2].Pos.y;
		grassmin.z = m_vertices[1].Pos.z;



		BuildIB(_GD, indices);
		BuildVB(_GD, numVerts, m_vertices);

		delete[] m_vertices; //this is no longer needed as this is now in the Vertex Buffer
	}
}

void VBGrassFile::Tick(GameData* _GD)
{

	Collisioncalc();
	CollisionWind(_GD,Windmin, Windmax);
	
	VBGO::Tick(_GD);


}





void VBGrassFile::CollisionWind(GameData* _GD, Vector3 windmin, Vector3 windmax)
{
	

		if ((grassmax.x) > (Windmin.x))
		{


			if ((grassmin.x) < (Windmax.x))
			{


		
				if ((grassmax.y) > (Windmin.y))
				{


	
					if ((grassmin.y) < (Windmax.y))
					{



						if ((grassmax.z) > (Windmin.z))
						{
							

							if ((grassmin.z) < (Windmax.z))
							{


								



									if (m_pitch >= -1.6)
									{

										m_pitch -= _GD->m_dt * 2;
								//	m_yaw-= _GD->m_dt/2 ;
										if (m_pitch <= -1.6|| (grassmax.z) > (Windmax.z))
										{
											//grassnewp = m_pos;
											Windisblown = true;
										}
									}
									
								
							}

						}
					}
				}
			}


		}


		if (Windisblown)
		{
		
		//	m_yaw += _GD->m_dt / 2;
			m_pitch += _GD->m_dt * 1;
			if (m_pitch >= 0)
			{
				Windisblown = false;
			}
		}




//	}

//*else if (Windisblown)
	//{
		
	//}

		
		}

void VBGrassFile::Collisioncalc()
{
	
	grassmin = Vector3(m_pos.x+10, m_pos.y, m_pos.z-1);
	grassmax = Vector3(m_pos.x+12, m_pos.y+8, m_pos.z+1);
	Windmin = Vector3(PP->GetPos().x, PP->GetPos().y-7, PP->GetPos().z-7);
	Windmax = Vector3(PP->GetPos().x, PP->GetPos().y+5, PP->GetPos().z+5);
}

void VBGrassFile::Draw(DrawData * _DD)
{

	VBGO::Draw(_DD);
}
	
void VBGrassFile::Spawn(Vector3 _pos, GameData* _GD)
{
	
	m_alive = true;
	//m_pos = Vector3(-21.0f, -10.0f, -10.0f);
	
	//DEBUG m_pos;
}
