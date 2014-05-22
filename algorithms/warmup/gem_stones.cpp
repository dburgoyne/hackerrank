/*
 * gem_stones.cpp
 *
 * AUTHOR:
 *   Danny Burgoyne <secure@dburgoyne.ca>
 *   Any comments/corrections/suggestions are very welcome.
 *
 * COPYING CONDITIONS:
 *   Copyright (C) 2014 Danny Burgoyne
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <iostream>

using namespace std;

int main() {
  // Global flags starts with a 1 in the lower 26 bits and 0 elsewhere.
  int N, global_flags = 0x03FFFFFF;
  // In binary, this number is 00000011111111111111111111111111.
  cin >> N;

  // For each stone...
  while (N--) {
    string s;
    cin >> s;
    int flags = 0;
    // ...look at each character in the stone...
    for(int i = 0; i < s.length(); i++) {
      // ...and set the corresponding bit of flags
      // e.g. if a 'c' is read in, the bit at index 2 is set.
      flags |= 1 << (s.at(i) - 'a');
    }
    global_flags &= flags;
  }

  // Add up all the bits in global_flags
  int answer = 0;
  while (global_flags > 0) {
    answer += global_flags % 2;
    global_flags /= 2;
  }
  
  cout << answer << endl;
  return 0;
}
