#include <iostream>
#include <unordered_map>
#include <unordered_set>

int main()
{
    std::unordered_set<int> s{10, 20, 30};

    // Insert and remove elements
    s.insert(25); // s: { 10, 20, 25, 30 }
    s.erase(20);  // s: { 10, 25, 30 }

    // Lookup elements
    std::cout << std::boolalpha << s.count(10) << std::endl; // Prints "true"
    std::cout << std::boolalpha << s.count(20) << std::endl; // Prints "false"

    // Iterate over the elements
    for (int x : s)
    {
        std::cout << x << " "; // Prints "10 25 30"
    }
    std::cout << std::endl;

    std::unordered_map<std::string, int> m{{"foo", 10}, {"bar", 20}, {"baz", 30}};

    // Insert and remove elements
    m["qux"] = 40;                                              // m: { { "foo", 10 }, { "bar", 20 }, { "baz", 30 }, { "qux", 40 } }
    m.erase("bar");                                             // m: { { "foo", 10 }, { "baz", 30 }, { "qux", 40 } }
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
