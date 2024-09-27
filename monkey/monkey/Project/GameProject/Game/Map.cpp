#include "Map.h"




Map::Map():Base(eType_Map)
{
	//画像の複製
	m_img = COPY_RESOURCE("Map_Tip",CImage);
}

void Map::Draw()
{
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			//切り抜き

			//サイズ
			m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);
			//位置設定
			m_img.SetPos(MAP_TIP_SIZE * j, MAP_TIP_SIZE * i);
			//描画
			m_img.Draw();
		}
	}
}
