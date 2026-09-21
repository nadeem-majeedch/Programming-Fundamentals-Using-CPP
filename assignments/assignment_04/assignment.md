# Assignment 4 · Interval Math Library — Advanced Functions
**Module 8 (L15–L16) · 40 marks · due end of Week 9**
Outcomes: CLO-5 (PF-8.x)

Build a tiny library for closed intervals `[lo, hi]` on integers, exercising
overloading, default arguments, recursion, and passing modes.

## Required API (signatures fixed)

```cpp
bool  isValid(int lo, int hi);                     // lo <= hi
bool  contains(int lo, int hi, int v);             // lo <= v <= hi
bool  overlap(int lo1, int hi1, int lo2, int hi2); // intervals share >= 1 point
int   clamp(int v, int lo = 0, int hi = 100);      // force v into [lo,hi] (default [0,100])
int   sumRange(int lo, int hi);                    // recursive sum lo..hi inclusive (isValid precondition)
void  swapInts(int& a, int& b);                    // exchange values
int   length2d(int w, int h, int depth = 1);       // overloading demo: volume of box
int   length2d(int w, int h);                      // 2-D overload: w*h
```

`main` must demonstrate *every* function with at least one call each, printing
labeled results, including one default-argument call and one explicit-argument
call of `clamp`.

## Sample output shape (labels must match)

```
isValid(3,1)     -> no
contains(0,10,5) -> yes
overlap(0,5,5,9) -> yes
clamp(150)       -> 100
clamp(150,0,50)  -> 50
sumRange(1,5)    -> 15
swap 2,9         -> 9,2
length2d(3,4)    -> 12
length2d(3,4,2)  -> 24
```

## Constraints

- `sumRange` must be recursive with a stated base case (no loops inside).
- No global variables. All state travels through parameters/returns.
- Passing modes: value for inputs, `int&` only where mutation is the contract (swap).

## Deliverables

`intervals.cpp` (contract, zero warnings) · `test_table.md` — touching intervals
(`overlap` yes), disjoint (no), degenerate `[5,5]` contains/overlap, `clamp` on
all three branches, `sumRange` with lo == hi, swap of same variable aliased via
two names (document the result) · `postmortem.md` (10 marks).

## Notes

- Touching intervals share exactly one point — they overlap.
- `sumRange` with `lo > hi` violates its precondition; assert-free handling is to
  document the precondition, not to "fix" inputs silently.
