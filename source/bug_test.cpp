#include <variant>
#include <iostream>
#include <string>

using namespace std;
using IntOrString = variant<int, string>;

void stringize(IntOrString &ios) {
    if(auto i = get_if<int>(&ios)) {
        ios = to_string(*i);
    }
}
int main() {
    IntOrString ios = 12;
    auto copy = ios;
    stringize(ios);
    cout << std::get<string>(ios) << '\n';
}
