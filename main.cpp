#include <iostream>

#include "test/tester.h"
#include "self_list.h"
#include <iterator>

using namespace std;

int main(int argc, char const *argv[]) {
    Tester::execute();
    Method me = Count;
    int array[] ={1,2,3,4,3,2,5,6,4,6,3,6,7,8,9,2,7,12};
    SelfList<int> *l1 = new SelfList<int>(me);
    for (int i = 0; i < 18; i++) {
        l1->insert(array[i]);
    }
    l1->print();
    for (int j = 1; j <=3 ; j++) {
        l1->remove(j*2);
    }
    l1->print();
    for (int k = 1; k <=9 ; ++k) {
        l1->find(k*3);
        l1->print();
    }
    l1->print();
    //SelfList<int> list(SelfList<int>::Move);
    return EXIT_SUCCESS;
}

