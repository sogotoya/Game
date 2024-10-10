#include "rast.h"
#include "../Game/Game.h"
rast::rast() :Base(eType_rast)
{
	m_img = COPY_RESOURCE("kabe", CImage);
	m_img.SetSize(1920, 1080);
	m_cnt = 0;
}

void rast::Update()
{


}

void rast::Draw()
{
	m_img.Draw();
	
}
