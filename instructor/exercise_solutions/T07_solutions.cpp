// instructor/exercise_solutions/T07_solutions.cpp — INSTRUCTOR-ONLY
// Solutions for PF-E-079 .. PF-E-090 (Strings).
// Build: g++ -std=c++17 -Wall -Wextra -pedantic T07_solutions.cpp -o t07
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

namespace e079 { // Name Greeting
void run()
{
    std::string name;
    std::getline(std::cin, name);
    std::cout << "Hello, " << name << "!\n" << "length: " << name.size() << '\n';
}
} // namespace e079

namespace e080 { // Initials Extractor
void run()
{
    std::string name;
    std::getline(std::cin, name);
    bool atStart{true};
    for (char ch : name)
    {
        if (std::isspace(static_cast<unsigned char>(ch)))
        {
            atStart = true;
        }
        else if (atStart)
        {
            std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(ch))) << '.';
            atStart = false;
        }
    }
    std::cout << '\n';
}
} // namespace e080

namespace e081 { // Vowel/Consonant Census
void run()
{
    std::string word;
    std::cin >> word;
    int vowels{0}, consonants{0}, other{0};
    for (char ch : word)
    {
        char lo{static_cast<char>(std::tolower(static_cast<unsigned char>(ch)))};
        if (lo == 'a' || lo == 'e' || lo == 'i' || lo == 'o' || lo == 'u')
            ++vowels;
        else if (std::isalpha(static_cast<unsigned char>(ch)))
            ++consonants;
        else
            ++other;
    }
    std::cout << "vowels: " << vowels << '\n'
              << "consonants: " << consonants << '\n' << "other: " << other << '\n';
}
} // namespace e081

namespace e082 { // Word Count (robust)
void run()
{
    std::string line;
    std::getline(std::cin, line);
    int words{0};
    int longest{0};
    int current{0};
    bool inWord{false};
    for (char ch : line)
    {
        if (std::isspace(static_cast<unsigned char>(ch)))
        {
            if (current > longest)
                longest = current;
            current = 0;
            inWord = false;
        }
        else
        {
            if (!inWord)
                ++words;
            inWord = true;
            ++current;
        }
    }
    if (current > longest)
        longest = current;
    std::cout << "words: " << words << '\n' << "longest: " << longest << '\n';
}
} // namespace e082

namespace e083 { // String Reversal (both ways)
void run()
{
    std::string line;
    std::getline(std::cin, line);
    std::string built;
    for (int i{static_cast<int>(line.size()) - 1}; i >= 0; --i)
        built += line[static_cast<std::size_t>(i)];
    std::string work{line};
    int left{0};
    int right{static_cast<int>(work.size()) - 1};
    while (left < right)
    {
        char tmp{work[static_cast<std::size_t>(left)]};
        work[static_cast<std::size_t>(left)] = work[static_cast<std::size_t>(right)];
        work[static_cast<std::size_t>(right)] = tmp;
        ++left;
        --right;
    }
    std::cout << built << '\n' << work << '\n'
              << "match: " << (built == work ? "yes" : "no") << '\n';
}
} // namespace e083

namespace e084 { // Palindrome Judge
void run()
{
    std::string line;
    std::getline(std::cin, line);
    std::string cleaned;
    for (char ch : line)
    {
        if (std::isalnum(static_cast<unsigned char>(ch)))
            cleaned += static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
    }
    int left{0};
    int right{static_cast<int>(cleaned.size()) - 1};
    bool palin{true};
    while (left < right)
    {
        if (cleaned[static_cast<std::size_t>(left)] != cleaned[static_cast<std::size_t>(right)])
        {
            palin = false;
            break;
        }
        ++left;
        --right;
    }
    std::cout << (palin ? "palindrome" : "not palindrome") << '\n'
              << "cleaned: " << cleaned << '\n';
}
} // namespace e084

namespace e085 { // Substring Finder with All Positions
void run()
{
    std::string text, word;
    std::getline(std::cin, text);
    std::getline(std::cin, word);
    std::size_t pos{text.find(word)};
    int count{0};
    std::cout << "positions:";
    while (pos != std::string::npos)
    {
        std::cout << ' ' << pos;
        ++count;
        pos = text.find(word, pos + 1); // +1 allows overlaps
    }
    if (count == 0)
        std::cout << " none";
    std::cout << '\n' << "count: " << count << '\n';
}
} // namespace e085

namespace e086 { // Case Normalizer
void run()
{
    std::string line;
    std::getline(std::cin, line);
    bool atWordStart{true};
    std::string out;
    for (char ch : line)
    {
        if (std::isalpha(static_cast<unsigned char>(ch)))
        {
            if (atWordStart)
                out += static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
            else
                out += static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
            atWordStart = false;
        }
        else
        {
            out += ch;
            if (std::isspace(static_cast<unsigned char>(ch)))
                atWordStart = true;
        }
    }
    std::cout << out << '\n';
}
} // namespace e086

namespace e087 { // CSV Tokenizer
void run()
{
    std::string line;
    std::getline(std::cin, line);
    std::string token;
    int count{0};
    auto emit = [&count](const std::string& t) {
        ++count;
        std::cout << count << ": " << (t.empty() ? "(empty)" : t) << '\n';
    };
    for (char ch : line)
    {
        if (ch == ',')
        {
            emit(token);
            token.clear();
        }
        else
            token += ch;
    }
    emit(token); // final token after the last comma — the classic bug
    std::cout << "count: " << count << '\n';
}
} // namespace e087

namespace e088 { // C-String Walk (char buffer)
void run()
{
    std::string word;
    std::cin >> word;
    if (word.size() > 30)
    {
        std::cout << "too long\n";
        return;
    }
    char buf[32]{};
    for (std::size_t i{0}; i < word.size(); ++i)
        buf[i] = word[i];
    int letters{0}, digits{0}, len{0};
    while (buf[len] != '\0')
    {
        if (std::isdigit(static_cast<unsigned char>(buf[len])))
            ++digits;
        else if (std::isalpha(static_cast<unsigned char>(buf[len])))
            ++letters;
        ++len;
    }
    std::cout << "letters: " << letters << '\n' << "digits: " << digits << '\n'
              << "reversed: ";
    for (int i{len - 1}; i >= 0; --i)
        std::cout << buf[i];
    std::cout << '\n';
}
} // namespace e088

namespace e089 { // Caesar Cipher
void run()
{
    int k{};
    std::cin >> k;
    std::cin.ignore(1000, '\n');
    std::string line;
    std::getline(std::cin, line);
    std::string cipher;
    for (char ch : line)
    {
        if (std::isupper(static_cast<unsigned char>(ch)))
            cipher += static_cast<char>('A' + (ch - 'A' + k) % 26);
        else if (std::islower(static_cast<unsigned char>(ch)))
            cipher += static_cast<char>('a' + (ch - 'a' + k) % 26);
        else
            cipher += ch;
    }
    std::string plain;
    for (char ch : cipher)
    {
        if (std::isupper(static_cast<unsigned char>(ch)))
            plain += static_cast<char>('A' + (ch - 'A' + 26 - k) % 26);
        else if (std::islower(static_cast<unsigned char>(ch)))
            plain += static_cast<char>('a' + (ch - 'a' + 26 - k) % 26);
        else
            plain += ch;
    }
    std::cout << cipher << '\n' << plain << '\n';
}
} // namespace e089

namespace e090 { // Word Frequency Table
void run()
{
    std::string line;
    std::getline(std::cin, line);
    std::string words[20]{};
    int counts[20]{};
    int distinct{0};
    std::string token;
    int total{0};
    for (std::size_t i{0}; i <= line.size(); ++i)
    {
        if (i == line.size() || std::isspace(static_cast<unsigned char>(line[i])))
        {
            if (!token.empty())
            {
                ++total;
                int found{-1};
                for (int w{0}; w < distinct; ++w)
                    if (words[w] == token)
                    {
                        found = w;
                        break;
                    }
                if (found >= 0)
                    ++counts[found];
                else if (distinct < 20)
                {
                    words[distinct] = token;
                    counts[distinct] = 1;
                    ++distinct;
                }
                token.clear();
            }
        }
        else
            token += line[i];
    }
    std::cout << "total words: " << total << '\n';
    for (int w{0}; w < distinct; ++w)
        std::cout << words[w] << ": " << counts[w] << '\n';
    int best{0};
    for (int w{1}; w < distinct; ++w)
        if (counts[w] > counts[best])
            best = w;
    std::cout << "top: " << words[best] << '\n';
}
} // namespace e090

int main()
{
    e079::run();
    e082::run();
    e084::run();
    e087::run();
    return 0;
}
