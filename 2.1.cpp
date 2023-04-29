#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");
    for (int i = 0;i<argc;i++)
        cout << i << ". " << argv[i] << endl;
    return 0;
}

//echo_arf a man a plan a canal panama