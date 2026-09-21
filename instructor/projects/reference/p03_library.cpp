// instructor/projects/reference/p03_library.cpp — INSTRUCTOR-ONLY
// Reference solution for Project 03 (Library Management System). Verified:
// g++ -std=c++17 -Wall -Wextra -pedantic (GCC 16.2), executed vs spec T1-T10.
// Grammar: id;title;author;out;borrower   (out: 0|1, borrower "-" when in)
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Book
{
    std::string id;
    std::string title;
    std::string author;
    bool out{false};
    std::string borrower{"-"};
};

// findById: index of id or -1. Precondition: none. Const observer.
int findIndex(const std::vector<Book>& v, const std::string& id)
{
    for (int i{0}; i < static_cast<int>(v.size()); ++i)
        if (v[i].id == id) return i;
    return -1;
}

// loadCatalog: skip-and-report loader. Returns loaded count; sets skipped.
int loadCatalog(const std::string& path, std::vector<Book>& out, int& skipped)
{
    std::ifstream in{path};
    if (!in.is_open()) return 0;               // missing file = empty catalog
    int loaded{0};
    skipped = 0;
    std::string line{};
    while (std::getline(in, line))
    {
        if (line.empty()) continue;
        std::istringstream ls{line};
        std::string id, title, author, flag, borrower;
        if (!std::getline(ls, id, ';'))       { ++skipped; continue; }
        if (!std::getline(ls, title, ';'))    { ++skipped; continue; }
        if (!std::getline(ls, author, ';'))   { ++skipped; continue; }
        if (!std::getline(ls, flag, ';'))     { ++skipped; continue; }
        if (!std::getline(ls, borrower))      { ++skipped; continue; }
        if (id.empty() || (flag != "0" && flag != "1")) { ++skipped; continue; }
        out.push_back(Book{id, title, author, flag == "1", borrower});
        ++loaded;
    }
    return loaded;
}

// saveCatalog: rewrite whole file. Returns false on open failure.
bool saveCatalog(const std::string& path, const std::vector<Book>& v)
{
    std::ofstream of{path};
    if (!of.is_open()) return false;
    for (const Book& b : v)
        of << b.id << ';' << b.title << ';' << b.author << ';'
           << (b.out ? 1 : 0) << ';' << b.borrower << '\n';
    return true;
}

// nextId: max numeric suffix + 1, formatted B-%d. Survives gaps in ids.
std::string nextId(const std::vector<Book>& v)
{
    int maxNum{1000};
    for (const Book& b : v)
    {
        if (b.id.rfind("B-", 0) == 0)
        {
            int num{std::stoi(b.id.substr(2))};
            if (num > maxNum) maxNum = num;
        }
    }
    return "B-" + std::to_string(maxNum + 1);
}

int main()
{
    std::vector<Book> catalog;
    int skipped{0};
    int loaded{loadCatalog("catalog.txt", catalog, skipped)};
    std::cout << "loaded: " << loaded << " skipped: " << skipped << '\n';

    while (true)
    {
        std::cout << "menu (add|lend|return|find|report|quit): ";
        std::string cmd{};
        if (!(std::cin >> cmd)) break;          // EOF = quit (FR5)

        if (cmd == "add")
        {
            std::string title, author;
            std::cin >> title >> author;   // token read: single-word title/author
            if (title.find(';') != std::string::npos)
            {
                std::cout << "title may not contain ';'\n";
                continue;
            }
            if (title.empty() || author.empty())
            {
                std::cout << "bad text\n";
                continue;
            }
            std::string id{nextId(catalog)};
            catalog.push_back(Book{id, title, author, false, "-"});
            std::cout << "added " << id << '\n';
        }
        else if (cmd == "lend")
        {
            std::string id, who;
            std::cin >> id >> who;
            int i{findIndex(catalog, id)};
            if (i < 0) { std::cout << "no such id\n"; continue; }
            if (catalog[i].out) { std::cout << "not available\n"; continue; }
            catalog[i].out = true;
            catalog[i].borrower = who;
            std::cout << "ok\n";
            saveCatalog("catalog.txt", catalog);
        }
        else if (cmd == "return")
        {
            std::string id;
            std::cin >> id;
            int i{findIndex(catalog, id)};
            if (i < 0) { std::cout << "no such id\n"; continue; }
            catalog[i].out = false;
            catalog[i].borrower = "-";
            std::cout << "ok\n";
            saveCatalog("catalog.txt", catalog);
        }
        else if (cmd == "find")
        {
            std::string text{};
            std::cin >> text;
            bool any{false};
            for (const Book& b : catalog)
            {
                if (b.title.find(text) != std::string::npos)
                {
                    std::cout << b.id << ' ' << b.title
                              << (b.out ? " out" : " in") << '\n';
                    any = true;
                }
            }
            if (!any) std::cout << "none\n";
        }
        else if (cmd == "report")
        {
            int outCount{0};
            for (const Book& b : catalog) if (b.out) ++outCount;
            std::cout << "books: " << catalog.size()
                      << " out: " << outCount
                      << " available: " << catalog.size() - outCount << '\n';
            for (const Book& b : catalog)
                if (b.out) std::cout << b.id << " -> " << b.borrower << '\n';
        }
        else if (cmd == "quit")
        {
            break;
        }
        else
        {
            std::cout << "bad input\n";
        }
    }

    if (saveCatalog("catalog.txt", catalog))
    {
        std::cout << "saved: " << catalog.size() << '\n';
        return 0;
    }
    std::cout << "cannot save\n";
    return 2;
}
