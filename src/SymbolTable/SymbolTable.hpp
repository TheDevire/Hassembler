#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <string>
#include <unordered_map>

class SymbolTable {
    public:
        SymbolTable();
        void addEntry(const std::string& symbol , int address);
        bool contains(const std::string& symbol );
        int GetAddress(const std::string& symbol);

        std::unordered_map<std::string,int> table;
    private:
};

#endif
