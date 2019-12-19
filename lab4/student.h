#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student
{
public:
    std::string getInitials() const { return m_initials; }
    const int* getGrades() const { return &m_grades[0]; }
    double averageGrade() const
    {
        auto sum = 0.0;
        for (auto i = 0; i < 5; ++i)
        {
            sum += m_grades[i];
        }
        return (sum / 5);
    }
    friend std::istream& operator >> (std::istream& in, Student& student);
    friend std::ostream& operator << (std::ostream& out, const Student& student);
private:
    std::string m_initials;
    int m_group_number;
    int m_grades[5];
};

std::istream& operator >> (std::istream& in, Student& student)
{
    in >> student.m_initials;
    in >> student.m_group_number;
    for (auto i = 0; i < 5; ++i)
    {
        in >> student.m_grades[i];
    }

    return in;
}

std::ostream& operator << (std::ostream& out, const Student& student)
{
    out << student.m_initials << std::endl;
    out << student.m_group_number << std::endl;
    for (auto i = 0; i < 5; ++i)
    {
        out << student.m_grades[i] << ' ';
    }
    out << std::endl;

    return out;
}

#endif // STUDENT_H
