#include "Slash.h"
Slash::Slash(const CVector2D& pos, bool flip, int type, int attack_no) : Base(type)
{
	//�U���̌���
	m_flip = flip;
	//�U�������ʒu
	m_pos = pos;
	//�����蔻��p��`
	m_rect = CRect(-30, -32, 30, 32); //-30, -98, 30, 0
	//�U���ԍ�
	m_attack_no = attack_no;

	m_count = 1;
}

void Slash::Update()
{
	m_count--;
	if (m_count == 0) {
		SetKill();
	}
}

void Slash::Draw()
{
	
	DrawRect();

}
