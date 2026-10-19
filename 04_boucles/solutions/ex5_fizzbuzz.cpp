#include <iostream>

int main() {
    for (int i = 1; i <= 100; i++) {
        // On teste "multiple de 15" EN PREMIER : sinon un multiple de 15
        // serait capturé par le test "multiple de 3" et afficherait "Fizz".
        if (i % 15 == 0) {
            std::cout << "FizzBuzz\n";
        } else if (i % 3 == 0) {
            std::cout << "Fizz\n";
        } else if (i % 5 == 0) {
            std::cout << "Buzz\n";
        } else {
            std::cout << i << "\n";
        }
    }
    return 0;
}
