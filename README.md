# Recursive-Lists
## STUDENT INFORMATION
- Student Name: Caleb Clements
- Student ID: 008878539
- Repository Link: https://github.com/calebwclem/Fun-With-Rec-Lists

## Collaboration & Sources
I did not work with anyone specifically on this project. I did use the following sources:
- CLion's AI Assistant to fix substitute errors.
  - Also used to discuss algorithms and my ideas throughout the project.


- Once again used AI to write my implementation details portion of the README below (thought I have it use my comments).

## Implementation Details
- Core representation
    - Lists are recursive structures composed via cons cells. The primitives available are null, is_null, is_atom, eq, car, cdr, cons, write_list, read_list.
    - All higher-level behavior is built purely with recursion and these primitives; no loops or external containers.

- Helper utilities
    - append(p, q): Recursively constructs a new list with p’s elements followed by q. Base case is when p is empty.

- Functions implemented

    - is_lat(p)
        - Returns true if p contains only atoms at the top level.
        - Recurses down cdr(p), failing if car(p) is not an atom.
        - Complexity: O(n).

    - member(a, q)
        - True iff atom a equals some element in q using eq.
        - Recursively compares a with car(q), then searches cdr(q).
        - Complexity: O(n).

    - last(p)
        - Returns the last element of a non-empty list p without using reverse.
        - Recurses until cdr(p) is empty, then returns car(p).
        - Complexity: O(n).

    - list_pair(p, q)
        - Zips two equal-length flat lists into a list of 2-element lists.
        - Builds each pair with cons and append at the pair level: ( (car(p) car(q)) ... ).
        - Stops when either list is empty.
        - Complexity: O(n).

    - firsts(p)
        - Given a list of non-empty sublists, returns a list of each sublist’s first element.
        - Uses car(car(p)) at each step, recurses on cdr(p).
        - Complexity: O(n).

    - flat(p)
        - Flattens one level of parentheses structure at the top list (removes nested parentheses, preserving order).
        - If car(p) is a list, append(car(p), flat(cdr(p))); else cons(car(p), flat(cdr(p))).
        - Complexity: O(n + total elements inside nested lists visited).

    - two_the_same(p, q)
        - True if p and q share at least one atom.
        - Uses member on each element of p; early return on first match.
        - Complexity: O(|p|·|q|) worst-case.

    - equal(p, q)
        - Structural and atomic equality: both structure and atoms must match.
        - If both atoms, uses eq. If one atom and the other not, false. Otherwise compare car and cdr recursively.
        - Complexity: O(n) over the size of the structure.

    - total_reverse(p)
        - Full mirror: reverses the top-level list and all sublists.
        - Uses append(total_reverse(cdr(p)), cons(total_reverse(car(p)), null())).
        - Complexity: O(n^2) in general due to append.

    - shape(p)
        - Returns only the parentheses structure of p, removing atoms.
        - For atom heads, skip them; for sublists, cons(shape(car(p)), shape(cdr(p))).
        - Complexity: O(n).

    - intersection(p, q)
        - Returns atoms that appear in both lists (treated as sets).
        - For each car(p), if member in q, cons it; recurse on cdr(p).
        - Assumes inputs are sets (distinct atoms) to avoid duplicates in output.
        - Complexity: O(|p|·|q|).

    - list_union(p, q)
        - Returns union of two sets (lists with distinct atoms).
        - Skips any element in p that’s already a member of q; otherwise cons it and continue.
        - Complexity: O(|p|·|q|).

    - substitute(old, newAtom, p)
        - Returns a copy of p where every atom equal to old is replaced with newAtom.
        - Base: empty list -> empty. If p is an atom: return newAtom if eq(p, old) else p. If p is a list: cons(substitute on car, substitute on cdr).
        - Works recursively through nested lists, preserving structure.
        - Complexity: O(n).

    - remove(p, a)
        - Removes all occurrences of atom a from p, preserving parentheses.
        - If p is a list:
            - If car(p) is atom equal to a, skip it and recurse on cdr(p).
            - If car(p) is atom and not equal, cons it with recursion on cdr(p).
            - If car(p) is a sublist, recurse into it and into cdr(p), consing results to preserve structure.
        - Complexity: O(n).

    - subset(p, q)
        - True if every atom in p appears in q (treating inputs as sets of atoms at the current list level).
        - Iterates atoms at the top level of p, ignores sublists per spec comment, and uses member against q.
        - Complexity: O(|p|·|q|).

    - permute(p) [extra credit]
        - Produces all permutations of a list of atoms.
        - Base: (()) for empty list. Recursive: insert head into every position of each permutation of the tail, then append all.
        - Uses only cons, append, recursion.
        - Complexity: O(n·n!) total output size.

- Design choices and assumptions
    - All algorithms are purely recursive and side-effect free.
    - equality uses structural matching and atom eq; union/intersection/subset treat inputs as sets where specified.
    - substitute and remove traverse into nested lists and preserve all parentheses.

- Testing approach
    - Interactive: read_list to input cases, write_list to display outputs.
    - Deterministic checks use equal to compare results with expected lists for PASS/FAIL reporting.
    - Covered scenarios: empty lists, singletons, multiple matches, nested structures, no-op substitutions/removals, and mixed atom/list inputs.


## Testing & Status
Everything works as intended to my knowledge and understanding EXCEPT substitute.
I have tried testing it and struggled to do so properly, and I simply am out of time.
I am however, confident in all my other functions and they have passed the tests
within main.cpp.