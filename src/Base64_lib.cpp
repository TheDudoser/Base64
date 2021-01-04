#include <iostream>
#include <vector>
#include "Base64_lib.h"

using namespace std;

const string Base64Table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

vector<int> gettingIndex (string message) {
    int count_iteration = 0;
    int add_count = 0;
    int byte;
    int first, second, third;
    vector<int> result;

    if ((message.size() % 3) != 0) {
        add_count = (message.size() % 3);
        count_iteration = (message.size() - add_count) / 3;
    } else
        count_iteration = message.size()/3;

    for (int i = 0; i < count_iteration; ++i) {
        first = (int)message[i*3];
        second = (int)message[i*3 + 1];
        third = (int)message[i*3 + 2];

        first = first >> 2;
        result.push_back(first);
        first = (int)message[i*3];

        byte = ((first & 3) << 4) | (second >> 4);
        result.push_back(byte);

        second = (int)message[i*3 + 1];
        byte = ((second & 15) << 2) | (third >> 6);
        result.push_back(byte);

        byte = third & 63;
        result.push_back(byte);
    }

    if (add_count == 1) {
        first = (int)message[message.size() - add_count] >> 2;
        result.push_back(first);

        first = (int)message[message.size() - add_count];
        second = first & 3;
        byte = second << 4;
        result.push_back(byte);

        result.push_back(64);
        result.push_back(64);
    }

    if (add_count == 2) {
        first = (int)message[message.size() - add_count];
        first = first >> 2;
        result.push_back(first);

        byte = ((((int)message[message.size() - add_count]) & 3) << 4) | ((int)message[message.size() - add_count + 1] >> 4);
        result.push_back(byte);

        byte = ((((int)message[message.size() - add_count + 1]) & 15) << 2);
        result.push_back(byte);

        result.push_back(64);
    }
    return result;
}

string codingMessage (vector<int> input, string message) {
    input = gettingIndex(message);
    //Интерпритация индексов
    char* result = new char[input.size()];
    for (int i = 0; i < input.size(); ++i) {
        result[i] = Base64Table[input[i]];
    }
    result[input.size()] = '\0';
    return result;
}

string getDeccoding (vector<int> message) {
    int count_iteration = 0;
    int add_count = 0;
    int byte;
    int first, second, third, fourth;
    vector<int> result;
    char* res = new char[message.size()];

    if (message[message.size() - 1] == 64) {
        if (message[message.size() - 2] == 64)
            add_count = 2;
        else add_count = 1;
        count_iteration = (message.size() - add_count) / 4;
    } else
        count_iteration = message.size()/4;

    for (int i = 0; i < count_iteration; ++i) {
        first = message[i*4];
        second = message[i*4 + 1];
        third = message[i*4 + 2];
        fourth = message[i*4 + 3];

        first = first << 2;
        second = ((second) >> 4)& 3;
        first = first | second;
        result.push_back(first);
        second = message[i*4 + 1];

        byte = (((second & 15) << 4)) | ((third >> 2));
        result.push_back(byte);

        byte = ((third & 3) << 6) | (fourth);
        result.push_back(byte);
    }

    if (add_count == 2) {
        first = message[message.size() - add_count - 2];
        second = message[message.size() - add_count - 1];
        byte = ((first & 63) << 2) | (second >> 4);
        result.push_back(byte);
    }

    if (add_count == 1) {
        first = message[message.size() - add_count - 3];
        second = message[message.size() - add_count - 2];
        third = message[message.size() - add_count - 1];
        byte = ((first & 63) << 2) | (second >> 4);
        result.push_back(byte);

        byte = (((second & 15) << 4)) | ((third >> 2));
        result.push_back(byte);
    }
    for (int i = 0; i < result.size(); ++i) {
        res[i] = (char)result[i];
    }
    res[result.size()] = '\0';
    return res;
}

vector<int> getNumberForDecoding (string input) {
    vector<int> result;
    int k;
    for (int i = 0; i < input.size(); ++i) {
        k = 0;
        while (input[i] != Base64Table[k])
            ++k;
        result.push_back(k);
    }

    return result;
}

string DecodingMessage(string message) {
    vector<int> vec;
    vec = getNumberForDecoding(message);
    message = getDeccoding(vec);
    return message;
}