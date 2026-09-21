# L28 · Structures: `struct` Definition, Members, Nesting, Arrays/Files of Records

**Module 14 — Dynamic Memory and Structures · Week 14 · Lecture 28 of 32 · 120 minutes**
**Outcomes:** CLO-7 · PF-14.3, PF-14.4 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md) · **Project milestone week**

## Learning objectives

1. Define `struct` types with appropriate members, initialize them (brace
   form), and access/modify members with `.` (including through references
   and pointers with `->`) (PF-14.3).
2. Implement functions that take and return structs (by value, `const T&`,
   and `T&` for write-back), justifying each passing mode per the L26
   checklist (PF-14.3).
3. Build a records-in-collection application — arrays/`std::vector` of
   structs with aggregate computations (average, max-by-field, search by
   field) — the architecture of the capstone project (PF-14.4).

## Prerequisites

L26 (passing-mode checklist); M9–M12 (collections + algorithms — now applied
to records); L25 (`->` preview: `(*p).member` vs `p->member`).

## Concept sequence

1. Parallel arrays don't scale: the records motivation
2. `struct` definition, member declaration, brace initialization
3. Member access `.`, through references, and `->` through pointers
4. Structs with functions: passing modes revisited for real data
5. Nested structs and struct assignments (whole-object copy)
6. Collections of records: the capstone architecture

## Teaching topics (detailed)

- **Motivation:** three parallel arrays (`names/ids/gpas`) break the moment
  one row is inserted — invariant maintenance fails; `struct Student
  { std::string name; int id; double gpa; };` makes *one row one value*.
- **Definition/init/access:** type definition ends with `;` (the classic
  missing-semicolon error); brace init `Student s{"Ayesha", 101, 3.8};` —
  member order matters; `s.gpa = 3.9;`; nested: `Student::address.city`;
  whole-struct assignment copies all members (`Student t = s;`).
- **Structs + functions:** `void print(const Student& s)` (read-only,
  no copy); `void promote(Student& s)` (write-back);
  `Student make_student(...)` (factory return); arrow access when holding a
  pointer: `Student* p{&s}; p->gpa` ≡ `(*p).gpa` — both forms shown, `->`
  preferred.
- **Records in collections:** `Student roster[120];` / 
  `std::vector<Student> roster;` — row-wise traversal (M10 skill),
  aggregate algorithms (average GPA = L18 accumulate; highest GPA *with
  who* = L18 min/max-with-index; find-by-id = L23 linear search — three
  prior algorithms re-instantiated on records in one program).
- **Capstone architecture preview:** the five project topics
  ([projects/README.md](../../projects/README.md)) are all
  *vector-of-struct + file load/save (M15) + menu (M5)* — this lecture's
  pattern is the capstone skeleton; milestone check (week 14) references it.
- **Style:** `PascalCase` type names; no member functions yet (that's
  Module 16 — structs here are pure data; the OOP bridge is explicit).

## C++ examples required

| File | Role |
|---|---|
| `struct_records.cpp` ✅ | Student struct: init, print/promote/factory functions, nested address, vector-of-Student with three aggregate algorithms |
| (live) `roster_stats.cpp` | capstone-skeleton: load-able roster + menu-less analytics build (M15 adds the file part) |

## Common student misconceptions

- "`struct` creates a variable." (It defines a *type*; variables come after.)
- "Structs are copied member-by-member expensively." (Yes member-wise — but
  that's exactly why big structs pass by `const&` per L26.)
- "`p.gpa` works on a struct pointer." (`.` requires an object;
  `p->gpa` or `(*p).gpa`.)
- "Vectors of structs need special syntax." (Element type is a type —
  everything from M9–M12 applies unchanged.)
- "Structs with data are OOP." (Data-only structs are records; *behavior +
  access control* is Module 16's line of demarcation.)

## Conceptual explanation (beginner-first)

Arrays taught you to group many values of *one* type. Real records mix
types: a student has a name (string), an ID (int), a GPA (double).
Parallel arrays (`string names[50]; int ids[50]; double gpas[50];`)
"work" — until one sort reorders one array and not the others, and the
records shred. A **`struct`** bundles the fields of one record into a
single user-defined **type**: `struct Student { ... };` — and from
that line on, `Student` behaves like a first-class type you can
declare, copy, pass, and collect into vectors.

Three mechanical facts organize the lecture. First, define the type
*before* use (types go at the top of the file). Second, access fields
with the dot operator: `s.gpa`. Third, a struct variable passed by
value is copied member-by-member — exactly why big records travel by
`const&` (L26's rule, now with a reason students can *see*). A struct
pointer uses `->` ("arrow") instead of `.`: `p->gpa` means
`(*p).gpa`.

The payoff is data design: functions like `printStudent(const
Student&)` and `findByGpa(const std::vector<Student>&, double)` make
programs read like the domain. And the horizon: a struct is the
class-object *without* behavior — Module 16 adds functions inside and
access control on top.

## Terminology and definitions

| Term | Definition |
|---|---|
| `struct` | A user-defined type bundling named members (fields) |
| Member / field | One named value inside the record |
| Member access | Dot operator: `student.gpa` |
| Struct pointer + arrow | `p->gpa` — shorthand for `(*p).gpa` |
| Member-wise copy | Assignment copies every field (in declaration order) |
| Nested struct | A struct with a struct-typed member (`Student` has `Address`) |
| Record design | Choosing fields, types, and the functions a record needs |
| `std::vector<Student>` | A collection of records — every M9–M12 pattern applies |
| Parallel arrays | Same data split across equal-length arrays — fragile anti-pattern |
| Data-only type | Struct without member functions; OOP (M16) adds behavior + access control |

## Syntax and C++ examples

```cpp
struct Student            // the TYPE — define before use, note the semicolon
{
    std::string name;
    int    id;
    double gpa;
};                        // <- semicolon is mandatory and famously forgotten

Student s{"Ada", 1001, 3.9};        // brace-init in member order
Student t{};                        // zero/empty by member

std::cout << s.name << ' ' << s.gpa << '\n';
s.gpa = 4.0;                        // fields are ordinary variables

// records + functions (big records travel by const&)
void printStudent(const Student& s)
{
    std::cout << s.id << "  " << s.name << "  " << s.gpa << '\n';
}

Student makeStudent(const std::string& name, int id, double gpa)
{
    return Student{name, id, gpa};   // return by value: safe copy-out
}

// pointer access: arrow
Student* p{&s};
std::cout << p->gpa << '\n';        // same as (*p).gpa
p->gpa = 4.0;

// a collection of records
std::vector<Student> roster{
    {"Ada", 1001, 3.9}, {"Grace", 1002, 3.8}, {"Alan", 1003, 4.0}
};
```

## Line-by-line code explanation

`examples/struct_records.cpp`:

1. The `struct` block ends in `;` — the demo file includes the compile
   error its omission produces ("expected ';' after struct").
2. Brace initialization maps values to members **in declaration
   order** — reorder the braces and the name becomes a GPA; the
   printed roster exposes it.
3. `printStudent` takes `const Student&`: no copy (L26), no mutation
   (the promise). Passing by value would copy every string field.
4. `promote(Student& s)` — an in-place mutator via reference: the
   record version of L26's bump.
5. The vector section runs three aggregate algorithms: average GPA,
   highest-GPA student (value-and-index via L18's pattern), count of
   students on the dean's list — every Module 9 pattern reused
   unchanged on records.
6. The nested `Address` struct shows composition: a record whose
   member is itself a record; access chains: `s.home.city`.

## Output prediction questions (with answers)

1. `Student a{"Ada", 1, 3.9}; Student b{a}; b.gpa = 2.0;` — what is
   `a.gpa`? — 3.9: member-wise copy, independent records.
2. `p->name` where `p = &a` — ? — `"Ada"`; `(*p).name` is identical.
3. After `promote(a)` (bumps GPA by 0.1) — does the caller's `a`
   change? — Yes: reference parameter, in-place update.
4. `roster.size()` for the three-student roster — ? — 3; vector
   operations are record-agnostic.
5. Forgetting the struct's closing `;` — ? — Compile error on the
   *next* line — the infamous misleading-message bug.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Missing `;` after the struct block | Error reported at the following line | Memorize the semicolon |
| `p.gpa` on a pointer | Compile error: `.` needs an object | `p->gpa` or `(*p).gpa` |
| Parallel-array sorts | Records shred (name list misaligns) | One `vector<Student>` instead |
| Big struct by value | Silent copy cost everywhere | `const Student&` for read-only |
| Brace-init order mismatch | Fields silently crossed | Follow declaration order; verify by print |
| Struct used before definition | "Unknown type" error | Types at the top of the file |

## Classroom demonstrations

1. **The shred:** sort a parallel-arrays gradebook by GPA — names no
   longer match IDs; then the `vector<Student>` sort that keeps records
   whole. The struct earns itself.
2. **Copy vs alias:** assign `b = a` then mutate `b` — the member-wise
   copy is visible; then `Student& alias = a` — mutation shows through.
3. **Arrow vs dot:** compile `p.gpa` with a pointer; the error message
   teaches; fix with `->`.

## Guided student activities
**Record-design workshop (20 min):** teams design structs for three domains
(bank account, library book, game character) — members, types, which
functions (print, search-by, aggregate) the record needs; designs exchange
for the "one row one value" test (would parallel arrays be worse here?).

## Practice problems
- Define `struct Book { std::string title; std::string author; double
  price; int stock; };` + functions: `print`, `restock` (write-back),
  `total_value` (vector aggregate).
- Implement find-by-id over a vector of Student (return index or −1) and
  highest-GPA-with-name.
- Nested struct trace: address change through a reference parameter.
- (🟡 stretch) Explain why `Student make(std::string name)` returning by
  value is safe even though locals "die at `}`" (copy-out semantics —
  precise return-value reasoning, M13 contrast).

## Summary

A `struct` bundles fields into a new type; dot for objects, arrow for
pointers, member-wise copies, `const&` for big records, and
`vector<Student>` where every array pattern applies unchanged.
Records turn parallel arrays into coherent data — and set up Module
16, where structs gain behavior. Next (L29): files — making data
outlive the program.

## Exit ticket / formative assessment

1. Write the definition line for a struct type `Point` with two doubles.
2. `Student* p = &s;` — two ways to read `gpa` through `p`.
3. Which passing mode for a `print` function over `Student`? Why?

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (RAII quiz) + parallel-arrays failure | 10 |
| struct definition/init/access + nesting | 35 |
| Break | 10 |
| Structs + functions + collections (capstone skeleton) | 40 |
| Record-design workshop | 20 |
| Exit ticket + Module 15 preview | 5 |
