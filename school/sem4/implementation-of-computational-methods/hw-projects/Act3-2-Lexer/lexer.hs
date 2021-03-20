{-# LANGUAGE OverloadedStrings #-}
import System.IO

{-
Contents->Lines
Lines->Char
foldl 
Char State -> nextState

-}

main = do
  putStrLn "Ingrese el nombre del archivo"
  hFlush stdout
  file <- getLine
  contents <- readFile file
  putStrLn $ concatMap show $ head (lines contents)
  let lexed = lexer (lines contents)
  putStrLn $ concatMap show lexed

lexer :: [[Char]] -> [Int]
--lexer = map (map (flip (nextState) 0))
lexer lines = scanl (\state char -> if state < 100 then nextState state char else nextState 0 char) 0 (head lines)

getToken :: Char -> Int -> [Char] -> [Char]
getToken char state token
  | next > 100             = token
  | otherwise              = token ++ [char]
  where
    next = nextState state char

calcStates :: [Char] -> [Int]
calcStates chars = states ++ [nextState (last states) ' ']
  where states = (tail . tail$ scanl (\state char -> if state < 100 then nextState state char else nextState 0 char) 0 chars)
--se sobreescriben tokens como = y +

nextState :: Int -> Char -> Int
nextState state char
  | char == ' '            = head stateList 
  | char `elem` ['a'..'z'] = stateList !! 1 
  | char `elem` ['A'..'Z'] = stateList !! 2 
  | char == '_'            = stateList !! 3 
  | char `elem` ['0'..'9'] = stateList !! 4 
  | char == '='            = stateList !! 5 
  | char == '+'            = stateList !! 6 
  | char == '-'            = stateList !! 7 
  | char == '/'            = stateList !! 8 
  | char == '*'            = stateList !! 9 
  | char == '^'            = stateList !! 10
  | char == '('            = stateList !! 11
  | char == ')'            = stateList !! 12
  | otherwise              = last stateList 
  where e = 999
        stateMatrix = [
         {- space     [a..z]   [A..Z]    _     [0..9]     =    +     -     /     *    ^   (     )     else-}
   {- 0 -} [   0,       1,       1,      e,      e,       2,   3,    4,    5,    7,   8,  9,    10,   e    ],
   {- 1 -} [   101,     1,       1,      1,      1] ++ repeat 101,
   {- 2 -} repeat 102,
   {- 3 -} repeat 103,
   {- 4 -} repeat 104,
   {- 5 -} replicate 8 105  ++ [6] ++ repeat 105,
   {- 6 -} repeat 6,
   {- 7 -} repeat 107,
   {- 8 -} repeat 108,
   {- 9 -} repeat 109,
   {- 10-} repeat 110

         ]
        stateList = stateMatrix !! state
