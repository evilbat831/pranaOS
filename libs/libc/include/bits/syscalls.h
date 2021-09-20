/*
 * Copyright (c) 2021, Krisna Pranav
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

// FIXME: need to add more sysid's

enum __sysid {
    SYS_RESTART = 0,
    SYS_EXIT,
    SYS_FORK,
    SYS_READ,
    SYS_WRITE,
    SYS_OPEN,
    SYS_CLOSE,
    SYS_WAITPID,
    SYS_CREAT,
    SYS_LINK,
    SYS_UNLINK,
    SYS_EXEC,
    SYS_CHDIR,
    SYS_SIGACTION,
    SYS_SIGRETURN,
    SYS_RAISE,
    SYS_GET_TIME_OF_DAY,
    SYS_LSEEK,
    SYS_GETPID,
    SYS_SETUID,
    SYS_GETUID,
    SYS_KILL,
    SYS_MKDIR,
    SYS_RMDIR,
    SYS_MMAP,
    SYS_MUNMAP,
    SYS_SOCKET,
    SYS_BIND,
    SYS_CONNECT,
    SYS_GETDENTS,
    SYS_IOCTL,
    SYS_SETPGID,
    SYS_GETPGID,
    SYS_PTHREADCREATE,
    SYS_SLEEP,
    SYS_SELECT,
    SYS_FSTAT,
    SYS_SCHEDYIELD,
    SYS_UNAME,
    SYS_CLOCK_SETTIME,
    SYS_CLOCK_GETTIME,
    SYS_CLOCK_GETRES,
    SYS_NICE,
    SYS_SHBUF_CREATE,
    SYS_SHBUF_GET,
    SYS_SHBUF_FREE,
};

typedef enum __sysid sysid_t;