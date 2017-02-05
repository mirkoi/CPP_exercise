#include <iostream>
#include "main.hpp"
#include "sort.hpp"
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using namespace std;

/* Structure definition */
namespace Space_1
{
    char var_1;
    int var_2;
}
/* Namespace definition*/
namespace Space_2
{
    int var_1;
    int var_2[5];
}
struct Alfa
{
    int a;
    mutable int b;
};

int main()
{

    /* BEGIN: Mutable field of structure */
    Alfa x;
    const Alfa y = {.a = 1, .b = 1};
    int arr[10] = { 5,1,9,6,4,7,8,2,5,7};

    x.a = 3;
    x.b = 4;
    y.b = 6;
    //y.a = 3; /* 'a' field is not mutable*/
    /* END: Mutable field of structure */

    /* BEGIN: Memory allocation */

    int *din_all = new int (1);
    int &ref_din = *din_all;

    cout << "Allocated memory 'din_all': " << *din_all <<endl;
    cout << "Reference to allocated memory 'ref_din'= " << ref_din <<endl;

    *din_all = 4;

    ref_din = 10;
    cout << "Allocated memory 'din_all' = " << *din_all << endl;

    *din_all = x.a;
    cout << "din_all = x.a" << endl;
    cout << "din_all = " << *din_all << endl;

    /* END: Memory allocation */

    cout << "Hello world!" << endl;

    cout << "Space_1::var_1 sizeof = " << sizeof(Space_1::var_1) << endl;
    cout << "Space_1::var_2 sizeof = " << sizeof(Space_1::var_2) << endl;

    cout << endl;

    cout << "Space_2::var_1 sizeof = " << sizeof(Space_2::var_1) << endl;
    cout << "Space_2::var_2 sizeof = " << sizeof(Space_2::var_2) << endl;

    //var_1 = 3; //Error. Not defined namespace.
    Space_1::var_1 = 3; // OK

    int *niz = new int [10000];

    for (int i = 0; i< 10000; i++)
    {
        int var;

        while (1)
        {
            var = (unsigned int)rand();
            if(var < 3000)
            {
                niz[i] = var;
                break;
            }
        }


    }
    //qsort_array(niz, 10000);
    //sort_slow(niz, 1000);
    sort_slow_w(niz, 1000);

    for (int i=0; i<1000; i++)
    {
      ;//cout << "element: "<<niz[i] <<endl;
    }


    delete niz;
    return 0;
}
