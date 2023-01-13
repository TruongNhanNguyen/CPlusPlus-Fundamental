#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> m{{"foo", 10}, {"bar", 20}, {"baz", 30}};

    // Insert and remove elements
    m["qux"] = 40;  // m: { { "foo", 10 }, { "bar", 20 }, { "baz", 30 }, { "qux", 40 } }
    m.erase("bar"); // m: { { "foo", 10 }, { "baz", 30 }, { "qux", 40 } }

    // Lookup elements
    std::cout << m["foo"] << std::endl;                         // Prints 10
    std::cout << std::boolalpha << m.count("bar") << std::endl; // Prints "false"

    // Iterate over the elements
    for (const auto &[key, value] : m)
    {
        std::cout << key << ": " << value << std::endl;
        // Prints "foo: 10"
        //         "baz: 30"
        //         "qux: 40"
    }

    return 0;
}
