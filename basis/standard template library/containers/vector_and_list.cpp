#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::vector<int> v{10, 20, 30};
    v.push_back(40); // v: { 10, 20, 30, 40 }
    v.pop_back();    // v: { 10, 20, 30 }
    v[1] = 25;       // v: { 10, 25, 30 }

    std::list<int> l{10, 20, 30};
    l.push_back(40);           // l: { 10, 20, 30, 40 }
    l.pop_back();              // l: { 10, 20, 30 }
    l.push_front(5);           // l: { 5, 10, 20, 30 }
    l.pop_front();             // l: { 10, 20, 30 }
    l.insert(++l.begin(), 15); // l: { 10, 15, 20, 30 }
    l.erase(--l.end());        // l: { 10, 15, 30 }

    return 0;
}
