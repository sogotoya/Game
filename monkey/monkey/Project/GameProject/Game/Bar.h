#include "../Base/Base.h"
class bar : public Base {
private:
	//時間
	int turn;
	CImage m_img;
public:
	bar(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	//当たり判定検証
	void Collision(Base* b);
};
extern TexAnimData bar_anim_data[];
