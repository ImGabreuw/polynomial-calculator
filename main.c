#include <stdio.h>

#include "cli.h"

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        test(argc, argv);
        return 0;
    }

    cli(argc, argv);
    return 0;
}
