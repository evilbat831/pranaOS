/*
 * Copyright (c) 2021, Krisna Pranav
 *
 * SPDX-License-Identifier: BSD-2-Clause
*/

// includes
#include <base/NonnullRefPtrVector.h>
#include <kernel/memory/AnonymousVMObject.h>
#include <kernel/memory/InodeVMObject.h>
#include <kernel/memory/MemoryManager.h>
#include <kernel/Process.h>

namespace Kernel {

KResultOr<FlatPtr> Process::sys$purge(int mode)
{
    VERIFY_PROCESS_BIG_LOCK_ACQUIRED(this)
    REQUIRE_NO_PROMISES;
    if (!is_superuser())
        return EPERM;
    size_t purged_page_count = 0;
    if (mode & PURGE_ALL_VOLATILE) {
        NonnullRefPtrVector<Memory::AnonymousVMObject> vmobjects;
        {
            KResult result(KSuccess);
            MM.for_each_vmobject([&](auto& vmobject) {
                if (vmobject.is_anonymous()) {

                    if (!vmobjects.try_append(vmobject) && vmobjects.is_empty()) {
                        result = ENOMEM;
                        return IterationDecision::Break;
                    }
                }
                return IterationDecision::Continue;
            });

            if (result.is_error())
                return result.error();
        }
        for (auto& vmobject : vmobjects) {
            purged_page_count += vmobject.purge();
        }
    }
    if (mode & PURGE_ALL_CLEAN_INODE) {
        NonnullRefPtrVector<Memory::InodeVMObject> vmobjects;
        {
            KResult result(KSuccess);
            MM.for_each_vmobject([&](auto& vmobject) {
                if (vmobject.is_inode()) {

                    if (!vmobjects.try_append(static_cast<Memory::InodeVMObject&>(vmobject)) && vmobjects.is_empty()) {
                        result = ENOMEM;
                        return IterationDecision::Break;
                    }
                }
                return IterationDecision::Continue;
            });

            if (result.is_error())
                return result.error();
        }
        for (auto& vmobject : vmobjects) {
            purged_page_count += vmobject.release_all_clean_pages();
        }
    }
    return purged_page_count;
}

}
