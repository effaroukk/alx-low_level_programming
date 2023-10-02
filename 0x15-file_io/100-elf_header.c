#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void elf_check(unsigned char *e_idnt);
void magic_print(unsigned char *e_idnt);
void class_print(unsigned char *e_idnt);
void close_elf(int elf);
void data_print(unsigned char *e_idnt);
void version_print(unsigned char *e_idnt);
void abi_print(unsigned char *e_idnt);
void osabi_print(unsigned char *e_idnt);
void type_print(unsigned int e_type, unsigned char *e_idnt);
void entry_print(unsigned long int e_entry, unsigned char *e_idnt);

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

/**
 * osabi_print - Prints the OS/ABI of an ELF header.
 * @e_idnt: A pointer to an array containing the ELF version.
 */
void osabi_print(unsigned char *e_idnt)
{
	printf(" OS/ABI: ");

	switch (e_idnt[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_idnt[EI_OSABI]);
	}
}

/**
 * abi_print( - Prints the ABI version of an ELF header.
 * @e_idnt: A pointer to an array containing the ELF ABI version.
 */
void abi_print(unsigned char *e_idnt)
{
	printf(" ABI Version: %d\n",
		e_idnt[EI_ABIVERSION]);
}

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

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

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

