//
// Created by bravo8234 on 18/05/2022.
//
#include "doctest.h"
#include "sources/OrgChart.hpp"
#include <iostream>
#include <sstream>

TEST_CASE ("good Test") {
    ariel::OrgChart organization;
    organization.add_root("CEO")
            .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
            .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
            .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
            .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
            .add_sub("COO", "VP_BI");      // Now the VP_BI is subordinate to the COO
    std::vector<std::string> names = {"CEO", "CTO", "CFO", "COO", "VP_SW", "VP_BI"};
    for (size_t i = 0; i < names.size(); i++) {
                CHECK_EQ(names.at(i), organization.nodes.at(i)->data);
    }
    for (auto &node: organization.nodes) {
        if (node->data == "CEO") {
                    CHECK_EQ(node->parent, nullptr);
                    CHECK_EQ(node->children.size(), 3);
        } else if (node->data.size() == 3) {
                    CHECK_EQ(node->parent->data, "CEO");
            if (node->data == "CFO") {
                        CHECK_EQ(node->children.size(), 0);

            } else {
                        CHECK_EQ(node->children.size(), 1);

            }
        } else {
            if (node->data == "VP_SW") {
                        CHECK_EQ(node->parent->data, "CTO");
            } else {
                        CHECK_EQ(node->parent->data, "COO");
            }
                    CHECK_EQ(node->children.size(), 0);
        }
    }
    std::stringstream toTest;
    for (const auto& element : organization)
    { // this should work like level order
        toTest << element << " " ;
    } // prints: CEO CTO CFO COO VP_SW VP_BI
    CHECK_EQ(toTest.str(),"CEO CTO CFO COO VP_SW VP_BI ");
    toTest.flush();

    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        toTest << (*it) << " " ;
    } // prints: CEO CTO CFO COO VP_SW VP_BI
    CHECK_EQ(toTest.str(),"CEO CTO CFO COO VP_SW VP_BI ");
    toTest.flush();

    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
        toTest << (*it) << " " ;
    } // prints: VP_SW VP_BI CTO CFO COO CEO
    CHECK_EQ(toTest.str(),"VP_SW VP_BI CTO CFO COO CEO ");
}