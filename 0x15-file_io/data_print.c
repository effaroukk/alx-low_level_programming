#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * data_print( - Prints the data of an ELF header.
 * @e_idnt: A pointer to an array containing the ELF class.
 */
void data_print(unsigned char *e_idnt)
{
        printf(" Data: ");

        switch (e_idnt[EI_DATA])
        {
        case ELFDATANONE:
                printf("none\n");
                break;
        case ELFDATA2LSB:
                printf("2's complement, little endian\n");
                break;
        case ELFDATA2MSB:
                printf("2's complement, big endian\n");
                break;
        default:
                printf("<unknown: %x>\n", e_idnt[EI_CLASS]);
        }
}
