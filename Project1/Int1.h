#pragma once

// Int1.h
#ifndef GUARD_Int1_H
#define GUARD_Int1_H

#include "Core.h"

class Int1 : public Core {
public:
	// 두 생성자 모두 암묵적으로 Core::Core()를 사용하여
	// 객체가 기본 클래스에서 상속한 부분을 초기화
	Int1() : toeic(0) {};
	Int1(istream& is) { read(is); };

	double grade() const;
	istream& read(istream&);
protected:
	Int1* clone() const { return new Int1(*this); }
private:
	double toeic; // 논문
};

#endif