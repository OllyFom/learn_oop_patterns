#include "classes.hpp"
#include <vector>
#include <sstream>

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

    string str_expr = "A AND B", s;
    Context ctx1;
    std::vector<string> parsed;
    std::stringstream ss(str_expr);

    std::vector<string> v;

    while (std::getline(ss, s, ' ')) {
        v.push_back(s);
    }
    //          TODO:   ДОДЕЛАТЬ ТАК, ЧТОБЫ ЭТО БЫЛО ДИНАМИЧЕСКИ
    //                  пока 0 смысла и выглядит не красиво
}