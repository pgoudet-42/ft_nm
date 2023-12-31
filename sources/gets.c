#include "../include/ft_nm.h"

int get_file_info(int fd, struct stat *buf) {
    int res = 0;

    res = fstat(fd, buf);
    return (res);
}

char *get_sym_name_64(char *buf, struct ELFheaders64 elfHeader ,struct sheaders64 *sheaders, unsigned int name) {
    char *str = NULL;
    size_t offset = 0;
    size_t i, j;

    if (name == 0)
        return (NULL);
    i = elfHeader.e_shstrndx;
    if (sheaders[i].sh_type != 0x03)
        return (NULL);

    offset = sheaders[i].sh_offset + name;
    j = 0;
    while (j <= sheaders[i].sh_size) {
        if (buf[offset + j] == 0 && j > 0)
            break;
        j++;
    }
    if (sheaders[i].sh_size <= j)
        return (NULL);
    str = malloc(j + 1);
    ft_strlcpy(str, &(buf[offset]), j + 1);
    return (str);
}


char *get_section_name_64(char *buf, struct ELFheaders64 elfHeader ,struct sheaders64 *sheaders, unsigned int name) {
    char *str = NULL;
    size_t offset = 0;
    size_t i, j;

    if (name == 0)
        return (NULL);
    i = elfHeader.e_shstrndx - 1;
    if (sheaders[i].sh_type != 0x03)
        return (NULL);

    offset = sheaders[i].sh_offset + name;
    j = 0;
    while (j <= sheaders[i].sh_size) {
        if (buf[offset + j] == 0 && j > 0)
            break;
        j++;
    }
    if (sheaders[i].sh_size <= j)
        return (NULL);
    str = malloc(j + 1);
    ft_strlcpy(str, &(buf[offset]), j + 1);
    return (str);
}

struct sheaders64 *get_string_offsets_64(struct ELFheaders64 elfHeader, char *buf) {
    struct sheaders64 *sheaders;

    sheaders = malloc(sizeof(struct sheaders64) * elfHeader.e_shnum);
    if (!sheaders)
        return (NULL);
    
    for (int i = 0; i < elfHeader.e_shnum; i++)
        (sheaders)[i] = get_sHeaders64_little_endian(buf, &elfHeader, i);

    return (sheaders);
}

struct Elf64_Sym *get_syms_64(struct ELFheaders64 elfHeader, struct sheaders64 *sheaders, char *buf, size_t *size) {
    struct Elf64_Sym *syms;

    for (int i = 0; i < elfHeader.e_shnum; i++) {
        if (sheaders[i].sh_type == 0x02) {
            *size = sheaders[i].sh_size / sheaders[i].sh_entsize;
            syms = malloc(sizeof(struct Elf64_Sym) * (*size));
            if (!syms)
                return (NULL);
            break;
        }
    }
    for (size_t i = 0; i < (*size); i++) 
        syms[i] = get_sym64_section_little(buf, elfHeader, sheaders, i);
    return (syms);
}

struct sym_name *get_sys_tab_64(struct ELFheaders64 elfHeader, struct sheaders64 *sheaders, char *buf, int *j) {
  struct Elf64_Sym *syms;
  size_t size = 0;
  struct sym_name *sym_tab = NULL;


  syms = get_syms_64(elfHeader, sheaders, buf, &size);
  sym_tab = malloc(sizeof(struct sym_name) * size);
  if (!sym_tab)
    return (NULL);
  for (size_t i = 0; i < size; i++) {
    if ((syms[i].st_name != 0 || i == 0)) {
      sym_tab[*j].name = get_section_name_64(buf, elfHeader, sheaders, syms[i].st_name);
      sym_tab[*j].sym.st_info = syms[i].st_info;
      sym_tab[*j].sym.st_name = syms[i].st_name;
      sym_tab[*j].sym.st_other = syms[i].st_other;
      sym_tab[*j].sym.st_shndx = syms[i].st_shndx;
      sym_tab[*j].sym.st_size = syms[i].st_size;
      sym_tab[*j].sym.st_value = syms[i].st_value;
      if (sym_tab[*j].name == NULL)
        (*j)--;
      (*j)++;
    }
  }
  free(syms);
  return (sym_tab);
}

char get_type_64(struct Elf64_Sym sym,  struct sheaders64 *shdr) {

    char  c;
    int bind = 0, type = 0;

    bind = (sym.st_info >> 4) & 0x0F;
    type = sym.st_info & 0x0F;

    if (bind == 0x0a)
      c = 'u';
    else if (bind == 0x02) {
        c = 'W';
        if (sym.st_shndx == 0x00)
          c = 'w';
    }
    else if (bind == 0x02 && type == 0x01) {
        c = 'V';
        if (sym.st_shndx == 0x00)
          c = 'v';
    }
    else if (sym.st_shndx == 0x00)
      c = 'U';
    else if (sym.st_shndx == 0xfff1)
      c = 'A';
    else if (sym.st_shndx == 0xfff2)
      c = 'C';
    else if (shdr[sym.st_shndx].sh_type == 0x08
         && shdr[sym.st_shndx].sh_flags == (0x02 | 0x01))
      c = 'B';
    else if (shdr[sym.st_shndx].sh_type == 0x01
         && shdr[sym.st_shndx].sh_flags == (0x02 | 0x01))
      c = 'D';
    else if (shdr[sym.st_shndx].sh_type == 0x01
         && shdr[sym.st_shndx].sh_flags == (0x02 | 0x04))
      c = 'T';
    else if (shdr[sym.st_shndx].sh_type == 0x0f
         || shdr[sym.st_shndx].sh_type == 0x0e
         || shdr[sym.st_shndx].sh_type == 0x06)
      c = 'D';
    else if (shdr[sym.st_shndx].sh_flags == 0x02)
      c = 'R';
    else
      c = '?';
    if (bind == 0x00 && c != '?')
      c += 32;
    return c;
}