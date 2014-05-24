--
-- string_o_permute.hs
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

-- How many BSTs exist on a list of c distinct elements?
-- Only one BST exists on 0 or 1 element.
-- For larger numbers, we can select any element as the root, and multiply the
-- number of BSTs on the elements less than the root with the number of BSTs on
-- the elements greater than the root. Summing over all possible roots gives
-- the answer.
f :: String -> String
f (x:y:xs) = y:x:(f xs)
f [] = []

main = do 
  n <- readLn :: IO Int 
  inputdata <- getContents 
  let 
    strings = lines inputdata :: [String] 
  putStr . unlines $ map f strings
