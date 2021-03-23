
-- Ejercicio 1
unique :: String -> String
unique = foldl acumulado []

acumulado :: String -> Char -> String
acumulado x nueva
  | nueva `notElem` x =  x ++ [nueva]
  | otherwise              = x

-- Ejercicio 2

evenHigherNumbers :: [Integer] -> [Integer]
evenHigherNumbers [] = []
evenHigherNumbers x = filter even x

-- Ejercicio 3

reduceMatrix :: [[Int]] -> Int
reduceMatrix [] = 0
reduceMatrix x = foldl (\x y -> x + sumaMatriz y) 0 x

sumaMatriz :: [Int] -> Int
sumaMatriz [] = 0
sumaMatriz x = sum x

-- Ejercicio 4

maskedSum :: [Int] -> [Bool] -> Int
maskedSum _ [] = 0
maskedSum [] _ = 0
maskedSum nums bools = sum (valid nums bools)

valid :: [Int] -> [Bool] -> [Int]
valid nums bools = map fst (filter (\i -> snd i == 1) ( zip nums (map boolToInt bools )))

boolToInt :: Bool -> Int
boolToInt True = 1
boolToInt False = 0

-- Ejercicio 5

multiples :: [Int] -> Int -> [Int]
multiples [] _ = []
multiples _ 0 = []
multiples nums x = filter (\i -> x `mod` i == 0) nums

-- Ejercicio 6

combine :: [[a]] -> [[a]] -> [[(a,a)]]
combine = zipWith zip

-- Challenge III

rotate :: [[Int]] -> [[Int]]
rotate matrix = map reverse (transpose matrix)

transpose :: [[Int]] -> [[Int]]
transpose matrix
  | length ( head matrix ) == 1 = [map head matrix]
  | otherwise    = map head matrix: transpose (map tail matrix)

-- Extras
{-
  Hace una matriz de n*n con formato
  | 1           2             ... n  |
  | n+1         n+2           ... n+n|
  | ...         ...           ...    |
  | n*(n-1)+1   n*(n-1)+2     ... n*n|
-}
rect dim = [[x+dim*j|x<-[1..dim]]|j<-[0..(dim-1)]]
