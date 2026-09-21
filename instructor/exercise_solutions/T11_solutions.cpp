// instructor/exercise_solutions/T11_solutions.cpp — INSTRUCTOR-ONLY
// Solutions for PF-E-122 .. PF-E-131 (File Handling).
// Build: g++ -std=c++17 -Wall -Wextra -pedantic T11_solutions.cpp -o t11
// NOTE: file exercises read/write in the CURRENT directory; run from a
// scratch folder. main() creates its own sample data files first.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace e122 { // Write and Read Back Lines
void run()
{
    std::ofstream out{"notes.txt"};
    if (!out)
    {
        std::cout << "cannot open notes.txt for writing\n";
        return;
    }
    std::string line;
    for (int i{1}; i <= 3; ++i)
    {
        std::getline(std::cin, line);
        out << i << ". " << line << '\n';
    }
    out.close(); // explicit close before reopening for read
    std::ifstream in{"notes.txt"};
    if (!in)
    {
        std::cout << "cannot reopen notes.txt\n";
        return;
    }
    while (std::getline(in, line))
        std::cout << line << '\n';
}
} // namespace e122

namespace e123 { // Copy File (line by line)
void run()
{
    std::ifstream in{"notes.txt"};
    if (!in)
    {
        std::cout << "cannot open notes.txt\n";
        return;
    }
    std::ofstream out{"notes_copy.txt"};
    if (!out)
    {
        std::cout << "cannot open notes_copy.txt for writing\n";
        return;
    }
    int lines{0};
    std::string line;
    while (std::getline(in, line)) // read-as-test: attempt + check in one
    {
        out << line << '\n';
        ++lines;
    }
    std::cout << "copied " << lines << " lines\n";
}
} // namespace e123

namespace e124 { // Number File Statistics
void run()
{
    std::ifstream in{"numbers.txt"};
    if (!in)
    {
        std::cout << "cannot open\n";
        return;
    }
    int count{0};
    long long sum{0};
    bool haveAny{false};
    int minV{0}, maxV{0};
    int v{};
    while (in >> v)
    {
        if (!haveAny)
        {
            minV = v; // seed with the FIRST successful read (not 0!)
            maxV = v;
            haveAny = true;
        }
        if (v < minV)
            minV = v;
        if (v > maxV)
            maxV = v;
        sum += v;
        ++count;
    }
    if (!haveAny)
    {
        std::cout << "empty file\n";
        return;
    }
    std::cout << "count: " << count << '\n' << "sum: " << sum << '\n'
              << "min: " << minV << '\n' << "max: " << maxV << '\n'
              << std::fixed << std::setprecision(2) << "mean: "
              << static_cast<double>(sum) / count << '\n';
}
} // namespace e124

namespace e125 { // Append Diary with Timestamp Count
void run()
{
    std::ofstream appender{"diary.txt", std::ios::app};
    if (!appender)
    {
        std::cout << "cannot open diary.txt\n";
        return;
    }
    std::cin.ignore(1000, '\n');
    int appended{0};
    std::string line;
    while (true)
    {
        std::getline(std::cin, line);
        if (line.empty())
            break;
        appender << line << '\n';
        ++appended;
    }
    appender.close();
    // Without std::ios::app this program would have TRUNCATED the diary:
    // plain output mode erases existing content at open time (L29 horror).
    std::ifstream in{"diary.txt"};
    int total{0};
    std::string entry;
    while (std::getline(in, entry))
        ++total;
    std::cout << "appended: " << appended << '\n' << "total entries now: " << total << '\n';
}
} // namespace e125

namespace e126 { // Student Record File Round-Trip
struct StudentF
{
    std::string name;
    int id;
    double gpa;
};

void run()
{
    int n{};
    std::cin >> n;
    // WRITER contract: one student per line as "name id gpa", name is one
    // word (no spaces). The reader below must mirror this exactly.
    {
        std::ofstream out{"students.txt"};
        for (int i{0}; i < n; ++i)
        {
            StudentF s;
            std::cin >> s.name >> s.id >> s.gpa;
            out << s.name << ' ' << s.id << ' ' << s.gpa << '\n';
        }
    }
    // READER (mirrors the contract field-for-field)
    std::ifstream in{"students.txt"};
    std::vector<StudentF> roster;
    StudentF s;
    double sum{0.0};
    while (in >> s.name >> s.id >> s.gpa)
    {
        roster.push_back(s);
        sum += s.gpa;
    }
    for (const StudentF& st : roster)
        std::cout << st.name << ' ' << st.id << ' ' << st.gpa << '\n';
    std::cout << std::fixed << std::setprecision(2) << "average gpa: "
              << (roster.empty() ? 0.0 : sum / roster.size()) << '\n';
}
} // namespace e126

namespace e127 { // Skip-and-Report Loader
void run()
{
    std::ifstream in{"scores.txt"};
    if (!in)
    {
        std::cout << "cannot open scores.txt\n";
        return;
    }
    int good{0}, bad{0}, lineNo{0};
    long long total{0};
    std::string line;
    while (std::getline(in, line))
    {
        ++lineNo;
        std::size_t commaPos{line.find(',')};
        int score{};
        bool ok{false};
        if (commaPos != std::string::npos)
        {
            std::string name{line.substr(0, commaPos)};
            std::istringstream rest{line.substr(commaPos + 1)};
            if (!name.empty() && rest >> score)
                ok = true;
        }
        if (ok)
        {
            ++good;
            total += score;
        }
        else
        {
            ++bad;
            std::cout << "line " << lineNo << ": skipped\n";
        }
    }
    std::cout << "loaded " << good << ", skipped " << bad << '\n';
    if (good > 0)
        std::cout << std::fixed << std::setprecision(2) << "average: "
                  << static_cast<double>(total) / good << '\n';
}
} // namespace e127

namespace e128 { // Word Frequency from File
void run()
{
    std::ifstream in{"story.txt"};
    if (!in)
    {
        std::cout << "cannot open story.txt\n";
        return;
    }
    std::string words[200]{};
    int counts[200]{};
    int distinct{0};
    int total{0};
    std::string word;
    while (in >> word)
    {
        ++total;
        int found{-1};
        for (int w{0}; w < distinct; ++w)
            if (words[w] == word)
            {
                found = w;
                break;
            }
        if (found >= 0)
            ++counts[found];
        else if (distinct < 200)
        {
            words[distinct] = word;
            counts[distinct] = 1;
            ++distinct;
        }
    }
    std::cout << "total: " << total << '\n';
    for (int rank{0}; rank < 3 && rank < distinct; ++rank)
    {
        int best{rank};
        for (int w{rank + 1}; w < distinct; ++w)
        {
            if (counts[w] > counts[best])
                best = w;
            else if (counts[w] == counts[best] && words[w] < words[best])
                best = w; // tie: alphabetical
        }
        std::cout << words[best] << ": " << counts[best] << '\n';
        // move winner to 'rank' slot so the next pass skips it
        std::string tw{words[rank]};
        words[rank] = words[best];
        words[best] = tw;
        int tc{counts[rank]};
        counts[rank] = counts[best];
        counts[best] = tc;
    }
}
} // namespace e128

namespace e129 { // Two-File Merge (sorted score files)
void run()
{
    std::ifstream a{"a.txt"};
    std::ifstream b{"b.txt"};
    std::ofstream out{"merged.txt"};
    if (!a || !b || !out)
    {
        std::cout << "cannot open input/output files\n";
        return;
    }
    int va{}, vb{};
    bool haveA{static_cast<bool>(a >> va)};
    bool haveB{static_cast<bool>(b >> vb)};
    int count{0};
    while (haveA || haveB)
    {
        if (!haveB || (haveA && va <= vb))
        {
            out << va << '\n';
            haveA = static_cast<bool>(a >> va);
        }
        else
        {
            out << vb << '\n';
            haveB = static_cast<bool>(b >> vb);
        }
        ++count;
    }
    std::cout << "merged " << count << " values\n";
}
} // namespace e129

namespace e130 { // Config Reader with Defaults
void run()
{
    std::ifstream in{"config.txt"};
    std::string theme{"dark"};
    int volume{50};
    std::string difficulty{"normal"};
    bool themeSeen{false}, volumeSeen{false}, diffSeen{false};
    if (!in)
    {
        std::cout << "config missing: all defaults\n";
    }
    else
    {
        std::string line;
        int lineNo{0};
        while (std::getline(in, line))
        {
            ++lineNo;
            std::istringstream row{line};
            std::string key, value;
            if (!(row >> key >> value))
            {
                std::cout << "anomaly: line " << lineNo
                          << " malformed\n";
                continue;
            }
            if (key == "theme" && !themeSeen)
            {
                theme = value;
                themeSeen = true;
            }
            else if (key == "volume" && !volumeSeen)
            {
                volume = std::stoi(value);
                volumeSeen = true;
            }
            else if (key == "difficulty" && !diffSeen)
            {
                difficulty = value;
                diffSeen = true;
            }
            else
                std::cout << "anomaly: line " << lineNo << " unknown key '"
                          << key << "'\n";
        }
    }
    std::cout << "theme=" << theme << (themeSeen ? "" : " (default)") << '\n';
    std::cout << "volume=" << volume << (volumeSeen ? "" : " (default)") << '\n';
    std::cout << "difficulty=" << difficulty
              << (diffSeen ? "" : " (default)") << '\n';
}
} // namespace e130

namespace e131 { // Transaction Log Audit
struct AccountT
{
    std::string id;
    long long balance;
    int processed{0};
};

void run()
{
    const int NUM_ACCOUNTS{3};
    AccountT accounts[NUM_ACCOUNTS]{{"A101", 0}, {"A102", 0}, {"A103", 0}};
    std::cout << "initial balances:\n";
    for (AccountT& a : accounts)
        std::cin >> a.id >> a.balance;
    std::ifstream in{"transactions.txt"};
    if (!in)
    {
        std::cout << "cannot open transactions.txt\n";
        return;
    }
    std::string line;
    int lineNo{0};
    int anomalies{0};
    long long grandProcessed{0};
    while (std::getline(in, line))
    {
        ++lineNo;
        std::istringstream row{line};
        std::string id, action;
        long long amount{};
        if (!(row >> id >> action >> amount))
        {
            ++anomalies;
            std::cout << "line " << lineNo << ": malformed, skipped\n";
            continue;
        }
        AccountT* acc{nullptr};
        for (AccountT& a : accounts)
            if (a.id == id)
                acc = &a;
        if (acc == nullptr || (action != "deposit" && action != "withdraw")
            || amount <= 0)
        {
            ++anomalies;
            std::cout << "line " << lineNo << ": invalid, skipped\n";
            continue;
        }
        if (action == "deposit")
        {
            acc->balance += amount;
            ++acc->processed;
            grandProcessed += amount;
        }
        else // withdraw with overdraft guard
        {
            if (amount > acc->balance)
            {
                ++anomalies;
                std::cout << "line " << lineNo << ": overdraft attempt, skipped\n";
            }
            else
            {
                acc->balance -= amount;
                ++acc->processed;
                grandProcessed += amount;
            }
        }
    }
    for (const AccountT& a : accounts)
        std::cout << a.id << ": " << a.balance << " (" << a.processed
                  << " processed)\n";
    std::cout << "anomalies: " << anomalies << '\n'
              << "total processed amount: " << grandProcessed << '\n';
}
} // namespace e131

// ---- test scaffolding: creates sample files, then runs a demo subset ----
void createSampleFiles()
{
    {
        std::ofstream a{"a.txt"};
        a << 1 << '\n' << 4 << '\n';
    }
    {
        std::ofstream b{"b.txt"};
        b << 2 << '\n' << 3 << '\n' << 9 << '\n';
    }
    {
        std::ofstream s{"scores.txt"};
        s << "Ayesha,88\nBEN\nBen,72\n,55\nChen,95\nDana,77\n";
    }
    {
        std::ofstream st{"story.txt"};
        st << "the cat sat on the mat\nthe cat saw a dog\n";
    }
    {
        std::ofstream c{"config.txt"};
        c << "theme light\nvolume 80\nlang fr\n";
    }
    {
        std::ofstream t{"transactions.txt"};
        t << "A101 deposit 500\nA102 withdraw 10\nA103 deposit 250\n"
             "A101 withdraw 900\nA103 deposit -5\nbadline\n";
    }
}

int main()
{
    createSampleFiles();
    e123::run(); // copies notes.txt if present, else reports
    e124::run(); // numbers.txt may be missing: prints "cannot open"
    e127::run(); // scores.txt: skip-and-report
    e128::run(); // story.txt: word frequency
    e129::run(); // a.txt + b.txt -> merged.txt
    e130::run(); // config.txt with defaults + anomalies
    return 0;
}
