#include "../include/ft_nm_32.h"

void print_elfHeader32(struct ELFheaders32 elfHeader) {
    printf("elfHeader.ei_mag0: %hhx %hhx %hhx %hhx\n", \
    elfHeader.ei_mag0 >> 24, elfHeader.ei_mag0 >> 16, \
    elfHeader.ei_mag0 >> 8, elfHeader.ei_mag0);
    printf("elfHeader.ei_class: %hhx\n", elfHeader.ei_class);
    printf("elfHeader.ei_data: %hhx\n", elfHeader.ei_data);
    printf("elfHeader.ei_version: %hhx\n", elfHeader.ei_version);
    printf("elfHeader.ei_osabi: %hhx\n", elfHeader.ei_osabi);
    printf("elfHeader.ei_abiversion: %hhx\n", elfHeader.ei_abiversion);
    printf("elfHeader.ei_pad: %hhx %hhx %hhx %hhx %hhx %hhx %hhx\n", \
        elfHeader.ei_pad[0], elfHeader.ei_pad[1], elfHeader.ei_pad[2],\
        elfHeader.ei_pad[3], elfHeader.ei_pad[4], elfHeader.ei_pad[5], elfHeader.ei_pad[6]);
    printf("elfHeader.e_type: %hhx %hhx\n", elfHeader.e_type >> 8, elfHeader.e_type);
    printf("elfHeader.e_machine: %hhx %hhx\n", elfHeader.e_machine >> 8, elfHeader.e_machine);
    printf("elfHeader.e_version: %hhx %hhx %hhx %hhx\n", \
    elfHeader.e_version >> 24, elfHeader.e_version >> 16, \
    elfHeader.e_version >> 8, elfHeader.e_version);
    printf("elfHeader.e_entry: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(elfHeader.e_entry >> 24), (unsigned int)(elfHeader.e_entry >> 16), \
    (unsigned int)(elfHeader.e_entry >> 8), (unsigned int)(elfHeader.e_entry));
    printf("elfHeader.e_phoff: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(elfHeader.e_phoff >> 24), (unsigned int)(elfHeader.e_phoff >> 16), \
    (unsigned int)(elfHeader.e_phoff >> 8), (unsigned int)(elfHeader.e_phoff));
    printf("elfHeader.e_shoff: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(elfHeader.e_shoff >> 24), (unsigned int)(elfHeader.e_shoff >> 16), \
    (unsigned int)(elfHeader.e_shoff >> 8), (unsigned int)(elfHeader.e_shoff));
    printf("elfHeader.e_flags: %hhx %hhx %hhx %hhx\n", \
    elfHeader.e_flags >> 24, elfHeader.e_flags >> 16, elfHeader.e_flags >> 8, elfHeader.e_flags);
    printf("elfHeader.e_ehsize: %hhx %hhx\n", elfHeader.e_ehsize >> 8, elfHeader.e_ehsize);
    printf("elfHeader.e_phentsize: %hhx %hhx\n", elfHeader.e_phentsize >> 8, elfHeader.e_phentsize);
    printf("elfHeader.e_phnum: %hhx %hhx\n", elfHeader.e_phnum >> 8, elfHeader.e_phnum);
    printf("elfHeader.e_shentsize: %hhx %hhx\n", elfHeader.e_shentsize >> 8, elfHeader.e_shentsize);
    printf("elfHeader.e_shnum: %hhx %hhx\n", elfHeader.e_shnum >> 8, elfHeader.e_shnum);
    printf("elfHeader.e_shstrndx: %hhx %hhx\n", elfHeader.e_shstrndx >> 8, elfHeader.e_shstrndx);
}

void print_pHeader32(struct pheaders32 pheader) {

    printf("pheader.p_type: %hhx %hhx\n", pheader.p_type >> 8, pheader.p_type);
    printf("pheader.p_offset: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(pheader.p_offset >> 24), (unsigned int)(pheader.p_offset >> 16), \
    (unsigned int)(pheader.p_offset >> 8), (unsigned int)(pheader.p_offset));
    printf("pheader.p_vaddr: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(pheader.p_vaddr >> 24), (unsigned int)(pheader.p_vaddr >> 16), \
    (unsigned int)(pheader.p_vaddr >> 8), (unsigned int)(pheader.p_vaddr));
    printf("pheader.p_paddr: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(pheader.p_paddr >> 24), (unsigned int)(pheader.p_paddr >> 16), \
    (unsigned int)(pheader.p_paddr >> 8), (unsigned int)(pheader.p_paddr));
    printf("pheader.p_filesz: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(pheader.p_filesz >> 24), (unsigned int)(pheader.p_filesz >> 16), \
    (unsigned int)(pheader.p_filesz >> 8), (unsigned int)(pheader.p_filesz));
    printf("pheader.p_memsz: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(pheader.p_memsz >> 24), (unsigned int)(pheader.p_memsz >> 16), \
    (unsigned int)(pheader.p_memsz >> 8), (unsigned int)(pheader.p_memsz));
    printf("pheader.p_align: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(pheader.p_align >> 24), (unsigned int)(pheader.p_align >> 16), \
    (unsigned int)(pheader.p_align >> 8), (unsigned int)(pheader.p_align));
}

void print_sHeader32(struct sheaders32 sheader) {
    printf("sheader.sh_name: %hhx %hhx %hhx %hhx\n",\
    (unsigned int)(sheader.sh_name >> 24), (unsigned int)(sheader.sh_name >> 16), \
    (unsigned int)(sheader.sh_name >> 8), (unsigned int)(sheader.sh_name));
    printf("sheader.sh_type: %hhx %hhx %hhx %hhx\n",\
    (unsigned int)(sheader.sh_type >> 24), (unsigned int)(sheader.sh_type >> 16), \
    (unsigned int)(sheader.sh_type >> 8), (unsigned int)(sheader.sh_type));
    printf("sheader.sh_flags: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(sheader.sh_flags >> 24), (unsigned int)(sheader.sh_flags >> 16), \
    (unsigned int)(sheader.sh_flags >> 8), (unsigned int)(sheader.sh_flags));
    printf("sheader.sh_addr: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(sheader.sh_addr >> 24), (unsigned int)(sheader.sh_addr >> 16), \
    (unsigned int)(sheader.sh_addr >> 8), (unsigned int)(sheader.sh_addr));
    printf("sheader.sh_offset: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(sheader.sh_offset >> 24), (unsigned int)(sheader.sh_offset >> 16), \
    (unsigned int)(sheader.sh_offset >> 8), (unsigned int)(sheader.sh_offset));
    printf("sheader.sh_size: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(sheader.sh_size >> 24), (unsigned int)(sheader.sh_size >> 16), \
    (unsigned int)(sheader.sh_size >> 8), (unsigned int)(sheader.sh_size));
    printf("sheader.sh_link: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(sheader.sh_link >> 24), (unsigned int)(sheader.sh_link >> 16), \
    (unsigned int)(sheader.sh_link >> 8), (unsigned int)(sheader.sh_link));
    printf("sheader.sh_info: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(sheader.sh_info >> 24), (unsigned int)(sheader.sh_info >> 16), \
    (unsigned int)(sheader.sh_info >> 8), (unsigned int)(sheader.sh_info));
    printf("sheader.sh_addralign: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(sheader.sh_addralign >> 24), (unsigned int)(sheader.sh_addralign >> 16), \
    (unsigned int)(sheader.sh_addralign >> 8), (unsigned int)(sheader.sh_addralign));
    printf("sheader.sh_entsize: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(sheader.sh_entsize >> 24), (unsigned int)(sheader.sh_entsize >> 16), \
    (unsigned int)(sheader.sh_entsize >> 8), (unsigned int)(sheader.sh_entsize));
}

void print_sections_names_32(struct sheaders32 *sheaders, char *buf, struct ELFheaders32 elfheader) {
    for (int i = 0; i < elfheader.e_shnum; i++) {
        if (sheaders[i].sh_type == 0x03) {
            size_t j = 0;
            int index = 0;
            while (j < sheaders[i].sh_size) {
                if (buf[sheaders[i].sh_offset + j] == 0) {
                    write(1, &buf[sheaders[i].sh_offset + index], j - index);
                    write(1, "\n", 1);
                    index = j;
                }
                j++;
            }
        }
    }
}

void    print_elf32_sym(struct Elf32_Sym sym) {

    printf("sym.sh_name: %hhx %hhx %hhx %hhx\n",\
    (unsigned int)(sym.st_name >> 24), (unsigned int)(sym.st_name >> 16), \
    (unsigned int)(sym.st_name >> 8), (unsigned int)(sym.st_name));
    printf("sym.sh_info: %hhx\n", sym.st_info);
    printf("sym.sh_other: %hhx\n", sym.st_other);
    printf("sym.st_shndx: %hhx %hhx\n", sym.st_shndx >> 8, sym.st_shndx);
    printf("sym.st_value: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(sym.st_value >> 24), (unsigned int)(sym.st_value >> 16), \
    (unsigned int)(sym.st_value >> 8), (unsigned int)(sym.st_value));
    printf("sym.st_size: %hhx %hhx %hhx %hhx\n", \
    (unsigned int)(sym.st_size >> 24), (unsigned int)(sym.st_size >> 16), \
    (unsigned int)(sym.st_size >> 8), (unsigned int)(sym.st_size));
}