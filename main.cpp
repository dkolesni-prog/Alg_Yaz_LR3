#include <iostream>

#include <ctime>

#include <vector>

#include <string>

#include <iterator>
//1. В условии целочисленный массив из 10 элементов, у вас — из 9 с плавающей точкой. А обращаетесь к нему, будто элементов 10.
//2. Нет динамического выделения памяти, пытаетесь создать статический массив с неконстатным кол-вом элементов, причём для неинициализированной переменной.
//3. В чём смысл выводить "invalid input", если дальше программа работает, как ни в чём ни бывало?
//4. Не выполнено задание ЛР с 2.3 и далее

int main() {
    std::cout << "Задача 1" << std::endl;
    std::srand(std::time(0));
    int array1[10]; // Если массив будет целочисленным, то при делении на 2-й член могут получиться нули.
    std::cout << "THe initial array is ";
    for (int i = 0; i < 10; i++) {
        array1[i] = std::rand() % 21 - 10;
        std::cout << array1[i] << " ";
    }
    int denominator = array1[1];

    std::cout << std::endl << "The final array is ";
    for (int i = 0; i < 10; i++) {
        array1[i] = array1[i] / denominator;
        std::cout << array1[i] << " ";
    }
    std::cout << "\n" << "Задача 2" << std::endl;
    int n = 0;
    std::cout << "Determine the size of an array (n > 10)" << std::endl;
    std::cin >> n;
    int* array2 = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> array2[i];
    }

    std::cout << "The initial array is " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << array2[i] << " ";
    }

    for (int i = 0; i < n; i++) {
        if (array2[i] == 0) {
            array2[i] = array2[i] - 3;
        }
    }

    std::cout << std::endl << "The final array is " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << array2[i] << " ";
    }

    std::cout << std::endl << " Enter k1 and k2" << std::endl;
    int k1 = 0;
    int k2 = 0;
    float sum2 = 0;
    float arifm1 = 0;
    std::cin >> k1 >> k2;
    for (int i = k1; i <= k2; i++) {
        sum2 += array2[i];
    }
    arifm1 = sum2 / (abs(k1 - k2) + 1);
    std::cout << "arifm = " << arifm1 << std::endl;
    delete[]  array2;

    std::cout << std::endl << "Задача 3" << std::endl;
    int length = 0;
    std::cout << "Set length" << std::endl;
    std::cin >> length;
    std::vector < int > v1(length);
    std::cout << "set elements" << std::endl;

    for (int i = 0; i < length; i++) {
        std::cin >> v1[i];
    }
    for (int i = 0; i < length; i++) {
        std::cout << v1[i] << ' ';
    }
    std::cout << std::endl;
    v1.push_back(12);
    for (int i: v1) {
        std::cout << i << ' ';
    }
    int sum = 0;
    for (int i: v1) {
        sum = sum + i;
    }
    std::cout << std::endl << "The sum of all elements: " << sum << std::endl;
    v1.erase(v1.begin() + 0);
    for (int i: v1) {
        std::cout << i << " ";
    }
    std::cout << std::endl << "Задача 4" << std::endl;

    std::cout << "Enter string: " << std::endl;

    int lengthS = 0;
    std::string str1;
    std::cin >> str1;
    std::cout << str1 << std::endl;
    float value = 0;
    value = std::count(str1.begin(), str1.end(), '8');
    lengthS = str1.length();
    float share = value / lengthS * 100 ;
    std::cout << "The length is " << lengthS << std::endl;
    std::cout << "The share of 8 is : " << share << "%" << std::endl;
    std::cout << "Enter L1 and L2: " << std::endl;
    int L1 = 0;
    int L2 = 0;
    std::cin >> L1 >> L2;
    str1 = str1.substr(L1, L2-L1);
    std::cout << str1 << std::endl;

    std::string s("Can you can a can as a canner can can a can?");
    std::string word;
    std::cout << "Enter a substitution" << std::endl;
    std::cin >> word;
    while (s.find("can") != std::string::npos)
        s.replace(s.find("can"), 3, word);
    while (s.find("Can") != std::string::npos)
        s.replace(s.find("Can"), 3, word);

    std::cout << s << std::endl;

    return 0;
}
