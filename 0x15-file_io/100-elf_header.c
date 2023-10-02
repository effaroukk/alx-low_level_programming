#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define ELF_MAGIC 0x7F454C46 

typedef struct {
    unsigned char   e_ident[16];
    uint16_t        e_type;
    uint16_t        e_machine;
    uint32_t        e_version;
    uint64_t        e_entry;
    uint64_t        e_phoff;
    uint64_t        e_shoff;
    uint32_t        e_flags;
    uint16_t        e_ehsize;
    uint16_t        e_phentsize;
    uint16_t        e_phnum;
    uint16_t        e_shentsize;
    uint16_t        e_shnum;
    uint16_t        e_shstrndx;
} ElfHeader;


void exit_with_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(98);
}
void read_and_display_elf_header(int fd) {
    ElfHeader header;
	
    int i;
   
    if (read(fd, &header, sizeof(ElfHeader)) != sizeof(ElfHeader)) {
        exit_with_error("Failed to read ELF header.");
    }

   
    if (*(uint32_t*)header.e_ident != ELF_MAGIC) {
        exit_with_error("Not an ELF file.");
    }

  
    printf("Magic: ");
    for (i = 0; i < 16; i++) {
        printf("%02x ", header.e_ident[i]);
    }
    printf("\n");

    printf("Class: %d-bit\n", header.e_ident[4] == 1 ? 32 : 64);

    printf("Data: %s\n", header.e_ident[5] == 1 ? "Little Endian" : "Big Endian");

    printf("Version: %d\n", header.e_ident[6]);

    printf("OS/ABI: %d\n", header.e_ident[7]);

    printf("ABI Version: %d\n", header.e_ident[8]);

    printf("Type: %d\n", header.e_type);

    printf("Entry point address: 0x%lx\n", header.e_entry);
}

int main(int argc, char *argv[]) {

	  const char *filename = argv[1];
    int fd = open(filename, O_RDONLY);

    if (argc != 2) {
        exit_with_error("Usage: elf_header elf_filename");
    }

  

    if (fd == -1) {
        exit_with_error("Failed to open file.");
    }

  
    read_and_display_elf_header(fd);

    
    close(fd);

    return 0;
}

