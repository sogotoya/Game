#include "../Base/Base.h"
class bar2 : public Base {
private:
	//����
	int turn;
	CImage m_img;
	CImage m_bar2;
public:
	bar2(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	//�����蔻�茟��
	void Collision(Base* b);
};
extern TexAnimData bar2_anim_data[];
