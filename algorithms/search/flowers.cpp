/*
 * flowers.cpp
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
#include <iostream>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N, 0);
  for (int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    A.at(i) = temp;
  }
  
  sort(A.begin(), A.end());
  
  int total = 0;
  int multiplier = 0;
  for(int i = 0; i < N; i++) {
    if (i % K == 0) multiplier++;
    total += A.at(N-i-1) * multiplier;
  }
  
  cout << total << endl;
    
  
  return 0;
}
