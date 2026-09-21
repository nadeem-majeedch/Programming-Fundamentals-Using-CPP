// purpose: text file I/O — token reading, line reading, record round-trip,
//          append mode, open-check discipline, correct EOF idioms — L29.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic file_read_write.cpp -o files

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Score
{
    std::string name;
    int points{};
};

// SAVE: write one line per record — "name,points".
// CONTRACT: whatever save writes, load must be able to parse (round-trip).
bool save_scores(const std::string& filename, const std::vector<Score>& rows)
{
    std::ofstream out{filename};          // truncates an existing file!
    if (!out)                             // open check, ALWAYS
    {
        return false;
    }
    for (const Score& s : rows)
    {
        out << s.name << ',' << s.points << '\n';
    }
    return true;                          // (no explicit close needed:
}                                         // the stream's destructor flushes)

// LOAD: parse lines written by save_scores.
bool load_scores(const std::string& filename, std::vector<Score>& rows)
{
    std::ifstream in{filename};
    if (!in)
    {
        return false;
    }
    rows.clear();
    std::string line{};
    while (std::getline(in, line))       // one record per line
    {
        std::string::size_type comma{line.find(',')};
        if (comma == std::string::npos)
        {
            continue;                    // malformed line: skip (L30 pattern)
        }
        std::istringstream parse{line.substr(comma + 1)};
        int points{};
        if (!(parse >> points))          // stream-state check, not exceptions
        {
            continue;                    // malformed number: skip
        }
        Score s{};
        s.name = line.substr(0, comma);
        s.points = points;
        rows.push_back(s);
    }
    return true;
}

int main()
{
    std::vector<Score> original{{"Ayesha", 88}, {"Ben", 72}, {"Chen", 95}};

    // --- WRITE (truncate) ---
    if (!save_scores("scores.txt", original))
    {
        std::cout << "Could not write scores.txt\n";
        return 1;
    }
    std::cout << "saved 3 records\n";

    // --- READ BACK (token form: >> splits on whitespace) ---
    std::ifstream in{"scores.txt"};
    if (!in)
    {
        std::cout << "Could not open scores.txt\n";
        return 1;
    }
    std::cout << "token read: ";
    std::string token{};
    while (in >> token)               // the read IS the test (correct EOF idiom)
    {
        std::cout << token << ' ';
    }
    std::cout << '\n';
    in.close();

    // --- LINE read: getline reads whole lines (spaces included) ---
    std::ifstream in2{"scores.txt"};
    if (!in2)
    {
        return 1;
    }
    std::cout << "line read:\n";
    std::string line{};
    while (std::getline(in2, line))
    {
        std::cout << "  " << line << '\n';
    }
    in2.close();

    // --- APPEND mode: add without destroying what is already there ---
    std::ofstream log{"app_log.txt", std::ios::app};
    if (!log)
    {
        return 1;
    }
    log << "run completed\n";         // runs twice -> two lines (try it!)
    log.close();
    std::cout << "appended one line to app_log.txt\n";

    // --- ROUND-TRIP: load what we saved ---
    std::vector<Score> loaded{};
    if (load_scores("scores.txt", loaded))
    {
        std::cout << "loaded " << loaded.size() << " records; first = "
                  << loaded[0].name << " (" << loaded[0].points << ")\n";
    }

    return 0;
}
