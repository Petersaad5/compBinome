#ifndef VISITOR_ANALYSE_SYNTAXIQUE_H
#define VISITOR_ANALYSE_SYNTAXIQUE_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

class SymbolTable {
public:
    void declareVariable(const std::string& name);
    void useVariable(const std::string& name);
    void checkUnusedVariables() const;
    void printSymbolTable() const;

private:
    std::unordered_map<std::string, int> symbolTable;
    std::unordered_set<std::string> usedVariables;
    int nextIndex = 0;
};

class SyntaxAnalysisVisitor {
public:
    SyntaxAnalysisVisitor(SymbolTable& table);

    void visitDeclaration(const std::string& varName);
    void visitUsage(const std::string& varName);
    void finalize();

private:
    SymbolTable& symbolTable;
};

#endif // VISITOR_ANALYSE_SYNTAXIQUE_H