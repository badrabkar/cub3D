// t_map   *turn_right(t_map *map)
// {
//     map->player.rotation_speed = ((int)map->player.rotation_speed + 23) % 24;
//     map->player.rotation_angle += map->player.rotation_speed * M_PI / 12;
//     return (map); 
// }

// t_map   *turn_left(t_map *map)
// {
//     map->player.rotation_speed = ((int)map->player.rotation_speed + 1) % 24;
//     map->player.rotation_angle = map->player.rotation_speed * M_PI / 12;
//     return (map);
// }


#include <math.h>
#include <stdio.h>

int equal(double a, double b)
{
    return fabs(a - b) < 1e-4;
}

int main()
{
    float a = cos(134 * M_PI / 90);
        printf("%f\n", a);
    return (0);
}


