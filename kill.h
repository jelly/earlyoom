/* SPDX-License-Identifier: MIT */

#include <stdbool.h>

typedef struct {
    /* directory file handle to /proc */
    DIR* procdir;
    /* if the available memory AND swap goes below these percentages,
     * we start killing processes */
    int mem_min_percent;
    int swap_min_percent;
    /* use the kernel oom killer? */
    bool kernel_oom_killer;
    /* ignore /proc/PID/oom_score_adj? */
    bool ignore_oom_score_adj;
    /* notifcation command to launch when killing something. NULL = no-op. */
    char* notif_command;
    /* prefer/avoid killing these processes. NULL = no-op. */
    regex_t* prefer_regex;
    regex_t* avoid_regex;
    /* memory report interval, in milliseconds */
    int report_interval;
} poll_loop_args_t;

void handle_oom(poll_loop_args_t args, int sig);
