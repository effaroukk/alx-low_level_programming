#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


/**
 *  * version_print( - Prints the version of an ELF header.
 *   * @e_idnt: A pointer to an array containing the ELF version.
 *    */
void version_print(unsigned char *e_idnt)
{
         printf(" Version: %d",
                          e_idnt[EI_VERSION]);

        switch (e_idnt[EI_VERSION])
        {
        case EV_CURRENT:
                printf(" (current)\n");
                break;
        default:
                printf("\n");
                break;
        }
}
