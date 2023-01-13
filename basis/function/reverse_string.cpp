#include <bits/stdc++.h>

std::string reverse(std::string str)
{
	if (str.length() == 0)
	{
		return ""; // Return an empty string if the input string is empty
	}
	else
	{
		return reverse(str.substr(1)) + str[0]; // Recursively call the reverse function with the substring starting at index 1, and append the first character to the result
	}
}

int main()
{
	std::string result = reverse("Hello, world!"); // The result will be "!dlrow ,olleH"
	std::cout << result << std::endl;
	return 0;
}
