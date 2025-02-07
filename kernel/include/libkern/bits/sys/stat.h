#pragma once

#include <libkern/types.h>

/* MODES */
#define S_IFSOCK 0xC000 /* [XSI] socket */
#define S_IFLNK 0xA000 /* [XSI] symbolic link */
#define S_IFREG 0x8000 /* [XSI] regular */
#define S_IFBLK 0x6000 /* [XSI] block special */
#define S_IFDIR 0x4000 /* [XSI] directory */
#define S_IFCHR 0x2000 /* [XSI] character special */
#define S_IFIFO 0x1000 /* [XSI] named pipe (fifo) */

#define S_ISUID 0x0800
#define S_ISGID 0x0400
#define S_ISVTX 0x0200

/* Read, write, execute/search by owner */
#define S_IRWXU 0x01c0
#define S_IRUSR 0x0100
#define S_IWUSR 0x0080
#define S_IXUSR 0x0040
/* Read, write, execute/search by group */
#define S_IRWXG 0x0038
#define S_IRGRP 0x0020
#define S_IWGRP 0x0010
#define S_IXGRP 0x0008
/* Read, write, execute/search by others */
#define S_IRWXO 0x0007
#define S_IROTH 0x0004
#define S_IWOTH 0x0002
#define S_IXOTH 0x0001

struct fstat {
    uint32_t dev; /* ID of device containing file */
    uint32_t ino; /* inode number */
    mode_t mode; /* protection */
    uint32_t nlink; /* number of hard links */
    uint32_t uid; /* user ID of owner */
    uint32_t gid; /* group ID of owner */
    uint32_t rdev; /* device ID (if special file) */
    uint32_t size; /* total size, in bytes */
    uint32_t atime; /* time of last access */
    uint32_t mtime; /* time of last modification */
    uint32_t ctime; /* time of last status change */
};
typedef struct fstat fstat_t;