/*
    191
    LinkedList1
    main
    pjirele, dfahrney
*/

#include "LinkedList.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    LinkedList l1 = LinkedList();
    l1.addTop(18);
    l1.addTop(12);
    l1.addTop(5);
    l1.addTop(-3);
    l1.addTop(123);
    l1.addTop(12);


    l1.display();

    
}


