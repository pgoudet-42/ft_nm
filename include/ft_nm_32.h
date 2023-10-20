#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include <string.h>


#ifndef FT_NM_32
#define FT_NM_32

struct ELFheaders32 {
    unsigned int ei_mag0;
    unsigned char ei_class;
    unsigned char ei_data;
    unsigned char ei_version;
    unsigned char ei_osabi;
    unsigned char ei_abiversion;
    unsigned char ei_pad[7];
    unsigned short int e_type;
    unsigned short int e_machine;
    unsigned int e_version;
    unsigned int e_entry;
    unsigned int e_phoff;
    unsigned int e_shoff;
    unsigned int e_flags;
    unsigned short int e_ehsize;
    unsigned short int e_phentsize;
    unsigned short int e_phnum;
    unsigned short int e_shentsize;
    unsigned short int e_shnum;
    unsigned short int e_shstrndx;
};


struct pheaders32 {
    unsigned int p_type;
    unsigned int p_offset;
    unsigned int p_vaddr;
    unsigned int p_paddr;
    unsigned int p_filesz;
    unsigned int p_memsz;
    unsigned int p_align;
};

struct sheaders32 {
    unsigned int sh_name;
    unsigned int sh_type;
    unsigned int sh_flags;
    unsigned int sh_addr;
    unsigned int sh_offset;
    unsigned int sh_size;
    unsigned int sh_link;
    unsigned int sh_info;
    unsigned int sh_addralign;
    unsigned int sh_entsize;
};

struct Elf32_Sym {
	unsigned int	    st_name;
	unsigned int	    st_value;
	unsigned int	    st_size;
	unsigned char	    st_info;
	unsigned char	    st_other;
	unsigned short int	st_shndx;
};

struct sym_name_32 {
    struct Elf32_Sym sym;
    char *name;
};

void print_elf32_sym(struct Elf32_Sym sym);
void print_sections_names_32(struct sheaders32 *sheaders, char *buf, struct ELFheaders32 elfheader);
void print_sHeader32(struct sheaders32 sheader);
void print_pHeader32(struct pheaders32 pheader);
void print_elfHeader32(struct ELFheaders32 elfHeader);

struct ELFheaders32 get_elfHeader32_little_endian(char *buf);
struct pheaders32 get_pHeader32_little_endian(char *buf, struct ELFheaders32 *elfHeader);
struct sheaders32 get_sHeaders32_little_endian(char *buf, struct ELFheaders32 *elfHeader, int nb);
struct Elf32_Sym get_sym32_section_little(char *buf, struct ELFheaders32 elfHeader, struct sheaders32 *sheaders, int i);

struct ELFheaders32 get_elfHeader32_little_endian(char *buf);
struct pheaders32 get_pHeader32_little_endian(char *buf, struct ELFheaders32 *elfHeader);
struct sheaders32 get_sHeaders32_little_endian(char *buf, struct ELFheaders32 *elfHeader, int nb);
struct Elf32_Sym get_sym32_section_little(char *buf, struct ELFheaders32 elfHeader, struct sheaders32 *sheaders, int i);
struct sheaders32 *get_string_offsets_32(struct ELFheaders32 elfHeader, char *buf);
struct Elf32_Sym *get_syms(struct ELFheaders32 elfHeader, struct sheaders32 *sheaders, char *buf, int *size);
char *get_section_name_32(char *buf, struct ELFheaders32 elfHeader ,struct sheaders32 *sheaders, unsigned int name);
char get_type_32(struct Elf32_Sym sym,  struct sheaders32 *shdr);
struct sym_name_32 *get_sys_tab_32(struct ELFheaders32 elfHeader, struct sheaders32 *sheaders, char *buf, int *j);
struct sym_name_32 *get_strings_sysm_32(struct ELFheaders32 elfHeader, struct sheaders32 *sheaders, char *buf, int *nb_string);
char *get_sym_name_32(char *buf, struct ELFheaders32 elfHeader ,struct sheaders32 *sheaders, unsigned int name);

void sort_tab(int **tab, size_t size);

#endif