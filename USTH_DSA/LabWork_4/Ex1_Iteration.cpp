/*
    Pseudo code: 
        Function Calculate(n)
            sum <- 0
            temp <- n
            while temp > 0 do
                sum <- sum + (temp % 10)
                temp <- 10
            return sum

        Funciton main()
            read n from the user

            result <- Calculate(n)
            print the result

    Complexity: O(logn)
*/

#include <bits/stdc++.h>

using namespace std;

int Calculate(int n) {
    int sum = 0;
    int temp = n;

    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }

    return sum;
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    int result = Calculate(n);
    cout << "Sum of the digit =  " << result;
}