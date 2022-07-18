#include <iostream>
#include "BinaryTree.h"

int main()
{
    BinaryTree tree;   
    int insert_q;   
    std::cout << "Enter quantity of elems to insert: ";
    std::cin >> insert_q;   

    double key;
    for (size_t i = 0; i < insert_q; i++)   
    {
        std::cout << "Enter " << i + 1 << " key: ";
        std::cin >> key;      
        tree.insert(key);  
    }

    std::cout << "Result tree(pre-order): ";
    tree.preorder_output();    
    std::cout << "Tree size: " << tree.size() << std::endl; 


    std::cout << "Enter to find key: ";
    std::cin >> key;    
    if (tree.is_present(key))   
    {
        std::cout << "Key (" << key << ") is present." << std::endl;
    }
    else
    {
        std::cout << "Key (" << key << ") is not present." << std::endl;
    }


    int delete_q;   
    std::cout << "Enter quantity of elems to delete: ";
    std::cin >> delete_q;  
    for (size_t i = 0; i < delete_q; i++)   
    {
        std::cout << "Enter " << i + 1 << " key: ";
        std::cin >> key;    
        tree.erase(key);   
    }
    std::cout << "Result tree(pre-order): ";
    tree.preorder_output();    
    std::cout << "Tree size: " << tree.size() << std::endl; 


    tree.clear();   
    std::cout << "Tree after clear(pre-order): ";
    tree.preorder_output();     
    std::cout << "Tree size: " << tree.size() << std::endl;


    return 0;
}
