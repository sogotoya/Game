#include "Map.h"




Map::Map():Base(eType_Map)
{
	//�摜�̕���
	m_img = COPY_RESOURCE("Map_Tip",CImage);
}

void Map::Draw()
{
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			//�؂蔲��

			//�T�C�Y
			m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);
			//�ʒu�ݒ�
			m_img.SetPos(MAP_TIP_SIZE * j, MAP_TIP_SIZE * i);
			//�`��
			m_img.Draw();
		}
	}
}
