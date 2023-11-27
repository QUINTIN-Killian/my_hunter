/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-killian.quintin
** File description:
** Manages the scope.
** scope
*/

#include "include/my.h"
#include "include/my_hunter.h"

void init_scope(window_s *window)
{
    window->scope = malloc(sizeof(scope_s));
    window->scope->scope_texture =
    sfTexture_createFromFile("images/black_scope.png", NULL);
    window->scope->scope_sprite = sfSprite_create();
    sfSprite_setTexture(window->scope->scope_sprite,
    window->scope->scope_texture, sfFalse);
    sfSprite_setScale(window->scope->scope_sprite, (sfVector2f){0.15, 0.15});
    sfSprite_setOrigin(window->scope->scope_sprite, (sfVector2f){270, 270});
}
