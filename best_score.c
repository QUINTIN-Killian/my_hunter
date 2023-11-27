/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-killian.quintin
** File description:
** Manages the best player score.
** best_score
*/

#include "include/my.h"
#include "include/my_hunter.h"

int get_file_size(void)
{
    int ans = 0;
    char *buff = malloc(sizeof(char));
    int len;
    int fd = open(".best_score.txt", O_RDONLY);

    if (fd == -1)
        return 84;
    len = read(fd, buff, 1);
    while (len > 0) {
        ans++;
        len = read(fd, buff, 1);
    }
    close(fd);
    free(buff);
    return ans;
}

char *get_nb_file(void)
{
    int file_size = get_file_size();
    char *buff = malloc(sizeof(char) * (file_size + 1));
    int len;
    int fd = open(".best_score.txt", O_RDONLY);

    len = read(fd, buff, file_size);
    while (len > 0)
        len = read(fd, buff, file_size);
    buff[file_size] = '\0';
    close(fd);
    return buff;
}

void refresh_file(int file_nb, int nb_comp)
{
    int fd = open(".best_score.txt", O_WRONLY | O_TRUNC);
    char *str;

    if (nb_comp > file_nb) {
        str = convert_int_to_str(nb_comp);
        write(fd, str, my_strlen(str));
        free(str);
    } else {
        str = convert_int_to_str(file_nb);
        write(fd, str, my_strlen(str));
        free(str);
    }
    close(fd);
}
