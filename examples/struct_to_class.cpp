// purpose: the struct -> class refactor checklist applied to the same
//          roster program, side by side — used in L32 (final synthesis).
// build:   g++ -std=c++17 -Wall -Wextra -pedantic struct_to_class.cpp -o s2c

#include <iostream>
#include <string>
#include <vector>

// ============================================================
// VERSION A — struct (Module 14 style): data + free functions
// Invariant ("0 <= score <= 100") exists only in comments.
// ============================================================
struct ScoreRecord
{
    std::string name;
    int score{};              // invariant: 0..100 (NOT enforced)
};

void bump_record(ScoreRecord& r, int points)   // free function, unchecked
{
    r.score += points;        // 105 is accepted silently — bug factory
}

void print_record(const ScoreRecord& r)
{
    std::cout << "[struct] " << r.name << " : " << r.score << '\n';
}

// ============================================================
// VERSION B — class (Module 16 style): same algorithms, guarded data.
// Refactor checklist applied:
//   1. state the invariant              (0 <= score_ <= 100)
//   2. privatize the data               (score_)
//   3. promote record functions         (bump, print become members)
//   4. constructor validates at birth   (reject/clamp bad scores)
//   5. const-mark the readers           (print, score())
// ============================================================
class ScoreCard
{
public:
    ScoreCard(std::string name, int score)
        : name_{std::move(name)}, score_{validated(score)}
    {
    }

    int score() const { return score_; }              // reader: const
    const std::string& name() const { return name_; }

    bool bump(int points)                             // mutator: validated
    {
        int candidate{score_ + points};
        if (candidate < 0 || candidate > 100)
        {
            return false;                             // invariant holds
        }
        score_ = candidate;
        return true;
    }

    void print() const
    {
        std::cout << "[class ] " << name_ << " : " << score_ << '\n';
    }

private:
    static int validated(int score)
    {
        if (score < 0)
        {
            return 0;
        }
        if (score > 100)
        {
            return 100;
        }
        return score;
    }

    std::string name_;
    int score_;               // invariant: 0 <= score_ <= 100, ENFORCED
};

int main()
{
    // The struct version accepts corruption:
    ScoreRecord rec{"Ayesha", 95};
    bump_record(rec, 20);                    // 115 — invariant broken
    print_record(rec);

    // The class version rejects it with the SAME call shape:
    ScoreCard card{"Ayesha", 95};
    if (!card.bump(20))
    {
        std::cout << "[class ] bump(20) rejected — score stays "
                  << card.score() << '\n';
    }
    if (card.bump(5))
    {
        card.print();                        // 100 — still valid
    }

    // Collection of objects: everything from M9-M12 still applies.
    std::vector<ScoreCard> roster{
        ScoreCard{"Ben", 72}, ScoreCard{"Chen", 88}};
    for (const ScoreCard& c : roster)
    {
        c.print();
    }

    // The synthesis: same algorithms (traversal, aggregation), new owner of
    // the invariant. That is the whole Module 16 idea.
    return 0;
}
