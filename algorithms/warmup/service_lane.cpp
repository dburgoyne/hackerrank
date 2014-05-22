/*
 * service_lane.cpp
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
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    std::vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
      int temp;
      cin >> temp;
      A.at(i) = temp;
    }

    while (T--) {
        int i, j;
        cin >> i >> j;
        cout << *min_element(A.begin() + i, A.begin() + j + 1) << endl;
    }
}
