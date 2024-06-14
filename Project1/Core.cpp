// Core.cpp

#include "Core.h"
#include "grade.h"

using namespace std;

// Core 클래스의 멤버 함수 정의
istream& read_hw(istream& in, vector<double>& hw);

string Core::getName() const { return name; }
double Core::grade() const {
	return ::grade(midterm, final, homework);
}

/**
 * @brief 공통으로 사용하는 데이터를 읽어들이는 함수
 * 
 * @param in
 * @return istream&
 * 
 * @see Core::read
 * 
 * @note Core 클래스의 read_common 함수는 학생 name, midterm, final 점수를 읽어들이는 함수이다.
 */
istream& Core::read_common(istream& in) {
	// 학생 이름과 시험 점수를 입력받아 저장
	in >> name >> midterm >> final;
	return in;
}
istream& Core::read(istream& in) {
	read_common(in);
	read_hw(in, homework); // Student_info.h에 있다.
	return in;
}

// 비멤버 함수 정의
bool compare(const Core& c1, const Core& c2) {
	return c1.getName() < c2.getName();
}

bool compare_grades(const Core& c1, const Core& c2) {
	return c1.grade() < c2.grade(); // 가상 함수 사용해야됨
}