 --
-- red_john_is_back.hs
--
-- AUTHOR:
--   Danny Burgoyne <secure@dburgoyne.ca>
--   Any comments/corrections/suggestions are very welcome.
--
-- COPYING CONDITIONS:
--   Copyright (C) 2014 Danny Burgoyne
--
--   This program is free software: you can redistribute it and/or modify
--   it under the terms of the GNU General Public License as published by
--   the Free Software Foundation, either version 3 of the License, or
--   (at your option) any later version.
--
--   This program is distributed in the hope that it will be useful,
--   but WITHOUT ANY WARRANTY; without even the implied warranty of
--   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--   GNU General Public License for more details.
--
--   You should have received a copy of the GNU General Public License
--   along with this program.  If not, see <http://www.gnu.org/licenses/>.
--

f1 :: [Int] -> Int
f1 [n] = sum $ map (\i -> choose (n-3*i) i) [0..n `div` 4]

choose n k = foldl (\z i -> (z * (n-i+1)) `div` i) 1 [1..k]

primes :: [Int]
primes = 2: 3: sieve (tail primes) [5,7..]
 where 
  sieve (p:ps) xs = h ++ sieve ps [x | x <- t, x `rem` p /= 0]  
                                -- or:  filter ((/=0).(`rem`p)) t
                  where (h,~(_:t)) = span (< p*p) xs

main = do 
  n <- readLn :: IO Int 
  inputdata <- getContents 
  let 
    numbers = map read (lines inputdata) :: [Int] 
  putStrLn . unlines $ map (show . (\x -> length (takeWhile (<= (f1 [x])) primes))) numbers
