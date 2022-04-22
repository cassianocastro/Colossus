#include <stdlib.h>
#include <locale.h>


int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");

    startApp();

    return EXIT_SUCCESS;
}