/*
 * sherlock_and_the_beast.cpp
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


#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    
    int num_fives = 0;
    int num_threes = 0;
    // We want to find non-negative integers x,y such that
    // 3x + 5y = n and x is maximized.
    for(int i = 0; i <= n/3; i++) {
      int y = i;
      int x = (n - 5*y) / 3;
      if (x >= 0 && 3*x + 5*y == n) {
	num_fives = 3*x;
	num_threes = 5*y;
	break;
      }
    }
    
    if (num_fives == 0 && num_threes == 0) {
      cout << -1 << endl;
    } else {
      for(int i = 0; i < num_fives; i++) cout << 5;
      for(int i = 0; i < num_threes; i++) cout << 3;
      cout << endl;
    }
  }
  
  return 0;
}