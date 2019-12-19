#ifndef DBASE_H
#define DBASE_H

#include "student.h"

class DBase
{
public:
    DBase(int);
    ~DBase();
    void InitInput();
    void Show();
    void ShowStudentsWithGrades4And5();
private:
    Student* m_students;
    int m_nRecords;
};

DBase::DBase(int nRec)
    : m_students(new Student[nRec])
    , m_nRecords(nRec)
{}

DBase::~DBase() { if (m_students) delete [] m_students; }

void DBase::InitInput()
{
    std::cout << "\nВведите данные в виде: " << std::endl;
    std::cout << "Инициалы студента(только буквы), номер группы(только цифры), оценка(только цифры) (5 оценок)" << std::endl;
    for (auto i = 0; i < m_nRecords; ++i)
    {
        std::cout << (i + 1) << ". ";
        std::cin >> m_students[i];
    }

    for (auto i = 0; i < m_nRecords - 1; ++i)
    {
        for (auto j = 0; j < m_nRecords - i - 1; ++j)
        {
            if (m_students[j].averageGrade() > m_students[j + 1].averageGrade())
            {
                auto temp = m_students[j];
                m_students[j] = m_students[j + 1];
                m_students[j + 1] = temp;
            }
        }
    }
}

void DBase::Show()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Показать всех студентов:" << std::endl;
    for (auto i = 0; i < m_nRecords; ++i)
    {
        std::cout << (i + 1) << ". " << m_students[i] << std::endl;
    }
}

void DBase::ShowStudentsWithGrades4And5()
{    
    auto not_found = true;
    std::cout << "\nПоказать всех студентов с 4 и 5 " << std::endl;
    for (auto i = 0; i < m_nRecords; ++i)
    {        
        auto student_grades = m_students[i].getGrades();
        auto is4or5 = true;
        for (auto j = 0; j < 5; ++j)
        {            
            if (4 > student_grades[j])
            {                
                is4or5 = false;
            }
        }

        if (is4or5)
        {
            not_found = false;
            std::cout << m_students[i];
        }
    }

    if (not_found)
    {
        std::cout << "Нет таких студентов" << std::endl;
    }
}

#endif // DBASE_H
