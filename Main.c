#include <locale.h>
#include <stdlib.h>

#include "./src/app/includes/Colossus.h"

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");

    startApp();

    return EXIT_SUCCESS;
}