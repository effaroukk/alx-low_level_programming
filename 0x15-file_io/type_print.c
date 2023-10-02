#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * type_print - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_idnt: A pointer to an array containing the ELF class.
 */
void type_print(unsigned int e_type, unsigned char *e_idnt)
{
        if (e_idnt[EI_DATA] == ELFDATA2MSB)
                e_type >>= 8;

        printf(" Type: ");

        switch (e_type)
        {
        case ET_NONE:
                printf("NONE (None)\n");
                break;
        case ET_REL:
                printf("REL (Relocatable file)\n");
                break;
        case ET_EXEC:
                printf("EXEC (Executable file)\n");
                break;
        case ET_DYN:
                printf("DYN (Shared object file)\n");
                break;
        case ET_CORE:
		  printf("CORE (Core file)\n");
                break;
        default:
                printf("<unknown: %x>\n", e_type);
        }
}
