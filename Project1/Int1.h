#pragma once

// Int1.h
#ifndef GUARD_Int1_H
#define GUARD_Int1_H

#include "Core.h"

class Int1 : public Core {
public:
	// �� ������ ��� �Ϲ������� Core::Core()�� ����Ͽ�
	// ��ü�� �⺻ Ŭ�������� ����� �κ��� �ʱ�ȭ
	Int1() : toeic(0) {};
	Int1(istream& is) { read(is); };

	double grade() const;
	istream& read(istream&);
protected:
	Int1* clone() const { return new Int1(*this); }
private:
	double toeic; // ��
};

#endif