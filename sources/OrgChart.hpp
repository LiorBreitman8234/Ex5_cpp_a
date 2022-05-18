//
// Created by bravo8234 on 17/05/2022.
//

#ifndef EX5_CPP_A_ORGCHART_HPP
#define EX5_CPP_A_ORGCHART_HPP7
#include "Node.hpp"
#include <string>
#include <iostream>
#include <utility>
#include "iterators.hpp"
namespace ariel{
    class OrgChart{
        Node<std::string>* root;
    public:
        using Iterator = std::vector<std::string>::iterator;
        std::vector<std::string> order;
        std::vector<Node<std::string>*> nodes;
        OrgChart(){this->root = nullptr;};
        OrgChart& add_root(std::string name);
        OrgChart& add_sub(const std::string& father, std::string child);
        Iterator begin_level_order();
        //#Todo create preorder iterator
        Iterator begin_preorder();
        Iterator begin_reverse_order();
        Iterator end_level_order();
        //#Todo create reverse iterator
        Iterator end_preorder();
        Iterator reverse_order();

        Iterator begin();
        Iterator end();
    };
}
#endif //EX5_CPP_A_ORGCHART_HPP
