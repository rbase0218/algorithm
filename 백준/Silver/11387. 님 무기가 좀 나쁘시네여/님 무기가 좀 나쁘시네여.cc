#include <iostream>
#include <vector>
using namespace std;

int getPower(vector<int> status)
{
	double attackPoint = status[0];
	double strengthPoint = status[1];
	double criticalPercent = status[2] / 100.0;    
	double criticalDamageRatio = status[3] / 100.0;
	double attackSpeedPercent = status[4] / 100.0;
	double cappedCrit = min(criticalPercent, 1.0);

	return attackPoint * (1 + (strengthPoint / 100)) * ((1 - cappedCrit) + (cappedCrit * criticalDamageRatio)) * (1 + attackSpeedPercent);
}

int main() {
    vector<vector<int>> stat(4, vector<int>(5));
    for (int i = 0; i < 4; ++i) 
    {
        for (int j = 0; j < 5; ++j) 
            cin >> stat[i][j];
    }

    vector<int> creeNew(5);
    for (int i = 0; i < 5; ++i)
        creeNew[i] = stat[0][i] - stat[2][i] + stat[3][i];

    vector<int> pabuNew(5);
    for (int i = 0; i < 5; ++i)
        pabuNew[i] = stat[1][i] - stat[3][i] + stat[2][i];

    auto compare = [](long double oldP, long double newP) {
        if (newP > oldP) return "+";
        else if (newP < oldP) return "-";
        else return "0";
        };

    cout << compare(getPower(stat[0]), getPower(creeNew)) << "\n";
    cout << compare(getPower(stat[1]), getPower(pabuNew));

    return 0;
}