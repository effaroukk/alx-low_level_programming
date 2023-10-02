#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * @e_indt - index
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
        Elf64_Ehdr *header;
        int oo, rr;

        oo = open(argv[1], O_RDONLY);
        if (oo == -1)
        {
                dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
                exit(98);
        }
        header = malloc(sizeof(Elf64_Ehdr));
        if (header == NULL)
        {
                close_elf(oo);
                             dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
                exit(98);
        }
        rr = read(oo, header, sizeof(Elf64_Ehdr));
        if (rr == -1)
        {
                free(header);
                close_elf(oo);
                dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
                exit(98);
        }

        elf_check(header->e_ident);
        printf("ELF Header:\n");
        magic_print(header->e_ident);
        class_print(header->e_ident);
        data_print(header->e_ident);
        version_print(header->e_ident);
        osabi_print(header->e_ident);
        abi_print(header->e_ident);
        type_print(header->e_type, header->e_ident);
        entry_print(header->e_entry, header->e_ident);

        free(header);
        close_elf(oo);
        return (0);
}
