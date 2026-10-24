class Solution {
public:
    vector<int> dateToInt (string date) {
        int mm = stoi(date.substr(0,2));
        int dd = stoi(date.substr(3,5));

        return {dd, mm};
    }

    vector<int> startDate (string arriveAlice, string arriveBob) {
        vector<int> alice = dateToInt (arriveAlice);
        vector<int> bob = dateToInt (arriveBob);

        if (alice[1] > bob[1]) return alice;
        if (alice[1] < bob[1]) return bob;

        return {max(alice[0], bob[0]), alice[1]};
    }

    vector<int> endDate (string leaveAlice, string leaveBob) {
        vector<int> alice = dateToInt (leaveAlice);
        vector<int> bob = dateToInt (leaveBob);

        if (alice [1] < bob[1]) return alice;
        if (bob[1] < alice[1]) return bob;

        return {min(alice[0], bob[0]), alice[1]};
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> start = startDate(arriveAlice, arriveBob);
        vector<int> end = endDate(leaveAlice, leaveBob);

        if (start[1] > end[1] || ((start[1] == end[1]) && (start[0] > end[0]))) return 0;

        vector<int> daysInMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (start[1] == end[1]) {
            return end[0] - start[0] + 1;
        }

        int totalDays = daysInMonth[start[1]] - start[0] + 1;

        for (int m=start[1] + 1; m<end[1]; m++) {
            totalDays += daysInMonth[m];
        }

        totalDays += end[0];

        return totalDays;
    }
};