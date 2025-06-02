#include "header.h"


bool IsDigits(std::string& word)
{
    for (size_t i{}; i < word.size(); ++i)
    {
        char c = word[i];
        if (c < '0' || c > '9')
        {
            return false;
        }
    }
    return true;
}

bool IsLetters(std::string& word)
{
    for (size_t i{}; i < word.size(); ++i)
    {
        char c = word[i];
        if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z'))
        {
            return false;
        }
    }
    return true;
}

std::string CheckWord(std::string& word)
{
    if (IsDigits(word))
    {
        if (word.size() < 5)
        {
            return std::string(10 - word.size(), '0') + word;
        }
        else
        {
            return word;
        }
    }
    else if (IsLetters(word))
    {
        std::string reversed;
        for (int32_t i = word.size() - 1; i >= 0; --i)
        {
            reversed += word[i];
        }
        return reversed;
    }
    else
    {
        return "";
    }
}

std::string ResultString(std::string& input)
{
    std::string result;
    std::string word;
    bool firstWord{ true };

    for (size_t i{}; i < input.size(); ++i)
    {
        if (input[i] == ' ')
        {
            if (!word.empty())
            {
                if (!firstWord)
                {
                    result += " ";
                }
                firstWord = false;
                result += CheckWord(word);
                word.clear();
            }
        }
        else
        {
            word += input[i];
        }
    }
    if (!word.empty())
    {
        if (!firstWord)
        {
            result += " ";
        }
        result += CheckWord(word);
    }

    return result;
}

void InputString(std::string& input)
{
    std::cout << "Input string: ";
    std::getline(std::cin, input);
    if (input.empty())
    {
        throw std::invalid_argument("Impossible to complete. Sentence is empty\n");
    }
}
