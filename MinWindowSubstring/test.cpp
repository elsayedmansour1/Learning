#include <iostream>
#include <set>
#include <utility> // For std::pair

int main() {
    // Declare a multiset of std::pair<int, std::string>
    // The first element of the pair (int) will be the "key" for ordering
    // The second element (std::string) will be the "value"
    std::multiset<std::pair<int, std::string>> myMultiset;

    // Insert elements
    myMultiset.insert({10, "f"});
    myMultiset.insert({5, "a"});
    myMultiset.insert({10, "d"}); // Duplicate key allowed in multiset
    myMultiset.insert({20, "a"});

    // Iterate and print
    std::cout << "Elements in multiset:" << std::endl;
    for (const auto& element : myMultiset) {
        std::cout << "Key: " << element.first << ", Value: " << element.second << std::endl;
    }

    // Find elements by key (first element of the pair)
    auto range = myMultiset.equal_range({10, ""}); // Value can be anything for comparison
    std::cout << "\nElements with key 10:" << std::endl;
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }

    return 0;
}