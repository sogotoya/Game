#include "Bar4.h"
#include"Map.h"


bar4::bar4(const CVector2D& p, bool flip) :Base(eType_bar4)
{
	//�摜����
	m_img = COPY_RESOURCE("bar4", CImage);
	//���W�ݒ�
	m_pos = p;
	//�摜�T�C�Y�ݒ�
	m_img.SetSize(150, 50);
	//���S�ʒu�ݒ�
	m_img.SetCenter(75, 25);
	m_rect = CRect(-65, -25, 65, 0);//���C�����A�E�A������
	turn = 0;
	m_img.ChangeAnimation(0);

}

void bar4::Update()
{

	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
	m_pos_old = m_pos;

	if (turn == 0)
	{
		m_pos.y +=3 ;
	}
	if (m_pos.y > 5 * MAP_TIP_SIZE)
	{
		turn = 1;
	}
	if (turn == 1)
	{
		m_pos.y -= 3;
	}
	if (m_pos.y < 2* MAP_TIP_SIZE)
	{
		turn = 0;
	}

}

void bar4::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	//DrawRect();


}

void bar4::Collision(Base* b)
{

}
static TexAnim barfuuu[] = {
	{0,5},
	{1,5},
	{2,5},
	{3,5},

};
TexAnimData bar4_anim_data[] = {
	ANIMDATA(barfuuu),
};