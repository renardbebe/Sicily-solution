#include <iostream>

using namespace std;

class Student
{
public:
    Student(int,int);
    int num;
    int score;
};

Student::Student(int num, int score)
{
    Student::num = num;
    Student::score = score;
}

int main ()
{
    Student s[5] = {
        Student(1001,98),
        Student(1002,76),
        Student(1003,65),
        Student(1004,90),
        Student(1005,77),
    };
    cout << s[0].num << " " << s[0].score << endl;
    cout << s[2].num << " " << s[2].score << endl;
    cout << s[4].num << " " << s[4].score << endl;
    return 0;
}
