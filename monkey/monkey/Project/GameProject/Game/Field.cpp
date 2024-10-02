#include "Field.h"

Field::Field(const CVector2D& pos) :Base(eType_Field)
{
	m_sky = COPY_RESOURCE("sky", CImage);
    m_Map_Tip = 850;
	m_sky.SetSize(2000, 1600);
	
}

void Field::Update()
{
}

void Field::Draw()
{
	
	m_sky.Draw();
	

}
