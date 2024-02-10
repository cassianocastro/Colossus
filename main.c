#include <locale.h>
#include <stdlib.h>

#include "./src/app/includes/Colossus.h"

int main(int argc, const char* argv[])
{
    setlocale(LC_ALL, "");

    startApp();

    return EXIT_SUCCESS;
}