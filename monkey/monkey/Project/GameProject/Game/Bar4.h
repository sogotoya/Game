#include "../Base/Base.h"
class bar4 : public Base {
private:
	//����
	int turn;
	CImage m_img;
	CImage m_bar4;
public:
	bar4(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	//�����蔻�茟��
	void Collision(Base* b);
};
extern TexAnimData bar4_anim_data[];