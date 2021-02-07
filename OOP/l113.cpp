#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Stack {
private:
    using num_t = int;
    vector<num_t> m_st{};
    size_t m_size = 0;

public:
    Stack() = default;

    void reset() {
        m_size = 0;
    }

    void print() {
        cout << "( ";

        for (const auto &e : m_st) {
            cout << e << ' ';
        }

        cout << " )\n";
    }

    void push(const num_t &elem) {
        m_st.push_back(elem);
        m_size++;
    }

    void pop() {
        assert(m_size > 0 && "Empty stack\n");

        m_st.pop_back();
        m_size--;
    }

    num_t top() const {
        assert(m_size > 0 && "Empty stack\n");

        return m_st[m_st.size() - 1];
    }
};

int main() {
    Stack stack;
    stack.reset();

    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}