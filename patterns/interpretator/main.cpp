#include "classes.hpp"

// (A AND B) OR (NOT C)
int main()
{
    bool A = true, B = false, C = true;

    auto expr = std::make_unique<OrExpression>(
        std::make_unique<AndExpression>(
            std::make_unique<Variable>("A"),
            std::make_unique<Variable>("B")
        ), 
        std::make_unique<NotExpression>(
            std::make_unique<Variable>("C")
        )
    );
    Context ctx;
    ctx.set("A", A);
    ctx.set("B", B);
    ctx.set("C", C);

    
    std::cout << "Result: " << expr->interpret(ctx) << std::endl;
}