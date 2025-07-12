#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <tuple>
using namespace std;

map<char, int> CARD_VALUES = {
    {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6},
    {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10},
    {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}
};

// Retorna se é sequência (straight)
bool is_straight(const vector<int>& values) {
    vector<int> v = values;
    sort(v.begin(), v.end());
    for (int i = 1; i < 5; ++i)
        if (v[i] != v[i - 1] + 1)
            return false;
    return true;
}

// Retorna se é flush (mesmo naipe)
bool is_flush(const vector<string>& hand) {
    char suit = hand[0][1];
    for (const auto& card : hand)
        if (card[1] != suit)
            return false;
    return true;
}

// Retorna o rank da mão como vetor de inteiros (para comparação)
vector<int> hand_rank(const vector<string>& hand) {
    vector<int> values;
    map<int, int> counts;
    for (const auto& c : hand) {
        int val = CARD_VALUES[c[0]];
        values.push_back(val);
        counts[val]++;
    }

    sort(values.rbegin(), values.rend()); // decrescente

    vector<pair<int, int>> count_values;
    for (const auto& [val, count] : counts)
        count_values.emplace_back(count, val);
    sort(count_values.rbegin(), count_values.rend());

    bool flush = is_flush(hand);
    bool straight = counts.size() == 5 && is_straight(values);
    int high = *max_element(values.begin(), values.end());

    if (straight && flush)
        return {8, high};

    if (count_values[0].first == 4)
        return {7, count_values[0].second, count_values[1].second};

    if (count_values[0].first == 3 && count_values[1].first == 2)
        return {6, count_values[0].second, count_values[1].second};

    if (flush)
        return {5, values[0], values[1], values[2], values[3], values[4]};

    if (straight)
        return {4, high};

    if (count_values[0].first == 3) {
        vector<int> kickers;
        for (int v : values)
            if (v != count_values[0].second) kickers.push_back(v);
        return {3, count_values[0].second, kickers[0], kickers[1]};
    }

    if (count_values[0].first == 2 && count_values[1].first == 2) {
        int high_pair = max(count_values[0].second, count_values[1].second);
        int low_pair = min(count_values[0].second, count_values[1].second);
        int kicker = 0;
        for (int v : values)
            if (v != high_pair && v != low_pair) kicker = v;
        return {2, high_pair, low_pair, kicker};
    }

    if (count_values[0].first == 2) {
        vector<int> kickers;
        for (int v : values)
            if (v != count_values[0].second) kickers.push_back(v);
        return {1, count_values[0].second, kickers[0], kickers[1], kickers[2]};
    }

    return {0, values[0], values[1], values[2], values[3], values[4]};
}

// Função principal que conta as vitórias do Jogador 1
int player1_wins(const vector<vector<string>>& hands) {
    int wins = 0;
    for (const auto& line : hands) {
        vector<string> h1(line.begin(), line.begin() + 5);
        vector<string> h2(line.begin() + 5, line.end());
        if (hand_rank(h1) > hand_rank(h2))
            wins++;
    }
    return wins;
}


int main() {
    ifstream file("poker.txt");
    string card;
    vector<vector<string>> hands;

    while (file) {
        vector<string> line;
        for (int i = 0; i < 10 && file >> card; ++i)
            line.push_back(card);
        if (line.size() == 10)
            hands.push_back(line);
    }

    int result = player1_wins(hands);
    cout << "Jogador 1 vence: " << result << " mãos" << endl;
    return 0;
}
