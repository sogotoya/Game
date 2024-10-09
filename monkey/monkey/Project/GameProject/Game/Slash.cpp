#include "Slash.h"
Slash::Slash(const CVector2D& pos, bool flip, int type, int attack_no) : Base(type)
{
	//�U���̌���
	m_flip = flip;
	//�U�������ʒu
	m_pos = pos;
	//�����蔻��p��`
	m_rect = CRect(-64, -64, 64, 0); //-30, -98, 30, 0
	//�U���ԍ�
	m_attack_no = attack_no;
}

void Slash::Update()
{
	
}

void Slash::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	//DrawRect();

}
