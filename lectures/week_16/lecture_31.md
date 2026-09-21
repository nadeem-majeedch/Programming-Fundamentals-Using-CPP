# L31 · Classes: Data + Behavior, Constructors, Encapsulation

**Module 16 — Introduction to Object-Oriented Programming · Week 16 · Lecture 31 of 32 · 120 minutes**
**Outcomes:** CLO-8 · PF-16.1, PF-16.2 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

## Learning objectives

1. Define a class with `private` data members, a public interface (member
   functions), and constructor(s); instantiate objects and call their
   interface (PF-16.1).
2. Explain encapsulation as an *invariant-protection* mechanism — contrast a
   public-data struct with a guarded class — and predict the compile error
   when outside code touches private members (PF-16.2).
3. Implement `get`/`set` accessors with validation so the invariant (e.g.
   `0 <= score <= 100`) cannot be violated from outside (PF-16.2).

## Prerequisites

L28 (structs — the class is introduced as "a struct that guards itself");
L15–L26 (functions, references, passing modes — member functions use them
all); M5 (loops for the menu driving objects).

## Concept sequence

1. The struct's weakness: any code can corrupt an invariant
2. `class`: `private` data, `public` interface; `.` on objects
3. Constructors: guaranteeing a valid birth state
4. Accessors/mutators with validation: the guarded set
5. Struct vs class side-by-side: same program, two disciplines
6. Where OOP goes next (the bridge-out slide)

## Teaching topics (detailed)

- **Invariant motivation:** L28's `Student` with `gpa` — free code sets
  `s.gpa = 99.0;` (nonsense accepted silently); the invariant statement
  ("0.0 ≤ gpa ≤ 4.0") written on the board *first*, then protected by
  making the data private.
- **Class anatomy:** `class Student { public: ... private: ... };` —
  access sections; member functions declared inside, defined after with
  `void Student::print() const {...}` syntax; calling via object: `s.print();`
  — member functions implicitly receive "the object" (the `this` idea,
  named informally).
- **Constructors:** default + parameterized
  `Student(std::string name, int id, double gpa)` with member-init-list
  shown once (assignment-in-body shown as the beginner form); constructor
  validates — an invalid gpa *cannot create an object* (clamped or
  rejected); objects are born valid.
- **Accessors/mutators:** `double get_gpa() const;` /
  `void set_gpa(double g)` with validation — the only door to the data;
  demo: outside write attempt `s.gpa = 99.0;` → exact compiler error
  (`double Student::gpa is private`); set-with-validation demo (clamp vs
  reject, course choice: reject with `false` return — honest about both
  schools).
- **`const` member functions:** read-only interface marked `const` —
  connects to L26's const discipline; rule: getters are `const`.
- **Bridge slide (not taught):** inheritance, polymorphism, RAII-classes,
  templates — the OOP course's territory; this module = *encapsulation +
  constructors* only ([docs/CPP_STANDARD.md](../../docs/CPP_STANDARD.md) § 4.2).

## C++ examples required

| File | Role |
|---|---|
| `first_class.cpp` ✅ | `Student` class: private data, two constructors, validated `set_gpa`, `const` getters; the same struct-based program beside it for contrast |
| (live) `bank_account_class.cpp` | `Account` with `deposit`/`withdraw` enforcing `balance >= 0` — invariant protection on a second domain |

## Common student misconceptions

- "`private` hides data from other files only." (It hides from *all outside
  code*, including `main` in the same file.)
- "Getters/setters are pointless ceremony." (They are the *validation
  point*; without them the invariant is unenforceable — the struct-vs-class
  demo proves it.)
- "Constructors are optional boilerplate." (They are the guarantee that
  objects start valid — delete the validation and the invariant is born
  broken.)
- "Classes are structs with different keywords." (In C++ the *default
  access* differs; the *discipline* differs — that's the point.)

## Conceptual explanation (beginner-first)

Module 14's structs bundle data. Today's **classes** add the second
half: *behavior* that *guards* the data. A class keeps its data
**private** — no outside code can touch it — and exposes a small
**public interface** of member functions ("methods") that are the only
way in. The public functions enforce the rules: a `Student` whose GPA
setter accepts anything is a struct with extra steps; one whose
`set_gpa` rejects 99.0 has *protected an invariant* — a condition
(like `0 <= gpa <= 4.0`) that holds for every valid object.

A **constructor** is a member function that runs automatically at
object creation and guarantees the object is born valid — no
half-initialized records slipping through. And `const` member
functions (getters) promise *not* to modify the object: the
const-correctness habit from Module 13, now inside a class.

The design habit of the week: ask *what can go wrong with this data if
anyone can write it?* — then make the write paths responsible.
Encapsulation is not secrecy; it's giving the type itself the power to
keep its own promises.

## Terminology and definitions

| Term | Definition |
|---|---|
| Class | A type bundling private data with a public interface of behavior |
| `private:` | Members only the class's own functions may access |
| `public:` | Members any code may call — the type's contract |
| Member function | A function declared inside the class; called with dot syntax |
| Constructor | Special member that runs at creation; same name as the class, no return type |
| Default constructor | The constructor callable with no arguments |
| Parameterized constructor | Takes arguments to initialize members properly |
| Getter / setter | Read-only accessor (`const`); validated writer — the invariant's checkpoints |
| Invariant | A condition that must hold for every valid object (e.g., non-negative balance) |
| Encapsulation | Data private + behavior public = the type protects its own rules |
| `const` member function | Promises not to modify the object; callable on const objects |

## Syntax and C++ examples

```cpp
class Student                 // contrast: the struct version beside it
{
public:                       // what any code may call — the interface
    Student() = default;                        // default constructor
    Student(const std::string& name, int id, double gpa);

    void  set_gpa(double gpa);                // validated writer
    double get_gpa() const { return gpa_; }   // const getter: no mutation
    void  print() const;                      // read-only behavior

private:                      // the data — nobody outside may touch
    std::string name_;
    int         id_;
    double      gpa_;
};

Student::Student(const std::string& name, int id, double gpa)
    : name_{name}, id_{id}
{
    set_gpa(gpa);            // construct valid: same validation path
}

void Student::set_gpa(double gpa)
{
    if (gpa >= 0.0 && gpa <= 4.0)     // the invariant enforced HERE
        gpa_ = gpa;
    else
        gpa_ = 0.0;                   // (or report — tier 1 style)
}

Student s{"Ada", 1001, 3.9};
// s.gpa_ = 99.0;        // COMPILE ERROR: private — the feature, not the obstacle
s.set_gpa(99.0);         // legal — and rejected by the validation
```

## Line-by-line code explanation

`examples/first_class.cpp`:

1. The class opens `public:` (interface first — readers see what they
   can call) and closes with `private:` data — the course layout
   convention.
2. `Student() = default;` keeps a no-argument construction path; the
   parameterized constructor routes *all* initialization through
   `set_gpa` so the invariant holds from birth.
3. `get_gpa() const` — the trailing `const` is the read-only promise;
   omitting it makes getters unusable on const objects (shown live).
4. The struct twin beside it accepts `s.gpa = 99.0;` silently — the
   side-by-side makes encapsulation's *point* undeniable.
5. The compile-error comment documents the failed outside write: the
   error message *is* the feature demo.

## Output prediction questions (with answers)

1. `s.gpa_ = 99.0;` from `main` — ? — Compile error: `gpa_` is
   private.
2. `s.set_gpa(99.0); s.get_gpa()` — ? — 0.0 (or the chosen report):
   the invariant held.
3. Can `main` call `s.print() const`? — Yes: public and read-only.
4. Which section can outside code call? — `public:` only.
5. The struct twin vs the class on the same corrupting write — struct
   accepts (corrupts), class rejects (invariant survives).

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Data declared `public:` | Invariant unenforceable — struct behavior | Keep data private; expose behavior |
| Setter without validation | Corrupt values accepted | Every setter checks the invariant |
| Constructor bypassing the setter | Objects born invalid | Route initialization through validation |
| Missing `const` on getters | Getters unusable on const objects; bugs hide | `const` every read-only member |
| `_`-less member names colliding with parameters | Self-assignment confusion | `gpa_` convention from the style guide |
| God-object interface (20 public functions) | No coherent contract | Minimal interface — the siege game's lesson |

## Classroom demonstrations

1. **The compile error as a feature:** attempt the private write in
   front of the class; read the error aloud; reframe: "the language
   just protected your invariant for free."
2. **Struct vs class, same attack:** corrupt the struct's GPA
   (silently accepted); attack the class (rejected) — the whole
   module's motivation in ninety seconds.
3. **The getter trap:** delete a getter's `const`; try to call it on a
   `const Student&` parameter — the compiler explains const-correctness
   better than slides.

## Guided student activities
**Invariant siege (20 min):** Team A ships a class with a stated invariant;
Team B gets 5 minutes to *try* to violate it through any legal outside call;
then roles swap with a new domain. Winning sieges list exactly which public
function let the corruption through (design feedback loop).

## Practice problems

- Convert L28's `Book` struct into a class: private stock enforced
  non-negative; `restock`/`sell` member functions.
- Add a parameterized constructor to `Student` that rejects invalid gpas;
  demonstrate the compile error for outside writes.
- Design the interface (signatures only) for a `Timer` class; mark every
  function `const`-correct.
- (🟡 stretch) Explain why the compiler error for `s.gpa = 99.0;` *is* the
  encapsulation feature, not an obstacle.

## Summary

A class pairs private data with a public interface; constructors
establish the invariant at birth, setters guard it on every write, and
`const` getters report without risk. The struct→class transition is
the course's final architectural step: from writing correct programs
to designing types that make incorrect programs *not compile*. Next
(L32): the synthesis — the capstone builds and the course closes.

## Exit ticket / formative assessment

1. Which section of a class does outside code call?
2. Write the signature of a read-only member function `get_gpa`.
3. One sentence: what does a constructor guarantee?

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (robustness quiz) + invariant motivation | 15 |
| Class anatomy + constructors | 40 |
| Break | 10 |
| Accessors + validation + struct-vs-class contrast | 30 |
| Invariant siege activity | 20 |
| Exit ticket + final-exam briefing | 5 |
