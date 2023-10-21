#include "JSimple.hpp"

void Print(string String)
{
    cout << String;
}

string GetInput()
{
    string userInput;
    cin >> userInput;
    return userInput;
}

string CreateInput(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

vector<string> ReadFileToList(const string& filename) {
    vector<string> lines;

    ifstream file(filename);
    if (!file.is_open()) {
        return lines;
    }

    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();

    return lines;
}

string ReadFileToString(const string& filename) {
    string lines;

    ifstream file(filename);
    if (!file.is_open()) {
        return lines;
    }

    string line;
    while (getline(file, line)) {
        lines = lines + "\n" + line;
    }

    file.close();

    return lines;
}

template <typename T>
void WriteToFile(const string& filename, const T& data) {
    ofstream outFile(filename, ios::app);
    if (!outFile.is_open()) {
        return;
    }

    outFile << data << endl;
    outFile.close();
}

string ListToString(vector<string> stringList) {
    string result;

    for (const string& str : stringList) {
        result += str;
    }

    return result;
}

vector<char> StringToListChars(string Input) {
    vector<char> Chars;
    istringstream iss(Input);
    char Char;

    while (iss >> Char) {
        Chars.push_back(Char);
    }

    return Chars;
}

vector<string> StringToListWords(string Input) {
    vector<string> Words;
    istringstream iss(Input);
    string Word;

    while (iss >> Word) {
        Words.push_back(Word);
    }

    return Words;
}


float RandomFloat(float min, float max) {
    random_device rd;
    mt19937 gen(rd());

    uniform_real_distribution<float> distribution(min, max);

    float random_number = distribution(gen);

    return random_number;
}

int RandomInt(int min, int max) {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distribution(min, max);

    int random_number = distribution(gen);

    return random_number;
}

string ToLowerCase(string stringIn)
{
    string lowerString;
    
    for (char& c : stringIn) {
        c = tolower(c);
        lowerString = lowerString + c;
    }

    return lowerString;
}

string ToUpperCase(string stringIn)
{
    string upperString;

    for (char& c : stringIn) {
        c = toupper(c);
        upperString = upperString + c;
    }

    return upperString;
}

float CompareStringByChar(const string& string1, const string& string2) { // Broken: Always returns 100.0
    vector<char> string1Chars(string1.begin(), string1.end());
    vector<char> string2Chars(string2.begin(), string2.end());

    int matchingChars = 0;

    for (char c1 : string1Chars) {
        for (char c2 : string2Chars) {
            if (c1 == c2) {
                matchingChars++;
                break;
            }
        }
    }

    float similarityPercent = (2.0f * matchingChars) / (string1.size() + string2.size()) * 100.0f;
    return similarityPercent;
}

float CompareStringByWord(const string& string1, const string& string2) { // Broken: Always returns 100.0
    vector<string> words1 = StringToListWords(string1);
    vector<string> words2 = StringToListWords(string2);

    int commonWords = 0;

    for (const string& word1 : words1) {
        for (const string& word2 : words2) {
            if (word1 == word2) {
                commonWords++;
                break;
            }
        }
    }

    float similarityPercent = (2.0f * commonWords) / (words1.size() + words2.size()) * 100.0f;
    return similarityPercent;
}

string ReverseString(string Input) {
    string Reversed;

    for (int i = Input.length() - 1; i >= 0; i--) {
        Reversed += Input[i];
    }

    return Reversed;
}

wstring ToWideString(string Input) { // https://gist.github.com/danzek/d6a0e4a48a5439e7f808ed1497f6268e
    vector<wchar_t> buf(Input.size());
    use_facet<ctype<wchar_t>>(locale()).widen(Input.data(),
        Input.data() + Input.size(),
        buf.data());
    return wstring(buf.data(), buf.size());
}

bool IsPrime(int Number) {
    if (Number <= 1) {
        return false;
    }

    for (int i = 2; i * i <= Number; i++) {
        if (Number % i == 0) {
            return false;
        }
    }

    return true;
}