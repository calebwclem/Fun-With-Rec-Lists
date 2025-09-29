#ifndef __MY_SOLUTION_HPP__
#define __MY_SOLUTION_HPP__

#include<iostream>
#include"reclists.hpp"

//Provided
int numNodesAtTheTopLevel(list p);
list append(list p, list q);
list reverseTopLevel(list p);


//Deliverables for project 2
bool is_lat(list p);//Done
bool member(list p,list q);//Done
list last(list p);//Done
list list_pair(list p,list q);//TODO: Check with someone about this
list firsts(list p);//Done
list flat(list p);//Done
bool two_the_same(list p, list q);//Done I think? Could use more testing
bool equal(list p, list q);//Done
list total_reverse(list p);
list shape(list p);
list intersection(list p, list q);//Done
list list_union(list p, list q);
list substitute(list old, list newList, list p);
list remove(list p, list a);
bool subset(list p, list q);
list permute(list p);//EC Problem

#endif
