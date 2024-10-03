#include "Map.h"

static int stage1data[MAP_HEIGHT][MAP_WIDTH] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,7,0,0,6,0,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,4,4,4,4,7,0,0,1,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,2,2,1,1,0,0,1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,2,2,0,7,0,8,0,2,2,5,5,5,2,2,0,2,1,1,0,0,0,0,0,0,0,1,1,1,1,1,2,2,2,2,0,0,2,1,1,1,2,0,2,0,2,1,1,1,1,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {2,2,1,1,0,0,0,0,0,1,1,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,0,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    



};





Map::Map() :Base(eType_Map)
{
    //画像の複製
    m_img = COPY_RESOURCE("Map_Tip1", CImage);
    m_background = COPY_RESOURCE("BackGround", CImage);
    m_background.SetSize(1920, 1080);
    memcpy(stage, stage1data, sizeof(stage1data));
    //m_Map_Tip = 900;
}

void Map::Draw()
{
    m_background.Draw();
        for (int i = 0; i < MAP_HEIGHT; i++) {
            for (int j = 0; j < MAP_WIDTH; j++) {
                //表示させない [i]行 [j]列
                if (stage1data[i][j] == 0)continue;
                int t = stage1data[i][j];
                //切り抜き    //左　//ue   //migi //sita
                m_img.SetRect(200*t,0,200*t+ 200, 200);
                //サイズ
                m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE); 
                
         
                //位置設定
                m_img.SetPos(MAP_TIP_SIZE * j - m_scroll.x, MAP_TIP_SIZE * i - m_scroll.y);
                //描画
                m_img.Draw();
            }
        }
    
}


int Map::GetTip(const CVector2D& pos, int* tx, int* ty)
{
    //列を計算
    int x = pos.x / MAP_TIP_SIZE;
    //列の制限
    if (x < 0) x = 0;
    if (x > MAP_WIDTH - 1) x = MAP_WIDTH - 1;
    //行を計算
    int y = pos.y / MAP_TIP_SIZE;
    //行の制限
    if (y < 0) y = 0;
    if (y > MAP_HEIGHT - 1) y = MAP_HEIGHT - 1;
    //行と列の出力
    if (ty) *ty = y * MAP_TIP_SIZE;
    if (tx) *tx = x * MAP_TIP_SIZE;
    //チップデータを返却
    return stage[y][x];
}
int Map::GetTip(int x, int y)
{
    return stage1data[y][x];
  
}

int Map::CollisionPoint(const CVector2D& pos)
{


    //1点のみ検証
    int t = GetTip(pos);
    if (t != 0)return 1;
    return 0;
}

int Map::CollisionRect(const CVector2D& pos, const CRect& rect)
{
    CRect r = CRect(
        pos.x + rect.m_left,
        pos.y + rect.m_top,
        pos.x + rect.m_right,
        pos.y + rect.m_bottom);
    int t;
    t = CollisionPoint(CVector2D(r.m_left, r.m_top));
    if (t != 0) return t;
    t = CollisionPoint(CVector2D(r.m_right, r.m_top));
    if (t != 0) return t;
    t = CollisionPoint(CVector2D(r.m_left, r.m_bottom));
    if (t != 0) return t;
    t = CollisionPoint(CVector2D(r.m_right, r.m_bottom));
    if (t != 0) return t;
    return 0;
}

