#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype> 

using namespace std;

int countPunctuation(const string& text) {
    int count = 0;
    for (size_t i = 0; i < text.length(); ++i) {
        if (ispunct(text[i])) {
            ++count;
        }
    }
    return count;
}

void findEvenLengthWords(const string& text, vector<string>& evenWords) {
    stringstream ss(text);
    string word;
    while (ss >> word) {
        if (word.length() % 2 == 0) {
            evenWords.push_back(word);
        }
    }
}

string swapFirstLastCharacter(const string& word) {
    if (word.length() <= 1) return word;

    string swapped = word;
    swap(swapped[0], swapped[swapped.size() - 1]);
    return swapped;
}

void printResults(const string& content, int punctuationCount, const vector<string>& evenWords, const string& swappedText) {
    // Виведення результатів на консоль
    cout << "Original Content:\n" << content << "\n\n";
    cout << "Punctuation Count: " << punctuationCount << "\n\n";
    cout << "Even Length Words: ";
    for (const string& word : evenWords) {
        cout << word << " ";
    }
    cout << "\n\n";
    cout << "Swapped Text: " << swappedText << "\n";
}

void writeFile(const char* outputFile, const string& content, int punctuationCount, const vector<string>& evenWords, const string& swappedText) {
    ofstream out(outputFile);

    out << "Original Content:\n" << content << "\n\n";
    out << "Punctuation Count: " << punctuationCount << "\n\n";
    out << "Even Length Words: ";
    for (size_t i = 0; i < evenWords.size(); ++i) {
        out << evenWords[i] << " ";
        // В середині циклу, кожне слово записується в файл
    }
    out << "\n\n";
    out << "Swapped Text: " << swappedText << "\n";

    out.close();
    
}

int main() {
    const char* inputFile = "input.txt";
    // Оголошення та ініціалізація вказівника на char, який вказує на рядок, що містить назву вхідного файлу
    const char* outputFile = "output.txt";

    ifstream in(inputFile);
    stringstream buffer;
    buffer << in.rdbuf();
    string content = buffer.str();

    int punctuationCount = countPunctuation(content);

    vector<string> evenWords;
    findEvenLengthWords(content, evenWords);

    stringstream ss(content);
    // обробка кожного слова
    string word, swappedText;
    while (ss >> word) {
        swappedText += swapFirstLastCharacter(word) + " ";
    }

    in.close();


    printResults(content, punctuationCount, evenWords, swappedText);

    
    writeFile(outputFile, content, punctuationCount, evenWords, swappedText);

    return 0;
}
