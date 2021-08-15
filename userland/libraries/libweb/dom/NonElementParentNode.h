/*
 * Copyright (c) 2021, Krisna Pranav
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

// includes
#include <base/Forward.h>
#include <libweb/Forward.h>
#include <libweb/html/AttributeNames.h>
#include <LibWeb/TreeNode.h>

namespace Web::DOM {

template<typename NodeType>
class NonElementParentNode {
public:
    RefPtr<Element> get_element_by_id(const FlyString& id) const
    {
        RefPtr<Element> found_element;
        static_cast<const NodeType*>(this)->template for_each_in_inclusive_subtree_of_type<Element>([&](auto& element) {
            if (element.attribute(HTML::AttributeNames::id) == id) {
                found_element = &element;
                return IterationDecision::Break;
            }
            return IterationDecision::Continue;
        });
        return found_element;
    }
    RefPtr<Element> get_element_by_id(const FlyString& id)
    {
        return const_cast<const NonElementParentNode*>(this)->get_element_by_id(id);
    }

protected:
    NonElementParentNode() { }
};

}
