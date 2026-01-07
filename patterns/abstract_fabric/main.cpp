#include "classes.hpp"

int main() {

    cout << "____Formal____" << endl;
    FormalNotify formal;
    auto femail = formal.create_email();
    auto fsms = formal.create_sms();

    femail->send("ms Watson, you are wizard");
    fsms->send("mr Potter, you are wizard");

    cout << "____Casual____" << endl;

    CasualNotify casual;

    auto cemail = casual.create_email();
    auto csms = casual.create_sms();
    
    cemail->send("ms Wisley, you are wizard");
    csms->send("mr Wisley, you are wizard");
}