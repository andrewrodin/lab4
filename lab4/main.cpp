#include "dbase.h"

int main()
{
	setlocale(0, "Russian");
    const int nRecord = 4;

    DBase dbase(nRecord);
    dbase.InitInput();
    dbase.Show();

    dbase.ShowStudentsWithGrades4And5();

    system("pause");
    return 0;
}
