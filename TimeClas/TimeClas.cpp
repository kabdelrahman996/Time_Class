#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
    Time t1(10, 30, 45);
    Time t2(2, 15, 20);

    std::cout << "t1: ";
    t1.display();

    std::cout << "t2: ";
    t2.display();

    std::cout << "t1 + t2: ";
    (t1 + t2).display();

    std::cout << "t1 - t2: ";
    (t1 - t2).display();


    // test prefix increment operator
    ++t1;
    cout << "After increment: ";
    t1.display();

    // test prefix decrement operator
    --t1;
    --t1;
    cout << "After decrement twice: ";
    t1.display();

	return 0;
}