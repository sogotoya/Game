#include "Field.h"

Field::Field(const CVector2D& pos) :Base(eType_Field)
{
	m_img.Load("Image/haikei2.png");
	m_pos = pos;
	m_img.SetSize(40, 40);
}

void Field::Update()
{
}

void Field::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
}
