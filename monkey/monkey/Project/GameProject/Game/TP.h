#pragma once
#include "../Base/Base.h"
class Tp :public Base {
private:
	//�摜
	CImage m_img;
	//�ړ��ʒu
	CVector2D m_next_pos;
public:
    /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        /// <param name="pos">�ʒu</param>
        /// <param name="next">�ړ���</param>
        /// <returns></returns>
    Tp(const CVector2D& pos, const CVector2D& next);
    /// <summary>
    /// �`��
    /// </summary>
    void Draw();
    /// <summary>
    /// �ړ���̈ʒu���擾
    /// </summary>
    /// <returns></returns>
    CVector2D GetNextPos() {
        return m_next_pos;
    }
};