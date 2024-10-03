#pragma once
#include "../Base/Base.h"
//横
#define MAP_WIDTH  400  //250   
//縦
#define MAP_HEIGHT 400  //250
//大きさ
#define MAP_TIP_SIZE  26   //128

class Map : public Base {
private:
	CImage m_img;
	int m_state;
public:
	Map();
	void Draw();
	//指定座標のチップ番号取得
	int GetTip(const CVector2D& pos);
	//指定列、指定行のマップチップを取得
	int GetTip(int col, int row);
	//マップとの当たり判定
	int CollisionPoint(const CVector2D& pos);
};


