#include "../Base/Base.h"
class bar3 : public Base {
private:
	//時間
	int turn;
	CImage m_img;
	CImage m_bar2;
public:
	bar3(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	//当たり判定検証
	void Collision(Base* b);
};
extern TexAnimData bar3_anim_data[];
