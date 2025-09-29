#include "reclists.hpp"
#include "solutions.hpp"

// As you implement functions in this file, you should add the
// function-prototype to the solutions.hpp.
//


//Takes a list of atoms and returns a list whose elements
//are all distinct permutations of p.
//For example: permute((a b c)) = ((a b c) (a c b) (b a c) (b c a) (c a b) (c b a))
list permute(list p) {

    return null();
}


//Takes two lists (neither of which is an atom) and returns true if
//every atom in p also appears in q (treating them as sets).
//For example:
//subset(((a) b), ((a) b c)) = true
//subset(((a b) c), (c (a b) d)) = true
//subset(((a b) c), (c d)) = false
//subset((a b), (a b c d)) = true
//subset((a d), (a b c)) = false
bool subset(list p, list q) {

    if (is_null(p))
        return true;

    // p is a non-empty list here;
    if (is_atom(car(p))) {
        if (member(car(p), q))
            return subset(cdr(p), q);
        else //Not a subset
            return false;
    }

    // If the head of p is a sublist, ignore it for atoms-only subset and continue
    return subset(cdr(p), q);
}


//Takes a list of atoms and an atom a, and returns a list that does not contain a.
//All occurrences of a are removed.
//For example: remove((a b a c b), a) = (b c b)
list remove(list p, list a) {

    if (is_null(p))
        return null();

    if (is_atom(p)) {
        if (eq(p, car(a))) {
            return null();
        } else {
            return p;
        }
    }

    // p is a non-empty list
    if (is_atom(car(p))) {
        if (eq(car(p), car(a))) {
            // Drop this element; continue with the tail
            return remove(cdr(p), a);
        }
        else {
            // Keep this atom; process the tail
            return cons(car(p), remove(cdr(p), a));
        }
    }
    else{
        // Recurse into sublist head; always preserve parentheses
        return cons(remove(car(p), a), remove(cdr(p), a));
    }
}


//Takes a list of atoms (atoms may repeat) and returns a copy of p with every
//occurrence of atom old replaced by atom new.
//For example: substitute(a, x, (a b a c)) = (x b x c)
list substitute(list old, list newList, list p){
    // Handle empty list
    if (is_null(p))
        return null();

    // If p is an atom, replace it if it matches `old`
    if (is_atom(p)) {
        if (eq(p, old))
            return newList;
        return p;
    }

    // Otherwise, recurse into both head and tail to preserve structure
    return cons(substitute(old, newList, car(p)),
                substitute(old, newList, cdr(p)));
}


//Takes two lists of distinct atoms (representing sets) and
//returns a list of the union of p and q, without repetition.
list list_union(list p, list q) {
    if (is_null(p) && is_null(q))
        return null();
    if (is_null(p))
        return q;
    if (is_null(q))
        return p;

    if (member(car(p), q))
        return list_union(cdr(p), q);

    return cons(car(p), list_union(cdr(p), q));
}

//Takes two lists of distinct atoms (representing sets) and returns a list of
//atoms that appear in both p and q. The empty list represents the empty set.
list intersection(list p, list q) {

    if (is_null(p) || is_null(q))
        return null();
    if (member(car(p), q))
        return cons(car(p), intersection(cdr(p), q));

    return intersection(cdr(p), q);
}

//Takes a recursive list (not an atom) and returns a recursive list
//that consists only of the parentheses structure of the original.
list shape(list p) {

    if (is_null(p))
        return null();
    if (is_atom(car(p)))
        return shape(cdr(p));

    return cons(shape(car(p)), shape(cdr(p)));
}


//Takes a recursive list and returns its mirror image.
//This extends reverse by reversing both the top-level list and all sublists recursively.
list total_reverse(list p) {
    if (is_null(p))
        return null();
    if (is_atom(p))
        return p;

    return append(total_reverse(cdr(p)), cons(total_reverse(car(p)), null()));
}

//Takes two recursive lists and determines if they are identical: parentheses must match in
//structure and all atoms must be identical in name and position. This is an extension of eq.
bool equal(list p, list q) {

    if (is_null(p) && is_null(q))
        return true;
    if (is_null(p) || is_null(q))
        return false;
    if (is_atom(p) && is_atom(q))
        return eq(p, q);
    if (is_atom(p) || is_atom(q))
        return false;
    return equal(car(p), car(q)) && equal(cdr(p), cdr(q));
}


//Takes two lists (not atoms) and returns true if p and q contain at least one atom in common
bool two_the_same(list p, list q) {

    //Removed the following base condition because TECHNICALLY
    // even though the null list is the same as the null list
    // it does not have atoms in common!
    //if (is_null(p) && is_null(q))
        //return true;

    if (is_null(p))
        return false;

    if (member(p, q))
        return true;

    return two_the_same(cdr(p), q);
}


//Takes a list (not an atom) and returns a list in which all nested parentheses
// are removed (except the outer set of course).
// Ex: flat((a (b) (c d))) = ( a b c d )
list flat(list p) {
    if (is_null(p))
        return null();

    if (is_atom(p))
        return p;

    if (!is_atom(car(p)))
        return append(car(p), flat(cdr(p)));

    return cons(flat(car(p)), flat(cdr(p)));
}

//Takes as input a list whose elements are lists of atoms and returns a list of
// the first element from each sublist
// Ex: firsts(((a b c) (d e f) (c d b a))) = (a d c)
list firsts(list p) {
    //My solution that works as deeply nested as we want
    /*
    if (is_null(p))
        return null();
    if (is_atom(car(p)))
        return car(p);

    return cons(firsts(car(p)), firsts(cdr(p)));*/

    //Actual solution I was told to use
    if (is_null(p))
        return null();

    return cons(car(car(p)), firsts(cdr(p)));
}


//Takes two lists of atoms of the same length and returns a list of pairs,
//where each pair contains corresponding atoms from p and q.
//list_pair((a b c), (d e f)) = ((a d) (b e) (c f))
list list_pair(list p,list q) {


    if (is_null(p) || is_null(q))
        return null();

    return cons(append(cons(car(p), null()),
        cons(car(q),null())), list_pair(cdr(p), cdr(q)));
}

// Takes a non-empty list (not an atom) and returns its last element.
// THIS MUST BE DONE WITHOUT USING REVERSE
list last(list p) {

    if (is_null(cdr(p)))
        return car(p);
    return last(cdr(p));
}

// Takes an atom p and a list q (possibly empty but not an atom)
// Returns true if p appears anywhere in q. Undefined if behavior does not meet the
// above conditions!
bool member(list p, list q) {

    if (is_null(q))
        return false;
    if (eq(p, car(q)))
        return true;
    return member(p, cdr(q));
}


// Takes a list (possibly empty) but not an atom and returns true if the list
// consists entirely of atoms.
bool is_lat(list p) {

    if (is_null(p))
        return true;
    if (!is_atom(car(p)))
        return false;

    return is_lat(cdr(p));
}


int numNodesAtTheTopLevel(list p) {
    // p is one of
    //    a null list
    //    an atom
    //    a recursive list

    // The function returns the number of nodes at the top-level
    // of p.

    if( is_null(p) )
        return 0;
    if( is_atom(p) )
        return 1;
    return 1 + numNodesAtTheTopLevel(cdr(p));
}

//Append function given/done in lab
list append(list p, list q) {

    if (is_null(p))
        return q;

    return cons(car(p), append(cdr(p), q));
}

//Reverses the list at the top level ONLY
list reverseTopLevel(list p) {

    if (is_null(p))
        return p;

    return append(cons(car(p), null()), reverseTopLevel(cdr(p)));
}

