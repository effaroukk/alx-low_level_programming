#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * magic_print - Prints the magic numbers of an ELF header.
 * @e_idnt: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void magic_print(unsigned char *e_idnt)
{
        int ind;

        printf(" Magic: ");

        for (ind = 0; ind < EI_NIDENT; ind++)
        {
                printf("%02x", e_idnt[ind]);

                if (ind == EI_NIDENT - 1)
                        printf("\n");
                else
                        printf(" ");
        }
}
