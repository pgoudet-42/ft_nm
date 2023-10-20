#include "../include/ft_nm.h"
#include "../include/ft_nm_32.h"

char cmp_names(char *str1, char *str2) {
    int i = -1, j = -1;

    if (str1 == NULL)    
        return (0);
    if (str2 == NULL)
        return (1);
    do {
        j++;
        i++;
        while (str1[i] != 0 && (str1[i] == '_' || str1[i] == '@'))
            i++;
        while (str2[j] != 0 && (str2[j] == '_' || str2[j] == '@'))
            j++;
        if (ft_tolower(str1[i]) != ft_tolower(str2[j])) {
            return (ft_tolower(str1[i]) - ft_tolower(str2[j]));
        }

    } while(str1[i] != 0 && str2[j] != 0);
    return (0);
}

void swap_64(struct sym_name **t, int j) {
    struct sym_name tmp;

    tmp = (*t)[j - 1];
    (*t)[j - 1] = (*t)[j];
    (*t)[j] = tmp;
}

void swap_32(struct sym_name_32 **t, int j) {
    struct sym_name_32 tmp;

    tmp = (*t)[j - 1];
    (*t)[j - 1] = (*t)[j];
    (*t)[j] = tmp;
}

void sort_sym_tab_32(struct sym_name_32 **t, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 1; j < size; j++)
            if (cmp_names((*t)[j - 1].name, (*t)[j].name) >= 0)
                swap_32(t, j);
}

void sort_sym_tab_64 (struct sym_name **t, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 1; j < size; j++)
            if (cmp_names((*t)[j - 1].name, (*t)[j].name) >= 0)
                swap_64(t, j);
}

int ft_nm_64(char *buf) {
    struct ELFheaders64 elfHeader;
    struct sheaders64 *sheaders;
    struct sym_name *sym_tab = NULL;
    int j = 0;

    elfHeader = get_elfHeader64_little_endian(buf);
    sheaders = get_string_offsets_64(elfHeader, buf);

    sym_tab = get_sys_tab_64(elfHeader, sheaders, buf, &j);
    if (sym_tab == NULL) {
        free(sheaders);
        return (1);
    }

    sort_sym_tab_64(&sym_tab, j);
    for (int i = 0; i < j; i++) {
        if (!(((sym_tab[i].sym.st_info >> 4) & 0x0F) == 0 && (sym_tab[i].sym.st_info & 0x0F) == 4)) {
            if (get_type_64(sym_tab[i].sym, sheaders) != 'U' && get_type_64(sym_tab[i].sym, sheaders) != 'w')
                printf("%.16lx %c %s\n", sym_tab[i].sym.st_value, get_type_64(sym_tab[i].sym, sheaders), sym_tab[i].name);
            else
                printf("                 %c %s\n", get_type_64( sym_tab[i].sym, sheaders), sym_tab[i].name);
        }
        free(sym_tab[i].name);
    }
    free(sheaders);
    free(sym_tab);
    return (0);
}

int ft_nm_32(char *buf) {
    struct ELFheaders32 elfHeader;
    struct sheaders32 *sheaders;
    struct sym_name_32 *sym_tab = NULL;
    int j = 0;

    elfHeader = get_elfHeader32_little_endian(buf);
    sheaders = get_string_offsets_32(elfHeader, buf);

    sym_tab = get_sys_tab_32(elfHeader, sheaders, buf, &j);
    if (sym_tab == NULL) {
        free(sheaders);
        return (1);
    }

    sort_sym_tab_32(&sym_tab, j);

    for (int i = 0; i < j; i++) {
        if (!(((sym_tab[i].sym.st_info >> 4) & 0x0F) == 0 && (sym_tab[i].sym.st_info & 0x0F) == 4)) {
            if (get_type_32(sym_tab[i].sym, sheaders) != 'U' && get_type_32(sym_tab[i].sym, sheaders) != 'w')
                printf("%.8x %c %s\n",sym_tab[i].sym.st_value, get_type_32(sym_tab[i].sym, sheaders), sym_tab[i].name);
            else
                printf("         %c %s\n", get_type_32( sym_tab[i].sym, sheaders), sym_tab[i].name);
        }
        free(sym_tab[i].name);
    }
    free(sheaders);
    free(sym_tab);
    return (0);
}

int get_fd(int argc, char **argv, struct stat **buf) {
    int fd;

    if (argc == 1)
        argv[1] = "./a.out";
    fd = open_file(argv[1]);
    if (fd == -1) {
        write(1, "Error: file opening failed\n", strlen("Error: file opening failed\n"));
        return (-1);
    }
    *buf = malloc(sizeof(struct stat));
    if (*buf == NULL)
        return(-1);
    if (get_file_info(fd, *buf) == -1) {
        write(1, "Error: fstat failed on file\n", strlen("Error: fstat failed on file\n"));
        return (-1);
    }
    return (fd);
}

int main(int argc, char **argv) {
    int fd = -1;
    struct stat *buf;
    void *ptr = NULL;
    int res = 0;

    fd = get_fd(argc, argv, &buf);
    ptr = ft_mmap(buf->st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (ptr == NULL) {
        write(1, "Error: ft_mmap failed\n", strlen("Error: ft_mmap failed\n"));
        free(buf);
        return (1);
    }
    if (((char *)ptr)[0x04] == 2)
        res = ft_nm_64(ptr);
    else if (((char *)ptr)[0x04] == 1)
        res =ft_nm_32(ptr);
    if (res == 1 || munmap(ptr, buf->st_size) == -1) {
        write(1, "Error: ft_nm failed\n", strlen("Error: ft_nm failed\n"));
        free(buf);
        return (1);
    }
    free(buf);
    return (0);
}