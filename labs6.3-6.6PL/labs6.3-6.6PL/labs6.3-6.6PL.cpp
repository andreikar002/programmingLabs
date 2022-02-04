#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>

using namespace std;




//functions name:
void proc6_3();
void proc6_4();
void proc6_5();
void proc6_6();
void menu();




int main()
{
    while (1) {
        menu();
    }
}



//functions:
void menu() {
    cout << "\nWhat lab?(if you want to exit print 0)";
    int varios; cin >> varios;
    if (varios == 3)
        proc6_3();
    else if (varios == 4)
        proc6_4();
    else if (varios == 5)
        proc6_5();
    else if (varios == 6)
        proc6_6();
    else if (varios == 0)
        exit(0);
    else
        cout << "wrong number";
}
void proc6_3() {
    int n; cin >> n;
    deque<int> x2, x3, x5;
    x2.push_back(2);
    x3.push_back(3);
    x5.push_back(5);
    for (int i = 0; i < n; i++) {
        int min_n =  min(x2.front(), min(x3.front(), x5.front()));
        cout << min_n << " ";
        x2.push_back(min_n * 2);
        x3.push_back(min_n * 3);
        x5.push_back(min_n * 5);
        if (x2.front() == min_n)
            x2.pop_front();
        if (x3.front() == min_n)
            x3.pop_front();
        if (x5.front() == min_n)
            x5.pop_front();
    }
}

void proc6_4() {
    int n; cin >> n;
    set<int> attempts;
    int mas[2000]; // u can change number if u have more students
    for (int i = 0; i < n; i++) {
        int j; cin >> j;
        if (attempts.count(j)) {
            cin >> j;
        }
        else {
            int newJ; cin >> newJ;
            mas[j] = newJ;
            attempts.insert(j);
        }
    }
    for (auto i : attempts)
        cout << i << " " << mas[i] << " \n";
}

void proc6_5() {
    int n; cin >> n;
    list<pair<int, string>> mas;
    for (int i = 0; i < n; i++) {
        int j; cin >> j;
        string surname; cin >> surname;
        mas.push_back(make_pair(j, surname));
    }
    for (auto i : mas)
        cout << i.first << " " << i.second << "\n";
}

void proc6_6() {
    ifstream in("text.txt");//reading from file because it's more comfortable
    string text = "", str;
    while (getline(in, str))
        text += str;
    map<string, int> res;
    string slov = "";
    int sum = 0;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] != ' ') {
            slov += text[i];
        }
        else {
            res[slov]++;
            slov = "";
            sum++;
        }
        if (i == text.length() - 1) {
            res[slov]++;
            slov = "";
            sum++;
        }
    }
    for (auto it = res.cbegin(); it != res.cend(); it++) {
        cout << it->first << " " << double(it->second) / double(sum) * 100.0 << "% \n";
    }
}
