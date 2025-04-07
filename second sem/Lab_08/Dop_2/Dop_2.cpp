#include <iostream>
#include <queue>

using namespace std;

double findmax(const queue<double>& q) {
    queue<double>temp = q;
    double maxe;
    maxe = temp.front();
    temp.pop();
    while (!temp.empty()) {
        if (maxe < temp.front()) {
            maxe = temp.front();
        }
        temp.pop();
    }
    return(maxe);
}

void circle(const queue<double>& q, double max) {
    queue<double>temp = q;
    double e;
    while (temp.front() != max) {
        e = temp.front();
        temp.push(e);
        temp.pop();
    }
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
}

int main() {
    system("chcp 1251");
    queue<double> q;
    cout << "Введите размер очереди: " << endl;
    int n;
    cin >> n;
    cout << "Введите очередь: " << endl;
    for (int i = 0; i < n; i++) {
        double e;
        cin >> e;
        q.push(e);
    }
    double max;
    max = findmax(q);
    cout << "max: " << max << endl;
    circle(q, max);

}
