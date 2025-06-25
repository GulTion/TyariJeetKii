#include <iostream>
#include <vector>
#include <algorithm>

int count_operations_to_zero(int n) {
    if (n == 0) {
        return 0;
    }

    int operations = 0;
    while (n > 0) {
        n /= 2;
        operations++;
    }
    return operations;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    int M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    int max_eligible_element = 0;

    for (int current_element : A) {
        int ops_needed = count_operations_to_zero(current_element);
        if (ops_needed == M) {
            max_eligible_element = std::max(max_eligible_element, current_element);
        }
    }

    std::cout << max_eligible_element << std::endl;

    return 0;
}
