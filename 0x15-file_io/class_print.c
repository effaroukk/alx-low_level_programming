#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * class_print - Prints the class of an ELF header.
 * @e_idnt: A pointer to an array containing the ELF class.
 */
void class_print(unsigned char *e_idnt)
{
        printf(" Class: ");

        switch (e_idnt[EI_CLASS])
        {
        case ELFCLASSNONE:
                printf("none\n");
                break;
        case ELFCLASS32:
                printf("ELF32\n");
                break;
        case ELFCLASS64:
                printf("ELF64\n");
                break;
        default:
                printf("<unknown: %x>\n", e_idnt[EI_CLASS]);
        }
}
