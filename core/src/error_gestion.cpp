/*
** EPITECH PROJECT, 2020
** error_gestion
** File description:
** error_gestion
*/

void check_errors(int ac, char **av)
{
    (void) av;
    if (ac < 2)
        throw ("The program must take as startup argument the graphics library to use initially");
}