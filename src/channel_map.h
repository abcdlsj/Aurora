//
// Created by abcdlsj on 2020/9/13.
//

#ifndef AURORA_CHANNEL_MAP_H
#define AURORA_CHANNEL_MAP_H

#include "channel.h"

/**
 * channel映射表, key为对应的socket描述字
 */
struct channel_map {
    void **entries;

    /* The number of entries available in entries */
    int nentries;
};

int map_make_space(struct channel_map *map, int slot, int msize);

void map_init(struct channel_map *map);

void map_clear(struct channel_map *map);

#endif //AURORA_CHANNEL_MAP_H
