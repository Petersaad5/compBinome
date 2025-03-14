#include "VisitorAnalyseSyntaxique.h"

void SymbolTable::declareVariable(const std::string& name) {
	if (symbolTable.find(name) != symbolTable.end()) {
		throw std::runtime_error("Variable '" + name + "' is already declared.");
	}
	symbolTable[name] = nextIndex;
	nextIndex += 4;
}

void SymbolTable::useVariable(const std::string& name) {
	if (symbolTable.find(name) == symbolTable.end()) {
		throw std::runtime_error("Variable '" + name + "' is not declared.");
	}
	usedVariables.insert(name);
}

void SymbolTable::checkUnusedVariables() const {
	for (const auto& entry : symbolTable) {
		if (usedVariables.find(entry.first) == usedVariables.end()) {
			std::cerr << "Warning: Variable '" << entry.first << "' declared but not used." << std::endl;
		}
	}
}

void SymbolTable::printSymbolTable() const {
	for (const auto& entry : symbolTable) {
		std::cout << "Variable '" << entry.first << "' has index " << entry.second << std::endl;
	}
}

SyntaxAnalysisVisitor::SyntaxAnalysisVisitor(SymbolTable& table) : symbolTable(table) {}

void SyntaxAnalysisVisitor::visitDeclaration(const std::string& varName) {
	symbolTable.declareVariable(varName);
}

void SyntaxAnalysisVisitor::visitUsage(const std::string& varName) {
	symbolTable.useVariable(varName);
}

void SyntaxAnalysisVisitor::finalize() {
	symbolTable.checkUnusedVariables();
	symbolTable.printSymbolTable();
}

// Example usage
int main() {
	SymbolTable symbolTable;
	SyntaxAnalysisVisitor visitor(symbolTable);

	try {
		visitor.visitDeclaration("x");
		visitor.visitDeclaration("y");
		visitor.visitUsage("x");
		visitor.visitUsage("z"); // This will throw an error
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	visitor.finalize();

	return 0;
}
