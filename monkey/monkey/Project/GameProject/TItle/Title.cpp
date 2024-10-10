#include "Title.h"
#include "../Game/Game.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	m_img = COPY_RESOURCE("Title", CImage);
	h_img = COPY_RESOURCE("Title1", CImage);
	g_img = COPY_RESOURCE("Title2", CImage);
	m_img.SetSize(1920, 1080);
	h_img.SetPos(400, 100);
	g_img.SetPos(450, 200);
	m_cnt = 0;
}

void Title::Update()
{
	//�{�^���P�Ń^�C�g���j��
	if (m_cnt++ > 60 && PUSH(CInput::eButton1)) {
		//���ׂẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�Q�[���V�[����
		Base::Add(new Game());
	}

}

void Title::Draw()
{
	m_img.Draw();
	h_img.Draw();
	g_img.Draw();
	//�����\��
	
	m_title_text.Draw(750, 512, 0, 0, 0, "Push Z");
}
