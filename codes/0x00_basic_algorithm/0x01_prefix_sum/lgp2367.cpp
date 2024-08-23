#include<bits/stdc++.h>

int main()
{
    int n;std::cin >> n;
    std::vector<int> array(n), c(n);
    for (int& x : array)std::cin >> x;
    for (int i = 1; i < array.size(); i++)
        c[i] = array[i] - array[i - 1];
    for (int j : array)
    {
        std::cout << j << std::endl;
    }

    c[2] += 2;

    for (int i = 1; i < array.size(); i++)
        array[i] = array[i - 1] + c[i];
    for (int j : array)
    {
        std::cout << j << std::endl;
    }
}