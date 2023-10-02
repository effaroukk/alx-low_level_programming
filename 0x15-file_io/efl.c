#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void elf_check(unsigned char *e_idnt);

/**
 * elf_check - Checks if a file is an ELF file.
 * @e_idnt: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void elf_check(unsigned char *e_idnt)
{
	    int ind;

        for (ind = 0; ind < 4; ind++)
        {
                if (e_idnt[ind] != 127 &&
                    e_idnt[ind] != 'E' &&
                    e_idnt[ind] != 'L' &&
                    e_idnt[ind] != 'F')
                {
                        dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
                        exit(98);
                }
        }
}

