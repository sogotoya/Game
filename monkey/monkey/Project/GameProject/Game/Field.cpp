#include "Field.h"

Field::Field(const CVector2D& pos) :Base(eType_Field)
{
	m_img.Load("Image/haikei2.png");
    m_Map_Tip = 540;
	m_pos = pos;
	m_img.SetSize(1920, 1080);
	m_img.SetCenter(1920 / 2, 1080 / 2);
}

void Field::Update()
{
}

void Field::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
}
