    values c = 0;
    char *keys[MAX] = {
        [COLD_BRICK_COUNT] = "volume%d.cold_brick_count",
        [COLD_TYPE] = "volume%d.cold_type",
        [COLD_DIST_COUNT] = "volume%d.cold_dist_count",
        [COLD_REPLICA_COUNT] = "volume%d.cold_replica_count",
        [COLD_ARBITER_COUNT] = "volume%d.cold_arbiter_count",
        [COLD_DISPERSE_COUNT] = "volume%d.cold_disperse_count",
        [COLD_REDUNDANCY_COUNT] = "volume%d.cold_redundancy_count",
        [HOT_BRICK_COUNT] = "volume%d.hot_brick_count",
        [HOT_TYPE] = "volume%d.hot_type",
        [HOT_REPLICA_COUNT] = "volume%d.hot_replica_count"};
    int value[MAX] = {};

later used as :


            if ((value[HOT_TYPE] != GF_CLUSTER_TYPE_TIER) &&
                (value[HOT_TYPE] > 0) &&
                (hot_dist_count < value[HOT_BRICK_COUNT]))
                tier_vol_type = value[HOT_TYPE] + GF_CLUSTER_TYPE_MAX - 1

                in the older cli-xml-output.c file
                check this out
