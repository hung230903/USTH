/*
    Pseudo code: 
        Function Calculate(n)
            if n == 0 do
                return 0
            else
                return n % 10 + Calculate(n / 10)
        Funciton main()
            read n from the user

            result <- Calculate(n)
            print the result

    Complexity: O(logn)
*/


#include <bits/stdc++.h>

using namespace std;

int Calculate(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n % 10 + Calculate(n / 10);
    }
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    int result = Calculate(n);
    cout << "Sum of the digit = " << result;
}