import Data.List
--Problema 1
fibonacci :: Int -> Integer
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci n = fibonacci (n-1) + fibonacci (n-2)


--Problema 2
evenNumbers :: (Integral a) => [a] -> [a]
evenNumbers [] = []
evenNumbers (x:xs)
  | x `mod` 2 == 0     = x : evenNumbers xs
  |otherwise           = evenNumbers xs

--Problema 3
listor :: (Ord a, Num a) => [a] -> [a] -> [a]
listor [] [] = []
listor ( x:xs ) ( y:ys ) = if (x+y) > 0
                       then 1 : listor xs ys
                       else 0 : listor xs ys

--Problema 4
inverseRelation :: (Real a) => [(a,a)] -> [(a,a)]
inverseRelation [] = []
inverseRelation ((a,b):xs) = (b,a) : inverseRelation xs

--Problema 5
multiples :: (Integral a) => [a] -> a -> [a]
multiples [] _= []
multiples x n =  ( filter (\i -> n `mod` i == 0) ) x

--Problema 6
toBinaryString :: (Integral a) => a -> String
toBinaryString 0 = "0"
toBinaryString 1 = "1"
toBinaryString x
  | x `mod` 2 == 1 = toBinaryString (div x 2) ++ "1"
  | otherwise = toBinaryString (div x 2) ++ "0"

--Challenge 1
polynomials :: [Int] -> Int -> Int
polynomials ( a:[] ) _ = a
polynomials (a:as) x = a * (x ^ ( length as )) + polynomials as x

--t-Challenge 2
transitive :: [(Int,Int)]-> [(Int,Int)]
transitive xs
  | current ==  next_closure = current
  | otherwise     = transitive next_closure
    where current = nub xs
          extra_relations = [(x,w)| (x,y)<- xs, (q,w)<- xs, y == q]
          next_closure = current `union` extra_relations

--for a in A and b in B if (a,b) and (b,c) then (a,c)
