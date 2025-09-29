#include<iostream>
#include"reclists.hpp"
#include"solutions.hpp"

int main()
{

    std::cout << "Enter a list p: ";
    list p = read_list();
    std::cout << "Echoing the list p that you entered below." << std::endl;
    write_list(p);

    std::cout << "Enter a list q: ";
    list q = read_list();
    std::cout << "Echoing the list q that you entered below." << std::endl;
    write_list(q);

    //Testing nodes at top level
    std::cout << "The number of nodes at the top level of the input list is: "
        << numNodesAtTheTopLevel(p) << std::endl;

    //Testing is_lat
    std::cout << "The list contains only atoms: ";
    if (is_lat(p))
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;


    //Testing member
    std::cout << "Does the list q contain the first element in p: ";
    if (member(p,q))
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    //Testing list_pair
    std::cout << "The new list of pairs from p and q is ";
    write_list(list_pair(p,q));

    //Testing last
    std::cout << "The last element in the list was: ";
    write_list(last(p));

    /*Testing firsts
    std::cout << "The first elements of the sublists in p are: ";
    write_list(firsts(p));*/

    //Testing total_reverse
    std::cout << "The list p with all elements reversed is: ";
    write_list(total_reverse(p));

    //Testing flat
    std::cout << "The list p with all nested parentheses removed is: ";
    write_list(flat(p));

    //Testing equal
    std::cout << "The lists p and q are equal: ";
    if (equal(p,q))
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    //Testing two_the_same
    std::cout << "The lists p and q contain at least one atom in common: ";
    if (two_the_same(p,q))
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    //Testing intersection
    std::cout << "The intersection of p and q is: ";
    write_list(intersection(p,q));

    //Testing union
    std::cout << "The union of p and q is: ";
    write_list(list_union(p,q));

    return 0;//Return 0 to indicate success.
}//End main.
