// main_stdinfo.cpp
#include <algorithm>

#include <ios>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

#include "Student_info.h"

using namespace std;

int main() {
	// 파일스트림 만들고 "txt" 파일을 읽기
	ifstream student_file("new_grades.txt"); // 에런

	vector<Student_info> students, undergrad, grad, intl;
	Student_info record;
	string::size_type maxlen = 0;

	// 데이터를 읽고 저장하기
	while (record.read(student_file)) {
		maxlen = max(maxlen, record.getName().size());
		students.push_back(record);
	}

	// 학생 기록을 알파벳 순으로 정렬
	sort(students.begin(), students.end(), Student_info::compare);

	// 이름과 점수 출력
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].getName()
			<< string(maxlen + 1 - students[i].getName().size(), ' ');

		try {
			double final_grade = students[i].grade(); // Student_info::grade()
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}