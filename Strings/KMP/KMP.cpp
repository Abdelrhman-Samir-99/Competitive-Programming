#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


class KMP {

	// String matching aglrotihm which takes O(M + N) time & Memory.
	// Has 2 sections which are building LPS and building the KMP table.
	
	private:
		vector <int> kmp;
		vector <int> lps; // Longest Prefix Suffix.
		int n; // length of a text.
		int m; // length of pattern.
		
		void build_lps(char* pattern) { // Takes O(M) to build.
			
			int ptr = 0; // pointer to the char to be compared.

			for(int i = 1; pattern[i]; ++i) {
				if(pattern[i] == pattern[ptr]) { // if we got a match then we move the pointer.
					++ptr;
					lps[i] = ptr;
				}
				else {
					if(ptr > 0) {
						// If we got a mismatch then we start where the lps[ptr - 1] was finished.
						// and repeat the same steps until we reach a (0) index or find a match.
						ptr = lps[ptr - 1];
						--i;
						continue;
					}
					else
						ptr = 0;
					lps[i] = ptr;
				}
			}
		}

		
		void build_kmp(char* text, char* pattern) {
			// Takes O(N) to build based on the lps array.
			// The same idea as build lps array.
			build_lps(pattern);
			
			int ptr = 0; // pointer on the pattern.
			
			for(int i = 0; text[i]; ++i) {
				if(text[i] == pattern[ptr]) {
					++ptr;
					kmp[i] = ptr;
				}
				else {
					if(ptr > 0) {
						ptr = lps[ptr - 1];
						--i;
						continue;
					}
					else
						ptr = 0;
					kmp[i] = ptr;
				}
			}
		}
		
	public:
	
		KMP(char* text, char* pattern) {
			n = strlen(text);
			m = strlen(pattern);
			kmp.resize(n, 0);
			lps.resize(m, 0);
			build_lps(pattern);
		}

		vector <int> get_lps(char* pattern) {
			build_lps(pattern);
			return lps;
		}
		
		vector <int> get_kmp(char* text, char* pattern) {
			build_kmp(text, pattern);
			return kmp;
		}
};
