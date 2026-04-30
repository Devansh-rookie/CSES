#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
// /**
//  * @brief Solves the Mario river crossing problem.
//  *
//  * @param A The width of the river.
//  * @param B Mario's maximum jump distance.
//  * @param C A vector containing the sizes of the M platforms.
//  * @return A vector representing the river layout, or {-1} if impossible.
//  */
// // std::vector<int> solve(int A, int B,  std::vector<int> C) {
// //     int M = C.size();

// //     // 1. Calculate total platform size and total gap space.
// //     long long sum_C = 0;
// //     for (int size : C) {
// //         sum_C += size;
// //     }

// //     // This case is prevented by problem constraints (sum(C) <= A), but is good practice.
// //     if (sum_C > A) {
// //         return {-1};
// //     }

// //     long long total_gap_space = A - sum_C;
// //     int num_gaps = M + 1;

// //     // 2. Check for impossibility.
// //     // Each of the M+1 gaps can have a size of at most B-1.
// //     // If the total required gap space is more than this, it's impossible.
// //     long long max_possible_total_gap = (long long)num_gaps * (B - 1);
// //     if (B == 0 && total_gap_space > 0) { // Can't jump at all if there are gaps.
// //          return {-1};
// //     }
// //     if (B > 0 && total_gap_space > max_possible_total_gap) {
// //         return {-1};
// //     }

// //     // 3. Greedily determine gap sizes for the lexicographically smallest result.
// //     // To push platforms right, maximize gaps from left to right.
// //     std::vector<long long> gaps(num_gaps, 0);
// //     long long remaining_gap_space = total_gap_space;
// //     long long max_single_gap_size = (B > 0) ? (B - 1) : 0;

// //     for (int i = 0; i < num_gaps; ++i) {
// //         long long fill = std::min(remaining_gap_space, max_single_gap_size);
// //         gaps[i] = fill;
// //         remaining_gap_space -= fill;
// //     }

// //     // 4. Construct the result vector based on the calculated gaps.
// //     std::vector<int> result(A, 0);
// //     int current_pos_1_based = 1;

// //     // Add the first gap (before any platforms).
// //     current_pos_1_based += gaps[0];

// //     // Place platforms and the gaps between them.
// //     for (int i = 0; i < M; ++i) {
// //         // Place platform i.
// //         int platform_size = C[i];
// //         int platform_id = i + 1; // 1-based platform index for output.
// //         for (int j = 0; j < platform_size; ++j) {
// //             int cell_index_0_based = current_pos_1_based + j - 1;
// //             if (cell_index_0_based < A) {
// //                 result[cell_index_0_based] = platform_id;
// //             }
// //         }
// //         current_pos_1_based += platform_size;

// //         // Add the gap after platform i.
// //         // gaps[i+1] is the gap between platform i and platform i+1.
// //         current_pos_1_based += gaps[i + 1];
// //     }

// //     return result;
// // }
// //

// // #include <iostream>
// // #include <vector>
// // #include <numeric>
// // #include <algorithm>
// // using namespace std;

// // vector<int> solve(int A, int B, vector<int> C) {
// //     int m = C.size();
// //     long long s = 0;
// //     for (int x : C) s += x;
// //     if (s > A) return {-1};
// //     long long g = A - s;
// //     int k = m + 1;
// //     long long mx = 1LL * k * (B - 1);
// //     if (B == 0 && g > 0) return {-1};
// //     if (B > 0 && g > mx) return {-1};

// //     vector<long long> gap(k, 0);
// //     long long rem = g, cap = (B > 0 ? B - 1 : 0);
// //     for (int i = 0; i < k; i++) {
// //         long long take = min(rem, cap);
// //         gap[i] = take;
// //         rem -= take;
// //     }

// //     vector<int> res(A, 0);
// //     int pos = 1;
// //     pos += gap[0];
// //     for (int i = 0; i < m; i++) {
// //         int sz = C[i], id = i + 1;
// //         for (int j = 0; j < sz; j++) {
// //             int idx = pos + j - 1;
// //             if (idx < A) res[idx] = id;
// //         }
// //         pos += sz;
// //         pos += gap[i + 1];
// //     }
// //     return res;
// // }
// //

// #include <iostream>
// #include <vector>
// #include <numeric>
// #include <algorithm>
// using namespace std;

// vector<int> solve(int A, int B, vector<int> C) {
//     int m = C.size();
//     long long s = 0;
//     for (int x : C) s += x;
//     if (s > A) return {-1};

//     long long g = A - s;
//     int k = m + 1;
//     long long mx = 1LL * k * (B - 1);
//     if (B == 0 && g > 0) return {-1};
//     if (B > 0 && g > mx) return {-1};

//     vector<long long> gap(k, 0);
//     long long rem = g, cap = (B > 0 ? B - 1 : 0);
//     for (int i = 0; i < k; i++) {
//         long long take = min(rem, cap);
//         gap[i] = take;
//         rem -= take;
//     }

//     vector<int> res(A, 0);
//     int pos = 1;
//     pos += gap[0];
//     for (int i = 0; i < m; i++) {
//         int sz = C[i], id = i + 1;
//         for (int j = 0; j < sz; j++) {
//             int idx = pos + j - 1;
//             if (idx < A) res[idx] = id;
//         }
//         pos += sz;
//         pos += gap[i + 1];
//     }
//     return res;
// }


#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

/**
 * @brief Calculates the initial number of blocks in each column of the field.
 * @param field The 2D vector representing the grid.
 * @return A vector where the element at index j is the count of blocks in column j.
 */
// std::vector<int> getInitialBlockCounts(const std::vector<std::vector<char>>& field) {
//     if (field.empty() || field[0].empty()) {
//         return {};
//     }
//     int height = field.size();
//     int width = field[0].size();
//     std::vector<int> counts(width, 0);
//     for (int j = 0; j < width; ++j) {
//         for (int i = 0; i < height; ++i) {
//             if (field[i][j] == '#') {
//                 counts[j]++;
//             }
//         }
//     }
//     return counts;
// }

// /**
//  * @brief Calculates the minimum and maximum number of moves to fill the first column.
//  * @param field The 2D vector representing the grid. '#' for blocks, '.' for empty.
//  * @return A vector of two integers: {minimum_moves, maximum_moves}.
//  */
// std::vector<int> solution(std::vector<std::vector<char>> field) {
//     if (field.empty() || field[0].empty()) {
//         return {0, 0};
//     }

//     int height = field.size();
//     int width = field[0].size();

//     std::vector<int> initial_counts = getInitialBlockCounts(field);
//     int empty_in_first_col = height - initial_counts[0];

//     if (empty_in_first_col == 0) {
//         return {0, 0};
//     }

//     // --- Minimum Moves Calculation ---
//     int min_moves = empty_in_first_col;
//     if (width > 1) {
//         int first_support_col = -1;
//         // Find the closest column >= 1 with a block.
//         for (int j = 1; j < width; ++j) {
//             if (initial_counts[j] > 0) {
//                 first_support_col = j;
//                 break;
//             }
//         }

//         if (first_support_col != -1) {
//             // It takes (k-1) moves to bring support from column k to column 1.
//             min_moves += (first_support_col - 1);
//         } else {
//             // If no support exists, we create it in the last column and bring it over.
//             min_moves += (width - 1);
//         }
//     }

//     // --- Maximum Moves Calculation ---
//     long long max_moves = empty_in_first_col;
//     long long needed_supports = empty_in_first_col;
//     for (int j = 1; j < width; ++j) {
//         // To maximize moves, for each required support, we create a new block
//         // in a previously empty cell of the current column.
//         long long blocks_to_add = std::min(needed_supports, (long long)height - initial_counts[j]);
//         max_moves += blocks_to_add;
//         needed_supports = blocks_to_add;
//     }

//     return {(int)min_moves, (int)max_moves};
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> solve(vector<vector<char>> g) {
//     if (g.empty() || g[0].empty()) return {0, 0};
//     int h = g.size(), w = g[0].size();
//     vector<int> c(w, 0);
//     for (int j = 0; j < w; j++)
//         for (int i = 0; i < h; i++)
//             if (g[i][j] == '#') c[j]++;
//     int e = h - c[0];
//     if (!e) return {0, 0};

//     int mn = e;
//     if (w > 1) {
//         int p = -1;
//         for (int j = 1; j < w; j++) if (c[j]) { p = j; break; }
//         mn += (p != -1 ? p - 1 : w - 1);
//     }

//     long long mx = e, need = e;
//     for (int j = 1; j < w; j++) {
//         long long add = min(need, (long long)h - c[j]);
//         mx += add;
//         need = add;
//     }
//     return {(int)mn, (int)mx};
// }
// #include <iostream>
// #include <vector>
// #include <string>
// #include <unordered_set>
// #include <unordered_map>
// #include <algorithm>
// #include <numeric>

// // Helper function to convert a word to its numerical value based on a mapping.
// long long wordToNumber(const std::string& word, const std::unordered_map<char, int>& mapping) {
//     long long number = 0;
//     for (char c : word) {
//         // Find the digit corresponding to the character and append it.
//         number = number * 10 + mapping.at(c);
//     }
//     return number;
// }

// int solution(std::vector<std::string> crypt) {
//     // 1. Identify all unique characters and leading characters.
//     std::unordered_set<char> unique_char_set;
//     std::unordered_set<char> leading_chars;

//     for (const auto& word : crypt) {
//         // Words with more than one letter cannot start with '0'.
//         if (word.length() > 1) {
//             leading_chars.insert(word[0]);
//         }
//         // Collect all unique characters.
//         for (char c : word) {
//             unique_char_set.insert(c);
//         }
//     }

//     // If there are more than 10 unique characters, no solution is possible.
//     if (unique_char_set.size() > 10) {
//         return 0;
//     }

//     // Create a vector of unique characters to map against permutations of digits.
//     std::vector<char> letters(unique_char_set.begin(), unique_char_set.end());
//     std::vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int solution_count = 0;

//     // 2. Iterate through all permutations of the digits [0-9].
//     do {
//         std::unordered_map<char, int> mapping;

//         // Create the character-to-digit mapping for the current permutation.
//         for (size_t i = 0; i < letters.size(); ++i) {
//             mapping[letters[i]] = digits[i];
//         }

//         // 3. Check for the leading zero constraint.
//         bool has_leading_zero = false;
//         for (char leading_char : leading_chars) {
//             if (mapping.count(leading_char) && mapping.at(leading_char) == 0) {
//                 has_leading_zero = true;
//                 break;
//             }
//         }

//         if (has_leading_zero) {
//             continue; // This permutation is invalid, try the next one.
//         }

//         // 4. Convert words to numbers and check if the arithmetic is correct.
//         long long num1 = wordToNumber(crypt[0], mapping);
//         long long num2 = wordToNumber(crypt[1], mapping);
//         long long num3 = wordToNumber(crypt[2], mapping);

//         if (num1 + num2 == num3) {
//             solution_count++;
//         }

//     } while (std::next_permutation(digits.begin(), digits.end()));

//     return solution_count;
// }
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class OptimizedCryptarithmSolver {
private:
    vector<string> words;
    vector<char> letters;
    set<char> leadingLetters;
    unordered_map<char, int> assignment;
    vector<bool> usedDigits;
    int solutionCount;

    // Powers of 10 for quick calculation
    vector<long long> pow10;

    // Precomputed coefficients for each letter in the equation
    unordered_map<char, long long> coefficients;

    void precomputeCoefficients() {
        coefficients.clear();

        // For word1 + word2 - word3 = 0
        // Calculate coefficient of each letter

        // Process first word (positive coefficients)
        long long multiplier = 1;
        for (int i = words[0].length() - 1; i >= 0; i--) {
            coefficients[words[0][i]] += multiplier;
            multiplier *= 10;
        }

        // Process second word (positive coefficients)
        multiplier = 1;
        for (int i = words[1].length() - 1; i >= 0; i--) {
            coefficients[words[1][i]] += multiplier;
            multiplier *= 10;
        }

        // Process third word (negative coefficients)
        multiplier = 1;
        for (int i = words[2].length() - 1; i >= 0; i--) {
            coefficients[words[2][i]] -= multiplier;
            multiplier *= 10;
        }
    }

    // Quick equation check using precomputed coefficients
    bool isValidEquation() {
        long long sum = 0;
        for (const auto& pair : coefficients) {
            if (assignment.count(pair.first)) {
                sum += pair.second * assignment[pair.first];
            }
        }
        return sum == 0;
    }

    // Partial equation check for pruning
    long long getPartialSum(int letterIndex) {
        long long sum = 0;
        for (int i = 0; i < letterIndex; i++) {
            char letter = letters[i];
            sum += coefficients[letter] * assignment[letter];
        }
        return sum;
    }

    // Check if remaining assignment can possibly satisfy equation
    bool canComplete(int letterIndex, long long currentSum) {
        if (letterIndex == letters.size()) {
            return currentSum == 0;
        }

        // Calculate bounds for remaining sum
        long long minRemaining = 0, maxRemaining = 0;
        vector<long long> remainingCoeffs;

        for (int i = letterIndex; i < letters.size(); i++) {
            long long coeff = coefficients[letters[i]];
            remainingCoeffs.push_back(coeff);
        }

        sort(remainingCoeffs.begin(), remainingCoeffs.end());

        // Assign smallest available digits to largest positive coefficients
        // and largest available digits to largest negative coefficients
        vector<int> availableDigits;
        for (int d = 0; d <= 9; d++) {
            if (!usedDigits[d]) {
                availableDigits.push_back(d);
            }
        }

        if (availableDigits.size() < letters.size() - letterIndex) {
            return false;
        }

        // Simple bound check
        for (int i = 0; i < remainingCoeffs.size(); i++) {
            if (remainingCoeffs[i] > 0) {
                minRemaining += remainingCoeffs[i] * availableDigits[0];
                maxRemaining += remainingCoeffs[i] * availableDigits.back();
            } else {
                minRemaining += remainingCoeffs[i] * availableDigits.back();
                maxRemaining += remainingCoeffs[i] * availableDigits[0];
            }
        }

        long long target = -currentSum;
        return target >= minRemaining && target <= maxRemaining;
    }

    void backtrack(int letterIndex) {
        if (letterIndex == letters.size()) {
            if (isValidEquation()) {
                solutionCount++;
            }
            return;
        }

        char currentLetter = letters[letterIndex];
        bool isLeading = leadingLetters.count(currentLetter) > 0;

        long long currentSum = getPartialSum(letterIndex);

        // Pruning: check if completion is possible
        if (!canComplete(letterIndex, currentSum)) {
            return;
        }

        // Try each digit
        for (int digit = (isLeading ? 1 : 0); digit <= 9; digit++) {
            if (!usedDigits[digit]) {
                assignment[currentLetter] = digit;
                usedDigits[digit] = true;

                // Early pruning for last letter
                if (letterIndex == letters.size() - 1) {
                    long long newSum = currentSum + coefficients[currentLetter] * digit;
                    if (newSum == 0) {
                        solutionCount++;
                    }
                } else {
                    backtrack(letterIndex + 1);
                }

                usedDigits[digit] = false;
            }
        }
    }

public:
    int solve(vector<string> crypt) {
        words = crypt;
        solutionCount = 0;

        // Extract unique letters
        set<char> letterSet;
        for (const string& word : words) {
            for (char c : word) {
                letterSet.insert(c);
            }
        }

        letters.assign(letterSet.begin(), letterSet.end());

        if (letters.size() > 10) return 0;

        // Find leading letters
        leadingLetters.clear();
        for (const string& word : words) {
            if (word.length() > 1) {
                leadingLetters.insert(word[0]);
            }
        }

        // Order letters by coefficient magnitude for better pruning
        precomputeCoefficients();
        sort(letters.begin(), letters.end(), [this](char a, char b) {
            return abs(coefficients[a]) > abs(coefficients[b]);
        });

        assignment.clear();
        usedDigits.assign(10, false);

        backtrack(0);

        return solutionCount;
    }
};

int solution(vector<string> crypt) {
    OptimizedCryptarithmSolver solver;
    return solver.solve(crypt);
}
int main() {

    cout << solution({"GREEN", "BLUE", "BLACk"});

    // for(int i: v){
    //     cout << i << ' ';
    // }
    return 0;
}
