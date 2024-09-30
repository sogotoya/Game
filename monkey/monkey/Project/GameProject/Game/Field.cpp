#include "Field.h"

Field::Field(const CVector2D& pos) :Base(eType_Field)
{
	m_sky = COPY_RESOURCE("sky", CImage);
	//m_img.Load("Image/haikei2.png");
    m_Map_Tip = 540;
	m_sky.SetSize(960, 1600);
	
}

void Field::Update()
{
}

void Field::Draw()
{
	
	m_sky.Draw();
	

}
