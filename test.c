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