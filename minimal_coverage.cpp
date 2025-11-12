#include <bits/stdc++.h>
using namespace std;

struct Seg
{
    int L, R;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;

    cin >> T;

    for (int tc = 0; tc < T; ++tc)
    {
        int M;
        cin >> M;

        vector<Seg> segs;
        while (true)
        {
            int L, R;
            cin >> L >> R;
            if (L == 0 && R == 0)
                break;
            segs.push_back({L, R});
        }

            vector<Seg> answer;
        int cur = 0; // início da região já coberta
        int i = 0, n = (int)segs.size();

        while (cur < M)
        {
            int bestR = cur;
            int bestIdx = -1;

            // considere todos com L <= cur e pegue o que mais avança R
            while (i < n && segs[i].L <= cur)
            {
                if (segs[i].R > bestR)
                {
                    bestR = segs[i].R;
                    bestIdx = i;
                }
                ++i;
            }

            if (bestIdx == -1)
            { // não há segmento começando antes/igual ao cur
                answer.clear();
                break;
            }

            answer.push_back(segs[bestIdx]);
            cur = bestR;
        }

        if (tc)
            cout << "\n"; // linha em branco entre casos
        if (answer.empty() || answer.back().R < M)
        {
            cout << 0 << "\n"; // não cobriu [0, M]
        }
        else
        {
            // saída pede: primeiro a quantidade, depois os segmentos por L
            sort(answer.begin(), answer.end(),
                 [](const Seg &a, const Seg &b)
                 { return a.L < b.L; });
            cout << (int)answer.size() << "\n";
            for (auto &s : answer)
                cout << s.L << " " << s.R << "\n";
        }
    }
    return 0;
}
