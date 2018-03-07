#include <iostream>
#include <vector>

using namespace std;

int search(int item, vector<int> items);

int main()
{
    vector<int> numbers;
    for (int i = 1; i <= 100; ++i) {
        numbers.push_back(i);
    }

    cout << search(15, numbers) + 1;

    return 0;
}

/* Logaritmikus keres�s:
    *rendezett sorozaton (t�mb, vektor) m�k�dik
    *az �sszehasonl�t�sok sz�ma legfeljebb log2n (n az elemsz�m), innen kapta a nev�t
*/
int search(int item, vector<int> items) {

    int lowerBound = 0;
    int upperBound = items.size();
    int ind;
    bool found;

    int steps = 0;

    while (!found && lowerBound <= upperBound) {
        steps++;
        ind = (lowerBound + upperBound) / 2;

        if (items[ind] < item) {
            lowerBound = ind + 1;
        } else if (items[ind] > item) {
            upperBound = ind - 1;
        } else {
            found = true;
        }
    }

    cout << "Steps: " << steps << endl;

    return found ? ind : -1;
}
