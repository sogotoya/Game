#include "../Base/Base.h"
class bar : public Base {
private:
	//����
	int turn;
	CImage m_img;
public:
	bar(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	//�����蔻�茟��
	void Collision(Base* b);
};
