#include "CodeGenVisitor.h"

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) 
{
    #ifdef __APPLE__
    std::cout<< ".globl _main\n" ;
    std::cout<< " _main: \n" ;
    std::cout<< "    pushq %rbp\n" ;
    std::cout<< "    movq %rsp, %rbp\n" ;
    std::cout<< "    popq %rbp\n" ;
    std::cout<< "    ret\n" ;
    #else
    std::cout<< ".globl main\n" ;
    std::cout<< " main: \n" ;
    std::cout<< "    pushq %rbp\n" ;
    std::cout<< "    movq %rsp, %rbp\n" ;
    std::cout<< "    popq %rbp\n" ;
    std::cout<< "    ret\n" ;
    #endif

    this->visit( ctx->return_stmt() );
    
    std::cout << "    ret\n";

    return 0;
}


antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx)
{
    int retval = stoi(ctx->CONST()->getText());

    std::cout << "    movl $"<<retval<<", %eax\n" ;

    return 0;
}
