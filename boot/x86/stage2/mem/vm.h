#pragma once

#include "../types.h"
#include "pde.h"
#include "pte.h"

#define VMM_PTE_COUNT (1024)
#define VMM_PDE_COUNT (1024)
#define VMM_PAGE_SIZE (4096)

enum VMM_ERR_CODES {
    VMM_ERR_PDIR,
    VMM_ERR_NO_SPACE,
    VMM_ERR_BAD_ADDR,
};

typedef struct {
    page_desc_t entities[VMM_PTE_COUNT];
} ptable_t;

typedef struct pdirectory {
    table_desc_t entities[VMM_PDE_COUNT];
} pdirectory_t;

int vm_setup();