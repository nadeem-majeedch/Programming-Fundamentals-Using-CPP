// purpose: per-character and word-level string algorithms — reverse,
//          palindrome (two-pointer), vowel count, space-proof word count,
//          longest word — used in L22.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic string_algorithms.cpp -o stralg

#include <cctype>     // tolower
#include <iostream>
#include <string>

// Reverse IN PLACE: swap symmetric pairs (same argument as matrix transpose).
void reverse_in_place(std::string& s)
{
    int n{static_cast<int>(s.length())};
    for (int i{0}; i < n / 2; ++i)
    {
        char temp{s[i]};
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = temp;
    }
}

// Two-pointer palindrome check (case-insensitive). "" and "x" are palindromes.
bool is_palindrome(const std::string& s)
{
    int i{0};
    int j{static_cast<int>(s.length()) - 1};
    while (i < j)
    {
        char left{static_cast<char>(std::tolower(static_cast<unsigned char>(s[i])))};
        char right{static_cast<char>(std::tolower(static_cast<unsigned char>(s[j])))};
        if (left != right)
        {
            return false;              // early exit
        }
        ++i;
        --j;
    }
    return true;
}

// Vowel count (character-level).
int count_vowels(const std::string& s)
{
    int count{};
    for (char c : s)
    {
        char lower{static_cast<char>(std::tolower(static_cast<unsigned char>(c)))};
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o'
            || lower == 'u')
        {
            ++count;
        }
    }
    return count;
}

// Word count robust to double spaces: count space->non-space TRANSITIONS.
int count_words(const std::string& s)
{
    int count{};
    int n{static_cast<int>(s.length())};
    for (int i{0}; i < n; ++i)
    {
        bool is_word_char{s[i] != ' '};
        bool prev_was_space{(i == 0) || (s[i - 1] == ' ')};
        if (is_word_char && prev_was_space)
        {
            ++count;
        }
    }
    return count;
}

// Longest word (word-level scan using find + substr).
std::string longest_word(const std::string& s)
{
    std::string best{};
    std::string::size_type pos{0};
    while (pos < s.length())
    {
        // skip spaces
        while (pos < s.length() && s[pos] == ' ')
        {
            ++pos;
        }
        std::string::size_type start{pos};
        while (pos < s.length() && s[pos] != ' ')
        {
            ++pos;
        }
        if (pos > start)
        {
            std::string word{s.substr(start, pos - start)};
            if (word.length() > best.length())
            {
                best = word;
            }
        }
    }
    return best;
}

int main()
{
    std::string text{"level"};
    reverse_in_place(text);
    std::cout << "reverse(\"level\")        = " << text << '\n';

    std::cout << "is_palindrome(\"Racecar\") = " << is_palindrome("Racecar") << '\n';
    std::cout << "is_palindrome(\"hello\")   = " << is_palindrome("hello") << '\n';
    std::cout << "count_vowels(\"Programming\") = " << count_vowels("Programming") << '\n';

    // The naive space-count would say 2 words here; the transition count
    // correctly reports 2 for messy spacing:
    std::cout << "count_words(\"one  two\")   = " << count_words("one  two") << '\n';

    std::cout << "longest_word(\"we love algorithms\") = "
              << longest_word("we love algorithms") << '\n';

    return 0;
}
