#include <iostream> // For input/output operations (cin, cout)
#include <vector>   // For using vectors (dynamic arrays)
#include <string>   // For using strings
#include <numeric>  // Potentially useful for numerical algorithms, though not directly used here
#include <algorithm> // For using standard algorithms like std::max

// Check if compiled with GCC or Clang which support __builtin_popcount intrinsic
#ifdef __GNUC__
// Define POPCOUNT macro to use the efficient built-in function for counting set bits
#define POPCOUNT __builtin_popcount
#else
// Define a manual implementation of popcount (counting set bits) for other compilers
// or older C++ standards that don't have a standard popcount function.
int countSetBits(int n) {
    int count = 0;
    // Brian Kernighan's algorithm is an efficient way to count set bits.
    // It works by repeatedly removing the least significant set bit until n becomes 0.
    while (n > 0) {
        n &= (n - 1); // This operation clears the least significant set bit
        count++;
    }
    return count;
}
// Define POPCOUNT macro to use the manual implementation
#define POPCOUNT countSetBits
#endif

// Define the fixed set of color names provided in the problem statement.
// Using a const vector of strings to store them.
const std::vector<std::string> colors = {
    "blue", "green", "yellow", "red", "purple", "orange", "pink", "grey", 
    "cyan", "brown", "ash", "silver", "gold", "white", "black"
};
// Store the number of colors in the set. This is fixed at 15.
const int NUM_COLORS = colors.size(); 

// Declare a global 2D vector to store the precomputed character frequency requirements for each color.
// `color_req[i][j]` will store the count of the j-th character ('a' + j) needed for the i-th color (`colors[i]`).
// Initialize with dimensions NUM_COLORS x 26 (for 'a' through 'z').
std::vector<std::vector<int>> color_req(NUM_COLORS, std::vector<int>(26, 0));

// Function to precompute the character requirements for all the colors in the `colors` list.
// This function populates the `color_req` table. It should be called once.
void precompute_reqs() {
    // Use a static flag to ensure this computation is performed only once during the program execution.
    static bool computed = false;
    if (computed) return; // If already computed, simply return.
    
    // Iterate through each color index `i` from 0 up to NUM_COLORS - 1.
    for (int i = 0; i < NUM_COLORS; ++i) {
        // Iterate through each character `ch` in the current color string `colors[i]`.
        for (char ch : colors[i]) {
            // Calculate the index corresponding to the character (0 for 'a', 1 for 'b', etc.).
            // Increment the count for this character in the requirement table for color `i`.
            // This assumes that color names only contain lowercase English letters, as specified.
            color_req[i][ch - 'a']++;
        }
    }
    computed = true; // Set the flag to true indicating computation is complete.
}

// The main function where the program execution begins.
int main() {
    // Optimize C++ standard input/output streams for faster execution.
    std::ios_base::sync_with_stdio(false); // Disable synchronization with C standard streams
    std::cin.tie(NULL); // Untie cin from cout

    // Call the function to precompute character requirements before handling any test cases.
    precompute_reqs(); 

    int t; // Declare variable to store the number of test cases.
    std::cin >> t; // Read the number of test cases from standard input.
    
    // Loop `t` times to process each test case.
    while (t--) {
        std::string s; // Declare variable to store the input string S for the current test case.
        std::cin >> s; // Read the input string S.

        // Calculate the frequency of each lowercase English letter ('a' to 'z') present in the string S.
        std::vector<int> s_counts(26, 0); // Initialize a vector of size 26 with all counts set to 0.
        for (char ch : s) {
             // Calculate the index for the character (0 for 'a', 1 for 'b', ...).
             // Increment the count for that character.
             // This assumes S contains only lowercase English letters as per problem constraints.
             s_counts[ch - 'a']++;
        }

        int max_colors = 0; // Initialize the variable to store the maximum number of colors possible for this test case.
        
        // Iterate through all possible subsets of the NUM_COLORS colors.
        // We use a bitmask approach. An integer `mask` from 0 to 2^NUM_COLORS - 1 represents a subset.
        // If the i-th bit of `mask` is set (1), it means the i-th color is included in the subset.
        for (int mask = 0; mask < (1 << NUM_COLORS); ++mask) {
            
            // For the current subset represented by `mask`, calculate the total character requirements.
            std::vector<int> current_req(26, 0); // Initialize requirements vector for this subset with zeros.
            
            // Iterate through each color index `i` from 0 to NUM_COLORS - 1.
            for (int i = 0; i < NUM_COLORS; ++i) {
                // Check if the i-th bit is set in the mask using a bitwise right shift and AND operation.
                if ((mask >> i) & 1) { 
                    // If the i-th color is part of the current subset...
                    // Add its precomputed character requirements to the `current_req` vector.
                    for (int char_idx = 0; char_idx < 26; ++char_idx) {
                        current_req[char_idx] += color_req[i][char_idx];
                    }
                }
            }

            // After calculating total requirements for the subset, check if it's feasible.
            // A subset is feasible if the requirement for every character does not exceed its available count in S.
            bool possible = true; // Assume the subset is feasible initially.
            for (int char_idx = 0; char_idx < 26; ++char_idx) {
                // Compare the required count `current_req[char_idx]` with the available count `s_counts[char_idx]`.
                if (current_req[char_idx] > s_counts[char_idx]) {
                    // If requirement exceeds availability for any character, the subset is not feasible.
                    possible = false; 
                    break; // Exit the feasibility check loop early, no need to check other characters.
                }
            }

            // If the current subset is determined to be feasible...
            if (possible) {
                 // Calculate the size of this feasible subset (number of colors). This is equal to the number of set bits in the mask.
                 // Use the POPCOUNT macro (either __builtin_popcount or the manual function).
                 // Update `max_colors` if the size of the current feasible subset is larger than the maximum found so far.
                 max_colors = std::max(max_colors, POPCOUNT(mask));
            }
        }
        // After checking all 2^15 possible subsets, print the maximum size found for this test case.
        std::cout << max_colors << std::endl;
    }
    
    return 0; // Indicate successful program termination.
}