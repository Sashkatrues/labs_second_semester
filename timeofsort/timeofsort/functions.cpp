#include "header.h"

bool operator<(const Student& arr, const Student& b)
{
    if (arr.course == b.course)
    {
        if (arr.group == b.group)
        {

            return arr.group < b.group;
        }
        else
        {
            return arr.name < b.name;
        }
    }
    return arr.course < b.course;

}
bool operator>(const Student& arr, const Student& b)
{
    if (arr.course == b.course)
    {
        if (arr.group == b.group)
        {

            return arr.group > b.group;
        }
        else
        {
            return arr.name > b.name;
        }
    }
    return arr.course > b.course;
}
bool operator==(const Student& arr, const Student& b)
{
    return arr.course == b.course && arr.group == b.group && arr.name == b.name;
}
bool operator<<(std::ostream& out, const Student& arr)
{
    out << arr.name << ';' << arr.group << ';' << arr.course << '\t';
    return 0;
}

void InputChoice(int32_t& choice)
{
    std::cout << "input choice: 1 - direct input and output to file;\n2 - generation of data random and output to file;\n3 - input from file and output to console\n";
    std::cin >> choice;
}
void InputSize(int32_t& size)
{
    std::cout << "input size\n";
    std::cin >> size;
    if (size < 0 || size > 1001)
    {
        throw std::invalid_argument("false size\n");
    }
}
void InputType(char& type)
{
    std::cout << "input type of data: i - int; d - double; c - char; s - string; S - student\n";
    std::cin >> type;

}
void InputFileName(std::string& fileName)
{
    std::cin.ignore();
    std::cout << "input name of file\n";
    getline(std::cin, fileName);
}
bool ChouseSort()
{
    bool sort;
    std::cout << "Choose type of sort: 1 - ascending 0 - descending\n";
    std::cin >> sort;
    return sort;
}
void ChouseTypeOfSort(int32_t& typeOfSort)
{
    std::cout << "input type of sort: 1 - bubblesort;\n2 - combsort;\n3 - insertionsort;\n4 - selectionsort;\n5 - quicksort;\n"
        << "6 - mergesort;\n7 - cocktailsort;\n8 - countsort;\n9 - bogosort\n";
    std::cin >> typeOfSort;
}

void ChouseType(char type)
{
    switch (type)
    {
    case 'i':
    {
        int32_t* arr = NULL;
        int32_t choice{};
        InputChoice(choice);
        ChouseInputAndOutput(choice, arr);
        break;
    }
    case 'd':
    {
        double* arr = NULL;
        int32_t choice{};
        InputChoice(choice);
        ChouseInputAndOutput(choice, arr);
        break;
    }
    case 'c':
    {
        char* arr = NULL;
        int32_t choice{};
        InputChoice(choice);
        ChouseInputAndOutput(choice, arr);
        break;
    }
    case 's':
    {
        std::string* arr = NULL;
        int32_t choice{};
        InputChoice(choice);
        ChouseInputAndOutput(choice, arr);
        break;
    }
    case 'S':
    {
        Student* arr = NULL;
        int32_t choice{};
        InputChoice(choice);
        ChouseInputAndOutput(choice, arr);
        break;
    }
    default:
    {
        throw std::invalid_argument("false type of data\n");
        break;
    }
    }
}

void ShowArray(Student* arr, int32_t size)
{
    for (int32_t i{}; i < size; ++i)
    {
        std::cout << "course: " << arr[i].course << " group: " << arr[i].group << " full name: " << arr[i].name << " grades: ";
        for (int32_t j{}; j < 3; ++j)
        {
            std::cout << arr[i].grades[j] << " ";
        }
        std::cout << "\n";
    }
}

int32_t CountSize(std::string* arr, std::string& fileName)
{
    std::ifstream fin(fileName);
    std::string element;
    int32_t count{};
    while (getline(fin, element))
    {
        ++count;
    }
    fin.close();
    return count;
}
int32_t CountSize(Student* arr, std::string& fileName)
{
    std::ifstream fin(fileName);
    std::string element;
    int32_t count{};
    while (getline(fin, element))
    {
        ++count;
    }
    fin.close();
    return count;
}

void InputFromConsole(Student* arr, int32_t size) {
    for (int32_t i{}; i < size; ++i)
    {
        std::cout << "student" << i + 1 << "\ncourse: ";
        std::cin >> arr[i].course;
        std::cout << "group: ";
        std::cin >> arr[i].group;
        std::cin.ignore();
        std::cout << "full name: ";
        std::getline(std::cin, arr[i].name);
        std::cout << "grades (3): ";
        for (int32_t j{}; j < 3; ++j)
        {
            std::cin >> arr[i].grades[j];
        }
    }
}
void ReadFromFile(std::string& filename, Student* arr, int32_t size) {
    std::ifstream in(filename);
    for (int32_t i{}; i < size; ++i)
    {
        in >> arr[i].course >> arr[i].group;
        in.ignore();
        std::getline(in, arr[i].name, ' ');
        for (int32_t j{}; j < 3; ++j)
        {
            in >> arr[i].grades[j];
        }
    }
    in.close();
}
void WriteToFile(std::string& filename, Student* arr, int32_t size)
{
    std::ofstream out(filename);
    for (int32_t i{}; i < size; ++i)
    {
        out << arr[i].course << " " << arr[i].group << " " << arr[i].name << " ";
        for (int32_t j{}; j < 3; ++j)
        {
            out << arr[i].grades[j] << " ";
        }
        out << "\n";
    }
    out.close();
}

void InputInterval(int32_t& firstElement, int32_t& lastElement)
{
    std::cout << "Input first element in interval\n";
    std::cin >> firstElement;
    std::cout << "Input last element in interval\n";
    std::cin >> lastElement;
    if (firstElement > lastElement)
    {
        std::swap(firstElement, lastElement);
    }
    else if (firstElement == lastElement)
    {
        throw std::invalid_argument("Impossible to complete. Wrong interval\n");
    }
}
void InputInterval(double& firstElement, double& lastElement)
{
    std::cout << "Input first element in interval\n";
    std::cin >> firstElement;
    std::cout << "Input last element in interval\n";
    std::cin >> lastElement;
    if (firstElement > lastElement)
    {
        std::swap(firstElement, lastElement);
    }
    else if (firstElement == lastElement)
    {
        throw std::invalid_argument("Impossible to complete. Wrong interval\n");
    }
}
void InputInterval(char& firstElement, char& lastElement)
{
    std::cout << "Input first element in interval\n";
    std::cin >> firstElement;
    std::cout << "Input last element in interval\n";
    std::cin >> lastElement;
    if (firstElement > lastElement)
    {
        std::swap(firstElement, lastElement);
    }
    else if (firstElement == lastElement)
    {
        throw std::invalid_argument("Impossible to complete. Wrong interval\n");
    }
}

void GenerateRandom(int32_t* arr, int32_t size) {
    int32_t firstElement{};
    int32_t lastElement{};
    InputInterval(firstElement, lastElement);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int32_t>dist(firstElement, lastElement);
    for (int32_t i{}; i < size; ++i)
    {
        arr[i] = dist(gen);
    }
}
void GenerateRandom(double* arr, int32_t size) {
    double firstElement{};
    double lastElement{};
    InputInterval(firstElement, lastElement);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double>dist(firstElement, lastElement);
    for (int32_t i{}; i < size; ++i)
    {
        arr[i] = dist(gen);
    }
}
void GenerateRandom(char* arr, int32_t size) {
    char firstElement{};
    char lastElement{};
    InputInterval(firstElement, lastElement);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int32_t> dist(static_cast<int>(firstElement), static_cast<int>(lastElement));
    for (size_t i = 0; i < size; ++i)
    {
        arr[i] = static_cast<char>(dist(gen));
    }
}
void GenerateRandom(std::string* arr, int32_t size) {
    for (int32_t i = 0; i < size; ++i) {
        arr[i] = GenerateRandomStr();
    }
}
std::string GenerateRandomStr() {
    std::cout << "extrim values of length\n";
    int32_t firstElement{};
    int32_t lastElement{};
    InputInterval(firstElement, lastElement);
    std::cout << "extrim values of letters\n";
    char firstLetter{};
    char lastLetter{};
    InputInterval(firstLetter, lastLetter);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int32_t> dist(firstElement, lastElement);
    std::uniform_int_distribution<int32_t> char_dist(static_cast<int>(firstLetter), static_cast<int>(lastLetter));
    int32_t size{ dist(gen) };
    std::string word;
    word.reserve(size);
    for (int32_t i{}; i < size; ++i) {
        word += char_dist(gen);
    }
    return word;
}
void GenerateRandom(Student* arr, int32_t size) {
    int32_t firstElement{};
    int32_t lastElement{};
    InputInterval(firstElement, lastElement);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int32_t> dist(firstElement, lastElement);
    for (int32_t i{}; i < size; ++i)
    {
        arr[i].name = GenerateRandomStr();
        arr[i].course = dist(gen);
        arr[i].group = dist(gen);
        for (int32_t j{}; j < 3; ++j)
        {
            arr[i].grades[j] = dist(gen);
        }
    }
}
