#include "../Base/Base.h"
class bar : public Base {
private:
	//ŠÔ
	int turn;
	CImage m_img;
public:
	bar(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	//“–‚½‚è”»’èŒŸØ
	void Collision(Base* b);
};
