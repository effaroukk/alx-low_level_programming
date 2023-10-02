#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>




/**
 * entry_print - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_idnt: A pointer to an array containing the ELF class.
 */
void entry_print(unsigned long int e_entry, unsigned char *e_idnt)
{
        printf(" Entry point address: ");

        if (e_idnt[EI_DATA] == ELFDATA2MSB)
        {
                e_entry = ((e_entry << 8) & 0xFF00FF00) |
                          ((e_entry >> 8) & 0xFF00FF);
                e_entry = (e_entry << 16) | (e_entry >> 16);
        }

        if (e_idnt[EI_CLASS] == ELFCLASS32)
                printf("%#x\n", (unsigned int)e_entry);

        else
                printf("%#lx\n", e_entry);
}

