#include <iostream>

using namespace std;

class IntPair {
private:
    using num_t = int;
    pair<num_t, num_t> m_p{};

public:
    IntPair() = default;

    IntPair(const num_t &x1, const num_t &x2) {
        m_p.first = x1;
        m_p.second = x2;
    }

    void set(const num_t &x1, const num_t &x2) {
        m_p.first = x1;
        m_p.second = x2;
    }

    void print() const {
        cout << "Pair(" << m_p.first << ", " << m_p.second << ")\n";
    }
};

int main() {
    IntPair p1;
    p1.set(1, 1); // set p1 values to (1, 1)

    IntPair p2{ 2, 2 }; // initialize p2 values to (2, 2)

    p1.print();
    p2.print();

    return 0;
}