#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void viterbi(vector<vector<double>> &transition_probs, vector<vector<double>> &emission_probs, vector<int> &observations)
{
    int num_states = transition_probs.size();
    int num_observations = observations.size();
    vector<vector<double>> viterbi(num_states, vector<double>(num_observations));
    vector<vector<int>> path(num_states, vector<int>(num_observations));
    // Initialize base case
    for (int s = 0; s < num_states; s++)
    {
        viterbi[s][0] = emission_probs[s][observations[0]] * 1; // Start with initial probability
        path[s][0] = s;
    }
    // Run Viterbi for t > 0
    for (int t = 1; t < num_observations; t++)
    {
        for (int s = 0; s < num_states; s++)
        {
            double max_prob = 0;
            int max_state = 0;
            for (int prev_s = 0; prev_s < num_states; prev_s++)
            {
                double prob = viterbi[prev_s][t - 1] * transition_probs[prev_s][s] * emission_probs[s][observations[t]];
                if (prob > max_prob)
                {
                    max_prob = prob;
                    max_state = prev_s;
                }
            }
            viterbi[s][t] = max_prob;
            path[s][t] = max_state;
        }
    }
    // Find the final most likely state
    double max_prob = 0;
    int final_state = 0;
    for (int s = 0; s < num_states; s++)
    {
        if (viterbi[s][num_observations - 1] > max_prob)
        {
            max_prob = viterbi[s][num_observations - 1];
            final_state = s;
        }
    }
    cout << "Most likely final state: " << final_state << endl;
    cout << "Probability: " << max_prob << endl;

    // Backtrack to find the most likely sequence of states
    vector<int> most_likely_seq;
    int state = final_state;
    for (int t = num_observations - 1; t >= 0; t--)
    {
        most_likely_seq.push_back(state);
        state = path[state][t];
    }
    reverse(most_likely_seq.begin(), most_likely_seq.end());
    cout << "Most likely sequence of states: [";
    for (int i = 0; i < most_likely_seq.size(); i++)
    {
        cout << most_likely_seq[i] << ", ";
    }
    cout << "]";
}

void test_viterbi()
{
    // Test case 1
    vector<vector<double>> transition_probs = {{0.7, 0.3}, {0.4, 0.6}};
    vector<vector<double>> emission_probs = {{0.1, 0.4, 0.5}, {0.7, 0.2, 0.1}};
    vector<int> observations = {0, 1, 2};
    viterbi(transition_probs, emission_probs, observations);
    cout << endl;

    // Test case 2
    // Add more test cases with different inputs and edge cases
}

int main()
{
    test_viterbi();
    return 0;
}
